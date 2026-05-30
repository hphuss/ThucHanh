#include "KiemChungVien.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void KiemChungVien::Nhap() {
    cout << "\n--- Nhap thong tin Kiem chung vien ---" << endl;
    NhanVien::Nhap();

    bool isError = cin.fail();
    if(isError) cin.clear();

    cout << "Nhap so loi phat hien duoc: ";
    if(!(cin >> soLoi)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    if(isError) cin.setstate(ios::failbit);
}

void KiemChungVien::TinhLuong() {
    luong = luongCoBan + (soLoi * 50000.0);
}

void KiemChungVien::Xuat() const {
    cout << left << setw(14) << "[KIEM CHUNG]";
    NhanVien::Xuat();
    cout << "Loi: " << soLoi << " loi\n";
}
