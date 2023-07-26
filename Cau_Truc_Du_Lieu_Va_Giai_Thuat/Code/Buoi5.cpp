#include <stdio.h>
#include <stdlib.h>//cap phat bo nho dong
/* 
   
   thuat toan tuan tu linh canh
   

*/

int LinerSentinel(int arr[], int n, int x){
	
	arr[n] = x;

	for(int i=0 ; i<n;i++){
		
		if(arr[i]==x){
			
			  return i;//vi tri cua mang
			
		}
		
	}
	
	return -1;//vi so am bieu dien cho khong ton tai
	
}

//thuat toan tuan tu vet can

void LinerExhaustive(int arr[], int n , int x){
	
	//thuat toan vet can ton thoi gian hon
	
	for(int i =0; i<n;i++){
		
		 if(arr[i]==x){
		 	
		 	printf("%d\t",i+1);
		 	
		 }
		
	}
		
}


int main(){
	
	int *arr;
	int n;
	printf("nhap so luong phan tu : ");
	scanf("%d",&n);
	//cap phat bo nho cho con tro, vi con tro phai co dia tri moi dung dc
	arr = (int*)malloc(n*sizeof(int*));
	//nhap mang
	for(int i=0; i<n ;i++){
		
		printf("nhap arr[%d]= ",i);
		scanf("%d",&arr[i]);
		
	}
	//nhap gia tri can tim 
	
	int x;
	printf("nhap x = ");
	scanf("%d",&x);
	//goi ham tra ve
	//tra ham tra ve chuyen tham so ve
	
  //  printf("Vi tri la %d",LinerSentinel(arr,n,x));	
	
	//ham tim kiem linh canh tra ve kieu nguyen len gia tri lam cunxg phai nguyen
	int index = LinerSentinel(arr,n,x);
	
	if(index==-1){
	    
	    printf("Khong tim thay !");
	    
	}else{
		
		 printf("Vi tri %d\n",index+1);
		
	}
	
		printf("Vi tri tuan tu ");
	//tim kiem vet can	
	LinerExhaustive(arr,n,x );
	
	
	return 0;
	
}
