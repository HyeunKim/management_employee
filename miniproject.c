#include <stdio.h>

typedef struct{
    char name[100];
    int month, day;
    int in_hour, in_minute;
    int out_hour, out_minute;
    int rest_hour, rest_minute;
} Employee;

int create_emp(Employee *a){
    char name[100] ;

    printf("��¥�Է� ex) 7��5�� -> 7/5\n");
    printf("��¥: ");
    scanf("%d/%d", &a->month, &a->day);
    printf("�̸��� �Է��ϼ���: ");
    scanf("%s", a->name);
    printf("\n");
    printf("�ð��� 24�� ���� ��) 19:15\n");
    printf("��ٽð�: ");
    scanf("%d:%d", &a->in_hour, &a->in_minute);
    printf("��ٽð�: ");
    scanf("%d:%d", &a->out_hour, &a->out_minute);
    printf("�޽Ľð�: ");
    scanf("%d:%d", &a->rest_hour, &a->rest_minute);
}

void read_emp(Employee a){

    printf("%d��%d��\n", a.month, a.day);
    printf("�̸�: %s\n", a.name);
    printf("��ٽð�:%d��%d��\n", a.in_hour, a.in_minute);
    printf("��ٽð�:%d��%d��\n", a.out_hour, a.out_minute);
    printf("�޽Ľð�:%d��%d��\n", a.rest_hour, a.rest_minute);

}

int main(){
    Employee a;

    create_emp(&a);
    read_emp(a);
    



}
