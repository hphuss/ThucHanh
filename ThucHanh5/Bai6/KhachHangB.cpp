#include "KhachHangB.h"
#include <iostream>
#include <string>

using namespace std;

void KhachHangB::Nhap() {
    KhachHang::Nhap();

    bool isError = cin.fail();
    if(isError) cin.clear();

    if(!(cin >> soNamThanThiet)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    if(isError) cin.setstate(ios::failbit);
}

void KhachHangB::TinhTien() {
    double phanTramKM = soNamThanThiet * 5.0;
    if (phanTramKM > 50.0) {
        phanTramKM = 50.0;
    }
    soTienPhaiTra = (soLuong * donGia) * (1.0 - phanTramKM / 100.0) * 1.1;
}
