#include <iostream>
#include <unordered_map>
#include <array>

struct ArrayHash {
    size_t operator()(const std::array<int, 26>& arr) const {
        size_t hashValue = 0;
        for (int i = 0; i < 26; ++i) {
            hashValue ^= std::hash<int>{}(arr[i]) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);
        }
        return hashValue;
    }
};

int countSubstringsWithEqualCharFreq(std::string s) {
    int res = 0;
    int n = s.length();

    for (int len = 1; len <= n; len++) {
        std::unordered_map<std::array<int, 26>, int, ArrayHash> freq;
        std::array<int, 26> count_a = {0};

        for (int i = 0; i < len; i++)
            count_a[s[i] - 'a']++;

        freq[count_a]++;

        for (int i = len; i < n; i++) {
            count_a[s[i - len] - 'a']--;
            count_a[s[i] - 'a']++;
            freq[count_a]++;
        }

        for (auto &it : freq) {
            int occurrences = it.second;
            res += (occurrences * (occurrences - 1)) / 2; // Calculate the number of pairs
        }
    }

    return res;
}

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        std::string s;
        std::cin >> s;
        std::cout << countSubstringsWithEqualCharFreq(s) << std::endl;
    }

    return 0;
}
