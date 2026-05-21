#include <iostream>
#include "Date.h"
#include <cmath>
#include <iomanip>


using namespace std;

int main()
{
    Date d1;
    cout<<"---NHAP NGAY BAT KY---\n";
    cin>>d1;

    if(cin.fail()){
        cout<<"ERROR\n";
        return 1;
    }
    cout << "Ngay vua nhap: " << d1 << "\n";
    cout << "Ngay hom sau: " << d1+1 << "\n";
    cout << "Ngay hom truoc: " << d1-1 << "\n";

    int soNgay;
    cout<<"Nhap so ngay ban muon them bot(nhap duong de them, am de bot): ";
    cin>>soNgay;
    Date nSauThemBot=d1+soNgay;
    if(soNgay > 0)
        cout << "\nNgay sau khi them " << soNgay << " ngay: " << nSauThemBot << "\n";
    else if(soNgay < 0)
        cout << "\nNgay sau khi bot " << abs(soNgay) <<" ngay: " << nSauThemBot << "\n";
    else
        cout << "\nNgay khong doi\n";

    cout<<"---TINH LAI SUAT NGAN HANG---\n";
    Date ngayGui, ngayRut;
    double soTienGoc, laiSuatNam;

    cout << "--- Nhap Thong Tin So Tiet Kiem ---\n";
    cout << "NHAP NGAY GUI TIEN:\n";
    cin >> ngayGui;
    if (cin.fail()) { cout << "ERROR\n"; return 1; }

    cout << "NHAP NGAY RUT TIEN:\n";
    cin >> ngayRut;
    if (cin.fail()) { cout << "ERROR\n"; return 1; }

    cout << "\nNhap so tien goc (VND): ";
    cin >> soTienGoc;
    if (cin.fail() || soTienGoc < 0) { cout << "ERROR\n"; return 1; }

    cout << "Nhap lai suat nam (%/nam - VD: 6.5): ";
    cin >> laiSuatNam;
    if (cin.fail() || laiSuatNam < 0) { cout << "ERROR\n"; return 1; }

    int soNgayGui = ngayRut - ngayGui;

    if (soNgayGui < 0) {
        cout << "\nLoi: Ngay rut tien khong the xay ra truoc ngay gui tien!\n";
    } else {
        double tienLai = soTienGoc * (laiSuatNam / 100.0) * ((double)soNgayGui / 365.0);
        double tongTien = soTienGoc + tienLai;

        cout << "\n---------------- KET QUA ----------------\n";
        cout << "Ngay gui: "<<ngayGui<<"\n";
        cout << "Ngay rut: "<<ngayRut<<"\n";
        cout << "Thoi gian gui thuc te: " << soNgayGui << " ngay\n";

        cout << fixed << setprecision(0);
        cout << "So tien lai nhan duoc: " << tienLai << " VND\n";
        cout << "TONG TIEN (Goc + Lai): " << tongTien << " VND\n";
        cout << "-----------------------------------------\n";
    }

    return 0;
}
