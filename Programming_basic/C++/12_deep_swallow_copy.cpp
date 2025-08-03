/*
포인터가 있는 객체가 복사될 경우
얕은 복사가 일어날 수 있음 : B.a = A.a; 이런식으로

*/


#include <iostream>
#include <string.h>
using namespace std;

class String {
public:
    String() { //생성자
        strData = NULL; // 현재 포인터가 아무것도 가리키지 않음
        len = 0;
    }
    String(const char *str) { // 포인터str이 const char를 가리키다. / 매개변수 있는 생성자
        //strData = str; // 얕은복사, 대입 자체가 안 됨
        len = strlen(str);
        strData = new char[len + 1]; // 맨끝에 NULL문자(\0) 있으니까 len+1
        strcpy(strData, str); // 깊은 복사
    }
    ~String() { //소멸자
        delete[] strData;
    }
    
    char *GetStrData() const {
        return strData;
    }

    int GetLen() const {
        return len;
    }

private:
    char *strData;
    int len;

};



int main(){
    int *a = new int(3);
    int *b = new int(5);

    a = b; // a가 가리키는 주소값이 b가 가리키는 주소값이 됨 = a도 int 5를 가리킴 => 얕은복사 = 참조만 복사, call by reference와 비슷
    // int 3 가리키는 주소가 사라짐 / 같은 주소 가리키면 하나 delete되면 다른 하나는 delete쓰면 runtime error 뜬다. or 프로그램 정지됨
    *a = *b; // 깊은 복사 = 값을 복사, call by value와 비슷

    delete a;
    delete b;






}