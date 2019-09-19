#include<iostream>

using namespace std;

class A {
public:
    A() {}
    ~A() {}
    // operator void * () const {
    //     cout << "call void * () const" << endl;
    //     return (void*)this;
    // }
    // bool operator!()const {
    //     return true;
    // }
    operator bool()const{
         cout << "call bool () const" << endl;
        return true;
    }
};

int main() {
    A a;
    if (a) cout << "operator void * () const" << endl;
    if (!a) cout << "bool operator!()const" << endl;
    return 0;
}