//  Ví dụ 1: 
//     a) khai báo 2 số nguyên M, N biết rằng M đại diện cho số tổ của một lớp và N đại diện cho số thành viên của tổ đó.
// Viết hàm void getData(int *M, int *N) yêu cầu người dùng nhập giá trị từ bàn phím, lưu giá trị vào biến M, N.
// Trong hàm main gọi đến hàm getData đó và sau đó in ra giá trị của M, N (2 điểm)
//     b) Khai báo mảng D là mảng số thực hai chiều kích thước M, N.
// Viết 2 vòng lặp for để gán giá trị điểm số của học sinh thuộc tổ i và là thành viên có chỉ số trong tổ là j (i và j bắt đầu từ 0).
// Giả sử người dùng luôn nhập đúng giá trị này (điểm luôn >= 0 và <= 10) (2 điểm)
//     c) Giả sử rằng thành viên có chỉ số (trong tổ) 0 của mọi tổ đều là tổ trưởng (tức mà D[0][0] là điểm của tổ trưởng tổ 0).
// Thành viên có chỉ số (trong tổ) 1 của mọi tổ là tổ phó (tức nói đến D[0][1]).
// Thành viên ở tổ 0 và là thành viên có chỉ số 2 là lớp trưởng, thành viên cũng tổ đó và là thành viên có chỉ số 3 là lớp phó.
// Hãy kiểm tra xem trong số các tổ trưởng, điểm cao nhất là điểm mấy? (2 điểm)
// Chẳng hạn ta có danh sách điểm như sau:
//     D[3][5] = {​
//     {​7, 6, 8, 9, 4}​,
//     {​8, 6, 7, 5, 7}​,
//     {​9, 8, 6, 7, 5}​
//     }​;
// Thì điểm cao nhất của các tổ trưởng là điểm 9.(2 điểm)
//     d) Hãy xác định trong các tổ phó, điểm thấp nhất là điểm mấy. Với ví dụ trên thì điểm đó là 6 (2 điểm)
//     e) Hãy kiểm tra xem trong lớp có bao nhiêu bạn cao điểm hơn bạn lớp trưởng (2 điểm)
// Với ví dụ trên thì có 2 bạn cao điểm hơn bạn lớp trưởng

#include<stdio.h>

int getData(int *M,int *N){
    printf("M: ");scanf("%d",&*M);
    printf("N: ");scanf("%d",&*N);
}

int main(){
    int i=0,j=0;
    int M,N;
    getData(&M,&N);
    printf("M = %d,N= %d",M,N);

    int A[100][100];
    printf("\nNhap diem:\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            do{
                printf("A[%d][%d]:",i,j);
                scanf("%d",&A[i][j]);
            }while(A[i][j]>10 && A[i][j]<0);
        }
    }

    int max=A[0][0];
    for(i=0;i<M;i++){
        if(max<A[i][0])
            max=A[i][0];
    }
    printf("Diem to truong cao nhat: %d\n",max);

    int min=A[0][1];
    for(i=0;i<M;i++){
        if(min>A[i][1])
        min=A[i][1];
    }
    printf("Diem to pho thap nhat: %d\n",min);

    int count=0;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if(A[i][j]>A[0][2]) 
            count++;
        }
    }
    printf("Trong lop co %d ban cao diem hon lop truong.\n",count);


    return 0;
}
