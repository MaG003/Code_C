#include <stdio.h>
typedef struct person{
   int age;
   float weight;
}person;

int main(){
    person *personPtr, person1; //Khai báo con trỏ personPtr và biến person1
    personPtr = &person1;   //Gán giá trị con trỏ bằng địa chỉ biến person1
    printf("Enter age: ");scanf("%d", &personPtr->age);//Con trỏ trỏ đến vị trí age của biến person1 và gán vào
    printf("Enter weight: ");scanf("%f", &personPtr->weight);//Con trỏ trỏ đến vị trí weight của biến person1 và gán vào
    printf("Displaying:\n");
    printf("Age: %d\n", personPtr->age);//personPtr -> age có kết quả giống (*personPtr).age
    printf("weight: %f", personPtr->weight);//personPtr -> weight có kết quả giống (*personPtr).weight
    return 0;
}