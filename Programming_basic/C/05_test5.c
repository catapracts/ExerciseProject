/*
1. 프로그램 출력 결과
#include <stdio.h>

typedef int Point[2];
typedef Point *PointPtr;

int main(){
    Point p = {3, 4};
    PointPtr pp = &p; // PointPtr *pp = &p;
    printf("%d %d %d\n", **pp, (*pp)[0], (*pp)[1]); // **pp = *(*pp) = *p = p[0]
}

결과 : 3의 주소값, 3, 4
정답 : 3 3 4

*/

/*
2. 빈칸에 들어갈 코드는?
#include <stdio.h>

struct Point {
    int x, y;
};

void pSwap(Point *p){
    Point tmp = *p.x;
    *p.x = *p.y;
    *p.y = tmp;
}

int main(){
    Point pos = {3, 4};
    pSwap(&pos);
    printf("(%d %d)\n", pos.x, pos.y); // **pp = *(*pp) = *p = p[0]
}

정답
void pSwap(Point *p){
    int tmp = p->x;
    p->x = p->y;
    p->y = tmp;
}
*/

/*
3. pSwap함수를 구조체 안에 넣기

#include <stdio.h>

struct Point {
    int x, y;
    void pSwap(){
        int tmp = x;
        x = y;
        y = tmp;
    }    
};


int main(){
    Point pos = {3, 4};
    pos.pSwap();
    printf("(%d %d)\n", pos.x, pos.y); // **pp = *(*pp) = *p = p[0]
}

정답
struct Point {
    int x, y;
    void pSwap(){
        int tmp = x;
        x = y;
        y = tmp;
    }    
};

pos.pSwap();

*/