#include <stdio.h>

int main(){
    int* ip;
    int var = 10;
    ip = &var;
    printf("%x\n", ip);
    printf("%x\n", *ip);
    return 0;
}