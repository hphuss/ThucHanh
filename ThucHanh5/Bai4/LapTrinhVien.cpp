#include "LapTrinhVien.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void LapTrinhVien::Nhap() {
    cout << "\n--- Nhap thong tin Lap trinh vien ---" << endl;
    NhanVien::Nhap();

    bool isError = cin.fail();
    if(isError) cin.clear();

    cout << "Nhap so gio overtime: ";
    if(!(cin >> soGioOvertime)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    if(isError) cin.setstate(ios::failbit);
}

void LapTrinhVien::TinhLuong() {
    luong = luongCoBan + (soGioOvertime * 200000.0);
}

void LapTrinhVien::Xuat() const {
    cout << left << setw(14) << "[LAP TRINH]";
    NhanVien::Xuat();
    cout << "OT: " << soGioOvertime << "h\n";
}
