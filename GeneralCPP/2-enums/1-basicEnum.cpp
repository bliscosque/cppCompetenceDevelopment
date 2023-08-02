#include <iostream>
using namespace std;

enum PersonType {
    STUDENT=1,
    INSTRUCTOR=2,
    ADMIN=3,
};

int main() {
    PersonType pt1=PersonType::STUDENT;
    PersonType pt2=INSTRUCTOR; //problem with this type of enum is that values are not namespaced

    cout << pt1 << " " << pt2;

    return 0; 
}