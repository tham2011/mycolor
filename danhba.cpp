#include <bits/stdc++.h>
using namespace std;
class QlDanhBa
{
private:
    string HoTen;
    int SoDT;
    string Email;

public:
    void nhap()
    {
        cout << "nhap ho ten:" << endl;
        getline(cin, HoTen);
        cout << "nhap so dien thoai:" << endl;
        cin >> SoDT;
        cin.ignore();
        cout << "nhap email:" << endl;
        getline(cin, Email);
        cin.ignore();
    }
    void hienThi()
    {
        cout << "ho ten:" << HoTen << endl;
        cout << "So dien thoai la:" << SoDT << endl;
        cout << "email la:" << Email << endl;
    }
};
int main()
{
    int n;
    cout << "nhap so luong:" << endl;
    cin >> n;
    cin.ignore();
    QlDanhBa DB[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap thong tin thu nhat" << i + 1 << endl;
        DB[i].nhap();
    }
    for (int i = 0; i < n; i++)
    {
        DB[i].hienThi();
    }
    return 0;
}
