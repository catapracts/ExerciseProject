/*
    묵시적(암시적) 형변환(implicit conversion)
    명시적 형변환(explicit conversion)

    형변환이 불편해지는 경우 -> 오버로드가 여러 개 있을 경우 어떤 게 뭔지 알 수 없다.

    의도치 않게 형변환이 일어나는 경우 존재 -> 묵시적 변환을 막아놓는 방법이 있음
    생성자, 메소드 등에 앞에 explicit 추가하면, implicit conversion 발생 안함
    흔하진 않은데, 필요한 경우가 있긴함
*/
#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    Item(int num) : num(num) {
        cout << "Item(int)" << endl;
    }
    Item(string name) : name(name) {
        cout << "Item(name)" << endl;
    }
    Item(int num, string name) : num(num), name(name) {
        cout << "Item(int, string)" << endl;
    }
    void print() {
        cout << num << " : " << name <<endl;
    }
    // int로 변환하는 연산자의 오버로딩, 연산자별로 오버로딩 방식 다름
    operator int() const {
        return num;
    }
    // string형변환 연산자
    operator string() const {
        string str = to_string(num) + " : " + name; // to_string = 숫자를 string으로 변경
        return str;
    }

private:
    int num;
    string name;
};

// 형변환이 불편해지는 경우 -> 오버로드가 여러 개 있을 경우 어떤 게 뭔지 알 수 없다.
void println(string s) {
    cout << s << endl;
}

void println(int n) {
    cout << n << endl;
}

void aaa(double a) {

}

int main() {
    aaa(3); // implicit conversion
    Item i1 = Item(1);
    Item i2(2);
    Item i3 = 3;
    i3 = 3;
    Item i4 = (Item)4;

    Item i5(5);
    i5 = (string)"stone";

 
    Item i6(1, "grass");
    Item i7 = {2, "dirt"};
    i7 = {2, "dirt"};
    Item i8{3, "wood"};

    // 형변환 = 연산자 = 오버로딩 가능
    int itemNum = (int)i7;
    cout << itemNum << endl;
    int itemNum1 = i8;
    cout << itemNum1 << endl;

    println((string)i8);
    //println(i8); // implicit conversion
    println((int)i8);

}