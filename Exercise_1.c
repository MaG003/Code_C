// Chương trình ramdom các số ngãu nhiên
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int minM, int maxM){
    return minM + rand() % (maxM + 1 - minM);
}
 
int main(){
    FILE* f = fopen("input.txt","w+");
    int n, m, M;
    printf("n = ");scanf("%d",&n);
    printf("m = ");scanf("%d",&m);
    printf("M = ");scanf("%d",&M);
    fprintf(f,"%d\n",n);
    srand((int)time(0));
    int r;
    for(int i = 0; i < n; i++){
        r = random(m,M);
        printf("%d ",r);
        fprintf(f,"%d ",r);
    } 
    fclose(f);    
}   