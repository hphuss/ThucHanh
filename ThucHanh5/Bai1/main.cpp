#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "NhanVien.h"
#include "NhanVienSanXuat.h"
#include "NhanVienVanPhong.h"

using namespace std;

int main() {
    vector<NhanVien*> danhSachNV;
    int soNVSX = 0, soNVVP = 0;

    bool isError = cin.fail();
    if(isError) cin.clear();

    // 1. Nhap so luong NV San Xuat
    cout << "Nhap so luong Nhan vien San xuat: ";
    if (!(cin >> soNVSX)) {
        isError = true;
        cin.clear();
        string rac;
        cin >> rac;
    }
    if (isError) cin.setstate(ios::failbit);

    for (int i = 0; i < soNVSX; ++i) {
        NhanVien* nv = new NhanVienSanXuat();
        nv->Nhap();
        danhSachNV.push_back(nv);
    }

    // 2. Nhap so luong NV Van Phong
    isError = cin.fail();
    if(isError) cin.clear();

    cout << "\nNhap so luong Nhan vien Van phong: ";
    if (!(cin >> soNVVP)) {
        isError = true;
        cin.clear();
        string rac;
        cin >> rac;
    }
    if (isError) cin.setstate(ios::failbit);

    for (int i = 0; i < soNVVP; ++i) {
        NhanVien* nv = new NhanVienVanPhong();
        nv->Nhap();
        danhSachNV.push_back(nv);
    }

    // Kiem tra loi tong the
    if (cin.fail()) {
        cout << "\nERROR\n";
        for (NhanVien* nv : danhSachNV) {
            delete nv;
        }
        danhSachNV.clear();
        return 1;
    }

    for (NhanVien* nv : danhSachNV) {
        nv->TinhLuong();
    }

    cout << "\n================= DANH SACH NHAN VIEN =================" << endl;
    for (NhanVien* nv : danhSachNV) {
        nv->Xuat();
    }
    cout << "=======================================================\n";

    double tongLuong = 0;
    for (NhanVien* nv : danhSachNV) {
        tongLuong += nv->GetLuong();
    }
    cout << "\nTong luong cong ty phai tra: " << fixed << setprecision(0) << tongLuong << " VND\n";

    NhanVienSanXuat* nvsxMin = nullptr;
    for (NhanVien* nv : danhSachNV) {
        if (NhanVienSanXuat* nvsx = dynamic_cast<NhanVienSanXuat*>(nv)) {
            if (nvsxMin == nullptr || nvsx->GetLuong() < nvsxMin->GetLuong()) {
                nvsxMin = nvsx;
            }
        }
    }

    if (nvsxMin != nullptr) {
        cout << "Nhan vien San xuat co luong thap nhat:\n";
        nvsxMin->Xuat();
    } else {
        cout << "Khong co Nhan vien San xuat nao trong danh sach.\n";
    }

    NhanVienVanPhong* nvvpMaxTuoi = nullptr;
    for (NhanVien* nv : danhSachNV) {
        if (NhanVienVanPhong* nvvp = dynamic_cast<NhanVienVanPhong*>(nv)) {
            if (nvvpMaxTuoi == nullptr || nvvp->GetNgaySinh().LonTuoiHon(nvvpMaxTuoi->GetNgaySinh())) {
                nvvpMaxTuoi = nvvp;
            }
        }
    }

    if (nvvpMaxTuoi != nullptr) {
        cout << "Nhan vien Van phong co tuoi cao nhat:\n";
        nvvpMaxTuoi->Xuat();
    } else {
        cout << "Khong co Nhan vien Van phong nao trong danh sach.\n";
    }

    for (NhanVien* nv : danhSachNV) {
        delete nv;
    }
    danhSachNV.clear();

    return 0;
}
