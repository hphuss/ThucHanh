#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "KhachHangA.h"
#include "KhachHangB.h"
#include "KhachHangC.h"

using namespace std;

int main() {
    vector<KhachHang*> danhSachKH;
    int x = 0, y = 0, z = 0;

    bool isError = cin.fail();
    if (isError) cin.clear();


    if (!(cin >> x >> y >> z)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }
    if (isError) cin.setstate(ios::failbit);

    for (int i = 0; i < x; ++i) {
        KhachHang* kh = new KhachHangA();
        kh->Nhap();
        danhSachKH.push_back(kh);
    }

    for (int i = 0; i < y; ++i) {
        KhachHang* kh = new KhachHangB();
        kh->Nhap();
        danhSachKH.push_back(kh);
    }

    for (int i = 0; i < z; ++i) {
        KhachHang* kh = new KhachHangC();
        kh->Nhap();
        danhSachKH.push_back(kh);
    }

    if (cin.fail()) {
        cout << "ERROR\n";
        for (KhachHang* kh : danhSachKH) {
            delete kh;
        }
        danhSachKH.clear();
        return 1;
    }


    double tongDoanhThu = 0;
    for (KhachHang* kh : danhSachKH) {
        kh->TinhTien();
        tongDoanhThu += kh->GetSoTien();
    }

    cout << x << " " << y << " " << z << "\n";
    for (KhachHang* kh : danhSachKH) {
        kh->Xuat();
    }
    cout << fixed << setprecision(0) << tongDoanhThu << "\n";

    for (KhachHang* kh : danhSachKH) {
        delete kh;
    }
    danhSachKH.clear();

    return 0;
}
