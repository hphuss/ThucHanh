#include <iostream>
#include"PhanSo.h"

using namespace std;

int main()
{
    PhanSo ps1, ps2;

    cout<<"---NHAP PHAN SO 1---\n";
    cin>>ps1;

    cout<<"---NHAP PHAN SO 2---\n";
    cin>>ps2;

    if(cin.fail()){
        cout<<"ERROR\n";
        return 1;
    }

    cout<<"\nPhan so 1: "<<ps1;
    cout<<"\nPhan so 2: "<<ps2<<"\n";

    PhanSo tong=ps1+ps2;
    PhanSo hieu=ps1-ps2;
    PhanSo tich=ps1*ps2;
    PhanSo thuong=ps1/ps2;

    cout << "\nTong: " << tong;
    cout << "\nHieu: " << hieu;
    cout << "\nTich: " << tich;
    cout << "\nThuong: " << thuong << "\n";

    cout << "\n--- SO SANH ---\n";
    if (ps1 == ps2) cout << "Phan so 1 bang Phan so 2\n";
    if (ps1 > ps2)  cout << "Phan so 1 lon hon Phan so 2\n";
    if (ps1 < ps2)  cout << "Phan so 1 nho hon Phan so 2\n";
}
