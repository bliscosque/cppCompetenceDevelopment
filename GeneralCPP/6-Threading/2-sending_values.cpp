#include <iostream>
#include <thread>

using namespace std;

void f1() {
    auto thread_id=this_thread::get_id();
    cout << "F1 Thread ID: " << thread_id << endl;
}

void f2(int n) {
    auto thread_id=this_thread::get_id();
    cout << "F2 Thread ID: " << thread_id << endl;
    cout << "Number: " << n << endl;
}

void f3(int &n) {
    auto thread_id=this_thread::get_id();
    cout << "F3 Thread ID: " << thread_id << endl;
    cout << "Number: " << n << endl; 
}

int main() {
    auto main_id=this_thread::get_id();
    cout << "Main thread ID: " << main_id << endl;
    
    int n=42; 
    
    auto t1=thread(f1);
    auto t2=thread(f2,n);
    auto t3=thread(f2,ref(n));

    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();
    if (t3.joinable())
        t3.join();

    return 0;
}