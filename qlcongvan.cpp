#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class CongVan
{
    int soCongVan;
    string ngayBanHanh;
    string noiDung;
    public:
public:
    CongVan() {}

    CongVan(int soCongVan, string ngayBanHanh, string noiDung)
    {
        this->soCongVan = soCongVan;
        this->ngayBanHanh = ngayBanHanh;
        this->noiDung = noiDung;
    }

    void nhapThongTin()
    {
        cout << "Nhap so cong van: ";
        cin >> soCongVan;
        cout << "Nhap ngay ban hanh: ";
        cin >> ngayBanHanh;
        cout << "Nhap noi dung: ";
        cin.ignore();
        getline(cin, noiDung);
    }

    void hienThiThongTin()
    {
        cout << "So cong van: " << soCongVan << endl;
        cout << "Ngay ban hanh: " << ngayBanHanh << endl;
        cout << "Noi dung: " << noiDung << endl;
    }

    void luuVaoTep(string tenTep)
    {
        ofstream outFile(tenTep, ios::app);
        outFile << soCongVan << "\n"
                << ngayBanHanh << "\n"
                << noiDung << "\n";
        outFile.close();
    }
};

class QuanLyCongVan
{
    vector<CongVan> danhSachCongVan;

public:
    void themCongVan(CongVan cv)
    {
        danhSachCongVan.push_back(cv);
    }

    void hienThiDanhSach()
    {
        for (auto &cv : danhSachCongVan)
        {
            cv.hienThiThongTin();
        }
    }

    void luuDanhSachVaoTep(string tenTep)
    {
        for (auto &cv : danhSachCongVan)
        {
            cv.luuVaoTep(tenTep);
        }
    }

    void docDanhSachTuTep(string tenTep)
    {
        ifstream inFile(tenTep);
        int soCongVan;
        string ngayBanHanh;
        string noiDung;

        while (inFile >> soCongVan >> ngayBanHanh)
        {
            getline(inFile, noiDung);
            CongVan cv(soCongVan, ngayBanHanh, noiDung);
            danhSachCongVan.push_back(cv);
        }

        inFile.close();
    }
};

int main()
{
    QuanLyCongVan qlcv;
    int luaChon;
    do
    {
        cout << "1. Them cong van\n";
        cout << "2. Hien thi danh sach cong van\n";
        cout << "3. Luu danh sach vao tep\n";
        cout << "4. Doc danh sach vao tep\n";
        cout << "5. Thoat\n";
        cout << "Nap lua chon: ";
        cin >> luaChon;

        switch (luaChon)
        {
        case 1:
        {
            CongVan cv;
            cv.nhapThongTin();
            qlcv.themCongVan(cv);
            break;
        }
        case 2:
        {
            qlcv.hienThiDanhSach();
            break;
        }
        case 3:
        {
            qlcv.luuDanhSachVaoTep("congvan.txt");
            break;
        }
        case 4:
        {
            qlcv.docDanhSachTuTep("congvan.txt");
            break;
        }
        case 5:
        {
            cout << "Thoat khoi chuong trinh.\n";
            break;
        }
        default:
        {
            cout << "Lua chon ko hop le vui long nhap lua chon lai.\n";
            break;
        }
        }
    } while (luaChon != 5);

    return 0;
}