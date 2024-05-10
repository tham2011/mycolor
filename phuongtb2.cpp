#include <iostream>
#include<math.h>
using namespace std;

void gtbac1(int a, int b){
    if(a!=0){
        int x;
        x=-b/a;
    }
    else{
        cout<<"pt vo nghiem!"<<endl;
    }
}
void gtbac2(int a, int b,int c){
    int deta; int x1, x2;
    deta= b*b-4*(a*c);
    if(deta<0){
        cout<<"Pt vo nghiem!"<<endl;
    }
    else if(deta == 0){
        x1=x2=-b/2*a;
cout<<"Nghiem cua pt la:"<<x1<<endl;
    }
    else if(deta>0){
        x1=-b+sqrt(deta)/2*a;
        x2=-b-sqrt(deta)/2*a;
        cout<<"X1="<<x1<<endl;
        cout<<"X2="<<x2<<endl;
    }
}
int main (){
    int a,b,c;
    cout<<"nhap a"<<endl;
    cin>>a;
    cout<<"nhap b"<<endl;
    cin>>b;
    cout<<"nhap c"<<endl;
    cin>>c;
    if(a==0){
         gtbac1(a,b);
    }
    else{
         gtbac2(a,b,c);
    }

return 0;
}