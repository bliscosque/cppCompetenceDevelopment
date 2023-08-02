#include <iostream>
using namespace std;

enum class PersonType {
    STUDENT=1,
    INSTRUCTOR=2,
    ADMIN=3,
};

int main() {
    PersonType pt1=PersonType::STUDENT;
    // PersonType pt2=INSTRUCTOR; //not work...
    PersonType pt2=PersonType::ADMIN; //has to be accessed using ns

    return 0; 
}