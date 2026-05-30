#include "SinhVien.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

SinhVien::SinhVien() : tongSoTinChi(0), diemTrungBinh(0) {}

SinhVien::~SinhVien() {}

void SinhVien::Nhap() {
    bool isError = cin.fail();
    if(isError) cin.clear();

    cout << "Nhap Ma SV: ";
    cin >> ws;
    getline(cin, maSV);

    cout << "Nhap Ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap Dia chi: ";
    getline(cin, diaChi);

    cout << "Nhap Tong so tin chi: ";
    if(!(cin >> tongSoTinChi)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    cout << "Nhap Diem trung binh: ";
    if(!(cin >> diemTrungBinh)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    if(isError) cin.setstate(ios::failbit);
}

void SinhVien::Xuat() const {
    cout << left
         << "MSSV: " << setw(10) << maSV
         << " Ho ten: " << setw(20) << hoTen
         << " Dia chi: " << setw(15) << diaChi
         << " Tin chi: " << setw(5) << tongSoTinChi
         << " DTB: " << setw(5) << fixed << setprecision(2) << diemTrungBinh;
}

double SinhVien::GetDiemTrungBinh() const {
    return diemTrungBinh;
}
