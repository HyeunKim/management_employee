#include <stdio.h>
#include <string.h>

// ���� �� �� ���� �̸�, �����, �ް� �ð� ������ ������ ����ü ����
typedef struct{ 
    char name[100];
    int month, day;
    int in_hour, in_minute;
    int out_hour, out_minute;
    int rest_hour, rest_minute;
} Employee;

int createProduct(Employee *a);            
void readProduct(Employee a);             
void updateProduct(Employee *a);           
int deleteProduct(Employee *a);             
void listProduct(Employee *a,int count);    
void saveData(Employee *a, int count);
int loadData(Employee *a);
int selectMenu();
int selectDataNo(Employee *e, int count);
void showInTime(Employee *e, int count);
void showOutTime(Employee *e, int count);
void searchTime(Employee *e, int count);
void calculateDailyWage(Employee *e, int count);


int createProduct(Employee *a){
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

    return 1;
}

void readProduct(Employee a){

    printf("\n%d��%d��\n", a.month, a.day);
    printf("�̸�: %s\n", a.name);
    printf("��ٽð�: %d��%d��\n", a.in_hour, a.in_minute);
    printf("��ٽð�: %d��%d��\n", a.out_hour, a.out_minute);
    printf("�޽Ľð�: %d��%d��\n", a.rest_hour, a.rest_minute);

}

void listProduct(Employee* a, int count){
    for(int i=0; i<count; i++){
        if(a[i].month ==0) continue;
        printf("%d��\n", i+1);
        readProduct(a[i]);
        printf("\n");
    }
}

int selectDataNo(Employee* a, int count){
    int no =0;
    listProduct(a, count);
    printf("��ȣ��? (���:0)");
    scanf("%d", &no);
    return no;
}

void updateProduct(Employee* a){

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

int deleteProduct(Employee *a){
    a->month = 0;
}

void saveData(Employee *a, int count){
    FILE *fp;
    fp = fopen("employee.txt", "wt");

    for(int i=0; i<count ; i++){
        if(a[i].month ==0) continue;
        fprintf(fp, "%s ", a[i].name);
        fprintf(fp, "%d %d ", a[i].month, a[i].day);
        fprintf(fp, "%d %d ", a[i].in_hour, a[i].in_minute);
        fprintf(fp, "%d %d ", a[i].out_hour, a[i].out_minute);
        fprintf(fp, "%d %d\n", a[i].rest_hour, a[i].rest_minute);
    }

    fclose(fp);
    printf("�����\n");
}

int loadData(Employee *a){
    int count=0;

    FILE *fp;
    fp = fopen("employee.txt", "rt");

    if(fp == NULL){
        printf("���� ����\n");
        return count;
    }

    for(int i=0; i<100; i++){
        if(feof(fp)) break;
        fscanf(fp, "%s ", a[i].name);
        fscanf(fp, "%d %d ", &a[i].month, &a[i].day);
        fscanf(fp, "%d %d ", &a[i].in_hour, &a[i].in_minute);
        fscanf(fp, "%d %d ", &a[i].out_hour, &a[i].out_minute);
        fscanf(fp, "%d %d\n", &a[i].rest_hour, &a[i].rest_minute);
        count++;
    }
    fclose(fp);
    printf("�ε� ����!\n");
    return count;

}


void calculateDailyWage(Employee *e, int count){
    char search[20];
    int wage;
    int working_time;

    printf("�ϱ��� �˻��� ������ �̸��� �Է��ϼ��� : ");
    printf("\t(�ϱ��� �����ñ����� ���˴ϴ�. ���� �����ñ�: 9,160��)\n");
    scanf("%s", search);

    for(int i = 0; i<count; i++){
        if(e[i].month == -1) continue;
        if(strstr(e[i].name, search)){
            working_time = ((e[i].out_hour*60 + e[i].out_minute) - (e[i].in_hour * 60 + e[i].in_minute)) - (e[i].rest_hour*60 + e[i].rest_minute);
            working_time /= 60;
            wage = 9160 * (working_time);
            printf("���� %s�� %d�� %d���� �Ϸ� �ӱ��� %d�� �Դϴ�.\n",e[i].name, e[i].month, e[i].day, wage);
        }
    }
}

void searchTime(Employee *e, int count){
    int scnt = 0;
    char search[20];

    printf("����� �ð��� �������� �˻��� ������ �̸��� �Է��ϼ��� : ");
    scanf("%s", search);

    for(int i = 0; i<count; i++){
        if(e[i].month == -1) continue;
        if(strstr(e[i].name, search)){
            readProduct(e[i]);
            scnt++;
        }
    }
    if(scnt == 0)
    printf("=> �˻��� ������ ����! \n");
}

void showInTime(Employee *e, int count){
    printf("---- ��� �ð� �ð��� ��� ----\n");
    printf(" (���� 6~7��, 7~8��, 8~9��, 9~10�÷� ����� ��� ������)\n");
    char mark = '*';
    for (int time = 6; time <= 9; time++){ // 6�ú��� 10�ñ��� �ѽð� �������� ����� ����� ������ ���
        int cnt = 0;
        for(int i=0; i<count; i++){
            if( e[i].in_hour == time){
                cnt++;
            }
        }
        printf("[ ���� %d�� ~ %d�� ]�� ����� ��� �� : %d\n  ", time, time+1, cnt);
        for(int i = 0; i < cnt; i++)
            printf("%c", mark);
        printf("\n\t:");
        for(int i=0; i<count; i++){
            if( e[i].in_hour == time){
                printf("%s ",e[i].name);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void showOutTime(Employee *e, int count){
    printf("---- ��� �ð� �ð��� ��� ----\n");
    printf(" (���� 5~6��, 6~7��, 7~8��, 8��~9�÷� ����� ��� ������)\n");
    char mark = '*';
    for (int time = 5; time <= 8; time++){ // 5�ú��� 9�ñ��� �ѽð� �������� ����� ����� ������ ���
        int cnt = 0;
        for(int i=0; i<count; i++){
            if( e[i].out_hour-12 == time){ // 18�ô� ���� 6����(18-12 = 6)
                cnt++;
            }
        }
        printf("[ ���� %d�� ~ %d�� ]�� ����� ��� �� : %d\n  ", time, time+1, cnt);
        for(int i = 0; i < cnt; i++)
            printf("%c", mark);
        printf("\n\t:");
        for(int i=0; i<count; i++){
            if( e[i].out_hour == time){
                printf("%s ",e[i].name);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int selectMenu(){
    int menu;
    printf("\n*** ������ ����� ���� �ý��� ***\n");
    printf("============  �� ��  ===========\n\n");
    printf("1. ��ϵ� ���� ����� ���� ��ȸ\n");
    printf("2. ���� ����� ���� �߰�\n");
    printf("3. ���� ����� ���� ����\n");
    printf("4. ���� ����� ���� ����\n");
    printf("5. ��ϵ� ���� ����� ���� ����\n");
    printf("6. ��� �ð� �ð��� ���\n");
    printf("7. ��� �ð� �ð��� ���\n");
    printf("8. ���� ����� �ð� �˻�\n");
    printf("9. ���� �ϱ� ���\n");
    printf("0. ���α׷� ����\n\n");
    printf("\n================================\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}


int main(void){
    Employee elist[100];                    // 100���� ���� ����
    int curcount=0;
    int count = 0, menu;
    
    count = loadData(elist);
    curcount=count; 

    while (1){
        menu = selectMenu();
        getchar();
        if(menu == 0) break;

        if(menu == 1 || menu ==3 || menu == 4){	
		    if (count==0){ 
                printf("�����Ͱ� �����ϴ�.\n");
			    continue;
			}
		}

        if(menu == 1) listProduct(elist,curcount);
                   
        else if (menu == 2) {
            count+=createProduct(&elist[curcount++]);           // -
        }

        else if (menu == 3) {
            int no=selectDataNo(elist, curcount);
            if(no==0){
                printf("=>��ҵ�!");
                continue;
            }
            updateProduct(&elist[no-1]);                        // -
        }
        else if (menu == 4) {
            int no=selectDataNo(elist, curcount);
            if(no==0){
                printf("=>��ҵ�!");
                continue;
            }
            int deleteok;
            printf("������ �����Ͻðڽ��ϱ�?(����:1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteProduct(&elist[no-1])) count --;       // -  
           	 } 
        }
	    else if (menu == 5){
		    if (count==0) printf("�����Ͱ� �����ϴ�.\n");
		    else saveData(elist,curcount);
	    }
        else if (menu == 6){
		    if (count==0) printf("�����Ͱ� �����ϴ�.\n");
		    else showInTime(elist,curcount);
	    }
        else if (menu == 7){
		    if (count==0) printf("�����Ͱ� �����ϴ�.\n");
		    else showOutTime(elist,curcount);
	    }
        else if (menu == 8){
		    if (count==0) printf("�����Ͱ� ���� �˻��� �� �����ϴ�.\n");
		    else searchTime(elist,curcount);
	    }
        else if (menu == 9){
		    if (count==0) printf("�����Ͱ� ���� �˻��� �� �����ϴ�.\n");
		    else calculateDailyWage(elist,curcount);
	    }
	}

	printf("\n�����!\n");
   	return 0;
}