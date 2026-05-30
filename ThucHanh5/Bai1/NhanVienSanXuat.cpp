#include "NhanVienSanXuat.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void NhanVienSanXuat::Nhap() {
    cout << "\n--- Nhap thong tin Nhan vien San xuat ---" << endl;
    NhanVien::Nhap();

    bool isError = cin.fail();
    if (isError) cin.clear();

    cout << "Nhap luong can ban: ";
    if (!(cin >> luongCanBan)) {
        isError = true;
        cin.clear();
        string rac;
        cin >> rac;
    }

    cout << "Nhap so san pham: ";
    if (!(cin >> soSanPham)) {
        isError = true;
        cin.clear();
        string rac;
        cin >> rac;
    }

    if (isError) {
        cin.setstate(ios::failbit);
    }
}

void NhanVienSanXuat::TinhLuong() {
    luong = luongCanBan + (soSanPham * 5000.0);
}

void NhanVienSanXuat::Xuat() const {
    cout << left << setw(15) << "[NV SAN XUAT]";
    NhanVien::Xuat();
    cout << "  Luong CB: " << setw(8) << luongCanBan << " VND"
         << "  So SP: " << soSanPham << endl;
}
