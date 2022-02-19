#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int A[100];
int n;

int random(int minM, int maxM){
    return minM + rand() % (maxM + 1 - minM);
}

//Thuật toán sinh số ngẫu nhiên
void random_1(){
    int n, m, M;
    printf("n = ");scanf("%d",&n);
    printf("m = ");scanf("%d",&m);
    printf("M = ");scanf("%d",&M);
    FILE* f = fopen("input.txt","w+");
    fprintf(f,"%d\n",n);
    srand((int)time(0));
    int r;
    for(int i = 0; i < n; ++i){
        r = random(m,M);
        fprintf(f,"%d ",r);
    } 
    fclose(f);
}

//Thuật toán sắp xếp chọn 
void selectionSort(int A[], int N){     
    for(int k = 1; k <= N; k++){    
        int min = k;   
        for(int j = k+1; j <= N; j++){      
            if(A[min] > A[j]) 
                min = j;    
        }    
        int tmp = A[min];
        A[min] = A[k];     
        A[k] = tmp;  
    }
}

// Input
void input(){
    int i = 0;
    FILE* ptr = fopen("input.txt","r");
    
    if (ptr == NULL){
        random_1();
        input();
    }

    else
        while(!feof(ptr)){
            fscanf(ptr,"%d",&A[i]);
            i++;
        }

    fclose(ptr);
}

//Output
void output(){
    FILE* ptr = fopen("output.txt","w+");
    for(int i = 1; i <= A[0]; i++){
        fprintf(ptr,"%d ",A[i]);
    }
    fclose(ptr);
}

int main(){
    input();
    selectionSort(A,A[0]);
    output();
    return 0;
}






