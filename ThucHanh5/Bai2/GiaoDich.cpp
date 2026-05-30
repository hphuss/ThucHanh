#include "GiaoDich.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

GiaoDich::GiaoDich() : donGia(0), dienTich(0), thanhTien(0) {}

GiaoDich::~GiaoDich() {}

void GiaoDich::Nhap() {
    bool isError = cin.fail();
    if (isError) cin.clear();

    cout << "Nhap ma giao dich: ";
    cin >> ws;
    getline(cin, maGiaoDich);

    ngayGiaoDich.Nhap();
    if (cin.fail()) isError = true;

    cout << "Nhap don gia: ";
    if (!(cin >> donGia)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    cout << "Nhap dien tich: ";
    if (!(cin >> dienTich)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    if (isError) cin.setstate(ios::failbit);
}

void GiaoDich::Xuat() const {
    cout << left
         << "Ma GD: " << setw(8) << maGiaoDich
         << "  Ngay: ";
    ngayGiaoDich.Xuat();
    cout << "  Dien tich: " << setw(6) << dienTich
         << "  Don gia: " << setw(10) << fixed << setprecision(0) << donGia
         << "  Thanh tien: " << setw(15) << thanhTien;
}

double GiaoDich::GetThanhTien() const { return thanhTien; }
NgayThang GiaoDich::GetNgayGiaoDich() const { return ngayGiaoDich; }
