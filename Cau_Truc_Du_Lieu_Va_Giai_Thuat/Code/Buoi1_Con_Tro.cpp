#include <stdio.h>
/*
----Con tro--
+ Bo nho máy tính
+ Con tro trong lap trình C<ki?u d? li?u> *<tên con tr?>;
- Con tro ko có kieu du lieu vì con tr?o chi tro den dia chi,
dia chi nào cung giong nhau,
 không có kieu dia chi là int, float, double, ..
 - Ðia chi ca bien là 1 con so
 - Ðt dia chi cia bien vào con tro su dung toán tu &:
         <tên con tr?> = &<tên bien>
+ Kích thuoc con tro:
 -Con tro ch? luu d?a ch? nên kích thu?c là nhu nha

*/

void khaiBaoConTro()
{
    int *ptr1; // khai báo 1 con tr?
    // pointer có tên là ptr1, tr? d?n vùng nh? có ki?u
    float *ptr2;
    int *ptr3, a;
    // ptr3 là con tr? nhung a l?i là bi?n
    int *ptr4 = NULL; // khoi tao con t voi dia chi NULL
    int b = 5, c = 7;
    // in ra giá tr? và d?a ch? c?a bi?n b và c
    printf("Gia tri cua bien b la: %d\n", b);
    printf("Dia chi cua b co kieu HEX: %p\n", &b);
    // Dau & giup lay dia chi cua bien
    //%p de in ra 1 dia chi co kieu HEX
}
// Tim so lon hon number1,number2
void timSoLonHon()
{
    int number1, number2;
    int *ptr;
    printf("Nhap vao so nguyen:");
    scanf("%d%d", &number1, &number2);
    // neu number1>number2 thi con tro ptr
    // se duoc gan gtri dia chi cua bien number1
    if (number1 > number2)
    {
        ptr = &number1;//roi number se là dia chi de lay du lieu
    }
    else
    {
        ptr = &number2;
    }
    printf("So lon hon la: %d", *ptr);//in ra con tro
}

//tim so lon hon trong 2 so 

void timLontrong2So(){
	
	int number1,number2;
	int *ptr;
	
	printf("Moi ban nhap so nguyen : ");
	scanf("%d%d",&number1,&number2);
	
	if(number1 > number2){
		
		 ptr = &number1;
		
	}else{
		
		ptr = &number2;
		
	}
	
	printf("So lon hon la : %d", *ptr);
	
	
}


// tim so lon nhat trong 3 so 
//cho 3 con tro
int timMax(int *a, int *b, int *c)
{
    int max = *a;
    if (*b > max)
    {
        max = *b;
    }
    if (*c > max)
    {
        max = *c;
    }
    return max;
}

// Thuat toan sap xep noi b?t
// Tinh tong a,b, S hinh chu nhat, a,b,
// swap là hàm hoán v?
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int *arrNumber, int n){
    int i=0;
    for (i; i < n - 1; i++)
    {
        int j = 0;
        for (j; j < n - 1 - i; j++)
        {
            if (arrNumber[j] > arrNumber[j + 1])
            {
                swap(&arrNumber[j], &arrNumber[j + 1]);
            }
        }
    }
    // in ra mang da sap xep
    for (i; i < n; i++)
    {
        printf("%5d", arrNumber[i]);
    }
}
int main()
{
    int arrNumber[] = {1, 4, 5, 0, -6,7,8,3};
    int n = sizeof(arrNumber) / sizeof(arrNumber[0]);
    bubbleSort(arrNumber, n);

    khaiBaoConTro();
    timSoLonHon();
    int a, b, c;

    printf("\nNhap vao 3 so:");
    scanf("%d%d%d", &a, &b, &c);
    printf("\nGia tri lon nhat la:%d", timMax(&a, &b, &c));
    return 0;
}

