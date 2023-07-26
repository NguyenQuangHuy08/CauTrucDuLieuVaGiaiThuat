#include <stdio.h>
#include <string.h>
/*

doi tuong sinh vien 
hoten
nganh
diemc
*/

struct SinhVien{
	
	char hoTen[30];
	char nganh[30];
	float diemC;	
	
};

void nhapSV(SinhVien sv[] , int n){
	
	int i;
	for(int i = 0;i<n;i++){
		fflush(stdin);
		printf("Moi nhap ten : ");
		gets(sv[i].hoTen);
		fflush(stdin);
		printf("Moi nhap nganh : ");
		gets(sv[i].nganh);
		fflush(stdin);
		printf("Moi nhap diemC : ");
		scanf("%f",&sv[i].diemC);
		fflush(stdin);
		printf("");
		
	}
	printf("\n");
	
}

void xuatSV(SinhVien sv[] , int n){
	
	int i;
	for(int i=0;i<n;i++){
		
		printf("Ho ten %s\n",sv[i].hoTen);
		printf("nganh %s\n",sv[i].nganh);
		printf("diem  %f\n",sv[i].diemC);

	}
	
}
void timKiemTheoNganh(SinhVien sv[],int n){
	int i;
	char nganhHoc[30];
	printf("Nhap nganh:");
	gets(nganhHoc);
	fflush(stdin);
	for(i=0;i<n;i++){
		if(strcmp(sv[i].nganh,nganhHoc)==0){
				printf("Thông tin:%s\t%s\t%f",sv[i].hoTen,sv[i].nganh,sv[i].diemC);
		}
	}
}

void timKiemTheoMa(SinhVien sv[],int n){
	
	int i;
	float diem;
	printf("Nhap diem: ");
	scanf("%f",&diem);
	printf("\n");
	fflush(stdin);
	for(int i=0; i<n;i++){
		if(sv[i].diemC==diem){
			
							printf("Thông tin:%s\t%s\t%f",sv[i].hoTen,sv[i].nganh,sv[i].diemC);
			
		}	
	}
	
}

int main(){
	
	int n;
	SinhVien sv[5];
	printf("Nhap n =");
	scanf("%d",&n);
	printf("\n");
	//check n 
	nhapSV(sv,n);
	printf("\n");
	xuatSV(sv,n);
	printf("\n");
	printf("Tim kiem nganh \n");
	timKiemTheoNganh(sv,n);
	printf("\n");
	printf("Tim kiem diem \n");
	timKiemTheoMa(sv,n);
	printf("\n");

	return 0;
}
