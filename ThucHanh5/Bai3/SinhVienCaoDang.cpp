#include "SinhVienCaoDang.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void SinhVienCaoDang::Nhap() {
    cout << "\n--- Nhap thong tin Sinh vien Cao dang ---" << endl;
    SinhVien::Nhap();

    bool isError = cin.fail();
    if(isError) cin.clear();

    cout << "Nhap Diem thi tot nghiep: ";
    if(!(cin >> diemThiTotNghiep)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    if(isError) cin.setstate(ios::failbit);
}

bool SinhVienCaoDang::KiemTraTotNghiep() const {
    return (tongSoTinChi >= 120 && diemTrungBinh >= 5.0 && diemThiTotNghiep >= 5.0);
}

void SinhVienCaoDang::Xuat() const {
    cout << left << setw(14) << "[CAO DANG]";
    SinhVien::Xuat();
    cout << " Diem thi TN: " << diemThiTotNghiep << endl;
}
