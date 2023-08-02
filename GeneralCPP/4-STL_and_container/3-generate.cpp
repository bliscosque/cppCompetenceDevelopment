#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int gen() {
    static int i;
    return ++i;
}

int main() {
    vector<int> v(5);
    generate(v.begin(),v.end(),gen);
    for (auto e:v) 
        cout << e << endl;
    return 0;
}