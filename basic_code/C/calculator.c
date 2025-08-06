#include <stdio.h>

int add (int x, int y) {
    int z = x + y;
    printf("result = %d\n", z);
    printf("\n");
    return z;
}

int sub (int x, int y) {
    int z = x - y;
    printf("result = %d\n", z);
    return z;
}

double product (double x, double y) {
    double z = x * y;
    printf("result = %lf\n", z);
    return z;
}

double divide (double x, double y) {
    double z = x / y;
    printf("result = %lf\n", z);
    return z;
}

int main() {
    int a, b, number;
    double c, d;

    while(1){
        printf("calculator start\n");
        printf("press button and choose number\n");
        printf("==============================\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Product\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("==============================\n");
        scanf("%d", &number);

        if(number == 1) {
            printf("Start Add\n");
            printf("input two integer : ");
            if(scanf("%d %d", &a, &b) != 1){
                printf("Your input type is wrong. Please restart.\n");
                break;                
            };
            add(a, b);
            printf("End Add\n");
        }

        else if(number == 2) {
            printf("Start Subtract\n");
            printf("input two integer : ");
            if(scanf("%d %d", &a, &b) != 1){
                printf("Your input type is wrong. Please restart.\n");
                break;                
            };
            sub(a, b);
            printf("End Subtract\n");
        }

        else if(number == 3) {
            printf("Start Product\n");
            printf("input two double : ");
            if(scanf("%lf %lf", &c, &d) != 1){
                printf("Your input type is wrong. Please restart.\n");
                break;                
            };
            product(c, d);
            printf("End Product\n");
        }

        else if(number == 4) {
            printf("Start Divide\n");
            printf("input two double : ");
            if(scanf("%lf %lf", &c, &d) != 1){
                printf("Your input type is wrong. Please restart.\n");
                break;                
            };
            divide(c, d);
            printf("End Add\n");
        }

        else if(number == 5) {
            printf("Good Bye\n");
            break;
        }

        else {
            break;
        }
    }
}