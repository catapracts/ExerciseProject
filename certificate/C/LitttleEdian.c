/*
Little Endian
- the format to define data byte sequence or data expression type

- to save first LSB(Least Siginificant Bit, the smallest byte) of data in the lowest memory address
e.g) when you save the integer(4byte) data in the memory, such as 0x12345678, then it can be saved in the memory reverse
0x12345678 / from the lowest to the highest
memoey address  value
    0x00        0x78 
    0x01        0x65 
    0x02        0x43
    0x03        0x21

- this format is using in the architecture like x86, x64 using in the Intel or AMD for efficiently reading data or fast processing it.
-> because of the process design of CPU is that it must read and write first the lowest byte.

- the opposite format is the Big Endian it is reverse concept for Little Endian

*/

#include <stdio.h>

int main() {
    char i;
    union {
        int int_arr[2];
        char char_arr[8];
    } endian;

    for(i = 0; i < 8; i++) {
        endian.char_arr[i] = i + 16;
        printf("%x", endian.int_arr[1]);
    }

    return 0;
}