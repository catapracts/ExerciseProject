/*
상속이 필요한 이유

메신저 - 텍스트, 이미지

공통 부모를 만들고 자식들이 상속받아서 여러 개 생성

*/

#include <iostream>
#include <string>

using namespace std;

class Message {
public:
    Message(int sendTime, string sendName) {
        this->sendTime = sendTime;
        this->sendName = sendName;
    }
    int GetSendTime() const { return sendTime;}
    string GetSendName() const { return sendName;}
private:
    int sendTime; // C언어에서 time은 int형
    string sendName;

};

class TextMessage : public Message {
public:
    TextMessage(int sendTime, string sendName, string text) : Message(sendTime, sendName) {
        this->text = text;
    }
    string GetSendText() const { return text;}
private:
    string text;
};

class Image {
public:
    operator string() {
        return "사진";
    }
};


class ImageMessage : public Message {
public:
    ImageMessage(int sendTime, string sendName, Image *image) : Message(sendTime, sendName) {
        this->image = image;
    }
    Image *GetImage() const { return image;}
private:
    Image *image;
};


int main() {
    Image *p_dogImage = new Image(); //동적 할당
    TextMessage *hello = new TextMessage(10, "AAA", "Hello");
    ImageMessage *dog = new ImageMessage(20, "AAA", p_dogImage);

    cout << "보낸 시간 : " << hello->GetSendTime() << endl;
    cout << "보낸 사람 : " << hello->GetSendName() << endl;
    cout << "보낸 메시지 : " << hello->GetSendText() << endl;
    cout << endl;

    cout << "보낸 시간 : " << dog->GetSendTime() << endl;
    cout << "보낸 사람 : " << dog->GetSendName() << endl;
    cout << "보낸 메시지 : " << (string)*dog->GetImage() << endl; // (string)* 이거 안 붙이면 주소값 출력됨
    cout << endl;

    delete hello;
    delete dog;
    delete p_dogImage;

}