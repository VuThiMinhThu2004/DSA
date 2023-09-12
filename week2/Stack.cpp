#include "iostream"
#include "stack"
using namespace std;

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    while (!st.empty()) {
        int x = st.top();
        cout << x << " ";
        st.pop();
    }
}