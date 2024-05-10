#include <stdio.h>
#include <string.h>

struct SinhVien
{
    char MaSV[10];
    char HoTen[50];  // Tăng kích thước mảng để chứa họ tên có dấu cách
    char MonHoc[30]; // Tăng kích thước mảng để chứa tên môn học có dấu cách
    float DiemCC;
    float DiemGK;
    float DiemThi;
};
typedef struct SinhVien SV;

float DiemMH(SV sv)
{
    return (sv.DiemCC + 3 * sv.DiemGK + 6 * sv.DiemThi) / 10;
}

void GhiFILE(SV sv[], int n)
{
    FILE *f = fopen("sinhvien.txt", "w");
    if (f == NULL)
    {
        printf("tao file that bai!\n");
    }
    else
    {
        printf("tao file thanh cong!\n");
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%s\n%s\n%s\n%.2f\n%.2f\n%.2f\n", sv[i].MaSV, sv[i].HoTen, sv[i].MonHoc, sv[i].DiemCC, sv[i].DiemGK, sv[i].DiemThi);
    }
    fclose(f);
}

void DocFILE()
{
    FILE *f = fopen("sinhvien.txt", "r");
    SV sv;
    int i = 1;
    printf("STT  |  Ho Va Ten    | Mon Hoc  | Diem MH\n");
    while (fscanf(f, "%[^\n]\n%[^\n]\n%[^\n]\n%f\n%f\n%f\n", sv.MaSV, sv.HoTen, sv.MonHoc, &sv.DiemCC, &sv.DiemGK, &sv.DiemThi) == 6)
    // while (fscanf(f, "%s\n%s\n%s\n%f\n%f\n%f\n", sv.MaSV, sv.HoTen, sv.MonHoc, &sv.DiemCC, &sv.DiemGK, &sv.DiemThi) == 6)

    {
        printf("%d | %s | %s | %.2f\n", i, sv.HoTen, sv.MonHoc, DiemMH(sv));
        i++;
    }
    fclose(f);
}

int main()
{
    int n;
    printf("nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); // Loại bỏ ký tự xuống dòng từ bộ đệm đầu vào
    SV sv[n];
    for (int i = 0; i < n; i++)
    {
        printf("nhap thong tin cho sinh vien thu %d:\n", i + 1);
        printf("nhap ma sinh vien: ");
        fgets(sv[i].MaSV, sizeof(sv[i].MaSV), stdin);
        sv[i].MaSV[strcspn(sv[i].MaSV, "\n")] = 0; // Loại bỏ ký tự xuống dòng
        printf("nhap ho ten sinh vien: ");
        fgets(sv[i].HoTen, sizeof(sv[i].HoTen), stdin);
        sv[i].HoTen[strcspn(sv[i].HoTen, "\n")] = 0; // Loại bỏ ký tự xuống dòng
        printf("Mon hoc: ");
        fgets(sv[i].MonHoc, sizeof(sv[i].MonHoc), stdin);
        sv[i].MonHoc[strcspn(sv[i].MonHoc, "\n")] = 0; // Loại bỏ ký tự xuống dòng
        printf("Diem chuyen can: ");
        scanf("%f", &sv[i].DiemCC);
        printf("Diem giua ky: ");
        scanf("%f", &sv[i].DiemGK);
        printf("Diem thi: ");
        scanf("%f", &sv[i].DiemThi);
        getchar(); // Loại bỏ ký tự xuống dòng từ bộ đệm đầu vào
    }
    GhiFILE(sv, n);
    DocFILE();
    return 0;
}
