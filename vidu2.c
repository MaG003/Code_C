/*Ví dụ 2:
    a) khai báo số nguyên N. Viết hàm void getData(int *N) yêu cầu người dùng nhập giá trị từ bàn phím, lưu giá trị vào biến N.Trong hàm main gọi đến hàm getData đó và sau đó in ra giá trị của N (2 điểm)
    b) Khai báo 2 mảng các số thực X, Y với số lượng các phần tử là N. Hãy viết vòng lặp for (biến đếm i lặp từ 0 đến N - 1) thực hiện việc gán giá trị tọa độ x, y cho điểm thứ i. 
Tọa độ x sẽ lưu vào X[i] còn toạ độ y sẽ lưu vào Y[i] (2 điểm)
    c) Viết hàm void getVertices(float x, float y, float width, float length) thực hiện việc in ra tọa độ 4 đỉnh của một hình chữ nhật có tâm là điểm tọa độ (x, y). 
Cạnh theo chiều rộng của hình chữ nhật này là width, cạnh theo chiều dài của nó là length. Giả sử hình chữ nhật này luôn có cạnh song song với trục tọa độ (2 điểm)
    d) Viết vòng lặp for thực hiện lặp N lần (biến i chạy từ 0 đến N - 1) sao cho nó gọi hàm getVertices và in ra tọa độ 4 đỉnh của hình chữ nhật có tâm là X[i], Y[i]. Biết width = 2 và length = 6 (2 điểm)
    e) Sửa lại hàm main sao cho nó yêu cầu người dùng nhập vào hai giá trị pX, pY kiểu float. Đây sẽ là hai tọa độ theo trục Ox, Oy của một điểm. (1 điểm)
    f) viết hàm void checkColliance(float pX, float pY, float x, float y, float width, float length). Hàm này sẽ in ra thông báo nếu điểm p(pX, pY) nằm trong lòng của hình chữ nhật có tọa độ tâm (x, y) (1 điểm)
Tư tưởng pX >= xMin (tọa độ x nhỏ nhất) và pX <= xMax (tọa độ x lớn nhất) pY >= yMin (tọa độ y nhỏ nhất) và pY <= yMax (tọa độ y lớn nhất)
*/

#include<stdio.h>

void getData(int*N){
    printf("N: ");scanf("%d",&*N);
}

void getVertices(float x, float y, float width, float length){
    printf("A: %.2f %.2f\n",x-(length/2),y-(width/2));
    printf("B: %.2f %.2f\n",x+(length/2),y-(width/2));
    printf("C: %.2f %.2f\n",x+(length/2),y+(width/2));
    printf("D: %.2f %.2f\n",x-(length/2),y+(width/2));
}

void checkColliance(float pX, float pY, float x, float y, float width, float length){
    float xMin = x-(length/2);
    float xMax = x+(length/2);
    float yMin = y-(length/2);
    float yMax = y+(length/2);

    if(pX >= xMin && pX <= xMax && pY >= yMin && pY <= yMax ){
        printf("p(%.2f, %.2f) nam trong long hinh chu nhat co toa do tam (%f, %f)",pX,pY,x,y);
    }

}

int main(){
    int i,N;
    float pX,pY;
    getData(&N);
    printf("N= %d\n",N);

    float X[N],Y[N];
    for(i = 0;i <= (N-1) ; i++){
        printf("x = ");scanf("%f",&X[i]);
        printf("y = ");scanf("%f",&Y[i]);
    }

    int width = 2, length = 6;
    for(i = 0;i<=(N-1);i++){
        getVertices(X[i],Y[i],width,length);
    }

    printf("pX = ");scanf("%f",&pX);
    printf("pY = ");scanf("%f",&pY);

    for(i = 0;i<=(N-1);i++){
        checkColliance(pX, pY,X[i],Y[i],width,length);
    }
    
    return 0;
}