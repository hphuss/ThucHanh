#include "PhanSo.h"
#include <iostream>
#include <limits>
using namespace std;
//Tìm UCLN Đầu vào: tử, mẫu Đầu ra: UCLN của tử và mẫu
int PhanSo::timUCLN(int a, int b)
{
    if (b==0) return a;
    return timUCLN(b, a%b);
}
//Kiểm tra đó phải là nhập số nguyên không có ký tự đặc biệt
int PhanSo::nhapSoNguyen()
{
    int n;
    while (true) {
        cin >> n;
        if (cin.fail()) { // Nếu nhập chữ hoặc ký tự đặc biệt
            cin.clear(); // Xóa trạng thái lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ nhớ đệm
            cout << "Loi! Vui long chi nhap so nguyen: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa ký tự thừa còn lại
            return n;
        }
    }
}
//Hàm nhập phân số, input a kiểu PhanSo
void PhanSo::Nhap()
{
    cout<<"Tu So: "; iTu=nhapSoNguyen();
    do{
        cout<<"Mau So (khac 0): "; iMau=nhapSoNguyen();
        if(iMau==0) cout<<"Mau so phai khac 0. Vui long nhap lai!\n";
    }while (iMau==0);
}
//Hàm xuất phân số, input a kiểu PhanSo, output dạng phân số a/b
void PhanSo::Xuat()
{
    if(iMau==1) cout<<iTu;
    else if(iMau==-1) cout<<-iTu;
    else if(iMau<0) cout<<-iTu<<"/"<<-iMau;
    else cout<<iTu<<"/"<<iMau;
}
void PhanSo::RutGon()
{
    int ucln=timUCLN(iTu, iMau);//Tìm UCNL của tử và mẫu
    iTu /= ucln;//Rút gọn tử
    iMau /= ucln;//Rút gọn Mẫu
}
//Hàm tính Tổng, Đầu vào
PhanSo PhanSo::Tong (PhanSo ps2)
{
    PhanSo kq;
    kq.iTu = iTu*ps2.iMau + iMau*ps2.iTu;
    kq.iMau = iMau*ps2.iMau;
    kq.RutGon();
    return kq;
}
PhanSo PhanSo::Hieu (PhanSo ps2)
{
    PhanSo kq;
    kq.iTu = iTu*ps2.iMau - iMau*ps2.iTu;
    kq.iMau = iMau*ps2.iMau;
    kq.RutGon();
    return kq;
}
PhanSo PhanSo::Tich (PhanSo ps2)
{
    PhanSo kq;
    kq.iTu = iTu*ps2.iTu;
    kq.iMau = iMau*ps2.iMau;
    kq.RutGon();
    return kq;
}
PhanSo PhanSo::Thuong(PhanSo ps2)
{
    PhanSo kq;
    kq.iTu = iTu*ps2.iMau;
    kq.iMau = iMau*ps2.iTu;
    kq.RutGon();
    return kq;
}

int PhanSo::SoSanh(PhanSo ps2)
{
    float gt1=(float) iTu/iMau;
    float gt2=(float) ps2.iTu/ps2.iMau;
    if (gt1>gt2) return 1;
    if (gt1<gt2) return -1;
    return 0;
}
