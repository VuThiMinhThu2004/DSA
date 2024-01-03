#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int MAXN = 1005;
#define ll long long

typedef pair<ll,int> ii;
vector<ii> adj[MAXN];
int visited[MAXN];

/*
Phan 1: CTDL
TH khong co duong di -> tra ve -1
Hang doi uu tien co trong so(w)
set
Map: anh xa: 2 cap key-value(key khong duoc trung nhau: anh xa don anh)
Hash: 2 loai: chuoi(training: danh sach lien ket: cai dat kho hon, khong gioi han so luong phan tu , tim kiem O(N))
Hash: tuyen tinh: mang -> cai dat de hon nhung bi gioi han so luong phan tu
Cay: la cau truc du lieu phan tang. Cay binh thuong: chieu cao cua not la, chieu cao cua cay
Duyet cay binh thuong co 2 cach: khong co sap xep trung
Cay nhi phân có N nốt -> độ cao max là: (N-1), do cao min la Log2(N)
Cay tim kiem nhi phân: con trái < cha < con phải => bài toán tìm kiếm

thêm sửa xóa

Cây heap: là cây đầy đủ, cha lớn hoặc nhỏ hơn các con do cài đặt
Được cài bằng các cấu trúc dữ liệu chứa được data
Vì nó là cây đầy đủ => dùng mảng để chứa: vì biết được vị trí cha sẽ tìm được con: 2*N-1

cây cân bằng = AVL: độ sâu chênh lệch giữa các lá không quá 1
Cây hoàn chỉnh, cây hoàn hảo: là cây full 1 tầng <=> độ cao của cây = log(N)

GRAPH: là cấu trúc dữ liệu gồm các đỉnh và các cạnh. Trong đó cạnh là nối các đỉnh
các loại: vô hướng, có hướng, có trọng số, không trọng số.
3 cách cài đặt: ma trận kề, danh sách cạnh, danh sách kề.
để biểu diễn ma trận thưa => nên dùng danh sách cạnh, danh sách kề.
Duyệt đồ thị: DFS: duyệt theo chiều sâu stack, BFS: queue: duyệt theo chiều rộng

Đếm số tplt: DFS: bao nhiêu lần stack rỗng .....

Đồ thị có chu trình: tồn tại đường đi từ đỉnh u đi qua các đỉnh khác về đến chính nó (đỉnh u): DFS và có parent
    Nếu kiểm tra đỉnh đã được duyệt và là cha của đỉnh đang xét => có chu trình
Tìm đường đi ngắn: 
    DIJSKTRA: dùng priorityQueue: có trọng số: O(N*M): N đỉnh, M cạnh. Không giải được bài toán có chu trình âm: vì lặp vô hạn
        hay ĐPT là: O(V*E)
    BellmanFord:
    FLoy: tìm đường đi ngắn nhất đến mọi cặp đỉnh. QHĐ: O(N^3)
        sét trạng thái đầu tiên: không qua trung gian
        SÉt khi đi qua đỉnh khác thì khoảng cách có nhỏ hơn không

Cây khung nhỏ nhất:
    PRIM: Chọn 1 đỉnh đầu tiên. Tìm các đỉnh có kc min đến đỉnh hiện tại. Tham lam
    KRUSAL: sắp xếp các cạnh nhỏ nhất. 

Kiểm tra chu trình: 

Phan2: Giai thuat
Độ phức tạp trong thuật toán sắp xếp: là số lượng phép so sánh
SORT:
O(NlogN)
    QUICK SORT: trung bình O(NlogN) và tồi nhất là O(N^2). Không tốn không gian bộ nhớ.
    MERGE SORT:Ngoài các phép so sánh: còn dùng bộ nhớ trung gian để gán các thứ (là các phép toán không cố định),...=> tốn bộ nhớ
    HEAP SORT

O(N^2)
    sắp xếp nổi bọt: tốt là O(N). Sau 1 lượt mà không có bọt nào nổi lên chứng tỏ nó đã sắp xếp rồi.

O(N)
    COUNTING SORT: không xếp được số thập phân
    RADIX: 

TIM KIEM:
tuan tu: O(N)
nhi phan: O(LogN)

Độ phức tạp:
Viết O: để đại diện cho hàm phức tạp: theo hàm nào. Sau đây là một số hàm
    Hằng số, loga, tuyến tính, đa thức (bậc 2, 3, 4,...), mũ, giai thừa. Có O chỉ cần viết đại diện hàm.

Chiến lược thiết kế thuật toán:
    Tùy thuộc chia: Dùng đệ quy
        Chia để trị: mergesort, tìm kiếm nhị phân. Chia nhỏ vấn để ra để dễ giải quyết hơn. (VD: merge sort)
        Quay lui: Duyệt hoán vị, sinh chuỗi. bai toan có tư tưởng quy nạp. các bài toán sau thì phải phụ thuộc vào các bài toán con trước

    Tham lam: theo costfunction: chiến lược tham lam. độ phức tạp thấp nhưng chưa chắc được tìm phương án tối ưu.
        VD: bài toán cái túi thì costfunction = giá trị/khối lượng
    Vét cạn: Duyet tat ca Th và tìm được phương án tối ưu. Độ phức tạp lớn.
    QHĐ: Độ phức tạp > tham lam va < vét cạn. tìm được phương án tối ưu. tìm đc solution khó hơn
    
Cài đặt MAP: key-value
    hashing: kích thước hash ntn: lớn -> thừa bộ nhớ, ít thì thiếu
    bth hash nhỏ khi quá số lượng hash ban đầu thì phải tăng dần kích thước hash để tính lại
    thông thường thì nhân 2

Vector nó là mảng. Khi vector đầy thì nó nhân đôi kích thước mảng để tạo thành vector mới.

STRING: nghịch đảo balan

Sắp xếp topo??

-KMP

lay diem: bai 5,8,9

CẤU TRÚC DỮ LIỆU:
1. Mảng
- Mảng: là tập hợp các phần tử cùng kiểu được lưu trữ liên tục trong bộ nhớ.
- 
*/
void DFS(int u, ll t, ll &res) {
    visited[u] = true;
    res = max(res,t);
    sort (adj[u].begin(), adj[u].end());
    for (auto v : adj[u]) {
        if (!visited[v.second]) {
            DFS(v.second, t+v.first, res);
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({t, v});
    }    

    ll res = 0;
    DFS(k,0, res);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ll tmp = 0;
            DFS(i,0, tmp);
            res += tmp;
        }
    }
    cout << res;
    return 0;
}

/*
void DFS(int u, int &res) {
    int t = 0;
    res = max(res, t);
    visited[u] = 1;
    sort(adj[u].begin(), adj[u].end());
    for (auto v : adj[u]) {
        if (!visited[v.first]) {
            t += v.second;
            DFS(v.first,res);
        }
    }
}*/
