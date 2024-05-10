#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class SinhVien {
private:
    string maSinhVien;
    string tenSinhVien;
    double diemTrungBinh;

public:
    void nhapThongTin() {
        cout << "Nhap ma sinh vien: ";
        getline(cin, maSinhVien);

        cout << "Nhap ten sinh vien: ";
        getline(cin, tenSinhVien);

        cout << "Nhap diem trung binh: ";
        cin >> diemTrungBinh;
        cin.ignore();  // Đọc bỏ ký tự Enter trong bộ nhớ đệm
    }

    void hienThiThongTin() const {
        cout << "Ma sinh vien: " << maSinhVien << ", Ten sinh vien: " << tenSinhVien
                  << ", Diem trung binh: " << diemTrungBinh << endl;
    }

    friend ostream& operator<<(ostream& os, const SinhVien& sinhVien) {
        os << sinhVien.maSinhVien << "," << sinhVien.tenSinhVien << "," << sinhVien.diemTrungBinh;
        return os;
    }
};

class QuanLySinhVien {
private:
    vector<SinhVien> danhSachSinhVien;

public:
    void themSinhVien(const SinhVien& sinhVien) {
        danhSachSinhVien.push_back(sinhVien);
    }

    void hienThiDanhSach() const {
        for (const auto& sinhVien : danhSachSinhVien) {
            sinhVien.hienThiThongTin();
        }
    }

    void luuVaoTep(const string& tenTep) const {
        ofstream outFile(tenTep);
        if (outFile.is_open()) {
            for (const auto& sinhVien : danhSachSinhVien) {
                outFile << sinhVien << endl;
            }
            outFile.close();
        } else {
            cerr << "Khong the mo tao tao tep tin." << endl;
        }
    }

    void docTuTep(const string& tenTep) {
        ifstream inFile(tenTep);
        if (inFile.is_open()) {
            danhSachSinhVien.clear(); // Xóa danh sách hiện tại trước khi đọc mới
            string line;
            while (getline(inFile, line)) {
                istringstream iss(line);
                string ma, ten;
                double diem;
                getline(iss, ma, ',');
                getline(iss, ten, ',');
                iss >> diem;
                themSinhVien(SinhVien{ma, ten, diem});
            }
            inFile.close();
        } else {
            cerr << "Khong the mo tao tao tep tin." << endl;
        }
    }
};

int main() {
    QuanLySinhVien quanLySinhVien;

    // Thêm và hiển thị thông tin sinh viên
    SinhVien sv1;
    sv1.nhapThongTin();
    quanLySinhVien.themSinhVien(sv1);

    SinhVien sv2;
    sv2.nhapThongTin();
    quanLySinhVien.themSinhVien(sv2);

    cout << "\nDanh sach sinh vien:\n";
    quanLySinhVien.hienThiDanhSach();

    // Lưu vào tệp và đọc từ tệp
    quanLySinhVien.luuVaoTep("danhSachSinhVien.txt");
    quanLySinhVien.docTuTep("danhSachSinhVien.txt");

    cout << "\nDanh sach sinh vien sau khi doc tu tep:\n";
    quanLySinhVien.hienThiDanhSach();

    return 0;
}