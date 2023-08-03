#include <iostream>

using namespace std;

template<typename T>
class DynamicArray {
private:
    int m_length;
    int m_capacity;
    T* m_data;
public:
    //1. constructor and destructor
    DynamicArray() : m_length(0), m_capacity(1), m_data(new T[m_capacity]) {}
    DynamicArray(const T &value, const int length):m_length(length),m_capacity(length>0?length:1),m_data(new T[m_capacity]) {
        for (int i=0;i<length;i++)
            m_data[i]=value;
    }
    ~DynamicArray() noexcept {
        if(m_data!=nullptr) {
            delete[] m_data;
            m_data=nullptr;
        }
    }

    //2. Copy Constructor
    DynamicArray(const DynamicArray &other):m_length(other.m_length),m_capacity(other.m_capacity),m_data(other.m_length>0? new T[other.m_length]:nullptr) {
        for (int i=0;i!=m_length;++i) 
            m_data[i]=other.m_data[i];
    }

    //3. Copy Assigmnent Operator
    DynamicArray &operator=(const DynamicArray &other) {
        if (this != &other) {
            if (m_length != other.m_length) {
                delete[] m_data;
                m_length=other.m_length;
                m_capacity=other.m_capacity;
                if (other.m_length>0)
                    m_data=new T[other.m_length];
                else
                    m_data=nullptr;
            }
            for (int i=0;i!=m_length;++i) 
                m_data[i]=other.m_data[i];
        }
        return *this;
    }

    //4. Move constructor
    DynamicArray(DynamicArray &&other) noexcept : m_length(move(other.m_length)), m_capacity(move(other.m_capacity)), m_data(move(other.m_data)) {
        other.m_length=0;
        other.m_capacity=0;
        other.m_data=nullptr;
    }

    //5. Move assignment operator
    DynamicArray &operator=(DynamicArray &&other) noexcept {
        if (this != &other) {
            delete[] m_data;
            m_length=move(other.m_length);
            m_capacity=move(other.m_capacity);
            m_data=move(other.m_data);

            other.m_length=0;
            other.m_capacity=0;
            other.m_data=nullptr;
        }
        return *this;
    }
};

int main() {

    DynamicArray<int> a1(1.0, 3);
    DynamicArray<int> a2(-1.0, 4);

    DynamicArray<int> a3 = a2;   // Copy constructor
    DynamicArray<int> a4(a2);    // Copy constructor
    DynamicArray<int> a5{a2};    // Copy constructor
    DynamicArray<int> a6 = {a2}; // Copy constructor

    a1 = a2; // Copy assignment operator

    return 0;
}