#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 256

int main(){
    char filename1[MAX_LEN];
    int value;
    char arr[10], str[10];
    int sum1 = 0, sum2 = 0;

    printf("Nhap ten file ban muon nhap vao :");scanf("%100s", filename1);
    printf("%s\n",filename1);

    FILE * fp = NULL;
    fp= fopen(filename1, "r");

    // Đọc ký tự đầu tiên
    arr[10] = fgetc(fp);
    value = atoi(arr);

    //  Tính tổng theo hàng dọc
    // while (fgets(filename1, 128, fp) != NULL){
    //     sum1 = sum1 + atoi(filename1);
    // }

    // sum1 = sum1 - value;
    // printf("%d\n",sum1);

    // Tính tổng theo hàng ngang
    while(fscanf(fp, "%s", str) != EOF){
        sum2 = sum2 + atoi(str);
    }
    sum2 = sum2 - value;
    printf("%d ",sum2);

    fclose(fp);
    return 0;
}