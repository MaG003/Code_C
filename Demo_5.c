// Đề thi C Basic_2020 Cuối kỳ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_L 256

typedef struct danhsach{
    char name[40]; // tên địa điểm
    int time;// giờ
    int mins;// phút
    struct danhsach *next;
}danhsach;

danhsach arr[MAX_L];
danhsach arr_1[MAX_L];

danhsach *first, *last;

danhsach *makeProfile(char *name, int time, int mins){//chú ý: chỉ sử dụng con trỏ với vị trí biến char
    danhsach *node = (danhsach*)malloc(sizeof(danhsach));
    strcpy(node->name,name);
    node->time = time;
    node->mins = mins;
    node->next = NULL; 
    return node;
}

void initList(){
    first = NULL; last = NULL;
}

int listEmpty(){
    return first == NULL && last == NULL;
}

void insertLast(char *name, int time, int mins){
    danhsach *profile = makeProfile(name,time,mins);
    if(listEmpty()){
        first = profile; last = profile;
    }else{
        last->next = profile; last = profile;
    }
}

void printList(){ //In dữ liệu
    for(danhsach *p = first; p != NULL; p = p->next)
        printf("%-50s%-10d%-10d\n",p->name, p->time, p->mins);
}

void load(char *filename){
    FILE *f = fopen(filename,"r");
    if(f == NULL) printf("Load data -> file not found\n");
    char c;
    char name[40];
    int time, mins;

    while(!feof(f)){
        fscanf(f,"%s",&name);
        if((c = fgetc(f)) == ' '){
            fscanf(f,"%d",&time);
            fscanf(f,"%d",&mins);
        }
        insertLast(name,time,mins);
    }
    fclose(f);
}

void processLoad(){// load dữ liệu từ file vào bộ nhớ
    initList();
    char filename[256] = "log.txt";
    // printf("Loading file: ");
    // scanf("%s",filename);
    load(filename);
}

void freeNode(){
    danhsach *p=first;
    while(p!=NULL){
        danhsach *node=p;
        p=p->next;
        free(node);
    }
}

void Search_name(){
    int count = 0;
    char name[256];
    printf("Loading name: ");scanf("%s",name);
    for(danhsach *p = first; p != NULL; p = p->next){
        if(strcmp(name,p->name)==0){
            arr[count].time = p->time;
            arr[count].mins = p->mins; 
            count++;   
        }
    }

    if(count != 0){
        printf("%d:%d",arr[0].time,arr[0].mins);
        for(int i = 1; i < count; i++){
            printf(", ");
            printf("%d:%d",arr[i].time,arr[i].mins);
        }
        printf("\n");
    }

    if(count == 0){
        printf("Ban chua toi dia diem do!\n");
    }
}

void Search_time(){
    int count_1 = 0;
    int time, mins;
    printf("time mins: ");
    scanf("%d %d", &time, &mins);

    if(0<=time && time<24 && 0<=mins && mins<60){
        // printf("%d %d\n", time, mins);
        for(danhsach *p = first; p!=NULL; p = p->next){
            if(p->time < time){
                strcpy(arr_1[count_1].name, p->name);
                count_1 ++;
            }

            if(p->time = time){
                if(p->mins < mins){
                    strcpy(arr_1[count_1].name, p->name);
                    count_1 ++;
                }
            }
        }

        if(count_1 != 0){
            printf("%s\n",arr_1[count_1 - 1].name);
        }

        if(count_1 == 0){
            printf("KHONG tim thay lich su di chuyen!\n");
        }
    }

    else{
        printf("Du lieu nhap vao khong hop le\n");
        Search_time();
    }
}

int main(){
    while(1){
        int x;
        printf("CHUONG TRINH TRUY VET COVID19\n");
        printf("1. Nap file log lich su di chuyen\n");
        printf("2. In ra lich su di chuyen\n");
        printf("3. Tim kiem lich su theo dia diem\n");
        printf("4. Tim kiem lich su theo thoi gian\n");
        printf("5. Kiem tra truy vet moi nhat\n");
        printf("6. Thoat\n");
        printf("Chon menu: ");scanf("%d",&x);
        switch(x){
            case 1:
                processLoad();
                printf("File loaded successfully!\n");
                break;

            case 2:
                printf("%-50s%-10s%-10s\n","Dia diem", "Gio", "Phut");
                printf("*******************************************************************\n");
                printList();
                break;
                
            case 3: 
                Search_name();
                break;

            case 4:
                Search_time();             
                break;

            case 5:
                printf("Thuc hien chuc nang 5\n");                
                break;

            case 6:
                printf("Tam biet !");
                freeNode();
                exit(0);

            default:
                printf("Xin moi chon lai !\n");
                break;
        }
    }
}