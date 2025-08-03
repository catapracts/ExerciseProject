#include <stdio.h>

int main() {
    FILE *in, *out; // stream, 파일을 가리키는 포인터    
    int n;
    
    in = fopen("input.txt", "r");
    //out = fopen("output.txt", "a"); // w - 다 지워지고 써짐, a - 기존에 있던거에서 하나 더 추가
    printf("in = %d\n", in); // in = 0 = NULL -> 포인터로는 아무것도 가리키지 않는 상태
    if(in != nullptr){
        fscanf(in, "%d", &n);
        printf("%d\n", n);
        fclose(in);
    }
    // fscanf(in, "%d", &n); // input stream
    // //fprintf(out, "%d\n", n); // output stream
    // printf("%d\n", n);
    // fclose(in);
    //fclose(out); // fopen 쓰면 fclose도 같이 쓰기

    // 자기 자신 출력하는 코드
    FILE *in1 = fopen("14_advanced_func1.c", "r");
    char ch;
    // while(!feof(in1)){ // feof = file을 끝까지 읽었으면 True, 다 읽고 1번 더 읽는다?
    //     fscanf(in1, "%c", &ch);
    //     printf("%c", ch);
    // }

    while(!feof(fscanf(in1, "%c", &ch) != EOF)){  // EOF = End Of File
        printf("%c", ch);
    }

    fclose(in1);
    
}