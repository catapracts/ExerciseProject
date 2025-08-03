/*
복사 생성자 오버로딩


*/


#include <iostream>
#include <string.h>
using namespace std;

class String {
public:
    String() {
        cout << "String() 생성자 호출됨" << endl;
        strData = NULL;
        len = 0;
    }
    String(const char *str) {
        cout << "String(const char*) 생성자 호출됨" << endl;
        len = strlen(str);
        strData = new char[len + 1];
        cout << "strData 할당 : " << (void*)strData << endl; // (void*) : 주소값만 가졌고 다른 정보(메모리 크기, 데이터 형식 등) 하나도 없는 것, 형변환  / 이거 없으면 문자일 경우 문자열로 인식함
        strcpy(strData, str);
    }
    ~String() {
        cout << "String() 소멸자 호출됨" << endl;
        delete[] strData;
        cout << "strData 해제됨 : " << (void*)strData << endl;
        strData = NULL;
    }

    /*
    복사 생성자가 작동되는 형식
    복사 생성자 제외 다른 생성자, 맴버 메서드에서는 String rhs 이런식으로 사용 가능
    */
    String(const String &rhs) {
        // strData = rhs.strData; // => 얕은 복사 발생
        cout << "String(const String &rhs) 생성자 호출됨" << endl;
        strData = new char[rhs.len + 1]; // => 이런식으로 해줘야
        cout << "strData 할당 : " << (void*)strData << endl;
        strcpy(strData, rhs.strData); // => 깉은 복사 발생
        len = rhs.len; // => 깊은 복사 발생
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
    /*
    이렇게 하면 생성자는 하나 생성되었는데 소멸자는 2개 실행됨
    = s2에 주소값이 똑같이 복사됨 = 얕은 복사 발생 = 복사 생성자
    */
    String s1("Hello");
    String s2(s1); // 복사 생성자

    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;
}