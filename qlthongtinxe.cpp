#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct XeOto {
    string bienSoXe;
    string hangSanXuat;
    string chusohuu;
    int namSanXuat;
};

// Hàm để thêm thông tin xe ô tô vào tệp tin
void themThongTinXeOto(const string& tenTep, const XeOto& xe) {
    ofstream outFile(tenTep, ios::app);

    if (outFile.is_open()) {
        outFile << xe.bienSoXe << "," << xe.hangSanXuat << "," << xe.namSanXuat << "," << xe.chusohuu << endl;
        cout << "Đã thêm thông tin xe ô tô thành công." << endl;
        outFile.close();
    } else {
        cout << "Không thể mở tạo tệp tin." << endl;
    }
}

// Hàm để hiển thị danh sách xe ô tô từ tệp tin
void hienThiDanhSachXeOto(const string& tenTep) {
    ifstream inFile(tenTep);

    if (inFile.is_open()) {
        cout << "Danh sách xe ô tô:" << endl;
        string line;

        while (getline(inFile, line)) {
            cout << line << endl;
        }

        inFile.close();
    } else {
        cout << "Không thể mở tệp tin để đọc." << endl;
    }
}

// Hàm để tìm kiếm thông tin xe ô tô theo biển số xe
bool timKiemXeOtoTheoBienSo(const string& tenTep, const string& bienSoCanTim) {
    ifstream inFile(tenTep);

    if (inFile.is_open()) {
        string line;

        while (getline(inFile, line)) {
            size_t pos = line.find(",");
            string bienSoXe = line.substr(0, pos);

            if (bienSoXe == bienSoCanTim) {
                cout << "Thông tin xe ô tô:\n" << line << endl;
                inFile.close();
                return true;
            }
        }

        cout << "Không tìm thấy thông tin xe ô tô với biển số " << bienSoCanTim << endl;
        inFile.close();
    } else {
        cout << "Không thể mở tệp tin để đọc." << endl;
    }

    return false;
}

int main() {
    const string tenTep = "thongtin_xeoto.txt";

    int choice;
    string bienSoCanTim;

    do {
        cout << "\nChọn chức năng:" << endl;
        cout << "1. Thêm thông tin xe ô tô" << endl;
        cout << "2. Hiển thị danh sách xe ô tô" << endl;
        cout << "3. Tìm kiếm ô tô theo biển số" << endl;
        cout << "4. Thoát chương trình" << endl;

        cout << "Nhập lựa chọn của bạn (1/2/3/4): ";
        cin >> choice;
        cin.ignore(); // Xóa bộ đệm sau khi nhập lựa chọn

        switch (choice) {
            case 1: {
                XeOto xe;
                cout << "Nhập biển số xe: ";
                cin.ignore(); // Xóa ký tự newline còn tồn tại sau khi nhập lựa chọn trước đó
                getline(cin, xe.bienSoXe);
                cout << "Nhập hãng sản xuất: ";
                getline(cin, xe.hangSanXuat);
                cout << "Nhập năm sản xuất: ";
                cin >> xe.namSanXuat;
                cout << "Nhập chủ sở hữu : ";
cin.ignore(); // Xóa ký tự newline còn tồn tại sau khi nhập năm sản xuất
                getline(cin, xe.chusohuu);

                themThongTinXeOto(tenTep, xe);
                break;
            }
            case 2: {
                hienThiDanhSachXeOto(tenTep);
                break;
            }
            case 3: {
                cout << "Nhập biển số xe cần tìm kiếm: ";
                cin.ignore(); // Xóa ký tự newline còn tồn tại sau khi nhập lựa chọn trước đó
                getline(cin, bienSoCanTim);
                timKiemXeOtoTheoBienSo(tenTep, bienSoCanTim);
                break;
            }
            case 4:
                cout << "Đã thoát chương trình." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
        }
    } while (choice != 4);

    return 0;
}
