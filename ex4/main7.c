#include <stdio.h>
int fac(int n){
    if(n == 1)return 1;
    return n*fac(n-1);
}
int main(){
    int n = 5;
    int m =fac(n);
    printf("factorial %d = %d\n",n,m);
    return 0;
}