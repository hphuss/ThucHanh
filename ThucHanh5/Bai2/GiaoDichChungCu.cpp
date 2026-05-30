#include "GiaoDichChungCu.h"
#include <iostream>
#include <iomanip>

using namespace std;

void GiaoDichChungCu::Nhap() {
    cout << "\n--- Nhap Giao dich Can ho chung cu ---" << endl;
    GiaoDich::Nhap();

    bool isError = cin.fail();
    if (isError) cin.clear();

    cout << "Nhap ma can: ";
    cin >> ws;
    getline(cin, maCan);

    cout << "Nhap vi tri tang: ";
    if (!(cin >> viTriTang)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    if (isError) cin.setstate(ios::failbit);
}

void GiaoDichChungCu::TinhThanhTien() {
    if (viTriTang == 1) {
        thanhTien = dienTich * donGia * 2.0;
    } else if (viTriTang >= 15) {
        thanhTien = dienTich * donGia * 1.2;
    } else {
        thanhTien = dienTich * donGia;
    }
}

void GiaoDichChungCu::Xuat() const {
    cout << left << setw(16) << "[GD CHUNG CU]";
    GiaoDich::Xuat();
    cout << "  Ma can:   " << setw(12) << maCan
         << "  Tang: " << viTriTang << endl;
}
