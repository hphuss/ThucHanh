#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "GiaoDich.h"
#include "GiaoDichDat.h"
#include "GiaoDichNhaPho.h"
#include "GiaoDichChungCu.h"

using namespace std;

int main() {
    vector<GiaoDich*> danhSachGD;
    int soGDDat = 0, soGDNhaPho = 0, soGDChungCu = 0;

    bool isError = cin.fail();
    if (isError) cin.clear();

    // 1. Nhap so luong GD Dat
    cout << "Nhap so luong Giao dich Dat: ";
    if (!(cin >> soGDDat)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }
    if (isError) cin.setstate(ios::failbit);

    for (int i = 0; i < soGDDat; ++i) {
        GiaoDich* gd = new GiaoDichDat();
        gd->Nhap();
        danhSachGD.push_back(gd);
    }

    // 2. Nhap so luong GD Nha Pho
    isError = cin.fail();
    if (isError) cin.clear();

    cout << "\nNhap so luong Giao dich Nha pho: ";
    if (!(cin >> soGDNhaPho)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }
    if (isError) cin.setstate(ios::failbit);

    for (int i = 0; i < soGDNhaPho; ++i) {
        GiaoDich* gd = new GiaoDichNhaPho();
        gd->Nhap();
        danhSachGD.push_back(gd);
    }

    // 3. Nhap so luong GD Chung cu
    isError = cin.fail();
    if (isError) cin.clear();

    cout << "\nNhap so luong Giao dich Chung cu: ";
    if (!(cin >> soGDChungCu)) {
        isError = true;
        cin.clear();
        string rac; cin >> rac;
    }
    if (isError) cin.setstate(ios::failbit);

    for (int i = 0; i < soGDChungCu; ++i) {
        GiaoDich* gd = new GiaoDichChungCu();
        gd->Nhap();
        danhSachGD.push_back(gd);
    }

    // Kiem tra loi tong the va dung chuong trinh
    if (cin.fail()) {
        cout << "\nERROR\n";
        for (GiaoDich* gd : danhSachGD) {
            delete gd;
        }
        danhSachGD.clear();
        return 1;
    }

    // Tinh thanh tien cho tat ca
    for (GiaoDich* gd : danhSachGD) {
        gd->TinhThanhTien();
    }

    cout << "\n=================== DANH SACH GIAO DICH ===================" << endl;
    for (GiaoDich* gd : danhSachGD) {
        gd->Xuat();
    }
    cout << "===========================================================\n";

    // 4. Tinh tong so luong tung loai (Da co soGDDat, soGDNhaPho, soGDChungCu)
    cout << "\nTong so luong Giao dich Dat: " << soGDDat;
    cout << "\nTong so luong Giao dich Nha pho: " << soGDNhaPho;
    cout << "\nTong so luong Giao dich Chung cu: " << soGDChungCu << endl;

    // 5. Tinh trung binh thanh tien cua GD Chung cu
    double tongTienChungCu = 0;
    for (GiaoDich* gd : danhSachGD) {
        if (dynamic_cast<GiaoDichChungCu*>(gd)) {
            tongTienChungCu += gd->GetThanhTien();
        }
    }
    if (soGDChungCu > 0) {
        cout << "\nTrung binh thanh tien GD Chung cu: "
             << fixed << setprecision(0) << (tongTienChungCu / soGDChungCu) << endl;
    } else {
        cout << "\nKhong co giao dich Chung cu nao de tinh trung binh.\n";
    }

    // 6. Cho biet GD Nha pho co tri gia cao nhat
    GiaoDichNhaPho* npMax = nullptr;
    for (GiaoDich* gd : danhSachGD) {
        if (GiaoDichNhaPho* np = dynamic_cast<GiaoDichNhaPho*>(gd)) {
            if (npMax == nullptr || np->GetThanhTien() > npMax->GetThanhTien()) {
                npMax = np;
            }
        }
    }

    if (npMax != nullptr) {
        cout << "\nGiao dich Nha pho co tri gia cao nhat:\n";
        npMax->Xuat();
    } else {
        cout << "\nKhong co Giao dich Nha pho nao trong danh sach.\n";
    }

    // 7. Xuat danh sach cac giao dich thang 12/2024
    cout << "\n=== DANH SACH GIAO DICH THANG 12/2024 ===\n";
    bool coGDThang12 = false;
    for (GiaoDich* gd : danhSachGD) {
        if (gd->GetNgayGiaoDich().GetThang() == 12 && gd->GetNgayGiaoDich().GetNam() == 2024) {
            gd->Xuat();
            coGDThang12 = true;
        }
    }
    if (!coGDThang12) {
        cout << "Khong co giao dich nao trong thang 12 nam 2024.\n";
    }

    // Giai phong bo nho con tro
    for (GiaoDich* gd : danhSachGD) {
        delete gd;
    }
    danhSachGD.clear();

    return 0;
}
