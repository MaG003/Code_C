#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_L 256

int N;
int i,j;
int arr[MAX_L][MAX_L] = {'\0'};//arr[N][MAX_L]

int Input1(){
    do{
        printf("Input N: "); scanf("%d",&N);
    }while(N<0 || N>9);
}

int check(int a){
    int dem = 0;
    while(arr[a][dem] != '\0'){
        dem++;
    }
    return dem;
}

int Input2(){
    int a;
    char s[MAX_L];
    printf("Input (i,j): "); scanf("%d%d",&i,&j);
    if(i > N || j < 0){
        printf("Ban da nhap sai!\n");
    }
    // if(){}
    else{
        int inf1 = check(i); 
        arr[i][inf1] = j;
        for(a = 0; a <= inf1; a++)
            printf("%d ", arr[i][a]);
        printf("\n");
        Input2();
    }
}

int Print(){
    int a,r;
    do{
        printf("Nhap i : "); scanf("%d",&r);
    }while(r>N);

    int inf2 = check(r);
    for(a = 0; a < inf2; a++){
        printf("%d -> ", arr[r][a]);
    }
    printf("NULL");
    printf("\n");
}

int main(){// chạy chương trình
    while(1){
        int x;
        printf("====Nhap vao so bat ky de thuc hien chuc nang====");
        printf("\n1.Nhap vao gia tri N (so luong cac queue)");
        printf("\n2.Nhap (i, j) de chen j vao queue i (i < N)");
        printf("\n3.Hien thi cac phan tu trong queue i");
        printf("\n4.Kiem tra va xoa phan tu trung lap (neu co)");
        printf("\n5.Thoat");
        printf("\nChon menu: ");scanf("%d",&x);
        if(x == 5){
            printf("Tam biet !");
            exit(0);
        }
        else if(x == 1) Input1();
        else if(x == 2) Input2();
        else if(x == 3) Print();
        else if(x == 4) printf("4\n");
    }
}
