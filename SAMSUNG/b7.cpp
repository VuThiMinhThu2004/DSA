/*
Tạo một hàng đợi các cặp.
Chèn một chỉ mục ban đầu được đưa ra trong hàng đợi.
Đánh dấu chỉ mục ban đầu là đã truy cập trong ma trận vis[][].
Cho đến khi hàng đợi không trống, lặp lại bước 4.1 đến 4.6
Lấy phần tử phía trước từ hàng đợi
Bật ra khỏi hàng đợi
Lưu trữ giá trị/màu hiện tại tại tọa độ được lấy ra từ hàng đợi (precolor)
Cập nhật giá trị/màu sắc của chỉ mục hiện tại được lấy ra khỏi hàng đợi
Kiểm tra cả 4 hướng tức là (x+1,y),(x-1,y),(x,y+1),(x,y-1) có hợp lệ hay không và nếu hợp lệ thì kiểm tra giá trị đó tại đó tọa độ phải bằng precolor và giá trị của tọa độ đó trong vis[][] là 0.
Nếu tất cả điều kiện trên là đúng, hãy đẩy tọa độ tương ứng trong hàng đợi và đánh dấu là 1 trong vis[][]
In ma trận.
*/
#include <iostream>
#include <vector>

using namespace std;

void floodFillDFS(vector<vector<int>>& matrix, int x, int y, int targetColor, int replacementColor) {
    int n = matrix.size();

    if (x < 0 || x >= n || y < 0 || y >= n) {
        return;
    }

    if (matrix[y][x] != targetColor) {
        return;
    }

    matrix[y][x] = replacementColor;

    floodFillDFS(matrix, x + 1, y, targetColor, replacementColor);
    floodFillDFS(matrix, x - 1, y, targetColor, replacementColor);
    floodFillDFS(matrix, x, y + 1, targetColor, replacementColor);
    floodFillDFS(matrix, x, y - 1, targetColor, replacementColor);
}

int main() {
    int n = 5; // Kích thước ma trận vuông n x n
    vector<vector<int>> matrix = {
        {1, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 1}
    };

    // Hiển thị ma trận trước khi thực hiện flood fill
    cout << "Ma tran truoc khi thuc hien flood fill:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int x = 2, y = 2; // Thay đổi x, y tùy thuộc vào điểm bạn muốn bắt đầu flood fill
    int targetColor = matrix[y][x]; // Màu của điểm (x, y)
    int replacementColor = 2; // Thay đổi màu tại đây

    floodFillDFS(matrix, x, y, targetColor, replacementColor);

    // Hiển thị ma trận sau khi thực hiện flood fill
    cout << "Ma tran sau khi thuc hien flood fill:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

