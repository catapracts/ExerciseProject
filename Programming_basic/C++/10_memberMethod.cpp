/*
Member Method(내부 method) 활용
연산자 오버로딩 - 벡터, member method
member method - 선언, 정의 분리 : 90% / 
클래스 이름은 네임스페이스와 거의 동일

Overloading

const로 선언할 수 있는 method는 모두 const로 선언

C에서 제공되는 기본 자료형들은 기본적으로 overloading이 불가능

객체에서만 operator 사용 가능

형변환도 연산자임

*/

#include <iostream>

using namespace std;

class Vector2 {
public:
    Vector2();
    Vector2(float x, float y);

    float GetX() const;
    float GetY() const;

    // rhs(right hand side) = 우변
    // dynamic
    // Vector2 Add(Vector2 rhs) {
    //     return Vector2(x + rhs.x, y + rhs.y);
    // }

    // operator : 예약자
    // operator+ : +라는 이름의 예약자 생성 / method이름 말고 간단하게 사용하고 싶을 때 사용 - 연산자 overload
    Vector2 operator+(Vector2 rhs) const;
    Vector2 operator-(Vector2 rhs) const;
    Vector2 operator*(float rhs) const;
    Vector2 operator/(float rhs) const;
    float operator*(Vector2 rhs) const;


private:
    float x;
    float y;
};

Vector2 Sum(Vector2 a, Vector2 b) {
    return Vector2( a.GetX() + b.GetX(), a.GetY() + b.GetY() );
}

Vector2 operator*(const float a, const Vector2 b) { // const 못 붙임, 전역함수니까
    return Vector2( a + b.GetX(), a + b.GetY() );
}


int main() {
    Vector2 a(2, 3);
    Vector2 b(-1, 4);
    Vector2 c = Sum(a, b); // 피연산자형식 : Vector2 + Vector2
    Vector2 c1 = a.operator+(b);
    Vector2 c2 = a + b;
    Vector2 c3 = a - b;
    Vector2 c4 = a * 1.4; // 피연산자형식 : double * vector
    Vector2 c5 = a / 4;
    float c6 = a * b;
    Vector2 c7 = 1.4 * a;
    cout << a.GetX() << ", " << a.GetY() << endl;
    cout << b.GetX() << ", " << b.GetY() << endl;
    cout << c.GetX() << ", " << c.GetY() << endl;
    cout << c1.GetX() << ", " << c1.GetY() << endl;
    cout << c2.GetX() << ", " << c2.GetY() << endl;
    cout << c3.GetX() << ", " << c3.GetY() << endl;
    cout << c4.GetX() << ", " << c4.GetY() << endl;
    cout << c5.GetX() << ", " << c5.GetY() << endl;
    cout << c6 << endl;
    cout << c7.GetX() << ", " << c7.GetY() << endl;
}


Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}
float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }
Vector2 Vector2::operator+(const Vector2 rhs) const {
    return Vector2(x + rhs.x, y + rhs.y);
}
Vector2 Vector2::operator-(const Vector2 rhs) const {
    return Vector2(x - rhs.x, y - rhs.y);
}
Vector2 Vector2::operator*(const float rhs) const {
    return Vector2(x * rhs, y * rhs);
}
Vector2 Vector2::operator/(const float rhs) const {
    return Vector2(x / rhs, y + rhs);
}
float Vector2::operator*(Vector2 rhs) const {
    return x * rhs.x + y * rhs.y;
}