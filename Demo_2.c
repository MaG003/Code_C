//Load file log.txt
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 256

typedef struct danhsach{
    char name[40];
    int time;
    int mins;
}danhsach;

int count = 0;
danhsach ds[MAX_LEN];

void Load(){
    FILE *fp = fopen("log.txt", "r");
    char c;
    char name[40];
    int time, mins;

    while(!feof(fp)){
        fscanf(fp,"%s",&name);
        strcpy(ds[count].name,name);

        if((c = fgetc(fp)) == ' '){
            fscanf(fp,"%d",&time);
            ds[count].time = time;
            fscanf(fp,"%d",&mins);
            ds[count].mins = mins;
            count++;
        }
        else{
            count++;
            continue;
        }
    }
}

void Print(){
    int i = 0;
    printf("*******\n");
    for(i = 0; i<count; i++){
        printf("%s  %d  %d\n", ds[i].name, ds[i].time, ds[i].mins);
    }
    printf("*******\n");
}

int main(){
    Load();
    Print();
}