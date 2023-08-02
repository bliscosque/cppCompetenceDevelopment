#include <ranges>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    auto v=vector<int>{1,2,3,4,5,6};
    auto r1= v | 
        views::transform([](const auto n) { return n * 3; }) | //multiply by 3
        views::filter([](const auto n) { return n % 2 == 0; }); //only even

    for (auto v: r1)
        cout << v << " ";
    cout << endl;

    auto r2= views::reverse(v) | 
        views::take(3) | //only first 3 numbers
        views::drop(1); // delete 1 elem

    for (auto v: r2)
        cout << v << " ";
    cout << endl;
        
    return 0;
}