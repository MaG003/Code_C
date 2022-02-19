/*
    Viết một chương trình C như sau:
a) Hiện ra một menu trong đó có các dòng sau:
1. Nhap vao so N (4 <= N <= 10)
2. Nhap vao mang N phan tu la cac diem co toa do (x, y)
3. Kiem tra hai diem lien tiep co tao thanh canh song song truc toa do khong?
4. Thoat
(2 điểm)
b) Viết hàm cài đặt chức năng (1) sao cho người dùng nhập được đúng giá trị của N thì thôi. Nếu nhập sai thì yêu cầu nhập lại. 
Hàm này nên có tên là void getN(int *N);
(1 điểm)
c) Viết hàm cài đặt chức năng (2) với prototype của hàm như sau:
void getArray(float X[ ], float Y[ ], int N); 
(1 điểm)
d) Viết vòng lặp while cho phép người dùng nhập vào các tùy chọn để thực hiện các chức năng của menu trên. 
Nếu người dùng nhấn 2 thì cần kiểm tra điều kiện sau:
Chức năng 2 chỉ thực hiện được nếu chức năng 1 đã được thực hiện. Vậy trong trường hợp chưa bao giờ thực hiện chức năng 1 mà đã thực thi chức năng 2 thì CT phải in ra câu “Hay thuc hien chuc nang 1” và yêu cầu người dùng nhập lại
Nếu chức năng 1 đã được thực thi (tức N đã được gán) thì gọi hàm đã làm ở câu (c) (2 điểm)
e) Cũng tương tự như trên nhưng kiểm tra xem:
nếu người dùng nhấn 3 thì chức năng (2) và chức năng (1) cần được thực hiện từ trước. Nếu hai chức năng đó chưa đươc thực hiện bao giờ thì phải in ra câu “Hay thuc hien chuc nang 1 va 2” rồi yêu cầu người dùng nhập lại
Còn nếu chức năng (2) và (1) đã được thực hiện rồi thì chức năng (3) hiện tại chỉ cần in ra “3 is done” (2 điểm)
f) Cài đặt hàm int checkArray(float X[ ], float Y[ ], int N);
Kiểm tra xem hai điểm liên tiếp có tọa độ (X[i], Y[i]) và (X[i+1], Y[i+1]) có tạo ra cạnh song song với trục tọa độ hay không? Nếu có thì trả về 1, ngược lại trả về 0 (1 điểm)
g) Cài đặt chức năng thoát (1 điểm)
Gợi ý chức năng 1 được coi là chưa được thực hiện nếu như N vẫn bằng một giá trị lúc khai báo (nói cách khác, lúc ta khai báo N thì ta nên gán N bằng một giá trị âm)
Gợi ý chức năng 2 được coi là chưa được thực hiện nếu như tất cả các phần tử của mảng X và mảng Y có giá trị bằng nhau và bằng 0

*/
#include <stdio.h>

int N = 0 ;
int check1 = 0, check2 = 0, check = 1;

void getN(){
    do{
        printf("N: ");scanf("%d",&N);
    }while(N<4 || N>10);
    check1 += 1;
}

void getArray(float X[ ], float Y[ ], int N){
    int i;
    for(i = 0;i < N; i++){
        printf("x%d = ",i+1);scanf("%f",&X[i]);
        printf("y%d = ",i+1);scanf("%f",&Y[i]);
    }
    check2 += 1;
}

int checkArray(float X[ ], float Y[ ], int N){
    for(int i = 0; i < N - 1; i++){
        if(X[i] = X[i+1]){
            check += 1;
        }
        if(Y[i] = Y[i+1]){
            check += 1;
        }
    }
}

int menu(){
    int x;
    float X[10]; float Y[10];
    printf("Menu:");
    printf("\n1.Nhap vao so N (4 <= N <= 10)");
    printf("\n2.Nhap vao mang N phan tu la cac diem co toa do (x, y)");
    printf("\n3.Kiem tra hai diem lien tiep co tao thanh canh song song truc toa do khong?");
    printf("\n4.Thoat");
    printf("\nChon menu: ");scanf("%d",&x);
    switch(x){
        case 1:
            getN();
            menu();
            break;
        case 2:
            if(check1 == 0){
                printf("Hay thuc hien chuc nang 1 !\n");
                menu(); 
            }
            else{
                getArray(X,Y,N);
                menu();
            }
            break;
        case 3:
            if (check1 == 0){
                printf("Hay thuc hien chuc nang 1 !\n");
                menu();
            }
            if (check1 != 0){
                if(check2 == 0){
                    printf("Hay thuc hien chuc nang 2 !\n");
                    menu();
                }
                else{
                    checkArray(X,Y,N);
                    printf("%d\n",check);
                    // if(check == N)
                    //     printf("1\n");
                    // else
                    //     printf("0\n");
                    menu();
                }
            }
            break;
        case 4:
            printf("Tam biet !");
            break;
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
