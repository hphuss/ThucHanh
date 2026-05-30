#include "KhachHang.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

KhachHang::KhachHang() : soLuong(0), donGia(0), soTienPhaiTra(0) {}

KhachHang::~KhachHang() {}

void KhachHang::Nhap() {
    bool isError = cin.fail();
    if(isError) cin.clear();

    cin >> ws;
    getline(cin, hoTen);

    if(!(cin >> soLuong)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    if(!(cin >> donGia)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }

    if(isError) cin.setstate(ios::failbit);
}

void KhachHang::Xuat() const {
    cout << hoTen << "\n" << fixed << setprecision(0) << soTienPhaiTra << "\n";
}

double KhachHang::GetSoTien() const {
    return soTienPhaiTra;
}
