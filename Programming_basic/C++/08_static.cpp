/*
static : 정적 / 붕어빵 틀
dynamic : 동적 / 붕어빵

static member method

static member variable
- 아무리 많이 찍어내도 하나만 존재

객체지향 프로그래밍에서는 전역변수, 전역함수 지양함 = 안 만들수록 좋다

*/

#include <iostream>

using namespace std;


// int idCounter = 1; // 다음에 만들어질 객체에 대한 번호 부여




// 색깔 저장 : RGB, 0~1
class Color {
public:
    Color() : r(0), g(0), b(0), id(idCounter++) {}
    Color(float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) {}

    float getR() {return r;}
    float getG() {return r;}
    float getB() {return r;}
    int getId() {return id;}

    // 2가지 색 섞고 반환
    // 얘를 안에 넣은 이유는 private field 접근 가능하게 하려고 사용
    // 전역으로 쓸 수 있으면서 private field에 접근하고 싶다? = static member method
    static Color MixColors(Color a, Color b) {
        return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
    }

    // class안에서는 값 넣을 수 없음
    // 큰 장점 : 전역변수 갯수 줄이기
    static int idCounter;

private:
    float r;
    float g;
    float b;

    // 객체가 만들어질때마다 자동으로 번호 부여
    int id;
};

// class가 namespace처럼 비슷한 역할
// static member variable도 선언과 초기화를 분리
int Color::idCounter = 1;


int main() {
    Color blue(0, 0, 1);
    Color red(1, 0, 0);
    Color purple = Color::MixColors(blue, red);
    cout << "r = " << purple.getB() << ", " << "g = " << purple.getG() << ", " << "b = " << purple.getB() << endl;
    
    cout << "blue.getId() = " << blue.getId() << endl;
    cout << "red.getId() = " << red.getId() << endl;
    cout << "purple.getId() = " << purple.getId() << endl;


}