/*
    묵시적(암시적) 형변환(implicit conversion)
    명시적 형변환(explicit conversion)
*/
#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    Item(int num) : num(num) { // 역할에 따라 변환 생성자, 일반 생성자 이런식으로 될 수 있다.
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

private:
    int num;
    string name;
};


int main() {
    Item i1 = Item(1);
    Item i2(2);
    Item i3 = 3;
    i3 = 3; // 왜 이동대입연산자가 나오고, 어떻게 변환한건가? -> 변환 생성자로 임시객체 생성, 그리고 임시객체를 통해 값이 들어감 => implicit conversion
    Item i4 = (Item)4; // explicit conversion

    Item i5(5);
    //i5 = string("stone");
    i5 = (string)"stone";

    // 2011년에 추가된 새로운 문법 / 2개 이상 implicit conversion
    Item i6(1, "grass");
    Item i7 = {2, "dirt"};
    i7 = {2, "dirt"};
    Item i8{3, "wood"};

    i1.print();
    i2.print();
    i3.print();
    i4.print();
    i5.print();
    i6.print();
    i7.print();
    i8.print();
}