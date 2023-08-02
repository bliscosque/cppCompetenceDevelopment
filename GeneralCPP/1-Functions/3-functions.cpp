#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void f2(function<double(double)> f) {
    cout << f(5) << endl;
}

int main() {
    auto f1=[](double d){return d+10;};
    f2(f1);

    return 0;
}