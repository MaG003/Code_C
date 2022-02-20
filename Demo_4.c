// Load dữ liệu sử dụng danh sách liên kết đơn
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
        printf("%s %d %d\n",p->name, p->time, p->mins);
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
    char filename[256];
    printf("Loading file: ");
    scanf("%s",filename);
    load(filename);
}

int main(){
    processLoad();
    printList();
}