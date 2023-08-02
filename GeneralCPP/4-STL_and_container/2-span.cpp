// available in c++20 
#include <iostream>
#include <vector>
#include <array>
#include <span>

using namespace std;

template <typename T>
void print_container(span<T> sp) {
    for (auto v: sp) 
        cout << v << endl;
}

int main() {
    auto v1=vector<int>{1,2,3,4,5};
    auto v2=array<int,5>{5,4,3,2,1};

    print_container<int>(v1);
    print_container<int>(v2);
    
    return 0;
}