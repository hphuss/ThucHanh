#include <iostream>
#include "SoPhuc.h"
#include <limits>
#include <iomanip>

using namespace std;
int SoPhuc::NhapSoNguyen()
{
    int n;
    while (true) {
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Vui long chi nhap so nguyen: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return n;
        }
    }
}
void SoPhuc::Nhap()
{
    cout<<"Nhap phan thuc: ";
    iThuc=NhapSoNguyen();
    cout<<"Nhap phan ao: ";
    iAo=NhapSoNguyen();
}
SoPhuc SoPhuc::Tong(SoPhuc sp2)
{
    SoPhuc kq;
    kq.iThuc=this->iThuc+sp2.iThuc;
    kq.iAo=this->iAo+sp2.iAo;
    return kq;
}
SoPhuc SoPhuc::Hieu(SoPhuc sp2)
{
    SoPhuc kq;
    kq.iThuc=this->iThuc-sp2.iThuc;
    kq.iAo=this->iAo-sp2.iAo;
    return kq;
}
SoPhuc SoPhuc::Tich(SoPhuc sp2)
{
    SoPhuc kq;
    kq.iThuc=(this->iThuc*sp2.iThuc)-(this->iAo*sp2.iAo);
    kq.iAo=(this->iThuc*sp2.iAo)+(this->iAo*sp2.iThuc);
    return kq;
}
SoPhuc SoPhuc::Thuong(SoPhuc sp2)
{
    SoPhuc kq;
    double mau=(sp2.iThuc*sp2.iThuc)+(sp2.iAo*sp2.iAo);
    //Kiem tra mau bang 0
    if (mau==0){
        cout<<"\nMau so bang 0, khong the chia.\n";
        kq.iThuc=0;
        kq.iAo=0;
        return kq;
    }
    kq.iThuc = (this->iThuc * sp2.iThuc + this->iAo * sp2.iAo) / mau;
    kq.iAo = (this->iAo * sp2.iThuc - this->iThuc * sp2.iAo) / mau;
    return kq;
}
void SoPhuc::Xuat() {
    //Thuc va Ao deu bang 0
    if (iThuc == 0 && iAo == 0) {
        cout << 0;
        return;
    }

    // In phan thuc khac 0
    if (iThuc != 0) {
        if (iThuc == (int)iThuc) {
            cout << (int)iThuc; //Khong phai so thap phan thi giu nguyen
        } else {
            cout << fixed << setprecision(2) << iThuc << defaultfloat; // La so thap phan thi in 2 chu so
        }
    }

    //In phan thuc khac 0
    if (iAo != 0) {
        //In dau cong tru
        if (iThuc != 0) {
            cout << (iAo > 0 ? " + " : " - ");
        } else if (iAo < 0) {
            cout << "-"; //Neu khong co phan thuc va ao am thi bo dau tru len tren
        }

        double absAo = abs(iAo);

        //In phan ao
        if (absAo == (int)absAo) {
            cout << (int)absAo;
        } else {
            cout << fixed << setprecision(2) << absAo << defaultfloat;
        }
        cout << "i";
    }
}
