#include <iostream>

using namespace std;
class Qlnongnghiep
{
private:
    string tencay;
    float dongia;
    float soluong;
    

public:
    float giaTien()
    {
        return soluong * dongia;
    }
    void nhap()
    {
        cout << "nhap thong tin cho chuong trinh quan ly nong nghiep" << endl;
        cout << "nhap ten cay:";
        getline(cin, tencay);
        cout << "nhap so luong:";
        cin >> soluong;
        cout << "nhap don gia:";
        cin >> dongia ;
        cout <<"\n";
    }
    void in()
    {
        cout << "Thong tin cay:" << endl;
        cout << "ten cay la:" << tencay << endl;
        cout << "gia tien la:" << giaTien() << endl;
        cout << "---------------------------------" << endl;
    }
};
int main()
{
    int n;
    cout << "nhap so luong cay :";
    cin >> n;
    cin.ignore();
    Qlnongnghiep *cay = new Qlnongnghiep[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap cay thu " << i + 1 << endl;
        cay[i].nhap();
        cin.ignore();
    }
    for (int i = 0; i < n; i++)
    {
        cay[i].in();
    }
    delete[] cay;
    return 0;
}
