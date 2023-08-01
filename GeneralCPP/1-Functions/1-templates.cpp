#include <iostream>
using namespace std;

template <typename T>
T max_val(T a, T b) {
    return a>b?a:b;
}

int main() {
    cout<<max_val(1,10) << endl;
    cout<<max_val<double>(2,5) << endl;
    return 0;
}