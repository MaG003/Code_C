#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    char anh[25];
    char viet[25];
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
Node* root;
Node* makeNode(char* anh, char* viet){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->anh,anh);
    strcpy(p->viet,viet);
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}
Node* find(Node* r, char* anh){
    if(r == NULL) return NULL;
    if(strcmp(r->anh,anh) == 0) return r;
    Node* p = find(r->leftChild,anh);
    if(p!=NULL){return p;}
    return find(r->rightChild,anh);
}
Node* insert(Node* r,char* anh, char* viet){
    if(r == NULL) return makeNode(anh,viet);
    int c = strcmp(r->anh,anh);
    if(c > 0){
        r->leftChild = insert(r->leftChild,anh,viet);
    }
    else if(c < 0){
        r->rightChild = insert(r->rightChild,anh,viet);
    }
    return r;
}
void print(Node* r){
    if(r == NULL) return ;
    printf("\n%s\t%s",r->anh,r->viet);
    print(r->leftChild);
    print(r->rightChild);
    return;
}

void load(){
    FILE* ptr = fopen("dic.txt","r");
    char anh[25], viet[25];
    while(!feof(ptr)){
        fscanf(ptr,"%s%s\n",anh,viet);
        root = insert(root,anh,viet);
    }
    fclose(ptr);
    print(root);
    return ;
}

void themSua(){
    char cmd[25];
    char str[25];
    char viet[25];
    printf("\nNhap vao tieng anh: ");
    scanf("%s",str);
    Node* p = find(root,str);
    if(p != NULL){
        printf("\nTu nay da co trong tu dien ban co muon sua nghia khong? (y/n): ");
        scanf("%s",cmd);
        if(strcmp(cmd,"y") == 0){
            printf("Nghia tieng viet duoc thay the cho %s: ",str);
            scanf("%s",viet);
            strcpy(p->viet,viet);
        }
    }
    else{
        printf("\nTu da nhap khong co trong tu dien!");
        printf("\nVui long nhap nghia de them vao tu dien: ");
        scanf("%s",viet);
        root = insert(root,str,viet);
    }
}
void cauA(char* str){
    printf("\n%s",str);
    char* p = strtok(str," ");
    printf("\n%s",p);
    while(p != NULL){
        p = strtok(NULL," ");
        printf("\n%s",p);
    }
    return;
}
void cauB(char* str){
    char* p = strtok(str," ");
    Node* v = find(root,p);
    if(v != NULL){
        printf("\n%s\t%s",p,v->viet);
    }
    else{printf("\n%s\t%s",p,"<thieu tu>");}
    
    while(p != NULL){
        p = strtok(NULL," ");
        if(p != NULL){
            Node* v = find(root,p);
            if(v != NULL){
                printf("\n%s\t%s",p,v->viet);
            }
            else{printf("\n%s\t%s",p,"<thieu tu>");}
        }
    }
    return;

}
void dichcau(){
    char string[30];
    printf("\nNhap cau can dich: ");
    fflush(stdin);
    gets(string);
    cauA(strlwr(string));
    cauB(strlwr(string));
    return;
}

void freeRoot(Node* r){
    if(r == NULL) return ;
    freeRoot(r->leftChild); 
    freeRoot(r->rightChild);
    free(r);
    r = NULL;
}

int main(){
    int key;
    while(1){
        printf("\n\tMENU\n1.Nap tu dien\n2.Noi dung tu dien\n3.Them/Sua tu dien\n4.Dich cau Anh - Viet\n5.Thoat\nYourchoice: ");
        scanf("%d",&key);
        switch(key){
            case 1: load(); break;
            case 2: print(root); break;
            case 3: themSua(); break;
            case 4: dichcau(); break;
            case 5: freeRoot(root); exit(1);
        }
    }
    return 0;
}