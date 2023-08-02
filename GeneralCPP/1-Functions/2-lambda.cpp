#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool checkless5(int n) {
    return n<5;
}

int main() {

    auto v1=vector<int>{1,2,3,4,5};
    auto checkAll=all_of(v1.begin(),v1.end(), [](int val){return val<5;} );
    auto checkAny=any_of(v1.begin(),v1.end(), [](int val){return val<5;} );
    auto checkNone=none_of(v1.begin(),v1.end(), [](int val){return val<5;} );

    cout << checkAll << " " << checkAny << " " << checkNone << endl;

    int upper_bound=3;
    //[=] -> copia o valor
    //[&] -> faz referencia
    v1.erase(remove_if(v1.begin(),v1.end(),[=](int val){return val>upper_bound;}),v1.end());
    for (auto el: v1)
        cout << el << " ";
    cout << endl;

    auto v2=vector<int>{10,5,2,1,5};
    auto sorting = [](const auto l, const auto r) { return l < r; };
    sort(v2.begin(), v2.end(), sorting);

    for (auto el: v2)
        cout << el << " ";
    cout << endl;

    return 0;
}