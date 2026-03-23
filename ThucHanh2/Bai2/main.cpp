#include <iostream>
#include "PhanSo.h"

using namespace std;

int main()
{
    PhanSo a,b;
    cout<<"NHAP PHAN SO A:\n";
    a.Nhap();
    cout<<"NHAP PHAN SO B:\n";
    b.Nhap();
    cout<<"PHAN SO A:";
    a.RutGon();
    a.Xuat();
    cout<<"\nPHAN SO B:";
    b.RutGon();
    b.Xuat();

    PhanSo tong = a.Tong(b);
    PhanSo hieu = a.Hieu(b);
    PhanSo tich = a.Tich(b);
    PhanSo thuong=a.Thuong(b);

    cout<<"\nTONG: ";tong.Xuat();cout<<"\n";
    cout<<"HIEU: ";hieu.Xuat();cout<<"\n";
    cout<<"TICH: ";tich.Xuat();cout<<"\n";
    cout<<"THUONG: ";thuong.Xuat();cout<<"\n";

    int cmp = a.SoSanh(b);
    if(cmp==1) cout<<"A>B\n";
    else if(cmp==-1)cout<<"A<B\n";
    else cout<<"A=B\n";
    return 0;
}
