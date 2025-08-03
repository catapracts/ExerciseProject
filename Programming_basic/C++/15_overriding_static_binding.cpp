/*
상속이 필요한 이유 2.

Overriding : 우선하다 / 
Overloading : 이름 같은거 여러개 생성 - 함수
Overwrite : 덮어쓰다

=========================

Static Binding : 다른 언어에서는 잘 안 발생하는데 C++에서는 발생함

Binding : 어떤 걸 참조해야 하나 결정
정적바인딩 : 현재 가리키는 객체가 뭘 참조하는지 모르니까 보이는거 그대로 쓰자 -> C++에서는 아무짓 안 하면 이 현상 일어남
동적바인딩 : 현재 참조하는 애가 어떨 때는 객체1이고, 어떤 때는 객체2가 될 수 있음

*/

#include <iostream>

using namespace std;

class Base {
public:
    // Base() : a(10) {}
    int a = 10; // 생성자 만들면서 변수 초기화
    void Print() {
        cout << "From Base" <<endl;
    }

};

class Derived : public Base {
public:
    int a = 20;
    void Print() {
        cout << "From Derived" <<endl;
    }
};

class Derived2 : public Base {

};

Derived d;
Base *b = &d; // 타입이 달라도 부모 클래스의 포인터가 자식 클래스를 가리키는게 가능(C++한정)

int main() {
    Base b;
    Derived d;

    cout << b.a << endl;
    cout << d.a << endl; // 상속받은 a가 아니라 자신의 a를 얻음 / cout << d.Derived::a << endl;와 동일 / 이름 같으면 자기걸 먼저 우선시함
    cout << d.Base::a << endl; // 상속받은 a 호출

    d.Print(); // 상속받은 Print()가 아니라 자신의 Print()를 얻음 / 이름 같으면 자기걸 먼저 우선시함
    d.Base::Print();
    d.Derived::Print();

    Base *b1 = new Derived(); // Derived타입의 객체를 동적할당 후 포인터를 b1에 저장 = 메모리 공간에 객체 할당 후 그 주소값 저장
    b1->Print(); // (*b).Print();와 동일 / Base의 함수 실행됨 -> why? 
    delete b1;
    b1 = new Derived2();
    b1->Print(); // 이것만 봐서는 Derived2를 가리키는지 Derived를 가리키는지 Base를 가리키는지 모름 -> 그래서 현재 타입을 보고 그 타입에 해당하는 동작을 하자! = 정적바인딩


}