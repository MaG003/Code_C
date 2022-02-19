/*Viết 1 mã nguồn C
    a) Yêu cầu người dùng nhập vào bàn phím số n, kiểm tra vòng lặp while sao cho n >=1 và <=6, nêú ngươì dùng nhập 
không đúng yêu cầu nhâpj lại cho đúng(2 điểm)
    b) Yêu câù người dùng nhập vào n số thực từ bàn phím. Các số được nhập hoàn toàn ngẫu nhiên và không cần 
kiểm tra, giả sử luôn nhập con số. Các số đó được lưu vào mảng X(1.5 điểm)
    c) Yêu câú người dùng nhập vào gía trị số thực lamda. Điều kiện lambda thuộc (0,1), nếu sai nhập lại cho 
đến khi đúng (1.5 điểm)
    d) Tạo ra mảng Y có n phần tử trong đó phần tử thứ i sẽ được tìm ra theo công thức đệ quy :
        Y[0]=X[0]
        Y[k]=(1-lambda)*Y[k-1]+lambda*X[k]
        In ra các gái trị cuả mảng Y.Chú ý phải nói rõ thứ tự in ra(từ chỉ số 0 hay từ chỉ số n-1 trở xuống)(2 điểm)
    e)Yêu câù người dùng nhập vào 1 giá trị số thực bất kỳ và in ra số thực đó.(1 điểm)
    f)Tính toán lại mảng Y với lambda = 0.4, sau đó in ra phânf tử cuối cùng của mảng Y(2 điểm)
*/

#include<stdio.h>

int main(){
    int k,i,n;
    do{
        printf("Nhap n:");scanf("%d",&n);
    }while(n<1 || n>=6);

    int X[n];
    for(i=0; i<n; i++){
        printf("X[%d]: ",i+1);scanf("%d",&X[i]);
    }

    float lambda ;
    do{
        printf("Nhap lambda:");scanf("%.2f",&lambda);
    }while(lambda<=0 || lambda>=1);

    int Y[n];
    for(k = 0; k < n; k++){
        if(k=0)
            Y[0] = X[0];
        else{
            Y[k] = (1 - lambda)*Y[k - 1] + lambda*X[k];
        }
        printf("%d\n",Y[k]);
    }


    float m;
    printf("Nhap m:");scanf("%f",&m);
    printf("%.2f",m);



    return 0;
}

