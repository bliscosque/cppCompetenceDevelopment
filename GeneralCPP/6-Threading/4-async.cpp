#include <future>
#include <iostream>

using namespace std;

int f(int i) {
    cout << "inside f with i: " << i << endl;
    return i*2;
}

int main() {
    int i=1;
    auto handle=async(launch::async,f,i);

    auto result=handle.get();
    cout << result << endl;

    return 0;
}