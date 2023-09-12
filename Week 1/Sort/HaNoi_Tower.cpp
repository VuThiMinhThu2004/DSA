#include "bits/stdc++.h"
using namespace std;
//bai toan giai quyet n dia voi 3 coc A,B,C
/*
Cách giải
Đầu tiên ta lấy cột C làm cọc trung gian. Chuyển n-1 chiếc đĩa sang cột B.
Ta chuyển chiếc đĩa lớn nhất sang cột C
Lấy cột A làm cột trung gian chuyển n-1 chiếc đĩa từ cột B sang cột C
*/
void tower_of_HN(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    tower_of_HN(n-1,source,target,auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    tower_of_HN(n-1,auxiliary,source,target);

}

void TowerOfHaNoi(int n, char a, char b, char c) {
    if (n == 1) {
        cout << "Move disk 1 from " << a << " to " << c << endl;
        return;
    }
    TowerOfHaNoi(n-1, a, c, b);// lay c lam trung gian de chuyen n-1 disk tu a->b
    cout << "Move disk " << n << " from " << a << " to " << c << endl;
    TowerOfHaNoi(n-1, b, a, c);//lay a lam trung gian chuyen n-1 disk tu b->c

} 
int main() {
    int numDisks = 4; // Số lượng đĩa
    char sourcePeg = 'A'; // Cọc nguồn
    char auxiliaryPeg = 'B'; // Cọc trung gian
    char targetPeg = 'C'; // Cọc đích

    std::cout << "Tower of Hanoi solution for " << numDisks << " disks:" << std::endl;
    //tower_of_HN(numDisks, sourcePeg, auxiliaryPeg, targetPeg);
    TowerOfHaNoi(numDisks, sourcePeg, auxiliaryPeg, targetPeg);
    return 0;
}   