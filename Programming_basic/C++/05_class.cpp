/*
class(type) = 특정 용도 수행을 위한 변수와 함수를 모아둔 틀 / 자료형 중 하나
가장 기본 기능
1.자료 저장
2.자료 처리

object = class를 통해 만든 것들, 변수 메모리상의 공간
접근 제어지시자 - private, public, protected
default - public
private - 범위 내에서만 사용가능
캡슐화 : 내부속성을 보호하고 외부에서 접근시 특정 수단으로만 가능하도록 설정

struct -> 접근제어지시자 안 쓰면 default가 public
class -> 접근제어지시자 안 쓰면 default가 private

*/

#include <iostream>

using namespace std;

struct TV {
private: // 내부 속성 보호
    bool powerOn;
    int channel;
    int volume;

public:
    void on() {
        powerOn = true;
        cout << "TV ON" << endl;
    }

    void off() {
        powerOn = false;
        cout << "TV OFF" << endl;
    }

    void setVolume(int vol) {
        if(vol >= 0 && vol <= 100) {
            volume = vol;
        }
    }

    void setChannel(int cnl) {
        if(cnl >= 1 && cnl <= 999) {
            channel = cnl;
            cout << "channel change : " << cnl << endl;
        }
    }
};


int main() {
    TV lg;
    lg.on();
    lg.off();
    lg.setVolume(50);
    lg.setChannel(10);
}