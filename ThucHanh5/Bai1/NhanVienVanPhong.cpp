#include "NhanVienVanPhong.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void NhanVienVanPhong::Nhap() {
    cout << "\n--- Nhap thong tin Nhan vien Van phong ---" << endl;
    NhanVien::Nhap();

    bool isError = cin.fail();
    if (isError) cin.clear();

    cout << "Nhap so ngay lam viec: ";
    if (!(cin >> soNgayLamViec)) {
        isError = true;
        cin.clear();
        string rac;
        cin >> rac;
    }

    if (isError) {
        cin.setstate(ios::failbit);
    }
}

void NhanVienVanPhong::TinhLuong() {
    luong = soNgayLamViec * 100000.0;
}

void NhanVienVanPhong::Xuat() const {
    cout << left << setw(15) << "[NV VAN PHONG]";
    NhanVien::Xuat();
    cout << "  So ngay lam: " << soNgayLamViec << endl;
}
