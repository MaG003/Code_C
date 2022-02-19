// Viết chương trình C có menu để người dùng thực hiện các chức năng sau đây:
// ====Program for management computers====
// 1) Number of Computers:
// 2) Update number of cores:
// 3) Update Ram info:
// 4) Search:
// 5) Quit
// SV viết được chương trình sao cho in ra menu và nhận lựa chọn của người dùng là 1 giá trị từ 1 đến 5, nếu sai thì thông báo nhập lại (0.5 ĐIỂM). Nếu chương trình thoát khi người dùng nhập 5 thì sinh viên sẽ được thêm (0.5 ĐIỂM).
// 1) Khi người dùng chọn chức năng 1, chương trình sẽ in ra câu hỏi yêu cầu người dùng nhập giá trị N biểu thị số phần tử của các Computers. Giả sử N < 100. 
// CT sau in ra số N vừa nhập (2 ĐIỂM)
// 2) Khi người dùng chọn chức năng 2.
// Chương trình cho phép cập nhật số core của CPU có trong các máy. Đầu tiên chương trình yêu cầu người dùng nhập vào ID của máy muốn nhập, sau đó nhập số core của CPU mới. Khi nhập xong một máy thì sẽ tự động yêu cầu nhập cho máy có ID lớn hơn. Nếu người dùng nhập sai ID (< 1 hoặc > N), hoặc sai số core của CPU, sẽ được yêu cầu nhập lại (Chú ý: CPU chỉ có số core là 2, 4, 6, 8, 10) (0.5 ĐIỂM). 
// Giả sử máy có ID thứ x thì sẽ nằm trong phần tử thứ (x - 1) của mảng.
// Chức năng này sẽ dừng nếu người dùng đã nhập đến máy có ID lớn nhất (Nếu có N máy thì các ID có giá trị từ 1 đến N) (0.5 ĐIỂM). 
// Sau khi kết thúc nhập thì in ra danh sách toàn bộ máy (mỗi máy trên 1 dòng: <ID> <số core>) (2 ĐIỂM).
// Chẳng hạn in ra 
// 1  2
// 2  2
// 3  4
// 4  6
// 5  10
// 6  2

#include <stdio.h>

int N ;
int A[] = {};

int Input(){
    do{
        printf("Input N: "); scanf("%d",&N);
    }while(N<=0 || N>100);
    printf("%d\n",N);
}

int Update(int n){
    A[n];
    int i;
    do{
        printf("Input ID start: ");scanf("%d",&i);
        for(int j=i-1 ; j<n ; j++){
            do{
                printf("Input CPU %d: ",j+1);scanf("%d",&A[j]);
            }while(A[j]%2!=0 || A[j]<2 || A[j]>10);
        }
    }while(i<1 || i>n);

    for(int k=0; k<n; k++){
        printf("%d  %d \n",k+1,A[k]);
    }
}

int menu(){
    int x;
    printf("====Program for management computers====");
    printf("\n1.Number of Computers:");
    printf("\n2.Update number of cores:");
    printf("\n3.Update Ram info:");
    printf("\n4.Search:");
    printf("\n5.Quit");
    printf("\nChon menu: ");scanf("%d",&x);
    switch(x){
        case 1:
            Input();
            menu();
            break;
        case 2:
            Update(N);
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