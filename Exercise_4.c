#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

//Thuật toán sắp xếp nổi bọt
void bubleSort(int A[], int N) {  
    int swapped;  
    do{    
        swapped = 0;    
        for(int i = 1; i < N; i++){      
            if(A[i] > A[i+1]){        
                int tmp = A[i];         
                A[i] = A[i+1];        
                A[i+1] = tmp;        
                swapped = 1;      
            }    
        }  
    }while(swapped == 1); 
}

void input_1(FILE* ptr){
    int i = 0;
    while(!feof(ptr)){
            fscanf(ptr,"%d",&A[i]);
            i++;
        }
}
// Input
void input(){
    FILE* ptr = fopen("input.txt","r");
    
    if (ptr == NULL){
        random_1();
        input();
    }

    else
        input_1(ptr);

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

void time_line(){
    clock_t start, end;
    double time_use;

    //Tính thời gian thuật toán
    start = clock();
    bubleSort(A,A[0]);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    printf("bubleSort take %f seconds",time_use);
}

int main(){
    input();
    time_line();
    output();
    
    return 0;
}