#include <stdio.h>

typedef union __endian {
    int num;
    char ch[4];
} endian_t;

void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    endian_t dat;
    dat.num = 0x12345678;

    printf("num = %X, ch[0] = %X, ch[1] = %X, ch[2] = %X, ch[3] = %X\r\n", dat.num, dat.ch[0], dat.ch[1], dat.ch[2], dat.ch[3]);

    // compiler 내장 명령 등 더 좋은 방법이 있지만, 여기서는 수동 스왑 합니다.
    swap(&dat.ch[0], &dat.ch[3]);
    swap(&dat.ch[1], &dat.ch[2]);

    printf("num = %X, ch[0] = %X, ch[1] = %X, ch[2] = %X, ch[3] = %X\r\n", dat.num, dat.ch[0], dat.ch[1], dat.ch[2], dat.ch[3]);
    
    // 출력 (Little-Endian | 실제): 
    //  num = 12345678, ch[0] = 78, ch[1] = 56, ch[2] = 34, ch[3] = 12
    //  num = 78563412, ch[0] = 12, ch[1] = 34, ch[2] = 56, ch[3] = 78
    //  
    // 출력 (   Big-Endian | 예측): 
    //  num = 12345678, ch[0] = 12, ch[1] = 34, ch[2] = 56, ch[3] = 78
    //  num = 78563412, ch[0] = 78, ch[1] = 56, ch[2] = 34, ch[3] = 12
}