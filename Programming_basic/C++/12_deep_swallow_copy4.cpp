// 이동시맨틱 = 이동생성자 & 이동대입연산자자

#include <iostream>
#include <string.h>
using namespace std;

class String {
public:
    String() {
        cout << "String() : " << endl;
        strData = NULL;
        len = 0;
    }
    String(const char *str) {
        cout << "String(const char*) : " << endl;
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);
    }
    //복사 생성자
    String(const String &rhs) { // const쓰면 r-value(수정 불가능한 값)도 담을 수 있다
        cout << "String(const String &rhs) :" << endl;
        len = rhs.len;
        alloc(len);
        strcpy(strData, rhs.strData);
    }
    // r-value생성자 / r-value를 선언해야 여기로 들어온다 / r-value참조를 매개변수로 받는 함수 / 이동생성자
    String(String &&rhs) {
        cout << "String(String &&rhs) :" << this << endl;
        // 얕은 복사로 인해 소멸자 2번 발생 방지
        len = rhs.len;
        strData = rhs.strData; // 이렇게 2개하면 얕은 복사 발생
        rhs.strData = NULL; // rhs를 NULL로 초기화 = strData 안 가리킴 = res소멸해도 소멸자는 1번만 나옴
    }
    ~String() {
        cout << "~String() : " << endl;
        release();
        strData = NULL;
    }
    // 복사 대입연산자
    String &operator=(const String &rhs){
        cout << "String &operator=(const String &rhs) : " << endl;
        if(this != &rhs) {
            release();
            len = rhs.len;
            alloc(len);
            strcpy(strData, rhs.strData);
        }
        return *this;
    }
    // 이동 대입연산자 -> 이제 r-value는 얘가 처리
    String &operator=(String &&rhs){
        cout << "String &operator=(String &&rhs) : " << endl;     
        len = rhs.len;
        strData = rhs.strData; // 얕은 복사 실행
        rhs.strData = NULL; 
        return *this; // 연쇄 등호 사용하는 문법 때문에 사용 (ex) String a = b = c;
    }
    
    char *GetStrData() const {
        return strData;
    }

    int GetLen() const {
        return len;
    }
    void SetStrData(const char *str){
        cout << "void SetStrData(const char*) : " << this << ", " << str << endl;
        len = strlen(str);
        alloc(len);
        strcpy(strData, str);
    }

private:
    void alloc(int len) {
        strData = new char[len + 1];
        cout << "strData allocated : " << (void*)strData << endl;
    }
    void release() {
        delete[] strData;
        if (strData) cout << "strData released : " << (void*)strData << endl;
    }
    char *strData;
    int len;
};

String getName() {
    cout << "==== 2 ====" << endl;
    String res("F-22"); // 이 사이에 코드 엄청 많다고 가정
    cout << "==== 3 ====" << endl;
    return res;
}


int main(){
    String a;
    cout << "==== 1 ====" << endl;
    a = getName();
    cout << "==== 4 ====" << endl;
}