//Load file X.txt
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 256

typedef struct danhsach{
    int arr1;
    int arr2;
}danhsach;

int count = 0;
danhsach strX[MAX_LEN];

void Load(){
    FILE *fp = fopen("X.txt", "r");
    char c;
    int arr1, arr2;

    while(!feof(fp)){
        fscanf(fp,"%d",&arr1);
        strX[count].arr1 = arr1;

        if((c = fgetc(fp)) == '\t' || c == ' '){
            // if((c = fgetc(fp)) == '\n'){
            //     count++;
            //     break;
            // }
            fscanf(fp,"%d",&arr2);
            strX[count].arr2 = arr2;
            count++;

            while((c = fgetc(fp)) == ','){
                fscanf(fp,"%d",&arr2);
                strX[count].arr1 = arr1;
                strX[count].arr2 = arr2;
                count++;
            }
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
        printf("%1.0d    %1.0d\n", strX[i].arr1, strX[i].arr2);
    }
    printf("*******\n");
}

int main(){
    Load();
    Print();
}