// Viết một hàm sao cho nhận vào một string và hai ký tự.
// Hàm đó duyệt toàn bộ phần tử của xâu string và thay thế những ký tự thứ nhất bằng ký tự thứ hai.

#include<stdio.h>
#include<string.h>
 
void thaythe(char *str, char c, char d){
    gets(str);
    c=getchar();
    d=getchar();
    char *p = str;
    while(*p != '\0'){
        if (*p == c){
            *p = d;
        }
        p++;
    }
}

int main(){
    char str,c,d;
    thaythe(&str, c, d);
    printf("%s\n", str);
    getch();
}
