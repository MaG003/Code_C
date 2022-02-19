//Ví dụ cấp phát bộ nhớ động 

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n, *p;
    printf("How many numbers do you want to enter?\n");scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));     //Tương đương tạo 1 mảng có con trỏ là p
    if (p == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    /* Nhập các số nguyên */
    printf("Nhap cac so nguyen: ");
    for(i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }
    
    /* Hiển thị chúng theo chiều ngược lại */
    printf("Hien thi chung theo chieu nguoc lai: ");
    for (i = n - 1; i >= 0; --i){
        printf("%d ",p[i]);
    }

    free(p); /* Giải phóng bộ nhớ */
    return 0;
}
