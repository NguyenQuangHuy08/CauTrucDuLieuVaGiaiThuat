#include<stdio.h>
#include<stdlib.h>
/*
    Quản lí bộ nhớ động malloc(), calloc(), free()
    Trong C++ new  delete
    Today we will study: cấp phát bộ nhớ cho con trỏ
    Warrring: KHÔNG THỂ THỰC HIỆN CÁC PHÉP TOÁN * / % cho con trỏ
    Phép toán số học trên con trỏ:
    n + *sizeof(<kieu du lieu>)

*/

void nhapMang(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("Nhap vao phan tu thu arr[%d]: \n", i);
        scanf("%d", arr);
        arr++;
    }
}
void inMang(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\n", *arr);
        arr++;
    }
}

void themPhanTu(int *arr, int n, int viTriThem, int giaTriThem){
    n++;
    //Cấp phát thêm bộ nhớ cho mảng
    arr = (int *)realloc(arr, n * sizeof(int));
    // 3571 chèn 21 sau số thứ 5
    for (int i = n - 1; i > viTriThem; i--)
    {
        arr[i] = arr[i - 1];  
    }
    arr[viTriThem] = giaTriThem;
    
}

void xoaPhanTu(int *arr, int n, int viTriXoa){
    for (int i = viTriXoa; i < n -1; i++)
    {
        arr[i] = arr[i + 1];  
    }
    n--; // trừ đi byte
    //realloc: thay đổi kích thước bộ nhwos được cấp phát
    arr = (int*)realloc(arr, n * sizeof(int)); // tính theo byte
}

int main(){
    int * arr;
    int n;
    //Cấp phát bộ nhớ sử dụng malloc
    // ten-con-tro = (kieu du lieu*)malloc(so luong o nho * sizeof(kieu du lieu*))

    // malloc không gán giá trị ban đầu
    // calloc sẽ gán giá trị mặc định các ô nhớ
    arr = (int*)malloc(n * sizeof(int*));
    do
    {
        printf("Moi nhap so luong phan tu mang:\n");
        scanf("%d", &n);
        if(n < 0){
            printf("Vui long nhap lai\n");
        }
    } while (n < 0);
    nhapMang(arr, n);
    inMang(arr, n);
    printf("\n");
    themPhanTu(arr, n, 1, 21);
    inMang(arr, n + 1);
    printf("\n");
    xoaPhanTu(arr, n, 1);
    inMang(arr, n);
    //Giải phóng bộ nhớ
    if(arr != NULL){
        free(arr);
    }
}