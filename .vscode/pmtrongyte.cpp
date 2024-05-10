#include <iostream>
using namespace std;
class benhnhan{
    private:
    string mabenhnhan;
    string tenbn;
    string benh;
    string thuocdieutri;
    double ngayvao;
    public:
    benhnhan(){}
    void nhapthongtin(){
        cout<<"nhap ma benh nhan:";
        getline(cin,mabenhnhan);
        cout<<"nhap ten benh nhan:";
        getline(cin,tenbn);
        cout<<"nhap ten benh:";
        getline(cin,benh);
        cout<<" nhap thuoc dieu tri:";
        getline(cin,thuocdieutri);
        cout<<"nhap ngay vao:";
        cin>>ngayvao;
        cin.ignore();

    }
    void hienthithongtin()
    const {
        cout<<"ma benh nhan:"<<mabenhnhan<<endl;
        cout<<"ten benh nhan:"<<tenbn<<endl;
        cout<<" ten benh:"<<benh<<endl;
        cout<<"thuoc dieu tri:"<<thuocdieutri<<endl;
        cout<<"ngay vao vien:"<<ngayvao<<endl;

    }
    






};
int main(){


}



