/*
1. 프로그램 출력 결과
#include <iostream>

using namespace std;

int n = 0;
namespace A {
    int n = 0;
    namespace B {
        void set() {n = 10;}
        int n = 0;
    }
}

namespace C {
    void set();
    int n = 0;
}

void C::set() { n=20; }

int main() {
    using namespace A::B;
    set();
    C::set();

    cout << ::n << endl;
    cout << A::n << endl;
    cout << A::B::n << endl;
    cout << C::n << endl;
}

결과
0 -> 전역변수 n
0 -> namespace A의 n
10 -> namespace B의 n
20 -> namespace C의 n

결과
0 -> 전역변수 n
10 -> namespace A 들어갔다가 set만나고 n값 수정
0 -> namespace B 들어가서 n = 0인거 확인하고 0출력
20 -> namespace C 갔는데, set함수 안에 n=20이라고 적혀있으니 20 출력
*/

/*
2. 코드 작성
2-1.아래의 GameWindow class의 코드에서 창 너비와 높이를 매개변수로 받는 ResizeWindow함수를 추가하여 다음 조건과 같이 width와 height의 값을 바꾸기
조건1. 들어온 매개변수의 값과 일치하도록 창 크기 설정
조건2. 너비가 800보다 작거나 높이가 600보다 작을 때는 각각 800, 600으로 설정

2-2. GameWindow::GameWindow(int w, int h) 생성자도 마찬가지로 조건2 만족하도록 설정

2-3. 코드 중 상수화 가능한 부분 전부 상수화 시키기

#include <iostream>

using namespace std;

class GameWindow {
public:
    GameWindow();
    GameWindow(int int);

    int GetWidth();
    int GetHeight();

private:
    int width;
    int height;
}

GameWindow::GameWindow() : width(800), height(600) {}
GameWindow::GameWindow(int w, int h) : width(w), height(h) {}
int GameWindow::GetWidth() { return width; }
int GameWindow::GetHeight() { return height; }

int main() {
    GameWindow mainWindow;
    mainWindow.ResizeWindow(1366, 768);
    cout << mainWindow.GetWidth() << "x" << mainWindow.GetHeight() << endl;
}


작성 답
#include <iostream>

using namespace std;

class GameWindow {
public:
    GameWindow();
    GameWindow(int width, int height);

    int GetWidth() const;
    int GetHeight() const;

    private GameWindow ResizeWindow(int w, int h) : width(w), height(h) const {
        w = w;
        h = h;
    }

private:
    int width;
    int height;
}

GameWindow::GameWindow() : width(800), height(600) {}
GameWindow::GameWindow(int w, int h) : width(w), height(h) {
    if( w < 800 && h <600) {
        w = 800;
        h = 600;
    }
}
int GameWindow::GetWidth() { return width; }
int GameWindow::GetHeight() { return height; }

int main() {
    GameWindow mainWindow;
    mainWindow.ResizeWindow(1366, 768);
    cout << mainWindow.GetWidth() << "x" << mainWindow.GetHeight() << endl;
}




답
#include <iostream>

using namespace std;

class GameWindow {
public:
    GameWindow();
    GameWindow(const int, const int);

    int GetWidth() const;
    int GetHeight() const;

    void ResizeWindow(const int, const int);

private:
    int width;
    int height;
}

GameWindow::GameWindow() : width(800), height(600) {}
GameWindow::GameWindow(const int w, const int h) : width(w), height(h) {
    ResizeWindow(w, h);
}
int GameWindow::GetWidth() const { return width; }
int GameWindow::GetHeight() const { return height; }

void GameWindow::ResizeWindow(const int w, const int h) {
    if(w < 800) width = 800;
    else width = w;
    if(h < 600) height = 600;
    else height = h;
}

int main() {
    GameWindow mainWindow;
    mainWindow.ResizeWindow(1366, 768);
    cout << mainWindow.GetWidth() << "x" << mainWindow.GetHeight() << endl;
}

*/


/*
3. 출력결과 예측하기
#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass() : num(cnt++), ch('\0') {}

    void Check(MyClass *ptr) { // 0 ~ 5
        if(ptr + num == this) { // ptr + num = &obj[num] : 현재 선택된 객체 위치랑 똑같은가? -> 항상 쓰는 if문
            cout << num << endl;
        }
    }
    static int cnt;
private:
    int num;
    char ch;
};

int MyClass::cnt = 0;

int main() {
    MyClass obj[5]; // 각 배열에 MyClass객체가 담긴 상태 = 객체 5개 생성
    cout << "Test #1 : " << endl;
    for(int i = 0; i < 5; i++){
        obj[i].Check(obj); // obj의 0번째 칸의 주소값을 매개변수로 넘김
    }
    cout << "Test #2 : " << endl;
    for(MyClass &i : obj){ // 위 for문이랑 같은 내용, 범위기반 for문으로만 바꾼것
        i.Check(obj);
    }
    cout << "cnt = " << MyClass::cnt << endl;
}


ptr = &obj[0] = obj
ptr* num = &ptr[num] = &obj[num]

예상 답
Test #1 :
0
1
2
3
4

Test #2 :
5
6
7
8
9
cnt = 10


답
Test #1 :
0
1
2
3
4
Test #2 :
0
1
2
3
4
cnt = 5



*/



#include <iostream>

using namespace std;

int main() {

}