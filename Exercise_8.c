#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n;

typedef struct{
    char ho[100];
    char dem[100];
    char ten[100];
    int nam;
    int thang;
    int ngay;
}danhsach;

danhsach A[100];

void input(){
    int i = 1;
    FILE* ptr1 = fopen("input-5.txt","r");
    while(!feof(ptr1)){
        fscanf(ptr1,"%s %s %s\n",A[i].ho,A[i].dem,A[i].ten);
        if(strcmp(A[i].ho,"#") == 0) break;
        else fscanf(ptr1,"%d-%d-%d\n",&A[i].nam,&A[i].thang,&A[i].ngay);
        i++;
    }
    n = i-1;
    fclose(ptr1);
}

void output(){
    FILE* ptr2 = fopen("output-8.txt","w+");
    for(int i = 1; i <= n; i++){
        fprintf(ptr2,"%s %s %s\n",A[i].ho,A[i].dem,A[i].ten);
        fprintf(ptr2,"%02d-%02d-%02d\n",A[i].nam,A[i].thang,A[i].ngay);
    }          
    fprintf(ptr2,"#");
    fclose(ptr2);
}

int sosanh(int i, int j){
    int r = strcmp(A[i].ten,A[j].ten);     
    if( r != 0) return r;                  
    int m = strcmp(A[i].dem,A[j].dem);     
    if(m != 0) return m;                   
    int d = strcmp(A[i].ho,A[j].ho);       
    if(d != 0) return d;
    if(A[i].nam < A[j].nam) return -1;
    if(A[i].nam > A[j].nam) return 1;
    if(A[i].thang < A[j].thang) return -1;
    if(A[i].thang > A[j].thang) return 1;      
    if(A[i].ngay < A[j].ngay) return -1;      
    if(A[i].ngay > A[j].ngay) return 1;
    return 0;
}

void swap(danhsach *a,danhsach *b){
	danhsach tmp=*a;
	*a = *b;
	*b = tmp;
}

void heapify(int i, int N) {
    int L = 2*i;
    int R = 2*i+1;
    int max = i;
    int a = sosanh(i,L);
    if(L <= N && a < 0)
        max = L;
    int b = sosanh(max,R);
    if(R <= N && b < 0)
        max = R;
    if(max != i){
        swap(&A[i], &A[max]);
        heapify(max,N);
    } 
}

void buildHeap(danhsach A[], int N) {
    for(int i = N/2; i >= 1; i--)
        heapify(i,N);
}

void heapSort(danhsach A[], int N) {
  buildHeap(A,N);
    for(int i = N; i > 1; i--) {
        swap(&A[1], &A[i]);
        heapify(1, i-1);
    }
}

int main(){
    input();
    heapSort(A,n);    
    output(n);
    return 0;
}   