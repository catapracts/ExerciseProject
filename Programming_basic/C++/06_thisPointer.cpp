/*
this : 객체 자신을 가리키는 포인터
함수도 메모리를 가지고 있음
객체 바깥에 함수가 있음

this -> 보이지 않는 매개변수 / 모든 함수는 이걸 가지고 있음 / 얘를 사용해서 어디 객체 소속인지 알 수 있다.

*/


#include <iostream>

using namespace std;

class MyClass {
public:
    void PrintThis() {
        cout << "My address : " << this <<endl;
    }
};

int main() {
    MyClass a, b;

    cout << "a address : " << &a << endl; // a 주소값
    cout << "b address : " << &b << endl; // b 주소값

    a.PrintThis(); // a 주소값
    b.PrintThis(); // b 주소값


}