#include <stdio.h>
    /*
    <kiểu dữ liệu>* <tên con trỏ>
    int* ptr1;
    pointer có tên là ptr1, trỏ đến vùng nhớ có kiểu dữ liệu Integer
    con trỏ không có kiểu dữ liệu gì con trỏ chỉ trỏ đến địa chỉ, mà
    địa chỉ nào cũng giống nhau, không có kiểu dữ liệu địa chỉ là int, float, double,...
    địa chỉ của biến là 1 con số
    đặt địa chỉ của biến vào con trỏ sử dụng toán tử &:
    <tên con trỏ> = &<tên biến>
    Kích thước con trỏ:
    Con trỏ chỉ lưu địa chỉ nên kích thước mọi con trỏ là như nhau
    */

// tìm số lớn hơn trong 2 số
// tìm số lớn nhất trong 3 số abc
void khaiBaoConTro(){
    int* prt3, a; // ptr3 là con trỏ, nhưng a là biến
    int* ptr4 = NULL; // con trỏ với địa chỉ là null thfi nó không trỏ đi đâu cả
    float* ptr2;
    int b = 5;
    int c = 7;
    printf("Gia tri cua bien b: %d\n", b);
    printf("Dia chi cua bien b co keiu HEX: %p\n", &b); // %p để in ra 1 địa chỉ có kiểu HEX, &b để lấy địa chỉ của biến
}
void timSoLonHon(int a, int b){
    int *pt1;
    if(a > b){
        pt1 = &a;
    }else{
        pt1 = &b;
    }
        printf("So lon hon la: %d", *pt1);
}
int timMax(int *a, int *b, int *c){
    int max;
    if(*a > *b && *a > *c){
        max = *a;
    }else if(*b > max && *b > *c){
        max = *b;
    }else{
        max = *c;
    }
    return max;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int *arrNummber, int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if(arrNummber[j] > arrNummber[j+1]){
                swap(&arrNummber[j], &arrNummber[j+1]);
            }
        }
    }
    for (int i = 0; i < n; i++){
        printf("%5d", arrNummber[i]);
    }
}

    
int main()
{
    // int a = 1, b = 2, c = 3;
    // int max = timMax(&a, &b, &c);
    // printf("Max la: %d\n", max);
    int arrNummber[] = {1,3,5,222,1,4,22,2222,1};
    int n = sizeof(arrNummber) / sizeof(arrNummber[0]);
    bubbleSort(arrNummber, n);

    return 0;
}
