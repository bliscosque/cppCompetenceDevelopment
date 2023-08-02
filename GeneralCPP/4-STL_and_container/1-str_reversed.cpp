#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1="This is a string";
    string rev=string(str1.rbegin(),str1.rend());
    cout << rev << endl;
    return 0;
}