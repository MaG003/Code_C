// Sắp xếp trộn
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int n;
typedef struct{
    char ho[100];
    char dem[100];
    char ten[100];
    int nam;
    int thang;
    int ngay;
}danhsach;

danhsach A[100];//Dùng mảng cấu trúc để lưu dữ liệu
danhsach TA[100];

void input(){
    int i = 0;
    FILE* ptr1 = fopen("input-5.txt","r");
    while(!feof(ptr1)){
        fscanf(ptr1,"%s %s %s\n",&A[i].ho,&A[i].dem,&A[i].ten);
        if(strcmp(A[i].ho,"#") == 0) break;
        else fscanf(ptr1,"%d-%d-%d\n",&A[i].nam,&A[i].thang,&A[i].ngay);
        i++;
    }//Lưu vào mảng cấu trúc theo các biến trên theo từng chu kì
    n = i-1;
    fclose(ptr1);
}

void output(){
    FILE* ptr2 = fopen("output-6.txt","w+");
    for(int i = 0; i <= n; i++){
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

void merge(danhsach A[], int L, int R, int M){
    int i = L, j = M + 1;
    int a;
    for(int k = L; k <= R; k++){
        if(i > M){ TA[k] = A[j]; j++; }
        else if(j > R){ TA[k] = A[i]; i++; }
        else{
            a = sosanh(i,j);                //Kiểm tra giá trị xem thỏa mãn chưa
            if(a < 0){ TA[k] = A[i]; i++; }  // Nếu đọc thì chỗ này có vẻ hơi sai sai
            else{ TA[k] = A[j]; j++; }   //Nhưng thật ra nó không sai đâu (google search là biết ngay)
        }
    }
    for(int k = L; k <= R; k++){ A[k] = TA[k]; }
}

void mergeSort(danhsach A[],int L, int R){
    if(L < R){
        for(int k = L; k <= R; k++){
            int M = (L+R)/2;     //Này là phần chia
            mergeSort(A,L,M);    // 2 cái này là phần trị
            mergeSort(A,M+1,R);
            merge(A,L,R,M);    //Xáo trộn tổ hợp 2 mảng giá trị
        }
    }
}

int main(){
    input();
    mergeSort(A,0,n);    //Mảng bắt đầu từ số chỉ 0
    output(n);
    return 0;
}