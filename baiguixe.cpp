#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;

class Xe
{
private:
    string veXe;
    string bienSo;

public:
    void nhap();
    void in();
    void setXe(string veXe, string bienSo)
    {
        this->veXe = veXe;
        this->bienSo = bienSo;
    }
    string getveXe()
    {
        return veXe;
    }
    string getbienSo()
    {
        return bienSo;
    }
    void DateTime()
    {
        time_t now = time(0);
        tm *t = localtime(&now);

        cout << "Thong tin ngay va gio: "
             << t->tm_mday << "/" << 1 + t->tm_mon << "/" << 1900 + t->tm_year << " " << t->tm_hour << ":" << t->tm_min << ":" << t->tm_sec << endl;
    }
    void inThongTin()
    {
        cout << "================================" << endl;
        in();
        cout << "================================" << endl;
    }
};

void Xe::nhap()
{
    cout << "Nhap ve xe:";
    getline(cin, veXe);
    cout << "Nhap bien so xe:";
    getline(cin, bienSo);
}

void Xe::in()
{
    cout << "Thong tin ve xe:" << getveXe() << endl;
    cout << "Thong tin bien so xe:" << getbienSo() << endl;
    DateTime();
}

class Ql_Xe : public Xe
{
private:
    vector<Xe> dsXe;
    int doanhThu;

public:
    Ql_Xe() : doanhThu(0) {} // Khởi tạo doanh thu bằng 0

    void themXe(Xe xe)
    {
        dsXe.push_back(xe);
    }

    void tienVe()
    {
        cout << "0_la xe may: 1_la oto" << endl;
        cout << "Vui long nhap lua chon:";
        int luachon;
        cin >> luachon;
        cin.ignore();
        if (luachon == 0)
        {
            cout << "So tien cua ban phai tra la: 5.000VND" << endl;
            doanhThu += 5000; // Cập nhật doanh thu
        }
        else if (luachon == 1)
        {
            cout << "So tien ma ban phai tra la 20.000VND" << endl;
            doanhThu += 20000; // Cập nhật doanh thu
        }
        else
        {
            cout << "Lua chon cua ban ko hop le!" << endl;
        }
        luuDoanhThu();
    }

    void timKiemXe()
    {
        string bienSoXe;
        cout << "Nhap bien so xe can tim:";
        getline(cin, bienSoXe);

        bool found = false;
        for (int i = 0; i < dsXe.size(); i++)
        {
            if (bienSoXe == dsXe[i].getbienSo())
            {
                dsXe[i].inThongTin();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Khong co thong tin ve xe!" << endl;
        }
    }

    void XuatXe()
    {
        string vexe;
        cout << "Nhap ve xe cua ban de lay xe:";
        getline(cin, vexe);

        bool found = false;
        for (int i = 0; i < dsXe.size(); i++)
        {
            if (vexe == dsXe[i].getveXe())
            {
                cout << "Ve xe " << vexe << " cua ban dung." << endl;
                cout << "Cam on ban da su dung dich vu cua chung toi!" << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Ve xe " << vexe << " khong hop le!" << endl;
            cout << "Vui long kiem tra lai ve xe cua ban." << endl;
        }
    }

    void luuThongTin()
    {
        ofstream file("thongtin.txt", ios::app);
        for (int i = 0; i < dsXe.size(); i++)
        {
            file << "Ve xe: " << dsXe[i].getveXe() << endl;
            file << "Bien so xe: " << dsXe[i].getbienSo() << endl;
            file << " ";
            dsXe[i].DateTime();
        }
        file.close();
    }

    void luuDoanhThu()
    {
        ofstream file("doanhthu.txt", ios::app);
        file << "Doanh thu trong ngay la: " << doanhThu << "VND" << endl;
        file.close();
    }

    void tinhTongDoanhThu()
    {
        ifstream file("doanhthu.txt");
        string line;
        int tongDoanhThu = 0;
        while (getline(file, line))
        {
            size_t pos = line.find(": ");
            if (pos != string::npos)
            {
                string strDoanhThu = line.substr(pos + 2, line.length() - pos - 5); // Loại bỏ "VND" và dấu cách
                tongDoanhThu += stoi(strDoanhThu);
            }
        }
        file.close();
        cout << "Tong doanh thu la: " << tongDoanhThu << "VND" << endl;
    }

    // New method to get dsXe vector
    vector<Xe> &getDsXe()
    {
        return dsXe;
    }
};

void menu()
{
    cout << "1.Nhap thong tin khach hang" << endl;
    cout << "2.In thong tin khach hang" << endl;
    cout << "3.Tien ve phai tra" << endl;
    cout << "4.Tim kiem thong tin xe" << endl;
    cout << "5.Xuat xe" << endl;
    cout << "6.Tinh tong doanh thu" << endl;
    cout << "7.Thoat khoi chuong trinh" << endl;
}

int main()
{
    Ql_Xe xe;
    menu();
    int luachon;
    do
    {
        cout << "Vui long nhap lua chon:";
        cin >> luachon;
        cin.ignore();
        switch (luachon)
        {
        case 1:
        {
            Xe new_xe; // create a new instance of Xe
            new_xe.nhap();
            xe.themXe(new_xe); // Thêm xe vào danh sách sau khi nhập thông tin
            xe.luuThongTin();
            break;
        }
        case 2:
            for (int i = 0; i < xe.getDsXe().size(); i++)
            {
                xe.getDsXe()[i].inThongTin();
            }
            break;
        case 3:
            xe.tienVe();
            break;
        case 4:
            xe.timKiemXe();
            break;
        case 5:
            xe.XuatXe();
            break;
        case 6:
            xe.tinhTongDoanhThu(); // Tính tổng doanh thu khi được chọn
            break;
        case 7:
            break;
        default:
            cout << "Lua chon ko hop le!" << endl;
            break;
        }
    } while (luachon != 7);
    return 0;
}