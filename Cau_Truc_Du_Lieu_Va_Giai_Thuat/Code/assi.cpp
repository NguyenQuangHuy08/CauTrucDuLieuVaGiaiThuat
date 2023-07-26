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
    nhanvien ds[sl];
    int n;
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
    system("Color 4");
    danhsach ds;
    int choose = 0;//Lua chon chuong trinh
    
    do
    {
       
       printf("                                             ====MENU====                                      \n");
       printf("                                                                                               \n");
       printf("                           1. Them vao 1 nhan vien                                             \n");
       printf("                           2. Tim nhan vien theo ma so                                         \n");
       printf("                           3. Tim nhan vien theo ten                                             ");
       printf("                        4. Bang luong cua nhan vien giam dan                                \n");
       printf("                            5. Xoa 1 nhan vien                                                  \n");
       printf("                           0.Ban chon thoat                                                    \n");
       printf("\n");
       printf("Vui long chon chuc nang : ");
       scanf("%d", &choose);
       
        switch (choose){
            
        case 1:
            printf("\n");
            nhapdanhsach(ds);
            break;
        case 2:
            xuatdanhsach(ds);
            break;
        case 3:
            {
                nhanvien x;
                printf("\nNhap thong tin nhan vien can them:\n");
                nhap1nv(x);
                int k;
                printf("\nNhap vi tri can them (0 <= vi tri <= %d): ", ds.n);
                scanf("%d", &k);
                themnv(ds, x, k);
            }
            break;
        case 4:
            {
                char ten[20];
                printf("\nNhap ten nhan vien can tim: ");
                scanf("%s", ten);
                int index = timten(ds, ten);
                if (index != -1)
                {
                    printf("\nThong tin nhan vien can tim:\n");
                    xuat1nv(ds.ds[index]);
                }
                else
                {
                    printf("\nKhong tim thay nhan vien co ten %s.\n", ten);
                }
            }
            break;
        case 5:
            {
                int msnv;
                printf("\nNhap ma so nhan vien can tim: ");
                scanf("%d", &msnv);
                int index = timMSNV(ds, msnv);
                if (index != -1)
                {
                    printf("\nThong tin nhan vien can tim:\n");
                    xuat1nv(ds.ds[index]);
                }
                else
                {
                    printf("\nKhong tim thay nhan vien co ma so %d.\n", msnv);
                }
            }
            break;
        case 6:
            {
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
                    xoanv(ds, vitri);
                }
                break;
            }
        case 0:
            printf("\nCam on ban da su dung chuong trinh!");
            break;
        default:
            printf("\nLua chon khong hop le!");
            break;
        }
        printf("\n\n\t\t\t\t\t Nhan phim Enter de tiep tuc\n");
        fflush(stdin);
        getchar();
    }
    while(choose!=0);
}
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

// nhap 1 nv
void nhap1nv(nhanvien &nv)
{
    printf("Nhap MSNV: ");
    scanf("%d", &nv.msnv);
    printf("Nhap ho nhan vien: ");
    scanf("%s", nv.ho);
    printf("Nhap ten nhan vien: ");
    scanf("%s", nv.ten);
    printf("Nhap ngay sinh: \n");
    nhapngaythang(nv.namsinh);
    printf("Nhap noi sinh: ");
    scanf("%s", nv.noisinh);
    printf("Nhap dia chi: ");
    scanf("%s", nv.diachi);
    printf("Nhap luong: ");
    scanf("%f", &nv.luong);
    printf("Nhap ngay vao lam: \n");
    nhapngaythang(nv.ngayvao);
}

// xuat 1 nv
void xuat1nv(nhanvien nv)
{
    printf("%-5d %-15s %-15s %-2d/%-2d/%-10d %-15s %-15s %-12.2f %-2d/%-2d/%-20d\n", nv.msnv, nv.ho, nv.ten, nv.namsinh.ngay, nv.namsinh.thang, nv.namsinh.nam, nv.noisinh, nv.diachi, nv.luong, nv.ngayvao.ngay, nv.ngayvao.thang, nv.ngayvao.nam);
}

//xuat ngay thang
void xuatngaythang(date ntn)
{
    printf("%02d/%02d/%04d", ntn.ngay, ntn.thang, ntn.nam);
}
// nhap danh sach
void nhapdanhsach(danhsach &ds)
{
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &ds.n);

    for (int i = 0; i < ds.n; i++)
    {
        printf("Nhap thong tin nhan vien thu %d:\n", i+1);
        nhap1nv(ds.ds[i]);
    }
}

// xuat danh sach
void xuatdanhsach(danhsach ds)
{
    printf("%-5s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "MSNV", "Ho", "Ten", "Ngay sinh", "Noi sinh", "Dia chi", "Luong", "Ngay vao lam");
    for (int i = 0; i < ds.n; i++)
    {
        xuat1nv(ds.ds[i]);
    }
}

// tim ten
int timten(danhsach ds, char *c)
{
    for (int i = 0; i < ds.n; i++)
    {
        if (strcmp(ds.ds[i].ten, c) == 0)
        {
            return i;
        }
    }
    return -1;
}

// them nv
void themnv(danhsach &ds, nhanvien x, int k)
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
    for (int i = ds.n; i > k; i--)
    {
        ds.ds[i] = ds.ds[i-1];
    }
    ds.ds[k] = x;
    ds.n++;
    printf("\nThem nhan vien thanh cong.");
}

//tim ma nv
int timMSNV(danhsach ds, int d)
{
    for (int i = 0; i < ds.n; i++)
    {
        if (ds.ds[i].msnv == d)
        {
            return i;
        }
    }
    return -1;
}

// xoa nv
void xoanv(danhsach &ds, int d)
{
    if (d < 0 || d >= ds.n)
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

// Main
int main()
{
    menu(); //goi ve ham menu de chay chuong trinh
    return 0;
}
