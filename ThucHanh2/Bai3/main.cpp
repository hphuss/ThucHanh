#include <iostream>
#include "SoPhuc.h"
using namespace std;

int main()
{
    SoPhuc sp1, sp2;
    cout<<"NHAP SO PHUC 1: \n"; sp1.Nhap();
    cout<<"NHAP SO PHUC 2: \n"; sp2.Nhap();
    cout<<"SO PHUC 1: "; sp1.Xuat();
    cout<<"\nSO PHUC 2: "; sp2.Xuat();

    SoPhuc tong=sp1.Tong(sp2);
    SoPhuc hieu=sp1.Hieu(sp2);
    SoPhuc tich=sp1.Tich(sp2);
    SoPhuc thuong=sp1.Thuong(sp2);

    cout<<"\nTONG: "; tong.Xuat();
    cout<<"\nHIEU: ";hieu.Xuat();
    cout<<"\nTICH: "; tich.Xuat();
    cout<<"\nTHUONG: ";thuong.Xuat();
    return 0;
}
