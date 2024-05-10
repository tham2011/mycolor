#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct qlcaytrong {
    string Tencay;
    string Loaicay;
    string thoigiantrong;
};

// Hàm thêm cây trồng vào tệp tin
void themcaytrong(const string& tenTep, const qlcaytrong& Caytrong) {
    ofstream outFile(tenTep, ios::app);

    if (outFile.is_open()) {
        outFile << Caytrong.Tencay << "," << Caytrong.Loaicay << "," << Caytrong.thoigiantrong << endl;
        cout << "Da them cay trong thanh cong." << endl;
        outFile.close();
    } else {
        cout << "Khong the mo tao tao tep tin." << endl;
    }
}

// Hàm hiển thị danh sách cây trồng từ tệp tin
void hienThiDanhSachqlcaytrong(const string& tenTep) {
    ifstream inFile(tenTep);

    if (inFile.is_open()) {
        cout << "Danh sach Caytrong:\n";
        string line;

        while (getline(inFile, line)) {
            cout << line << endl;
        }

        inFile.close();
    } else {
        cout << "Khong the mo tep tin de doc." << endl;
    }
}

// Hàm tìm kiếm cây trồng theo tên cây
bool timKiemqlcaytrong(const string& tenTep, const string& tenCayCanTim) {
    ifstream inFile(tenTep);

    if (inFile.is_open()) {
        string line;

        while (getline(inFile, line)) {
            size_t pos = line.find(",");
            string tenCay = line.substr(0, pos);

            if (tenCay == tenCayCanTim) {
                cout << "Thong tin Cay trong:\n" << line << endl;
                inFile.close();
                return true;
            }
        }

        cout << "Khong tim thay thong tin cay trong voi ten " << tenCayCanTim << endl;
        inFile.close();
    } else {
        cout << "Khong the mo tep tin de doc." << endl;
    }

    return false;
}

int main() {
    const string tenTep = "qlcaytrong.txt";

    // Thêm cây trồng
    qlcaytrong cay1 {"Cay A", "Loai A","Mua Xuan" };
    themcaytrong(tenTep, cay1);

    qlcaytrong cay2 {"Cay B", "Loai B","Mua Thu" };
    themcaytrong(tenTep, cay2);

    // Hiển thị danh sách cây trồng
    hienThiDanhSachqlcaytrong(tenTep);

    // Tìm kiếm cây trồng
    string tenCay;
    cout << "Nhap ten cay can tim kiem: ";
    getline(cin, tenCay);

    timKiemqlcaytrong(tenTep, tenCay);

    return 0;
}
