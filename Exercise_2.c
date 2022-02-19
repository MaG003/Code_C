#include <stdio.h>
#include <stdlib.h>

int N;
int C,R;

typedef struct Car{
    char name[256]; //Biển số
    int year;       //Năm sản xuất
    char brand[256];//Nhãn hiệu xe
}Car;

//Stack
// typedef struct Node{
//     char c;
//     struct Node* next;
// }Node;
// Node* top;

// Node* makeNode(char x){
//     Node* p = (Node*)malloc(sizeof(Node));
//     p->c = x; p->next = NULL;
//     return p;
// }

// void initStack(){
//     top = NULL;
// }

// int stackEmpty(){
//     return top == NULL;
// }

// void push(char x){
//     Node* p = makeNode(x);
//     p->next = top; top = p;
// }

// char pop(){
//     if(stackEmpty()) 
//         return ' ';
    
//     char x = top->c;
//     Node* tmp = top; top = top->next; free(tmp);
//     return x;
// }
//Stack


int Input_number(){
    do{
        printf("Nhap so o dau xe (N< 100) :"); scanf("%d",&N);
        printf("Nhap so cot :"); scanf("%d",&C);
    }while(N%C!=0);

    printf("So o dau xe : %d\n",N);
    printf("So hang dau xe : %d\n",N/C);
    printf("So cot dau xe : %d\n",C);   

}


// int R=N/C;
//     int i,j;
//     if(car_num<=R){i=0; j=R-car_num;}
//     if(car_num>R){i=car_num/R;j=R-(car_num%R)-1;}
//         printf("\nCar%d",car_num++);
//         printf("\nName, Year, Brand: ");
//         scanf("%s%d%s",&listcar[i][j].name,&listcar[i][j].year,&listcar[i][j].brand);
//         for(int i=0;i<R;i++){
//             for(int j=0;j<C;j++){
//                 if(listcar[i][j].name!=NULL){
//                     printf("X");}
//                     else printf("_");
//                 }
//                 printf("\n");
//             }
//     if(car_num>N)printf("\nAll site");
//     return 0;

Car car[100][100];

int Input_car(){
    for(int i = 0; i < N; i++){
        printf("Input name car %d :",i+1);scanf("%s",&car[i][i].name);
        printf("Input year car %d :",i+1);scanf("%s",&car[i][i].year);
        printf("Input brand car %d :",i+1);scanf("%s",&car[i][i].brand);
    }
} 

int menu(){
    int x;
    printf("====Program for management car parking====");
    printf("\n1.Numbers of Parking lot & columns:");
    printf("\n2.Insert new car:");
    printf("\n3.Search:");
    printf("\n4.Remove a car:");
    printf("\n5.Quit");
    printf("\nChon menu: ");scanf("%d",&x);
    switch(x){
        case 1:
            Input_number();
            menu();
            break;
        case 2:
            Input_car();
            menu();
            break;
        case 3:
            menu();
            break;
        case 4:
            menu();
            break;
        case 5:
            printf("Tam biet !");
            exit(0);
        default:
            printf("Xin moi chon lai !\n");
            menu();
            break;
    }
} 

int main(){
    menu();
    return 0;
}