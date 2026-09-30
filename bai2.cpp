#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][15];
    char tenSach[MAX][50];
    int soNgayMuon[MAX];
    int tienPhat[MAX];

    int soLuong = 0;
    int luaChon;

    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH ================\n");
        printf("1. Them luot muon sach moi\n");
        printf("2. Hien thi danh sach muon sach\n");
        printf("3. Cap nhat so ngay muon theo Ma phieu\n");
        printf("4. Xoa luot muon sach theo Ma phieu\n");
        printf("5. Thong ke danh sach phieu muon bi phat\n");
        printf("6. Thoat chuong trinh\n");
        printf("=================================================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        while (getchar() != '\n');

        switch (luaChon) {
            case 1: {
                if (soLuong >= MAX) {
                    printf("He thong day, khong the them phieu muon moi!\n");
                    break;
                }

                int trungMa;

                do {
                    trungMa = 0;

                    printf("Nhap ma phieu muon: ");
                    scanf("%s", maPhieu[soLuong]);
                    while (getchar() != '\n');

                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maPhieu[soLuong]) == 0) {
                            trungMa = 1;
                            break;
                        }
                    }

                    if (trungMa == 1) {
                        printf("Ma phieu da ton tai! Vui long nhap lai.\n");
                    }

                } while (trungMa == 1);

                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], 50, stdin);

                if (tenSach[soLuong][strlen(tenSach[soLuong]) - 1] == '\n') {
                    tenSach[soLuong][strlen(tenSach[soLuong]) - 1] = '\0';
                }

                do {
                    printf("Nhap so ngay muon thuc te: ");
                    scanf("%d", &soNgayMuon[soLuong]);
                    while (getchar() != '\n');

                    if (soNgayMuon[soLuong] <= 0) {
                        printf("So ngay muon phai lon hon 0!\n");
                    }

                } while (soNgayMuon[soLuong] <= 0);

                if (soNgayMuon[soLuong] > 14) {
                    tienPhat[soLuong] =
                        (soNgayMuon[soLuong] - 14) * 5000;
                } else {
                    tienPhat[soLuong] = 0;
                }

                printf("Tien phat tu dong tinh: %d VNÐ\n",
                       tienPhat[soLuong]);

                soLuong++;

                printf("Them luot muon sach thanh cong!\n");
                break;
            }

            case 2: {
                if (soLuong == 0) {
                    printf("Danh sach muon sach hien dang rong!\n");
                    break;
                }

                int tongTienPhat = 0;

                printf("\n================ DANH SACH MUON SACH ================\n");
                printf("%-5s | %-10s | %-30s | %-10s | %-15s\n",
                       "STT", "Ma Phieu", "Ten Sach",
                       "So Ngay", "Tien Phat");
                printf("--------------------------------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    printf("%-5d | %-10s | %-30s | %-10d | %-15d\n",
                           i + 1,
                           maPhieu[i],
                           tenSach[i],
                           soNgayMuon[i],
                           tienPhat[i]);

                    tongTienPhat += tienPhat[i];
                }

                printf("--------------------------------------------------------------------------\n");
                printf("Tong tien phat toan he thong: %d VNÐ\n",
                       tongTienPhat);

                break;
            }

            case 3: {
                char maNhap[15];
                int index = -1;
                int ngayMoi;

                printf("\n=== CAP NHAT SO NGAY MUON ===\n");
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%s", maNhap);
                while (getchar() != '\n');

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n",
                           maNhap);
                } else {
                    printf("Tim thay phieu muon cua sach: %s\n",
                           tenSach[index]);
                    printf("So ngay hien tai: %d\n",
                           soNgayMuon[index]);

                    do {
                        printf("Nhap so ngay muon thuc te moi: ");
                        scanf("%d", &ngayMoi);
                        while (getchar() != '\n');

                        if (ngayMoi <= 0) {
                            printf("So ngay muon phai lon hon 0!\n");
                        }

                    } while (ngayMoi <= 0);

                    soNgayMuon[index] = ngayMoi;

                    if (soNgayMuon[index] > 14) {
                        tienPhat[index] =
                            (soNgayMuon[index] - 14) * 5000;
                    } else {
                        tienPhat[index] = 0;
                    }

                    printf("Tien phat moi: %d VNÐ\n",
                           tienPhat[index]);
                    printf("Cap nhat so ngay muon thanh cong!\n");
                }

                break;
            }

            case 4: {
                char maNhap[15];
                int index = -1;

                printf("\n=== XOA PHIEU MUON ===\n");
                printf("Nhap ma phieu muon can xoa: ");
                scanf("%s", maNhap);
                while (getchar() != '\n');

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n",
                           maNhap);
                } else {
                    for (int i = index; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(tenSach[i], tenSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                        tienPhat[i] = tienPhat[i + 1];
                    }

                    soLuong--;

                    printf("Xoa phieu muon thanh cong!\n");
                }

                break;
            }

            case 5: {
                int coPhieuPhat = 0;

                printf("\n=== DANH SACH PHIEU MUON BI PHAT ===\n");

                for (int i = 0; i < soLuong; i++) {
                    if (soNgayMuon[i] > 14) {
                        printf("Ma phieu: %s | Ten sach: %s | "
                               "So ngay: %d | Tien phat: %d VNÐ\n",
                               maPhieu[i],
                               tenSach[i],
                               soNgayMuon[i],
                               tienPhat[i]);

                        coPhieuPhat = 1;
                    }
                }

                if (coPhieuPhat == 0) {
                    printf("Khong co luot muon nao bi qua han phat!\n");
                }

                break;
            }

            case 6:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }

    } while (luaChon != 6);

    return 0;
}
