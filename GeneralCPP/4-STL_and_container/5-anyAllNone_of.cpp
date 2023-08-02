#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool checkless5(int n) {
    return n<5;
}

int main() {

    auto v1=vector<int>{1,2,3,4,5};
    auto checkAll=all_of(v1.begin(),v1.end(),checkless5);
    auto checkAny=any_of(v1.begin(),v1.end(),checkless5);
    auto checkNone=none_of(v1.begin(),v1.end(),checkless5);

    cout << checkAll << " " << checkAny << " " << checkNone << endl;

    return 0;
}