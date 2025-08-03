/*
생성자 : 객체가 생성될 때 자동으로 호출되는 함수
소멸자 : 객체가 소멸될 때 자동으로 호출되는 함수

생성자 소멸자 안 적으면?
default로 둘 다 있음 - 아무 내용 없음

언제 사용?
생성자 : 객체의 맴버 변수 초기화
소멸자 : 메모리 해제

*/

#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass() { // 생성자
        cout << "생성자 호출됨" << endl;
    }
    ~MyClass() { // 소멸자
        cout << "소멸자 호출됨" << endl;
    }
};

MyClass globalObj; // main시작 전 생성되고, main 끝나고 소멸됨

void testLocalObject(){ // 지역 obj는 컴퓨터가 이 구문 만나는 순간 생성, 이 함수 끝나면 지역 obj도 같이 소멸
    cout << "Local Obj start" << endl;
    MyClass localObj;
    cout << "Local Obj end" << endl;
}


// 복소수 저장 class만들기
class Complex {
public :
    Complex() : real(0), img(0) {
        //real = 0;
        //img = 0; // 단순히 변수에 값 대입을 위해 ()는 사용 불가능
    }

    Complex(double real_, double img_) { // overload, 만약 매개변수가 default면 위랑 이거랑 어떤 거 선택해야할지 모름 그래서 이런경우는 위를 지워버림
        real = real_;
        img = img_;
    }

    // Complex(double real_, double img_) : real(real_), img(img_) {} // 초기화 목록, 위랑 똑같은 역할
    // Complex(double real, double img) : real(real), img(img) {} // 이렇게도 가능

    double GetReal() {
        return real;
    }

    double SetReal(double real_) {
        real = real_;
    }

    double GetImg() {
        return img;
    }

    double SetImg(double img_) {
        img = img_;
    }


private:
    double real;
    double img;
};


// 시간 저장 클래스
class Time {
public:
    // 초 저장 : Time(5);
    // 분 저장 : Time(5, 0);
    // 시 저장 : Time(2, 27, 25);
    Time() : h(0), m(0), s(0) {}

    Time(int s_) : Time() {
        s = s_;
    }

    Time(int m_, int s_) : Time(s_) {
        m = m_;
    }

    // 변수 초기화 = : m(m_), s(s_)
    // 생성자 위임 = : Time(m_, s_)
    // 생성자 따라서 끝까지 올라가서 Time()까지 올라감
    /*
        Time(h, m, s) 여기에 값 들어왔다고 가정
        1. Time(m, s)로 이동
        2. Time(s)로 이동
        3. Time()으로 이동
        4. Time()에서 정의한대로 0, 0, 0 넣음
        5. Time(s)로 가서 s값 넣기
        6. Time(m, s)로 가서 m값 넣기
        7. Time(h, m, s)로 가서 h값 넣기
        8. 종료
    */
    Time(int h_, int m_, int s_) : Time(m_, s_) { // 생성자 위임 -> 값 들어오면 위임된거 먼저 보고 그 다음 내용 본다.
        h = h_;
    }

//private: -> 원래대로라면 이거 살리고 GET/SET함수 만들어야 함 지금은 편의를 위해 일부러 다 public으로 둔것
    int h, m, s;
};






int main () {
    cout << "main start" << endl;
    testLocalObject();
    cout << "main end" << endl;

    Complex c1; // 이렇게 생성하면 default 생성자로 시작
    Complex c2 = Complex(2, 3);
    Complex c3(3, 4);
    Complex c4 = {2, 3};
    Complex c5 = Complex{2, 3};
    Complex c6{2,3};
    // default매개변수 사용시 가능한 형태 : Complex c7 = Complex(2);

    cout << "c1 = "<< c1.GetReal() << ", " << c1.GetImg() << endl; // 0, 0
    cout << "c2 = "<< c2.GetReal() << ", " << c2.GetImg() << endl; // 2, 3
    cout << "c3 = "<< c3.GetReal() << ", " << c3.GetImg() << endl; // 3, 4

    Time t1;
    Time t2(5);
    Time t3(4, 14);
    Time t4(2, 44, 16);
    cout << "t1 : " << t1.h << ":" << t1.m << ":" << t1.s << endl;
    cout << "t2 : " << t2.h << ":" << t2.m << ":" << t2.s << endl;
    cout << "t3 : " << t3.h << ":" << t3.m << ":" << t3.s << endl;
    cout << "t4 : " << t4.h << ":" << t4.m << ":" << t4.s << endl;

}