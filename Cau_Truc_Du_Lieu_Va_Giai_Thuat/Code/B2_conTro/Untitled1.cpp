#include <stdio.h>

/*
   ----con tro----
   
   * bo nho may tinh
   bo nho ram chua rat nhieu o nho, moi o nho 
   co kich thuoc la 1 byte
   
   dia chi cua value duoc luu tru o he thap luc phan 
   
(hexadecimal)

+) con trong lap trinh c:

cong thuc dung
<kieu du lieu>  * ptr

ptr là con tro

con tro khong co kieu du lieu vi con tro chi cho den dia chi, dia chi nao cung giong nhau
khong co kieu dia chi la int, float , double 

  

*/

//void khaiBaoConTro(){
//	
//	printf("Dia chi cua bien b co kieu HEX : %p\n", &b);
//	//Dau & giup lay dia chi cua bien 
//	//%p de in ra 1 dia chi co kieu HEX
//	
//}

//tim so lon hon number1 và number2

void timSoLonHon(){
	 
	 int number1, number2;
	 int * ptr ;//khai báo con tro
	
	  printf("Moi ban nhap number1");
	  scanf("%d\n",&number1);
	   printf("Moi ban nhap number2\n");
	  scanf("%d\n",&number2); 
	  //neu number1 > number2 thi con tro ptr
	  //se duoc gan gia tri dia chi cua bien number1
	  
	  if(number1 > number2){
	  	
	  	ptr = &number1;
	  	
	  	
	  }else{
	  
	    ptr = &number2;
	  
	  }
	  
	  printf("So lon hon la : %d",*ptr);
	  
	  
	
}

//tim so lon nhat trong 3 so a b c 

void timMax(int* a , int * b , int * c){
	
	int max = *a;
	
	if(*b > max){
		 
		max = *a;
		
	}if(*b > max ){
		
		max = *b;
		
	}if(*c > max){
		
		max = *c;
		
	}
	
	return max;
	
}

//thuat toan sap xep



int main(){
	
//	int * ptr1;//khai bao mot con tro
//	//pointer có tên là ptr1, tro den vung du lieu co kieu int
//	
//	khaiBaoConTro();
	timSoLonHon();
	int a,b,c;
	printf("Nhap 3 so nguyen : ");
	scanf("%d%d%d",&a,&b,&c);

	printf("\nGia tri lon nhat: %d",timMax(&a, &b, &c));
	
	return 0;
	
}
