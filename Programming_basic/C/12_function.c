#include <stdio.h>

int itemCnt = 0;
int money = 100;
//int result;

int buyItem(int cost, int cnt){
    // if(money >= cost){
    //     itemCnt += cnt;
    //     money -= cost;
    //     printf("item 구매\n");
    //     printf("item 갯수 : $d\n", itemCnt);
    //     printf("잔액 : %d\n", money);
    //     //result = 0;
    //     return 0;
    // }
    // else {
    //     printf("잔액 부족\n");
    //     return -1;
    // }
    if(money < cost) {
        printf("잔액 부족\n");
        return -1;
    }

    itemCnt += cnt;
    money -= cost;
    printf("item 구매\n");
    printf("item 갯수 : $d\n", itemCnt);
    printf("잔액 : %d\n", money);
    return 0;
}


int plus(int a, int b){
    return a+b;
}

int noMeaning(){
    printf("first\n");
    return 1;
    printf("second\n");
    printf("third\n");
    printf("forth\n");
}


int main(){
    int result;
    if(result == -1) printf("not enough money\n");

    buyItem(30000, 5);
    buyItem(50, 7);
    int sum = plus(3,5);
    printf("%d\n", sum);
    int a;
    a = noMeaning();
    printf("return : %d\n", a);


}