#include <stdio.h>

const int K=46337;

void matrix_mult(long long int v1[2][2], long long int v2[2][2], long long int ret[2][2]) {
    ret[0][0]=(v1[0][0]*v2[0][0]+v1[0][1]*v2[1][0])%K;
    ret[0][1]=(v1[0][0]*v2[0][1]+v1[0][1]*v2[1][1])%K;
    ret[1][0]=(v1[1][0]*v2[0][0]+v1[1][1]*v2[1][0])%K;
    ret[1][1]=(v1[1][0]*v2[0][1]+v1[1][1]*v2[1][1])%K;
}

void fibonacci(long long int n, long long int ret[2][2]) {
    if (n==2) {
        ret[0][0]=1; ret[0][1]=1;
        ret[1][0]=1; ret[1][1]=2;
    } 
    else if (n==1) {
        ret[0][0]=0; ret[0][1]=1;
        ret[1][0]=1; ret[1][1]=1;
    } 
    else {
        long long int mitad[2][2];
        fibonacci(n/2, mitad);
        if (n%2==0) matrix_mult(mitad, mitad, ret);
        else {
            long long int unidad[2][2]={ { 0, 1 }, { 1, 1 } };
            long long int temp[2][2];
            matrix_mult(mitad, mitad, temp);
            matrix_mult(temp, unidad, ret);
        }
    }
}

int main() {
    long long int n;
    while (scanf("%lld", &n) && n!=0) {
        long long int ret[2][2];
        fibonacci(n, ret);
        printf("%lld\n", ret[0][1]);
    }
    
    return 0;
}