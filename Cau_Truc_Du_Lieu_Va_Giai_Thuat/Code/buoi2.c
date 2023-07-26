#include<stdio.h>
/*
+ Con Trỏ(trỏ vào địa chị để lấy giá trị)
+ Bộ nhớ máy tính
- Bộ nhớ Ram chứa rất nhiều ô nhớ, mỗi ô nhớ có kích thước 1 byte(8 bit)

Địa chỉ của value được lưu trữ ở hệ thập thập lục phân(hexadecimal)
+ Con trỏ trong lập trình C
Công thức dùng:
<kiểu dữ liệu>* <tên con trỏ>
- Con trỏ k có kiểu dữ liệu bởi vì con trỏ chỉ trỉ đến 
địa chỉ, địa chỉ nào cũng giống nhau , không có kiểu địa chỉ là int, float, double,...
- Địa chỉ của biến là một con số
- Đặt địa chỉ của biến vào con trỏ sửa dụng toán tử &:
    <tên con trỏ> = &<tên biến>
- Truy xuất/ trỏ đến để lấy giá trị thì dùng: *<tên con trỏ>
+ Kích thước con trỏ:
- Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau
*/

void khaiBaoConTro(){
    int* ptr1;//khai báo 1 cpn trỏ
        //pointer có tên là ptr1, trỏ đến vùng nhớ có kiểu int
    float* ptr2;
    int* ptr3, a;
    int* ptr4 = NULL;//khởi tạo con trỏ với địa chỉ null thì con trỏ k trỏ đi đâu cả
    //ptr3 là con trỏ nhưng a lại là biến
    int b = 5, c = 7;
    //In ra giá trị và địa chỉ của biến b và c;
    printf("Gia trị của biến b là: %d\n", b);
    printf("Địa chỉ của biến b có kiểu Hex: %p\n", &b);
    //Dấu & giúp lấy địa chỉ của biến
    //%p để in ra 1 địa chỉ có kiểu hex
}

//tìm số lớn hơn number1, number2
void timSoLonHon(){
    int number1, number2;
    int* ptr;// khai báo 1 con trỏ
    printf("Nhap vao 2 so:");
    scanf("%d%d", &number1, &number2);
    //nếu number1>number2 thì con trỏ ptr
    //sẽ được gán giá trị địa chỉ của biến number1
    if(number1 > number2){
        ptr = &number1;
    }else{
        ptr = &number2;
    }
    printf("So lon hon là %d", *ptr);

}
//tìm số lớn nhất trong 3 số a,b,c
int timMax(int* a, int* b, int* c){
    int max = *a;
    if(max < *b){
        max = &b;
    }else if(max < *c){
        max = &c;
    }
    return max;
}
//hàm hoán đổi vị trí
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int* arrNumber, int n){
    for (int i = 0; i < n-1; i++){
         for (int j = 0; j < n - 1 - i; i++)
         {
            if(arrNumber[j] > arrNumber[j+1]){ //so sánh 2 số liền kề nhau
                swap(&arrNumber[j], &arrNumber[j+1]);
            }
         }
         
    }
    //in ra mảng đã sắp xếp
    for (int i = 0; i < n; i++)
    {
        printf("%5d", arrNumber[i]);
    }
    
}


int main(){
    int arrNumber[] = {1,4,5,0,-6};
    //lấy kích thước ()
    int n = sizeof(arrNumber) / sizeof(arrNumber[0]);
    bubbleSort(arrNumber, n);
    khaiBaoConTro();
    timSoLonHon();
    int a,b,c;
    printf("\nNhap 3 so nguyen:");
    scanf("%d%d%d",&a,&b,&c);
    printf("\nGia tri lon nhat la: %d", timMax(&a, &b, &c));
    return 0;
}