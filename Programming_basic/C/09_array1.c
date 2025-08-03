// N차원 배열

#include <stdio.h>
#include <string.h>

int main(){
    int arr[3][4] = {
        {1, 2 ,3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    for(int  i = 0; i< 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }

    /*
    파스칼의 삼각형
    1
    1 1
    1 2 1
    1 3 3 1
    j == 0 || j == i -> 1
    i핼, j열 = [i-1, j-1] + [i-1 j]
    */

    int p[10][10];
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == 1){
                p[i][j] = 1;
            }
            else {
                p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
            }
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }


    // 문자열
    char arr1[] = "abc"; // = {'a', 'b', 'c',  '\0'} \0 = null 문자, 배열의 끝을 나타냄, 

    printf("%s\n", arr1);
    printf("%d\n", sizeof(arr1) / sizeof(char)); // 배열의 길이

    char s[100];
    scanf("%s", s);
    printf("%s\n", s);

    char str[] = "Hello";
    char str1[100];
    int len;
    len = strlen(str);
    sizeof(str) / sizeof(char) - 1;

    printf("문자열 길이 : %d\n", len);

    strcpy(str1, str);
    printf("str1 : %s\n", str1);

    char str2[100] = "Hello";
    strcat(str2, "World!");
    strcat(str2, "World!");
    strcat(str2, "World!");
    strcat(str2, "World!");
    printf("%s\n", str2);

    char str3[] = "sample";
    char str4[] = "simple";
    int cmp = strcmp(str3, str4);
    int cmp1 = strcmp(str4, str3);
    printf("%d\n", cmp);
    printf("%d\n", cmp1);


}