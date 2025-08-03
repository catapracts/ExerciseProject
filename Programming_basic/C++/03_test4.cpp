/*
1. 복사, 이동 생성자 / 복사, 이동 대입 연산자 구현

#include <iostream>

using namespace std;

struct Point {
    int x, y;
}

class Polygon {
public:
    Polygon() {
        nPoints = 0;
        points = NULL;
    }
    Polygon(const int nPoints, const Point *points) : nPoints(nPoints) {
        this->points = new Point[nPoints];
        for(int i = 0; i < nPoints; i++)
            this->points[i] = points[i];
    }
    
    // 복사 생성자

    // 이동 생성자

    ~Polygon() {
        delete[] nPoints;
    }

    // 복사 대입 연산자

    // 이동 대입 연산자
    
    int GetNPoints() const {
        return nPoints;
    }
    
    Point *GetPoints() const {
        if(nPoints == 0) return NULL;
        return points;
    }

private:
    int nPoints;
    Point *points;
}

Polygon getSquare() {
    Point points[4] = { { 0, 0 }, { 1 , 0 }, { 1 , 1 }, { 0 , 1 }};
    Polygon p(4, points);
    return p;
}


int main() {
    Polygon a;
    a = getSquare();
    Polygon b = a;
    Polygon c;
    c = a;

    int nPoints = c.getNPoints();
    Point *points = c.GetPoints();
    for(int i = 0; i < nPoints; i++) {
        cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
    }
}

내 답 : 
    // 복사 생성자
    Polygon(const Polygon &rhs) {
        points = new int[rhs.len]; 
    }
    // 이동 생성자

    // 복사 대입 연산자
    Polygon operator=(const Polygon &rhs){
        if(this != &rhs) {
            delete[] *points;
            *points = new Point[rhs.len];
        }
        return *this;
    }
    // 이동 대입 연산자
    Polygon &operator=(Polygon &&rhs){
        nPoints = rhs.nPoints;
        point = rhs.point;
        rhs.point = NULL;
        return *this;
    }
정답 : 
    // 복사 생성자
    Polygon(const Polygon &rhs) {
        nPoints = rhs.nPoints;
        points = new Point[nPoints];
        for(int i; i < nPoints; i++){
            points[i] = rhs.points[i];
        }
        cout << "깊은 복사" << endl;
    }

    // 이동 생성자
    Polygon(Polygon &&rhs) {
        nPoints = rhs.nPoints;
        points = rhs.points;
        rhs.points = NULL;
        cout << "얕은 복사" << endl;
    }

    // 복사 대입 연산자
    Polygon &operator=(const Polygon &rhs) {
        if( this != &rhs){
            nPoints = rhs.nPoints;
            delete[] points;
            points = new Point[nPoints];
            for(int i; i < nPoints; i++) {
                points[i] = rhs.points[i];
            }
        }
        cout << "깊은 복사" << endl;
        return *this;
    }

    // 이동 대입 연산자 -> 자기 자신이랑 같은지 확인하는 작업 필요
    Polygon &operator=(Polygon &&rhs){
        if(this != &rhs){
            nPoints = rhs.nPoints;
            delete[] points;
            points = rhs.points;
            rhs.points = NULL;
        }
        cout << "얕은 복사" << endl;
        return *this;
    }
*/