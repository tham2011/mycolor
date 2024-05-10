#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class NhanVien
{
public:
    string maNhanVien;
    string ten;
    double luong;

    NhanVien() {}

    NhanVien(string maNhanVien, string ten, double luong)
    {
        this->maNhanVien = maNhanVien;
        this->ten = ten;
        this->luong = luong;
    }

    void nhapThongTin()
    {
        cout << "nhap ma nhan vien: ";
        getline(cin, maNhanVien);
        cout << "nhap ten nhan vien: ";
        getline(cin, ten);
        cout << "nhap luong: ";
        cin >> luong;
        cin.ignore();
    }
};

class QuanLyNhanVien
{
private:
    vector<NhanVien> nhanVien;

public:
    void themNhanVien(NhanVien nv)
    {
        nhanVien.push_back(nv);
    }

    void xoaNhanVien(string maNhanVien)
    {
        for (int i = 0; i < nhanVien.size(); i++)
        {
            if (nhanVien[i].maNhanVien == maNhanVien)
            {
                nhanVien.erase(nhanVien.begin() + i);
                break;
            }
        }
    }

    void suaNhanVien(string maNhanVien)
    {
        for (int i = 0; i < nhanVien.size(); i++)
        {
            if (nhanVien[i].maNhanVien == maNhanVien)
            {
                cout << "Nhap thong tin moi cho nhan vien: " << maNhanVien << endl;
                nhanVien[i].nhapThongTin();
                break;
            }
        }
    }

    void hienThiNhanVien()
    {
        for (int i = 0; i < nhanVien.size(); i++)
        {
            cout << "----------------------------------------------------" << endl;
            cout << "Ma Nhan Vien: " << nhanVien[i].maNhanVien << endl;
            cout << "Ten: " << nhanVien[i].ten << endl;
            cout << "Luong: " << nhanVien[i].luong << endl;
            cout << "----------------------------------------------------" << endl;
        }
    }

    void luuNhanVien()
    {
        ofstream file;
        file.open("nhanvien.txt");
        for (int i = 0; i < nhanVien.size(); i++)
        {
            file << nhanVien[i].maNhanVien << endl;
            file << nhanVien[i].ten << endl;
            file << nhanVien[i].luong << endl;
        }
        file.close();
    }

    void docNhanVien()
    {
        ifstream file;
        file.open("nhanvien.txt");
        string maNhanVien;
        string ten;
        double luong;
        while (file >> maNhanVien >> ten >> luong)
        {
            NhanVien nv(maNhanVien, ten, luong);
            nhanVien.push_back(nv);
        }
        file.close();
    }
};

int main()
{
    QuanLyNhanVien qlnv;
    int luachon;
    do
    {
        cout << "1.Them nhan vien" << endl;
        cout << "2.Sua thong tin nhan vien" << endl;
        cout << "3.Xoa thong tin nhan vien" << endl;
        cout << "4.Hien thi thong tin nhan vien" << endl;
        cout << "5.Luu thong tin nhan vien" << endl;
        cout << "6.Thoat" << endl;
        cout << "Nhap lua chon:";
        cin >> luachon;
        cin.ignore();
switch (luachon)
        {
        case 1:
        {
            NhanVien nhanvien;
            nhanvien.nhapThongTin();
            qlnv.themNhanVien(nhanvien);
            break;
        }
        case 2:
        {
            string maNhanVien;
            cout << "Nhap ma nhan vien can sua: ";
            getline(cin, maNhanVien);
            qlnv.suaNhanVien(maNhanVien);
            break;
        }
        case 3:
        {
            string maNhanVien;
            cout << "Nhap ma nhan vien can xoa: ";
            getline(cin, maNhanVien);
            qlnv.xoaNhanVien(maNhanVien);
            break;
        }
        case 4:
        {
            qlnv.hienThiNhanVien();
            break;
        }
        case 5:
        {
            qlnv.luuNhanVien();
            break;
        }
        case 6:
        {
            break;
        }

        default:
        {
            cout << "\n Lua chon ko hop le vui long nhap lai!" << endl;
            break;
        }
        }
    } while (luachon != 6);

    return 0;
}
