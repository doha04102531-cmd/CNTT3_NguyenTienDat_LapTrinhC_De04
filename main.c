#include <stdio.h>
#include <string.h>
#define MAX_SP 50

typedef struct {
    int maHang;
    char tenHang[50];
    int soLuong;
    float donGia;
} SanPham;



int themMatHang(SanPham ds[], int n) {
    if (n >= MAX_SP) {
        printf("Danh sach da day!\n");
        return n;
    }
    SanPham sp;
    printf("Nhap ma mat hang: ");
    scanf("%d", &sp.maHang);
    

    getchar();
    printf("Nhap ten mat hang: ");
    fgets(sp.tenHang, sizeof(sp.tenHang), stdin);
    sp.tenHang[strcspn(sp.tenHang, "\n")] = '\0';

    printf("Nhap so luong mat hang: ");
    scanf("%d", &sp.soLuong);
    if(sp.soLuong < 0){
        printf("So luong mat hang phai > 0! Hay nhap lai");
        return n;
    }

    printf("Nhap don gia mat hang: ");
    scanf("%f", &sp.donGia);
    if(sp.donGia < 0){
        printf("Don gia mat hang phai > 0! Hay nhap lai");
        return n;
    }

    ds[n] = sp;
    n++;
    printf("Them mat hang thanh cong!\n");
    return n;
}

void hienThiDanhSach(SanPham ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong!\n");
        return;
    }
    
   
}

void capNhatMatHang(SanPham ds[], int n) {
    int ma;
    printf("Nhap ma mat hang can cap nhat: ");
    scanf("%d", &ma);

    for (int i = 0; i < n; i++) {
        if (ds[i].maHang == ma) {
            getchar();
            printf("Nhap ten mat hang moi: ");
            fgets(ds[i].tenHang, sizeof(ds[i].tenHang), stdin);
            ds[i].tenHang[strcspn(ds[i].tenHang, "\n")] = '\0';

            printf("Nhap so luong moi: ");
            scanf("%d", &ds[i].soLuong);
            if(ds[i].soLuong < 0){
                printf("So luong mat hang phai > 0! Hay nhap lai");
                return;
            }

            printf("Nhap don gia moi: ");
            scanf("%f", &ds[i].donGia);
            if(ds[i].donGia < 0){
                printf("Don gia mat hang phai > 0! Hay nhap lai");
                return;
            }
            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay mat hang!\n");
}

int xoaMatHang(SanPham ds[], int n) {
    int ma;
    printf("Nhap ma mat hang can xoa: ");
    scanf("%d", &ma);
    for (int i = 0; i < n; i++) {
        if (ds[i].maHang == ma) {
            for (int j = i; j < n - 1; j++) {
                ds[j] = ds[j + 1];
            }
            n--;
            printf("Xoa mat hang thanh cong!\n");
            return n;
        }
    }
    printf("Khong tim thay mat hang!\n");
    return n;
}

void timMatHangTheoTen(SanPham ds[], int n) {
    char ten[50];
    int found = 0;
    getchar();
    printf("Nhap ten mat hang can tim: ");
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = '\0';
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].tenHang, ten) != NULL) {
            printf("\nMa: %d - Ten Mat Hang: %s - So Luong: %d - Don Gia: %.2f\n", ds[i].maHang, ds[i].tenHang, ds[i].soLuong, ds[i].donGia);
            found = 1;
        }
    }
    if (found == 0) {
        printf("Khong tim thay mat hang\n");
    }
}



int main() {
    SanPham ds[MAX_SP];
    int n = 0;
    int choice;
    do {
        printf("\n===== QUAN LY MAT HANG =====\n");
        printf("1. Them mat hang\n");
        printf("2. Hien thi danh sach mat hang\n");
        printf("3. Cap nhat mat hang theo ma\n");
        printf("4. Xoa mat hang theo ma\n");
        printf("5. Tim mat hang theo ten\n");
        printf("6. Thong ke kho hang\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                n = themMatHang(ds, n);
                break;
            case 2:
                hienThiDanhSach(ds, n);
                break;
            case 3:
                capNhatMatHang(ds, n);
                break;
            case 4:
                n = xoaMatHang(ds, n);
                break;
            case 5:
                timMatHangTheoTen(ds, n);
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
    return 0;
}

