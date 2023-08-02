#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    auto v1=vector<int>{1,2,3};
    auto v2=vector<int>{1,2,3};
    auto v3=vector<int>{6,2,3};

    cout << equal(v1.begin(), v1.end(), v2.begin()) << endl;
    cout << equal(v1.begin(), v1.end(), v3.begin()) << endl;
    return 0;
}