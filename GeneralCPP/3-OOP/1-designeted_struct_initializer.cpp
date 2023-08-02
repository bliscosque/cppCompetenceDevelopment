//only in CPP20
#include <iostream>
using namespace std;

struct Car {
    int id;
    float speed;
    string description;
};

int main() {
    auto c1=Car{.id=1,.speed=90.0F,.description="First car"}; //can insert attribute names direct
    cout << c1.id << " " << c1.speed << " " << c1.description << endl;
    return 0;
}