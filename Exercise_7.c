//Thuật toán xắp xếp nhanh 
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
    int i = 0;
    FILE* ptr1 = fopen("input-5.txt","r");
    while(!feof(ptr1)){
        fscanf(ptr1,"%s %s %s\n",&A[i].ho,&A[i].dem,&A[i].ten);
        if(strcmp(A[i].ho,"#") == 0) break;
        else fscanf(ptr1,"%d-%d-%d\n",&A[i].nam,&A[i].thang,&A[i].ngay);
        i++;
    }
    n = i-1;
    fclose(ptr1);
}

void output(){
    FILE* ptr2 = fopen("output-7.txt","w+");
    for(int i = 0; i <= n; i++){
        fprintf(ptr2,"%s %s %s\n",A[i].ho,A[i].dem,A[i].ten);
        fprintf(ptr2,"%02d-%02d-%02d\n",A[i].nam,A[i].thang,A[i].ngay);
    }
    fprintf(ptr2,"#");
    fclose(ptr2);
}

int sosanh(int i, danhsach j){
    int r = strcmp(A[i].ten,j.ten);
    if( r != 0) return r;
    int m = strcmp(A[i].dem,j.dem);
    if(m != 0) return m;
    int d = strcmp(A[i].ho,j.ho);
    if(d != 0) return d;
    if(A[i].nam < j.nam) return -1;
    if(A[i].nam > j.nam) return 1;
    if(A[i].thang < j.thang) return -1;
    if(A[i].thang > j.thang) return 1;
    if(A[i].ngay < j.ngay) return -1;
    if(A[i].ngay < j.ngay) return 1;
    return 0;
}

void swap(danhsach *a,danhsach *b){
    danhsach tmp= *a;
    *a = *b;
    *b = tmp;
}

int partition(danhsach A[], int L, int R, int indexPivot){
    int a;
    danhsach pivot = A[indexPivot];
    swap(&A[indexPivot], &A[R]);
    int storeIndex = L;
    for(int i = L; i <= R-1; i++){
        a = sosanh(i,pivot);
        if(a < 0){
            swap(&A[storeIndex], &A[i]);
            storeIndex++;
        }
    }
    swap(&A[storeIndex], &A[R]);
    return storeIndex;
}
 
/* Hàm thực hiện giải thuật quick sort */
void quickSort(danhsach A[], int L, int R){
    if(L < R){
        int index = (L + R)/2;
        index = partition(A, L, R, index);
        if(L < index)
            quickSort(A, L, index-1);
        if(index < R)
            quickSort(A, index+1, R);
    }
}

int main(){
    input();
    quickSort(A,0,n);    //Mảng bắt đầu từ số chỉ 0
    output(n);
    return 0;
}