#include <stdio.h>
/*
----Con tro--
+ Bo nho m�y t�nh
+ Con tro trong lap tr�nh C<ki?u d? li?u> *<t�n con tr?>;
- Con tro ko c� kieu du lieu v� con tr?o chi tro den dia chi,
dia chi n�o cung giong nhau,
 kh�ng c� kieu dia chi l� int, float, double, ..
 - �ia chi ca bien l� 1 con so
 - �t dia chi cia bien v�o con tro su dung to�n tu &:
         <t�n con tr?> = &<t�n bien>
+ K�ch thuoc con tro:
 -Con tro ch? luu d?a ch? n�n k�ch thu?c l� nhu nha

*/

void khaiBaoConTro()
{
    int *ptr1; // khai b�o 1 con tr?
    // pointer c� t�n l� ptr1, tr? d?n v�ng nh? c� ki?u
    float *ptr2;
    int *ptr3, a;
    // ptr3 l� con tr? nhung a l?i l� bi?n
    int *ptr4 = NULL; // khoi tao con t voi dia chi NULL
    int b = 5, c = 7;
    // in ra gi� tr? v� d?a ch? c?a bi?n b v� c
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
        ptr = &number1;//roi number se l� dia chi de lay du lieu
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
// swap l� h�m ho�n v?
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

