#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include <windows.h>
#include <stdlib.h>
#define sl 100  //so luong gioi han la 100

/// khai báo struct

//Khai bao date la kieu luu tru du lieu voi nhung kieu du lieu khac nhau
struct Date
{
	int ngay;
	int thang;
	int nam;
};
typedef struct Date date; //tao ten moi cho kieu du lieu

//Khai bao nhan vien 
struct NhanVien
{
	int msnv;
	char ho[20];
	char ten[20];
	date namsinh;
	char noisinh[100];
	char diachi[200];
	float luong;
	date ngayvao;
};

typedef struct NhanVien nhanvien;

//Khai bao danh sach
struct DanhSach
{
	nhanvien ds[sl];//lay du lieu cua nhan vien vao danh sach va so luong phai tu 1 - 100
	int n;//so luong them vao
};

typedef struct DanhSach danhsach;

// Khai bao tat ca cac ham 
//& la dia chi con tro
void nhapngaythang(date &ntn);
void nhap1nv(nhanvien &nv);
void xuat1nv(nhanvien nv);
void xuatngaythang(date ntn);
void nhapdanhsach(danhsach &ds);
void xuatdanhsach(danhsach ds);
int timten(danhsach ds, char *c);
void themnv(danhsach &ds, nhanvien x,int k);
int timMSNV(danhsach ds, int d);
void xoanv(danhsach &ds, int d);


//Xay dung menu 
void menu()
{
	system("Color 2");
	danhsach ds;
    int choose = 0;//Lua chon chuong trinh
    
    do
    {
       
       printf("                                  			====MENU====                               		  \n");
	   printf("                                                                                               \n");
	   printf("                           1. Them vao 1 nhan vien		                                      \n");
	   printf("                           2. Tim nhan vien theo ma so                 						  \n");
	   printf("                           3. Tim nhan vien theo ten               							   ");
	   printf("                         4. Xuat danh sach                                 \n");
	   printf("                      	   5. Xoa 1 nhan vien                                                  ");
	   printf("						  	           6. Them nhan vien vao danh sach 									   \n");
	//   printf("								Sap xep luong giam dan												");
	   printf("                           0.Ban chon thoat                                                    \n");
	   printf("\n");
       printf("Vui long chon chuc nang : ");
       scanf("%d", &choose);
       
        switch (choose){
        	
        case 1://Chuc nang them nhan vien 
        	printf("\n");
        	printf("Ban chon chuc nang them nhan vien \n");
        	printf("\n");
            nhapdanhsach(ds);
            printf("\n");
            xuatdanhsach(ds);
            break;
            
        case 2://Chuc nang tim nhan vien theo ma so
            {
            	printf("Ban chon chuc nang tim nhan vien theo ma so !\n");
                int msnv;
                printf("\nNhap ma so nhan vien can tim: ");
                scanf("%d",&msnv);
                //thuat toan linh canh
                int index = timMSNV(ds, msnv);
                if (index != -1)//tai vi dang lay phan tu thu 0+1
                {
                	printf("Da tim thay nhan vien co ma : %d\n",msnv);
                    printf("\nThong tin nhan vien can tim:\n");
                    xuat1nv(ds.ds[index]);
                }else{
				
                    printf("\nKhong tim thay nhan vien co ma so %d.\n", msnv);
                    
                }
            }
            break;
            
        case 3://tim nhan vien theo ten
            {
            	printf("Ban chon chuc nang tim nhan vien theo ten !\n");
  				char ten[20];//gioi han ten nhap la 20
  				fflush(stdin);
                printf("\nNhap ten nhan vien can tim:");
			    gets(ten);
                int index = timten(ds,ten);
                if (index!= -1){
                	printf("Da tim thay nhan vien co ten %s\n",ten);
                    printf("\nThong tin nhan vien can tim!\n");
                    xuat1nv(ds.ds[index]);
                }
                else{
                    printf("\nKhong tim thay nhan vien co ten: %s\n", ten);
                }
	        
				
				break;
                

            }
            break;
        case 4:
            {
		
			printf("Ban chon chuc nang xuat danh sach !\n");
            xuatdanhsach(ds);
				
            }
            break;
        case 5:
		{
        	
				printf("Ban chon chuc nang xoa nhan vien theo ma so!\n");
		  		int msnv;
		        printf("\nNhap ma so nhan vien can xoa: ");
		        scanf("%d", &msnv);
		        int vitri = timMSNV(ds, msnv);
		        if (vitri == -1)
		        {
		            printf("\nKhong tim thay nhan vien co ma so %d", msnv);
		        }
		        else
		        {
		            printf("\nDa tim thay nhan vien co ma so %d", msnv);
		            xoanv(ds, vitri);
		        }
            break;
        }
        
        case 6:
        	
        {
        	
        	 printf("Ban chon chuc nang them nhan vien vao danh sach \n");
        	 printf("\n");
        	 nhanvien x;
             printf("\nNhap thong tin nhan vien can them:\n");
             nhap1nv(x);
             int k;//k se la vi tri muon them
             printf("\nNhap vi tri can them (0 <= vi tri <= %d): ", ds.n);
             scanf("%d", &k);
             themnv(ds, x, k);
             printf("\n");
        		
		}
		
//	   case 7:
//	   	   {
//	   		sapxepLuongGiamDan(ds);
//	   		
//		   }
        
        case 0:
            break;
        default:
            printf("\nVui long chon lai chuc nang !");
            break;
        }
       printf("\n");
    }
	while(choose!=0);
}

//Xay dung chi tiet cac ham 

// nhap ngay thang
void nhapngaythang(date &ntn)//ham voi co kieu du lieu la date
{

    printf("Nhap ngay: ");
    scanf("%d", &ntn.ngay);
    printf("Nhap thang: ");
    scanf("%d", &ntn.thang);
    printf("Nhap nam: ");
    scanf("%d", &ntn.nam);
    
}

//xuat ngay thang
void xuatngaythang(date ntn)
{
	
    printf("%d-",ntn.ngay);
	printf("%d-",ntn.thang);
	printf("%d",ntn.nam);
	
}

// nhap du lieu cua 1 nhan vien 
void nhap1nv(nhanvien &nv)//nhap theo &nv
{
	
    printf("Nhap MSNV: ");
    scanf("%d", &nv.msnv);
	fflush(stdin);//Giai phong bo nho
	
    printf("Nhap ho nhan vien: ");
    gets(nv.ho);
	fflush(stdin);//Giai phong bo nho

    printf("Nhap ten nhan vien: ");
    gets(nv.ten);
    fflush(stdin);//Giai phong bo nho

    printf("Nhap ngay sinh: \n");
    nhapngaythang(nv.namsinh);
    fflush(stdin);//Giai phong bo nho
    
    printf("Nhap noi sinh: ");
    gets(nv.noisinh);
	fflush(stdin);//Giai phong bo nho

    printf("Nhap dia chi: ");
	gets(nv.diachi);
	fflush(stdin);//Giai phong bo nho

    printf("Nhap luong: ");
    scanf("%f", &nv.luong);
    fflush(stdin);//Giai phong bo nho

    printf("Nhap ngay vao lam: \n");
    nhapngaythang(nv.ngayvao);
    printf("\n");

}

// xuat 1 nhan vien
void xuat1nv(nhanvien nv)
{

	printf("Ma so nhan vien : %d\n",nv.msnv);
    printf("Ho nhan vien : %s\n",nv.ho);
    printf("Ten nhan vien : %s\n",nv.ten);
    printf("Ngay sinh ");
    xuatngaythang(nv.namsinh);
    printf("\n");
    printf("Noi sinh nhan vien : %s\n",nv.noisinh);
    printf("Dia chi nhan vien : %s\n",nv.diachi);
    printf("Luong nhan vien : %.2f\n",nv.luong);
    printf("Ngay vao cua nhan vien ");
    xuatngaythang(nv.ngayvao);
    printf("\n");

}


// nhap danh sach
void nhapdanhsach(danhsach &ds)
{
	printf("\n");
	int so = 1;
	
	

	
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &ds.n);
	printf("\n");
	//ds la lay kieu du lieu tu themnv 
    for (int i = 0; i < ds.n; i++)
    {
        printf("Nhap thong tin nhan vien thu %d:\n", i+1);
        nhap1nv(ds.ds[i]);
    }
    
    
    
}

// xuat danh sach
void xuatdanhsach(danhsach ds)
{
    for (int i = 0; i < ds.n; i++)
    {
        xuat1nv(ds.ds[i]);
        printf("\n");
    }
}

 //tim ten cua mot nhan vien 
//tim ten kieu du lieu la int va tra ve so 
int timten(danhsach ds, char *c)
{
    for (int i = 0; i < ds.n; i++)
    {
        if (strcmp(strlwr(ds.ds[i].ten),strlwr(c))== 0)
        //hoac
            //    if (strcasecmp(ds.ds[i].ten,c)== 0)

        //ham strlwr se la bien doi chu hoa thanh chu thuong
        //ham strcmp dung de so sanh chuoi va khong phai de so sanh do dai
        {
            return i;
        }
    }
    return -1;  // am 100 hay am bao nhieu cung duoc
}



// them nv vao danh sach 
void themnv(danhsach &ds, nhanvien x, int k)
//k se la vi tri nhap
{
	
    if (k < 0 || k > ds.n)
    {
        printf("\nVi tri them khong hop le.");
        return;
    }
    if (ds.n == sl)
    {
        printf("\nDanh sach da day, khong the them nhan vien.");
        return;
    }
    //giam sl danh sach
    for (int i = ds.n; i > k; i--)
    {
        ds.ds[i] = ds.ds[i-1];
    }
    ds.ds[k] = x;
    ds.n++;
    printf("\nThem nhan vien thanh cong.");
}

// xoa nv
void xoanv(danhsach &ds, int d){

//d la vi tri them
    if (d < 0 || d >= ds.n)
{
    {
        printf("\nVi tri xoa khong hop le.");
        return;
    }
    for (int i = d; i < ds.n - 1; i++)
    {
        ds.ds[i] = ds.ds[i+1];
    }
    ds.n--;
    printf("\nXoa nhan vien thanh cong.");
}
}

//tim nhan vien theo mnv
int timMSNV(danhsach ds, int d)
{
    for (int i = 0; i < ds.n; i++)
    {
        if (ds.ds[i].msnv == d)
        {
            return i;//tim thay nhan vien 
        }
    }
    return -1;//khong tim thay nhan vien
}

//sap xep theo luong

//void sapxepLuongGiamDan(danhsach ds){
//	int i,j;
//	for(i=0;i<ds.n-1;i++){
//		for(j=i+1;j<ds.n;j++){
//          //sap xe[ lien ke nhau 
//			if(ds.ds[i].luong <ds.ds[j].luong){
//			float temp = ds.ds[i].luong;
//			ds.ds[i].luong = ds.ds[j].luong;
//				ds.ds[j].luong = temp;
//			}
//		}
//	}
//}

//void sapxepLuongGiamDan(danhsach ds){
//	int i,j;
//	for(i=0;i<ds.n-1;i++){
//		for(j=i+1;j<ds.n;j++){
//          //sap xe[ lien ke nhau 
//			if(ds.ds[i].luong <ds.ds[j].luong){
//			float temp = ds.ds[i];
//			ds.ds[i] = ds.ds[j];
//				ds.ds[j] = temp;
//			}
//		}
//	}
//	
//	xuatdanhsach(ds);
//}
// Main
int main()
{
	menu(); //goi ve ham menu de chay chuong trinh
	return 0;
}
