import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.time.Instant;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class WebCrawlerMultiThread {

    private Map<String, Integer> visitedUrls;
    private Deque<String> urlsQueue;
    private Instant startTime;
    private final int maxDepth = 4;
    private final int maxUrlsPerPage = 130;

    public WebCrawlerMultiThread(Instant start) {
        visitedUrls = new HashMap<>();
        urlsQueue = new LinkedList<>();
        startTime = start;
    }

    public void crawl(String rootUrl) {
        urlsQueue.addLast(rootUrl);
        visitedUrls.put(rootUrl, 1);

        ExecutorService executorService = Executors.newFixedThreadPool(10);
        while (!urlsQueue.isEmpty()) {
            String url = urlsQueue.removeFirst();
            int depth = visitedUrls.get(url);

            if (depth < maxDepth) {
                Runnable task = new Runnable() {
                    @Override
                    public void run() {
                        try {
                            URL urlObject = new URL(url);
                            BufferedReader in = new BufferedReader(new InputStreamReader(urlObject.openStream()));
                            String inputLine = in.readLine();
                            String rawHtml = "";

                            while (inputLine != null) {
                                rawHtml += inputLine;
                                inputLine = in.readLine();
                            }

                            in.close();
                            parseAndAddUrls(rawHtml, depth);
                        } catch (IOException e) {
                            throw new RuntimeException(e);
                        }
                    }
                };

                executorService.submit(task);
            }
        }
        executorService.shutdown();
        try {
            executorService.awaitTermination(100000000, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    private void parseAndAddUrls(String rawHtml, int depth) {
        String urlPattern = "((\\/wiki\\/)+[^\\s\\.\\#\\:\"]+[\\w])\"";
        Pattern pattern = Pattern.compile(urlPattern);
        Matcher matcher = pattern.matcher(rawHtml);

        int cntUrlsPerPage = 0;

        while (matcher.find()) {
            String newUrl = matcher.group(1);
            newUrl = "https://en.wikipedia.org" + newUrl;

            if (!visitedUrls.containsKey(newUrl)) {
                urlsQueue.addLast(newUrl);
                visitedUrls.put(newUrl, depth + 1);
                cntUrlsPerPage += 1;

                if (cntUrlsPerPage >= maxUrlsPerPage) {
                    break;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        long startTime = System.nanoTime();
        Instant start = Instant.now();
        WebCrawlerMultiThread crawler = new WebCrawlerMultiThread(start);
        crawler.crawl("https://en.wikipedia.org/wiki/Travelling_salesman_problem");


        long endTime = System.nanoTime();
        long totalTime = endTime - startTime;
        System.out.println("Visited " + crawler.visitedUrls.size() + " Urls  in " + totalTime / 1000000 + " ms");
//        List<String> list = new ArrayList<>();
//        for (Map.Entry<String, Integer> entry : crawler.visitedUrls.entrySet()) {
//            list.add(entry.getKey());
//        }
//        Collections.sort(list);
//        for (String s : list) {
//            System.out.println(s);
//        }
    }
}