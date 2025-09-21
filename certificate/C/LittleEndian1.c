/*
Error Message

Undefined symbols for architecture x86_64:
  "_main", referenced from:
     implicit entry/start for main executable
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)

-> using wrong word / we use "main" function not "mian"
*/

#include <stdio.h>

union Data {
    int num;
    char ch[4];
};

int main() {
    union Data dt;
    dt.num = 0x41424344;
    printf("%X, %x %c %c %c\n", dt.num, dt.ch[0], dt.ch[1], dt.ch[2], dt.ch[3]);
    
    dt.ch[0] = 'X';
    printf("%X, %x %c %c %c\n", dt.num, dt.ch[0], dt.ch[1], dt.ch[2], dt.ch[3]);

    dt.ch[2] = 'Y';
    printf("%X, %x %c %c %c\n", dt.num, dt.ch[0], dt.ch[1], dt.ch[2], dt.ch[3]);

    return 0;
}