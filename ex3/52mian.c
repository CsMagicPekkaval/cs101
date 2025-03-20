#include <stdio.h>

int func(int *i, int *j) {
    printf("in func, i = %d, j = %d\n", *i, *j);
    int t;
    t = *i;
    *i = *j;
    *j = t;
    printf("in func, i = %d, j = %d\n", *i, *j);
    return 0;
}

int main() {
    int n = 1, m = 2;
    func(&n, &m);
    printf("in main, n = %d, m = %d\n", n, m);
    return 0;
}
