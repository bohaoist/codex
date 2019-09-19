#include<iostream>
using namespace std;

template<typename T>
class Complex{
public:
    Complex(T a, T b){
        this->a = a;
        this->b = b;
    }

    friend ostream & operator <<(ostream & out, const Complex<T> &c){
        out << c.a << c.b << endl;
        return out;
    }

    Complex operator+(const Complex<T> &c){
        Complex tmp(this->a+c.a, this->b+c.b);
        return tmp;
    }   

private:
    T a;
    T b;
};

int main(){
    Complex<int> one(1,1);
    Complex<int> two(2,2);
    Complex<int> sum(0,0);
    sum = one + two;
    cout << sum << endl;
    return 0;
}