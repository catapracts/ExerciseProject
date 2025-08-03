/*
상속 / 

★★★★★★★★접근제어★★★★★★★
private : 외부 접근 금지 / 자식클래스 상속 but 접근 불가능
protected : 외부 접근 금지 / 자식클래스 상속, 접근 가능
public : 외부 접근 허용 / 자식클래스 상속, 접근 가능

*/

#include <iostream>

using namespace std;

class Base {
public:
    void bFunc() {
        cout << "Hello" << endl;
    }
    int bNum;
    int bPublic;
protected:
    int bProtected;
private:
    int bPrivate;
};

class Derived : public Base { // 여기서 쓴 public = 상속받을 때, 기준 설정 / 얘를 기준으로 어디까지 접근 가능하게 해줄것인가?
public:
    void dFunc() {
        cout << "Hello?" << endl;
        bPublic = 1;
        bProtected = 2;
        dPublic = 3;
        dPrivate = 4;
        //bPrivate = 5;
    }
    int dNum;
    int dPublic;
private:
    int dPrivate;
};

int main(){
    Base b;
    Derived d;
    b.bFunc();
    b.bNum = 1;
    //b.dFunc();
    d.bFunc();
    d.bNum = 2;
    d.dFunc();
    d.dNum = 3;

    b.bPublic; // b.bProtected; b.bPrivate;
    d.bPublic; d.bNum; d.bFunc(); d.dNum; d.dPublic;

}