#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 256

typedef struct danhsach{
    int arr1[MAX_LEN];
    int arr2[MAX_LEN];
}danhsach;

int N = 0;
danhsach strX;
danhsach strY;

// void load(){
//     int i = 0;
//     FILE *ptr1 = fopen("X.txt", "r");
//     if(ptr1 == NULL){
//         printf("Error: Could not open");
//     }
//     fscanf(ptr1, "%d", &strX.arr1[i]);
//     i++;
//     while(!feof(ptr1)){
//         fscanf(ptr1, "%d %d", &strX.arr1[i], &strX.arr2[i]);
//         i++;
//     }
//     N = i;
//     fclose(ptr1);
// }

// void Print(){
//     int i = 0;
//     printf("*******\n");
//     printf("%d\n", strX.arr1[i]);
//     for(i = 1;i<N;i++){
//         printf("%d    %d\n", strX.arr1[i], strX.arr2[i]);
//     }
//     printf("*******\n");
// }

int main(){
    while(1){
        int x,city;
        char name[MAX_LEN];
        printf("Ban hay nhap chuc nang can thuc hien\n");
        printf("1. Xac dinh so luong cac tuyen duong bay cua hang\n");
        printf("2. Xoa di cac tuyen duong bay cua mot hang\n");
        printf("3. Them cac tuyen duong bay cua mot hang\n");
        printf("4. Tinh toan chi phi di lai\n");
        printf("5. Thoat\n");
        printf("Chon menu: ");scanf("%d",&x);
        switch(x){
            
            case 1:
                printf("Nhap ten: "); scanf("%s",&name);
                if(strcmp(name,"X") == 0 || strcmp(name,"Y") == 0){
                    // load();
                    // Print();
                    printf("in ra so tuyen duong hang %s\n",name);
                }
                break;

            case 2:
                printf("Nhap ten hang muon xoa tuyen duong: "); scanf("%s",&name);
                printf("Nhap ten thanh pho muon dieu chinh: "); scanf("%d",&city);
                break;
                
            case 3: 
                printf("Nhap ten hang muon them tuyen duong: "); scanf("%s",&name);
                printf("Nhap ten thanh pho muon dieu chinh: "); scanf("%d",&city);
                break;

            case 4:
                printf("Nhap ten hang muon di: "); scanf("%s",&name);
                break;

            case 5:
                printf("Tam biet !");
                exit(0);

            default:
                printf("Xin moi chon lai !\n");
                break;
        }
    }
}