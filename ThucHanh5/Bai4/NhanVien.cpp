#include "NhanVien.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

NhanVien::NhanVien() : tuoi(0), luongCoBan(0), luong(0) {}

NhanVien::~NhanVien() {}

void NhanVien::Nhap() {
    bool isError = cin.fail();
    if(isError) cin.clear();

    cout << "Nhap Ma nhan vien: ";
    cin >> ws;
    getline(cin, maNV);

    cout << "Nhap Ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap Tuoi: ";
    if(!(cin >> tuoi)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    cout << "Nhap SDT: ";
    cin >> ws;
    getline(cin, sdt);

    cout << "Nhap Email: ";
    getline(cin, email);

    cout << "Nhap Luong co ban: ";
    if(!(cin >> luongCoBan)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    if(isError) cin.setstate(ios::failbit);
}

void NhanVien::Xuat() const {
    cout << left
         << "Ma NV: " << setw(8) << maNV
         << " Ten: " << setw(18) << hoTen
         << " Tuoi: " << setw(4) << tuoi
         << " Luong CB: " << setw(9) << fixed << setprecision(0) << luongCoBan
         << " Luong thuc nhan: " << setw(10) << luong << " VND  ";
}

double NhanVien::GetLuong() const { return luong; }
string NhanVien::GetHoTen() const { return hoTen; }
