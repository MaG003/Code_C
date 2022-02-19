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

//Thuật toán sắp xếp chèn
void insertionSort(int A[], int N) {
    for(int k = 2; k <= N; k++){
        int last = A[k];
        int j = k;
        while(j > 1 && A[j-1] > last){
            A[j] = A[j-1];
            j--;
        }
        A[j] = last;
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
    insertionSort(A,A[0]);
    output();
    return 0;
}