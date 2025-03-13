#include <stdio.h>
#include <string.h>

// 只需要保留一个定义，使用 typedef
typedef struct employee {
    int id;
    int age;
    float salary;
    char name[50];
} emp_t;

void emp_info(emp_t emp) {
    printf("employee id = %d\n",emp.id);
    printf("employee name = %s\n",emp.name);
    printf("employee age = %d\n",emp.age);
    printf("employee salary = %f\n",emp.salary);  
    printf("\n");
}

int emp_average_age(emp_t emp[],int n){
    int sum=0;
    for (int i = 0; i < 3; i++) {
        sum += emp[i].age;
    }
    return sum/n;
}

void emp_write_file(emp_t emp[],int n){
    FILE*fp = fopen("employee.bin","wb+");
    for (int i = 0; i < n; i++) {
        fwrite(emp+i, sizeof(emp_t), 1, fp);
    }
    fclose(fp);
    return;
}

void emp_read_file(emp_t emp[],int n){
    FILE*fp = fopen("employee.bin","rb");
    int i = 0;
    while (fread(emp+i,sizeof(emp_t),1,fp)) {
        printf("[%d] %d %s\n",i, emp[i].id,emp[i].name);
        i++;
    }
    return;
}


int main() {
    emp_t emp[3];
    //printf("sizeof(emp_t) = %lu\n", sizeof(a));  // 修改 %d 为 %lu
    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0;
    strcpy(emp[0].name, "IU");

    emp[1].id = 2;
    emp[1].age = 25;
    emp[1].salary = 88000.0;
    strcpy(emp[1].name, "chodan");

    emp[2].id = 3;
    emp[2].age = 30;
    emp[2].salary = 100000.0;
    strcpy(emp[2].name, "magenta");

    emp_write_file(emp, 3);
    emp_t emp_read[10];
    emp_read_file(emp_read, 10);

    for (int i = 0; i < 3; i++) {
        emp_info(emp_read[i]);
    }
    return 0;
}   
