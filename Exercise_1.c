#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 256

typedef struct Node{
    char name[256];
    struct Node* leftMostChild;
    struct Node* rightSibling;
}Node;

Node* root;

Node* makeNode(char* name){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,name);
    p-> leftMostChild = NULL; 
    p-> rightSibling = NULL;
    return p;
}

Node* find(Node* r, char* name){
    if(r == NULL) 
        return NULL;
    if(strcmp(r->name,name) == 0) 
        return r;

    Node* p = r->leftMostChild;

    while(p != NULL){
        Node* q = find(p,name);
        if(q != NULL) 
            return q;
        p = p->rightSibling;
    }
}

Node* addLast(Node* p, char*name){
    if(p == NULL) 
        return makeNode(name);

    p->rightSibling = addLast(p->rightSibling, name);

    return p;
}

void addChild(char* name, char* child){
    Node* r = find(root,name);

    if(r == NULL) 
        return;

    r->leftMostChild = addLast(r->leftMostChild,child);
}

void printTree(Node* r){
    if(r == NULL) 
        return;
    printf("%s: ",r->name);
    Node* p = r->leftMostChild;

    while(p != NULL){
        printf("%s ",p->name);
        p = p->rightSibling;
    }

    printf("\n");
    p = r->leftMostChild;

    while(p != NULL){
        printTree(p);
        p = p->rightSibling;
    }
}

void printTreeF(Node* r, FILE* f){
    if(r == NULL) 
        return;
    fprintf(f,"%s ",r->name);
    Node* p = r->leftMostChild;

    while(p != NULL){
        fprintf(f,"%s ",p->name);
        p = p->rightSibling;
    }

    fprintf(f," $\n");
    p = r->leftMostChild;

    while(p != NULL){
        printTreeF(p,f);
        p = p->rightSibling;
    }
}

void processFind(){
    char name[256]; scanf("%s",name);
    Node* p = find(root,name);
    if(p == NULL) 
        printf("Not Found %s\n",name);
    else 
        printf("Found %s\n",name);
}

void processFindChildren(){
    char name[256]; 
    scanf("%s",name);
    Node* p = find(root,name);
    if(p == NULL) 
        printf("Not Found %s\n",name);
    else{
        printf("Found %s with children: ",name);
        Node* q = p->leftMostChild;
        while(q != NULL){
            printf("%s ",q->name); q = q->rightSibling;
        }
    }
    printf("\n");
}

int height(Node* p){
    if(p == NULL) 
        return 0;

    int maxH = 0;
    Node* q = p->leftMostChild;

    while(q != NULL){
        int h = height(q);
        maxH = maxH < h ? h : maxH;
        q = q->rightSibling;
    }
    return maxH + 1;
}

void processHeight(){
    char name[256];
    scanf("%s",name);

    Node* p = find(root,name);

    if(p == NULL) 
        printf("Not Found %s\n",name);
    else{
        printf("Found %s having height = %d\n",name,height(p));
    }
}

int count(Node* r){
    if(r == NULL) 
        return 0;
    int cnt = 1;
    Node* q = r->leftMostChild;

    while(q != NULL){
        cnt += count(q);
        q = q->rightSibling;
    }
    return cnt;
}

void processCount(){
    printf("Number of members is %d\n",count(root));
}

void processStore(){
    char filename[256];
    scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    printTreeF(root,f);
    fprintf(f,"$$");
    fclose(f);
}

void freeTree(Node* r){
    if(r == NULL) 
        return;

    Node* p = r->leftMostChild;

    while(p != NULL){
        Node* sp = p->rightSibling;
        freeTree(p);
        p = sp;
    }

    printf("free node %s\n",r->name); 
    free(r);
    r = NULL;
}

// Truyền file
void load(char *filename){
    char name[MAX_LEN];  
    char str[MAX_LEN];
    char *p;
    FILE *f = fopen(filename,"r");
    fscanf(f,"%s",&name);
    rewind(f);
    root = makeNode(name);
    if(f == NULL) printf("Load data -> file not found\n");
    else{
        while(!feof(f)){
            fgets(str, MAX_LEN, f);
            if(strcmp(str,"$$") !=0){
                p = strtok(str," $\n");
                strcpy(name,p);
                while(p != NULL){
                    p = strtok(NULL," $\n");
                    if(p != NULL){
                        addChild(name,p);
                    }
                }
            }
        }
    }
    fclose(f);
}

void processLoad(){
    char filename[256];
    scanf("%s",filename);
    load(filename);
}

// In file
void processPrint(){
    printTree(root);
}   

void processAddChild(){
    char name[MAX_LEN];
    char child[MAX_LEN];
    do{
        printf("Father: ");scanf("%s",&name);
        printf("Child: ");scanf("%s",&child);
    }
    while(strcmp(name,child)==0);
    addChild(name,child);
}

void main(){
    while(1){
        char cmd[256];
        printf("Enter command: "); scanf("%s",cmd);
        if(strcmp(cmd,"Quit") == 0) break;
        else if(strcmp(cmd,"Load")==0) processLoad();//Load file
        else if(strcmp(cmd,"Print")==0) processPrint();// In file
        else if(strcmp(cmd,"Find")==0) processFind();// Tìm kiếm nút
        else if(strcmp(cmd,"FindChildren")==0) processFindChildren();//Tìm kiếm nút con
        else if(strcmp(cmd,"Height")==0) processHeight();//Chiều dài của cây(max)
        else if(strcmp(cmd,"Count")==0) processCount();//Số phần tử 
        else if(strcmp(cmd,"AddChild")==0) processAddChild();// Thêm 1 node con vào node đã biết
        else if(strcmp(cmd,"Store")==0) processStore();//Xuát file
    }
    freeTree(root); 
}