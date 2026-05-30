#include "SinhVienDaiHoc.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void SinhVienDaiHoc::Nhap() {
    cout << "\n--- Nhap thong tin Sinh vien Dai hoc ---" << endl;
    SinhVien::Nhap();

    bool isError = cin.fail();
    if(isError) cin.clear();

    cout << "Nhap Ten luan van: ";
    cin >> ws;
    getline(cin, tenLuanVan);

    cout << "Nhap Diem luan van: ";
    if(!(cin >> diemLuanVan)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    if(isError) cin.setstate(ios::failbit);
}

bool SinhVienDaiHoc::KiemTraTotNghiep() const {
    return (tongSoTinChi >= 170 && diemTrungBinh >= 5.0 && diemLuanVan >= 5.0);
}

void SinhVienDaiHoc::Xuat() const {
    cout << left << setw(14) << "[DAI HOC]";
    SinhVien::Xuat();
    cout << " Ten LV: " << setw(18) << tenLuanVan
         << " Diem LV: " << diemLuanVan << endl;
}
