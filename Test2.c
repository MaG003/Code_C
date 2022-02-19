#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_L 256

int N,B;
int check;
int dem = 0;
char *stack[MAX_L];

typedef struct data {
    int arr[MAX_L][MAX_L];
    int xr,yr;
}data;

data str;

void input_N(){ //Nhap vào số ô theo hàng dọc
    do{
        printf("Input N (3<=N<=7):");scanf("%d",&N);
    }while(N<3 || N>7);
    check = 1;
}

void input_num(){ //Nhập vào giá trị của cấu hình (Người dùng luôn nhập các chữ số khác nhau)
    if(check != 1){
        input_N();
        input_num();
    }

    else{
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                printf("A[%d][%d]:",i,j);scanf("%d",&str.arr[i][j]);
            }
        }
    }
}

int check0(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(str.arr[i][j] == 0){
                str.xr = j;
                str.yr = i;
            }
        }
    }
}

void left(){
    if (str.xr != 0){
        str.arr[str.yr][str.xr] = str.arr[str.yr][str.xr-1];
        str.arr[str.yr][str.xr-1] = 0;
        str.xr--;
        stack[dem] = "L";
        dem++;
    }
    else{
        printf("Thao tac khong phu hop\n");
    }
}

void right(){
    if (str.xr != N-1){
        str.arr[str.yr][str.xr]=str.arr[str.yr][str.xr+1];
        str.arr[str.yr][str.xr+1] = 0;
        str.xr++;
        stack[dem] = "R";
        dem++;
    }
    else{
        printf("Thao tac khong phu hop\n");
    }
}

void down(){
    if (str.yr != N-1){
        str.arr[str.yr][str.xr]=str.arr[str.yr+1][str.xr];
        str.arr[str.yr+1][str.xr]=0;
        str.yr++;
        stack[dem] = "D";   
        dem++;
    }
    else{
        printf("Thao tac khong phu hop\n");
    }
}

void up(){
    if (str.yr != 0 ){
        str.arr[str.yr][str.xr]=str.arr[str.yr-1][str.xr];
        str.arr[str.yr-1][str.xr]=0;
        str.yr--;
        stack[dem] = "U";
        dem++;
    }
    else{
        printf("Thao tac khong phu hop\n");
    }
}

void Print(){
    printf("*******\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("*%1.0d",str.arr[i][j]);
        }
        printf("*\n");
    }
    printf("*******\n");
}

void move_1(char *cmd){
    if(strcmp(cmd,"L")==0){
        left();
        Print();
    }        
    else if(strcmp(cmd,"R")==0){
        right(); 
        Print();
    }         
    else if(strcmp(cmd,"D")==0){
        down();
        Print();  
    }        
    else if(strcmp(cmd,"U")==0){
        up();
        Print(); 
    }         
}

void move(){
    check0();
    while(1){        
        char cmd[256];       
        printf("Move: ");scanf("%s",cmd);
        if(strcmp(cmd,"Q") == 0) break;        
        else move_1(cmd);
    }    
}

void rollback(){
    printf("Nhap so buoc muon lui: ");scanf("%d",&B);
    Print();
    for(int a = dem - 1 ; a > dem - B ; a--){
        if(stack[a] == "L"){
            move_1("R");
            dem--;
        }
        else if(stack[a] == "R"){
            move_1("L");
            dem--;
        }
        else if(stack[a] == "D"){
            move_1("U");
            dem--;
        }
        else if(stack[a] == "U"){
            move_1("D");
            dem--;
        }
    }
    printf("\n");
}

int main(){// chạy chương trình
    while(1){
        int x;
        printf("====Nhap vao so bat ky de thuc hien chuc nang====");
        printf("\n1.Nhap vao gia tri N (N*N)");
        printf("\n2.Nhap gia tri vao cau hinh");
        printf("\n3.Di chuyen cac gia tri cau hinh");
        printf("\n4.Quay lai vi tri cau hinh truoc do");
        printf("\n5.In ra cau hinh hien tai");
        printf("\n6.Thoat");
        printf("\nChon menu: ");scanf("%d",&x);
        if(x == 6){
            printf("Tam biet !");
            exit(0);
        }
        else if(x == 1) input_N();
        else if(x == 2) input_num();
        else if(x == 3) move();
        else if(x == 4) rollback();
        else if(x == 5) Print();
    }
}
