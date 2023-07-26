#include<stdio.h>
/*
* -Truyền tham trị là truyền giá trị của biến ( không phải là địa chỉ ô nhớ)
Giá trị của biến không thay đổi ngoài phương thức

* -Truyền tham chiếu là địa chỉ ô nhớ của biến
Giá trị của biến cũng bị thay đổi bên ngoài phương thức
*/
void hoanViThamTri(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("Ben trong hoan vi tham tri a = %d, b = %d\n", a, b);
}

void hoanViThamChieu(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a = 1;
    int b = 2;
    hoanViThamChieu(&a, &b);
    // hoanViThamTri(a,b);
    // printf("Ben ngoai hoan vi tham tri a = %d, b = %d", a, b);
    
    printf("Ben ngoai hoan vi tham chieu a = %d, b = %d", a, b);
}