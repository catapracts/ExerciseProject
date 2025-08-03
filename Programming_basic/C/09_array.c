#include <stdio.h>

int main(){
    int a[5], b[5];

    a[0] = 2;
    a[1] = 2;
    a[2] = 2;
    a[3] = 2;
    a[4] = 2;

    printf("%d\n"), a[0];
    printf("%d\n"), a[1];
    printf("%d\n"), a[2];
    printf("%d\n"), a[3];
    printf("%d\n"), a[4];

    for(int i = 0; i <= 4; i++){
        b[i] = i * 5;
    }

    for(int i = 0; i <= 4; i++){
        printf("%d\n", b[i]);
    }

    int arr[5] = {3, 4, 1, 5, 1, 6, 7, 9, 11, 15};

    printf(sizeof(arr));

    for(int i = 0; i <= sizeof(arr) / sizeof(int) - 1; i++){ // i < sizeof(arr) / sizeof(int)
        printf("%d\n", arr[i]);
    }
    printf("\n");
    

    // 입력받은 숫자들을 거꾸로 출력하기
    // 짝수의 개수
    int arr1[1000];
    int n;

    printf("입력할 숫자의 갯수 입력 : ");
    scanf("%d", &n);

    for(int  i = n-1; i >= 0; i--){
        scanf("%d", arr1[i]);
    }

    // 최대, 최소
    int arr2[100];
    int n1;

    printf("입력할 숫자의 갯수 입력 : ");
    scanf("%d", &n1);

    for(int  i = 0; i < n; i++){
        scanf("%d", arr2[i]);
    }

    int max = arr2[0];
    for(int i = 0; i < n1; i++){
        if(max < arr2[i]) max = arr2[i];
    }

    printf("%d\n", max);


    int arr3[100];
    int n2;

    printf("입력할 숫자의 갯수 입력 : ");
    scanf("%d", &n2);

    for(int  i = 0; i < n2; i++){
        scanf("%d", arr3[i]);
    }

    int min = arr3[0];
    for(int i = 0; i < n2; i++){
        if(min < arr3[i]) min = arr3[i];
    }

    printf("%d\n", min);


    // 짝수의 개수
    int arr4[1000];
    int n3;

    printf("입력할 숫자의 갯수 입력 : ");
    scanf("%d", &n3);

    for(int  i = 0; i < n3; i++){
        scanf("%d", arr4[i]);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr4[i] % 2 == 0) cnt++;
    }

    printf("%d\n", cnt);
    
}