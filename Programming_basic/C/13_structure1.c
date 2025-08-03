/*
현재 버그 발생
struct 이름 {}; -> 이렇게 쓰면 구조체 아니라고 하고
typedef써야 구조체 취급함


구조체 포인터

구조체에 함수 넣기 -> C++에만 있는 기능이라는 썰이 있다.

*/

#include <stdio.h>

typedef struct {
    int num;
    char name[100];
    int cost;
} ProductInfo;

// 할인가 = 원가 - {원가*(할인률/100)}
void productSale(ProductInfo p, int percent){ // call-by-value라서 안 바뀜
    p.cost -= p.cost * percent / 100;
}

void productSale1(ProductInfo *p, int percent){ // call-by-reference로 바꿔야 바뀜
    p->cost -= p->cost * percent / 100;
}

// 제품 바꾸기
void productSwap(ProductInfo *a, ProductInfo *b){
    ProductInfo tmp = *a;
    *a = *b;
    *b = tmp;
}

typedef struct {
    int h, m, s;
    int totalSec(Time t){
        return 3600 * h + 60 * m + s;
    }
} Time;

typedef struct {
    int x, y;
    void moveRight() {x++;};
    void moveLeft() {x--;};
    void moveUp() {y++;};
    void moveDown() {y--;};
} Point1;


int main(){
    ProductInfo myProduct = {272938, "제주 한라봉", 19900};
    printf("Product Number : %d\n", myProduct.num);
    printf("Product Name : %s\n", myProduct.name);
    printf("Product Cost : %d\n", myProduct.cost);
    printf("size : %d\n", sizeof(myProduct));
    printf("number address : %d\n", &myProduct.num);
    printf("cost address : %d\n", &myProduct.cost);
    printf("myProduct address : %d\n", &myProduct); // number address랑 동일

    ProductInfo *ptr_product = &myProduct; // myProduct의 주소값 저장, myProduct를 가리키는 중
    printf("number address : %d\n", (*ptr_product).num); // (*ptr_product) = myProduct
    printf("number address : %d\n", ptr_product->num); // (*ptr_product).num = ptr_product->num
    printf("name address : %d\n", (*ptr_product).name);
    printf("name address : %d\n", ptr_product->name);
    printf("cost address : %d\n", (*ptr_product).cost);
    printf("name address : %d\n", ptr_product->cost);
    printf("myProduct address : %d\n", (*ptr_product)); // number address랑 동일

    productSale1(&myProduct, 10);
    printf("Product Number : %d\n", myProduct.num);
    printf("Product Name : %s\n", myProduct.name);
    printf("Product Cost : %d\n", myProduct.cost);

    ProductInfo myProduct1 = {272939, "성주 꿀참외", 10000};
    productSwap(&myProduct, &myProduct1);
    printf("Product Number 1 : %d\n", myProduct.num);
    printf("Product Name 1 : %s\n", myProduct.name);
    printf("Product Cost 1: %d\n", myProduct.cost);
    printf("Product Number 2 : %d\n", myProduct1.num);
    printf("Product Name 2 : %s\n", myProduct1.name);
    printf("Product Cost 2 : %d\n", myProduct1.cost);

    Time t = { 1, 22, 48 };
    // 1시간 = 60분, 1분 = 60초, 1*3600(1시간) + 22*60(22분) + 48(48초)
    printf("%d\n", t.totalSec());

    Point1 p1 = {2, 5};
    p1.moveDown();
    p1.moveRight();

    printf("(%d, %d)\n", p1.x, p1.y);

}