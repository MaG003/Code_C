/*
• Hồ sơ sinh viên bao gồm:
    • name: tên của sinh viên
    • email: địa chỉ email của sinh viên
• Viết chương trình trong chế độ tương tác dòng lệnh thực hiện các 
nghiệp vụ cơ bản trong quản lý hồ sơ sinh viên
    • Đọc dữ liệu từ file văn bản vào danh sách
    • In danh sách sinh viên
    • Thêm 1 hồ sơ vào cuối danh sách
    • Xóa 1 hồ sơ
    • Tìm kiếm hồ sơ
    • Lưu hồ sơ vào file văn bản
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_L 256

typedef struct Profile{
    char name[MAX_L]; // tên sinh viên
    char email[MAX_L];// email sinh viên
    struct Profile *next;
}Profile;

Profile *first, *last;

Profile *makeProfile(char *name, char *email){
    Profile *node = (Profile*)malloc(sizeof(Profile));
    strcpy(node->name,name);
    strcpy(node->email,email);
    node->next = NULL; 
    return node;
}

void initList(){
    first = NULL; last = NULL;
}

int listEmpty(){
    return first == NULL && last == NULL;
}

void insertLast(char *name, char *email){
    Profile *profile = makeProfile(name,email);
    if(listEmpty()){
        first = profile; last = profile;
    }else{
        last->next = profile; last = profile;
    }
}

void printList(){ //In dữ liệu
    for(Profile *p = first; p != NULL; p = p->next)
        printf("%s, %s\n",p->name, p->email);
}

Profile *removeProfile(Profile *f, char *name){
    if(listEmpty()) return NULL;
    if(strcmp(f->name,name) == 0){
        Profile *tmp = f->next;
        free(f);
        if(tmp == NULL) last = NULL;
            return tmp;
    }else{
        f->next = removeProfile(f->next,name);
        return f;
    }
}

void load(char *filename){
    FILE *f = fopen(filename,"r");
    if(f == NULL) printf("Load data -> file not found\n");
    while(!feof(f)){
        char name[256], email[256];
        fscanf(f,"%s%s",name, email);
        insertLast(name,email);
    }
    fclose(f);
}
    
void processFind(){//Tìm dữ liệu
    char name[256];
    scanf("%s",name);
    Profile *profile = NULL;
    for(Profile *p = first; p != NULL; p = p->next){
        if(strcmp(p->name,name)==0){
            profile = p; break;
        }
    }
    if(profile == NULL){
        printf("NOT FOUND profile %s\n",name);
    }else{
        printf("FOUND profile %s, %s\n",profile->name,profile->email);
    }
}

void processLoad(){// load dữ liệu từ file vào bộ nhớ
    char filename[256];
    scanf("%s",filename);
    load(filename);
}

void processStore(){// lưu dữ liệu vào 1 file văn bản
    char filename[256];
    scanf("%s",filename);
    FILE *f = fopen(filename,"w");
    for(Profile *p = first; p != NULL; p = p->next){
        fprintf(f,"%s %s",p->name,p->email);
        if(p->next != NULL) fprintf(f,"\n");
    }
    fclose(f);
}

void processInsert(){//Chèn hồ sơ vào cuối danh sách
    char name[256], email[256];
    scanf("%s%s",name,email);
    insertLast(name,email);
}

void processRemove(){//Xóa hồ sơ khỏi danh sách
    char name[256];
    scanf("%s",name);
    first = removeProfile(first,name);  
}

int main(){// chạy chương trình 
    initList();
    while(1){
        printf("Enter command: ");
        char cmd[256];
        scanf("%s",cmd);
        if(strcmp(cmd,"Quit")==0) break;
        else if(strcmp(cmd,"Load")==0) processLoad();//đọc 1 file nào đó
        else if(strcmp(cmd,"Print")==0) printList();//in ra danh sách dữ liệu
        else if(strcmp(cmd,"Find")==0) processFind();//tìm kiếm
        else if(strcmp(cmd,"Insert")==0) processInsert();//nhập vào thêm 1 hồ sơ vào cuối danh sách
        else if(strcmp(cmd,"Remove")==0) processRemove();//xóa 1 hồ sơ khỏi danh sách 
        else if(strcmp(cmd,"Store")==0) processStore();//tạo ra 1 file dữ liệu
    }
}