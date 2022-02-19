#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_L 100

int n;
typedef struct danhsach{
    int num;
    char toy[30];
    struct danhsach *next;
}danhsach;

danhsach arr[MAX_L];

danhsach *first, *last;

danhsach *Alink(int num, char *toy){
    danhsach *node = (danhsach*)malloc(sizeof(danhsach));
    node->num = num;
    strcpy(node->toy,toy);
    node->next = NULL; 
    return node;
}

void initList(){
    first = NULL; last = NULL;
}

int listEmpty(){
    return first == NULL && last == NULL;
}

void insertLast(int num, char *toy){
    danhsach *profile = Alink(num,toy);
    if(listEmpty()){
        first = profile; last = profile;
    }
    else{
        last->next = profile; last = profile;
    }
}

void input_A(){
    int num;
    char toy[MAX_L];
    FILE *ptr1 = fopen("A.txt","r");
    if(ptr1 == NULL) printf("Load data -> file not found\n");
    while(!feof(ptr1)){
        fscanf(ptr1,"%d %s\n",&num,&toy);
        insertLast(num,toy);
    }
    fclose(ptr1);
}

void input_toy(){
    char addtoy[MAX_L];
    for(danhsach *p = first; p != NULL; p = p->next)
        if (strcmp(p->toy,"null!") == 0){
            printf("Add toy to null!\n");scanf("%s",&addtoy);
            strcpy(p->toy,addtoy);
        }
}

void swap(danhsach *xp, danhsach *yp){// Hàm sắp xếp 
    danhsach temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Sort(){// Hàm sắp xếp Alink theo thứ tự tăng dần 
	for(danhsach* p = first; p != last; p = p->next){
        for(danhsach* p2 = p->next; p2 != NULL; p2 = p2->next){
            if(p->num > p2->num){
                swap(p, p2);// Gọi hàm
            }
        }
    }
}

void PrintList(){ //In dữ liệu
    for(danhsach *p = first; p != NULL; p = p->next)
        printf("%d  %s\n",p->num, p->toy);
}

void input_B(){
    int i = 0;
    FILE* ptr2 = fopen("B.txt","r");
    if(ptr2 == NULL) printf("Load data -> file not found\n");
    while(!feof(ptr2)){
        fscanf(ptr2,"%d %s\n",&arr[i].num,&arr[i+1].toy);
        i++;
    }
    n = i;
    fclose(ptr2);
}

void Print_arr(){
    for(int i = 0; i < n; i++){
        printf("%d  %s\n",arr[i].num,arr[i+1].toy);
    }
}

int main(){// chạy chương trình
    initList();
    while(1){
        int x;
        printf("====Nhap vao so bat ky de thuc hien chuc nang====");
        printf("\n1.Doc file A.");
        printf("\n2.Doc file B.");
        printf("\n3.Tim kiem.");
        printf("\n4.Tong hop.");
        printf("\n5.Thong ke.");
        printf("\n6.Thoat.");
        printf("\nChon menu: ");scanf("%d",&x);
        if(x == 6){
            printf("Tam biet !");
            exit(0);
        }
        else if(x == 1){
            input_A();
            PrintList();
            input_toy();
            PrintList();
            Sort();
            PrintList();
        }
        else if(x == 2){
            input_B();
            Print_arr();
        }
        else if(x == 3) printf("3\n");
        else if(x == 4) printf("4\n");
        else if(x == 5) printf("5\n");
    }
}