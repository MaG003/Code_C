//Menu
#include <stdio.h>
#include <stdlib.h>

int main(){
    while(1){
        int x;
        printf("Ban hay nhap chuc nang can thuc hien\n");
        printf("1. Thuc hien chuc nang 1\n");
        printf("2. Thuc hien chuc nang 2\n");
        printf("3. Thuc hien chuc nang 3\n");
        printf("4. Thuc hien chuc nang 4\n");
        printf("5. Thoat\n");
        printf("Chon menu: ");scanf("%d",&x);
        switch(x){
            case 1:
                printf("Thuc hien chuc nang 1\n");
                break;

            case 2:
                printf("Thuc hien chuc nang 2\n");
                break;
                
            case 3: 
                printf("Thuc hien chuc nang 3\n");
                break;

            case 4:
                printf("Thuc hien chuc nang 4\n");                
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