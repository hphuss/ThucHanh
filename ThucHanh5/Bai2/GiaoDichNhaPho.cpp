#include "GiaoDichNhaPho.h"
#include <iostream>
#include <iomanip>

using namespace std;

void GiaoDichNhaPho::Nhap() {
    cout << "\n--- Nhap Giao dich Nha pho ---" << endl;
    GiaoDich::Nhap();

    bool isError = cin.fail();
    if (isError) cin.clear();

    cout << "Nhap loai nha ('cao cap' hoac 'thuong'): ";
    cin >> ws;
    getline(cin, loaiNha);

    cout << "Nhap dia chi: ";
    getline(cin, diaChi);

    if (isError) cin.setstate(ios::failbit);
}

void GiaoDichNhaPho::TinhThanhTien() {
    if (loaiNha == "cao cap") {
        thanhTien = dienTich * donGia;
    } else {
        thanhTien = dienTich * donGia * 0.9;
    }
}

void GiaoDichNhaPho::Xuat() const {
    cout << left << setw(16) << "[GD NHA PHO]";
    GiaoDich::Xuat();
    cout << "  Loai nha: " << setw(12) << loaiNha
         << "  Dia chi: " << diaChi << endl;
}
