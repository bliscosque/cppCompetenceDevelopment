#include <array>
#include <iostream>
#include <mutex>
#include <thread>
#include <numeric>

using namespace std;

const int NUM_THREADS=3;
const int NUM_INCREMENTS=100000; 
int GLOBAL_COUNTER=0;

auto MUTEX_COUNTER=mutex{};

void f(int input, int &output)
{
    output = input * 2;

    for (int i = 0; i < NUM_INCREMENTS; ++i)
    {
        auto guard = lock_guard<std::mutex>(MUTEX_COUNTER); //commenting this line is possible to check that GLOBAL_COUNTER does not ends with expected value due to race condition
        ++GLOBAL_COUNTER;
    }
}

int main() {
    array<thread, NUM_THREADS> threads;

    auto inputs = array<int, NUM_THREADS>{};
    auto outputs = array<int, NUM_THREADS>{};
    iota(inputs.begin(), inputs.end(), 0);

    for (int i = 0; i < NUM_THREADS; ++i)
        threads[i] = thread(f, inputs[i], ref(outputs[i])); //return in outputs

    for (int i = 0; i < NUM_THREADS; ++i)
        threads[i].join();

    cout << "GLOBAL_COUNTER: " << GLOBAL_COUNTER << endl;

    return 0;
}