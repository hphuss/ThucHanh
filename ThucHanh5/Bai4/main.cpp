#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "NhanVien.h"
#include "LapTrinhVien.h"
#include "KiemChungVien.h"

using namespace std;

int main() {
    vector<NhanVien*> danhSachNV;
    int soLTV = 0, soKCV = 0;

    bool isError = cin.fail();
    if(isError) cin.clear();

    // a. Nhap danh sach
    cout << "Nhap so luong Lap trinh vien: ";
    if (!(cin >> soLTV)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }
    if (isError) cin.setstate(ios::failbit);

    for (int i = 0; i < soLTV; ++i) {
        NhanVien* nv = new LapTrinhVien();
        nv->Nhap();
        danhSachNV.push_back(nv);
    }

    isError = cin.fail();
    if(isError) cin.clear();

    cout << "\nNhap so luong Kiem chung vien: ";
    if (!(cin >> soKCV)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }
    if (isError) cin.setstate(ios::failbit);

    for (int i = 0; i < soKCV; ++i) {
        NhanVien* nv = new KiemChungVien();
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

    // Tinh luong cho toan bo NV
    double tongLuongCongTy = 0;
    for (NhanVien* nv : danhSachNV) {
        nv->TinhLuong();
        tongLuongCongTy += nv->GetLuong();
    }

    double luongTrungBinh = 0;
    int tongSoNV = soLTV + soKCV;
    if (tongSoNV > 0) {
        luongTrungBinh = tongLuongCongTy / tongSoNV;
    }

    // b. Xuat danh sach
    cout << "\n============================================ DANH SACH NHAN VIEN ============================================\n";
    for (NhanVien* nv : danhSachNV) {
        nv->Xuat();
    }
    cout << "=============================================================================================================\n";

    // c. Xuat danh sach NV co luong < luong trung binh
    cout << "\nLuong trung binh cong ty: " << fixed << setprecision(0) << luongTrungBinh << " VND\n";
    cout << "=== DANH SACH NHAN VIEN LUONG THAP HON TRUNG BINH ===\n";
    bool coNVDuoiTB = false;
    for (NhanVien* nv : danhSachNV) {
        if (nv->GetLuong() < luongTrungBinh) {
            nv->Xuat();
            coNVDuoiTB = true;
        }
    }
    if (!coNVDuoiTB) cout << "Khong co nhan vien nao co luong thap hon trung binh.\n";

    // d, e, f, g. Tim cac nhan vien theo yeu cau
    NhanVien* nvMax = nullptr;
    NhanVien* nvMin = nullptr;
    LapTrinhVien* ltvMax = nullptr;
    KiemChungVien* kcvMin = nullptr;

    for (NhanVien* nv : danhSachNV) {
        // Tim NV Max, Min chung
        if (nvMax == nullptr || nv->GetLuong() > nvMax->GetLuong()) nvMax = nv;
        if (nvMin == nullptr || nv->GetLuong() < nvMin->GetLuong()) nvMin = nv;

        // Tim LTV Max, KCV Min dung dynamic_cast
        if (LapTrinhVien* ltv = dynamic_cast<LapTrinhVien*>(nv)) {
            if (ltvMax == nullptr || ltv->GetLuong() > ltvMax->GetLuong()) {
                ltvMax = ltv;
            }
        }
        else if (KiemChungVien* kcv = dynamic_cast<KiemChungVien*>(nv)) {
            if (kcvMin == nullptr || kcv->GetLuong() < kcvMin->GetLuong()) {
                kcvMin = kcv;
            }
        }
    }

    cout << "\n--- THONG KE NHAN VIEN ---\n";
    if (nvMax) {
        cout << "[NV Luong Cao Nhat]\n";
        nvMax->Xuat();
    }
    if (nvMin) {
        cout << "[NV Luong Thap Nhat]\n";
        nvMin->Xuat();
    }
    if (ltvMax) {
        cout << "[LTV Luong Cao Nhat]\n";
        ltvMax->Xuat();
    } else {
        cout << "[LTV Luong Cao Nhat]\nKhong co Lap trinh vien nao trong danh sach.\n";
    }
    if (kcvMin) {
        cout << "[KCV Luong Thap Nhat]\n";
        kcvMin->Xuat();
    } else {
        cout << "[KCV Luong Thap Nhat]\nKhong co Kiem chung vien nao trong danh sach.\n";
    }

    // Giai phong bo nho
    for (NhanVien* nv : danhSachNV) {
        delete nv;
    }
    danhSachNV.clear();

    return 0;
}
