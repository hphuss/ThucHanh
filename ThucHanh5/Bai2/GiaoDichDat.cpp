#include "GiaoDichDat.h"
#include <iostream>
#include <iomanip>

using namespace std;

void GiaoDichDat::Nhap() {
    cout << "\n--- Nhap Giao dich Dat ---" << endl;
    GiaoDich::Nhap();

    bool isError = cin.fail();
    if (isError) cin.clear();

    cout << "Nhap loai dat (A, B, hoac C): ";
    cin >> ws;
    getline(cin, loaiDat);

    if (isError) cin.setstate(ios::failbit);
}

void GiaoDichDat::TinhThanhTien() {
    if (loaiDat == "A" || loaiDat == "a") {
        thanhTien = dienTich * donGia * 1.5;
    } else {
        // loai B hoac C
        thanhTien = dienTich * donGia;
    }
}

void GiaoDichDat::Xuat() const {
    cout << left << setw(16) << "[GD DAT]";
    GiaoDich::Xuat();
    cout << "  Loai dat: " << setw(12) << loaiDat << endl;
}
