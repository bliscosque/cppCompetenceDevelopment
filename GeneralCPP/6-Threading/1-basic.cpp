#include <iostream>
#include <thread>

using namespace std;

void f1() {
    auto thread_id=this_thread::get_id();
    cout << "Thread ID: " << thread_id << endl;
}

int main() {
    auto main_id=this_thread::get_id();
    cout << "Main thread ID: " << main_id << endl;

    auto t1=thread(f1);

    if (t1.joinable())
        t1.join(); //needs to join the threads b4 finishing app execution

    return 0;
}