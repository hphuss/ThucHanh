#include "NhanVien.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

NhanVien::NhanVien() : luong(0) {}

NhanVien::~NhanVien() {}

void NhanVien::Nhap() {
    bool isError = cin.fail();
    if (isError) cin.clear();

    cout << "Nhap ho ten: ";
    cin >> ws;
    getline(cin, hoTen);

    ngaySinh.Nhap();

    if (cin.fail()) isError = true;

    if (isError) {
        cin.setstate(ios::failbit);
    }
}

void NhanVien::Xuat() const {
    cout << left
         << "Ho ten: " << setw(18) << hoTen
         << "  Ngay sinh: ";
    ngaySinh.Xuat();
   cout << "  Luong: " << setw(8) << fixed << setprecision(0) << luong << " VND";
}

double NhanVien::GetLuong() const { return luong; }

NgayThang NhanVien::GetNgaySinh() const { return ngaySinh; }
