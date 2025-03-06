#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp;
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};
    fp = fopen("a.bin","wb+");

    fwrite(a, sizeof(int), 3, fp);
    fseek(fp, 0, SEEK_SET);
    fread(a, sizeof(int), 3, fp);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", a[i]);
    }
    

    fwrite(b, sizeof(int), 3, fp);
    fread(b, sizeof(char), 3, fp);
    for (int i = 0; i < 3; i++) {
        printf("%c\n", b[i]);
    }
    

    fwrite(c, sizeof(float), 3, fp);
    //fseek(fp, 0, SEEK_SET);
    fread(c, sizeof(float), 3, fp);
    for (int i = 0; i < 3; i++) {
        printf("%f\n", c[i]);
    }

    fclose(fp);

    return 0;
}
