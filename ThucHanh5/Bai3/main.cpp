#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "SinhVien.h"
#include "SinhVienCaoDang.h"
#include "SinhVienDaiHoc.h"

using namespace std;

int main() {
    vector<SinhVien*> danhSachSV;
    int soSVCD = 0, soSVDH = 0;

    bool isError = cin.fail();
    if (isError) cin.clear();


    cout << "Nhap so luong Sinh vien Cao dang: ";
    if (!(cin >> soSVCD)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }
    if (isError) cin.setstate(ios::failbit);

    for (int i = 0; i < soSVCD; ++i) {
        SinhVien* sv = new SinhVienCaoDang();
        sv->Nhap();
        danhSachSV.push_back(sv);
    }

    isError = cin.fail();
    if (isError) cin.clear();

    cout << "\nNhap so luong Sinh vien Dai hoc: ";
    if (!(cin >> soSVDH)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }
    if (isError) cin.setstate(ios::failbit);

    for (int i = 0; i < soSVDH; ++i) {
        SinhVien* sv = new SinhVienDaiHoc();
        sv->Nhap();
        danhSachSV.push_back(sv);
    }

    // Kiem tra loi tong the
    if (cin.fail()) {
        cout << "\nERROR\n";
        for (SinhVien* sv : danhSachSV) {
            delete sv;
        }
        danhSachSV.clear();
        return 1;
    }


    cout << "\n=========================================== DANH SACH SINH VIEN ===========================================\n";
    for (SinhVien* sv : danhSachSV) {
        sv->Xuat();
    }
    cout << "===========================================================================================================\n";


    cout << "\n=== DANH SACH SINH VIEN DU DIEU KIEN TOT NGHIEP ===\n";
    for (SinhVien* sv : danhSachSV) {
        if (sv->KiemTraTotNghiep()) {
            sv->Xuat();
        }
    }


    cout << "\n=== DANH SACH SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP ===\n";
    for (SinhVien* sv : danhSachSV) {
        if (!sv->KiemTraTotNghiep()) {
            sv->Xuat();
        }
    }


    SinhVienDaiHoc* svdhMax = nullptr;
    SinhVienCaoDang* svcdMax = nullptr;
    int khongDuCD = 0;
    int khongDuDH = 0;

    for (SinhVien* sv : danhSachSV) {

        if (SinhVienDaiHoc* dh = dynamic_cast<SinhVienDaiHoc*>(sv)) {
            if (svdhMax == nullptr || dh->GetDiemTrungBinh() > svdhMax->GetDiemTrungBinh()) {
                svdhMax = dh;
            }
            if (!dh->KiemTraTotNghiep()) khongDuDH++;
        }
        else if (SinhVienCaoDang* cd = dynamic_cast<SinhVienCaoDang*>(sv)) {
            if (svcdMax == nullptr || cd->GetDiemTrungBinh() > svcdMax->GetDiemTrungBinh()) {
                svcdMax = cd;
            }
            if (!cd->KiemTraTotNghiep()) khongDuCD++;
        }
    }

    cout << "\nSinh vien Dai hoc co Diem trung binh cao nhat:\n";
    if (svdhMax != nullptr) svdhMax->Xuat();
    else cout << "Khong co sinh vien Dai hoc nao trong danh sach.\n";

    cout << "\nSinh vien Cao dang co Diem trung binh cao nhat:\n";
    if (svcdMax != nullptr) svcdMax->Xuat();
    else cout << "Khong co sinh vien Cao dang nao trong danh sach.\n";

    cout << "\nSo luong Sinh vien Cao dang khong du dieu kien TN: " << khongDuCD;
    cout << "\nSo luong Sinh vien Dai hoc khong du dieu kien TN: " << khongDuDH << endl;

    // Giai phong bo nho an toan
    for (SinhVien* sv : danhSachSV) {
        delete sv;
    }
    danhSachSV.clear();

    return 0;
}
