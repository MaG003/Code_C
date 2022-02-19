// Sinh dữ liệu ngẫu nhiên 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int random(int minM, int maxM){
    return minM + rand() % (maxM + 1 - minM);
}

char ho[5][10]= {"Nguyen","Le","Tran","Ly","Hoang"};
char dem[6][10] = {"Van","Trung","Hieu","Cong","Tuan","Vien"};
char ten[7][10] = {"Hung","Dat","Cuong","Dung","Ngoc","An","Bao"};

int main(void){
    FILE* f = fopen("input-5.txt","w+");
    
    int n;
    printf("n = ");scanf("%d",&n);
    srand((int)time(0));

    for(int i = 0; i < n; i++){
        fprintf(f,"%s %s %s\n",ho[random(0,4)],dem[random(0,5)],ten[random(0,6)]);
        fprintf(f,"%d-%d-%d\n",random(1970,2002),random(03,12),random(01,30));
    }

    fprintf(f,"#");
    fclose(f);
}