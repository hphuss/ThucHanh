#include <iostream>
#include "DaGiac.h"
#include <limits>
#include <cmath>
#include <string>

using namespace std;
double NhapSoThuc(const string& thongBao)
{
        double giaTri;
        while (true) {
            cout << thongBao;
            if (cin >> giaTri) {
                return giaTri;
            } else {
                cout << "Vui long chi nhap so\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
}
int main()
{
    const double PI = 3.14159265358979323846;

    cout<<"----CHUONG TRINH XU LY DA GIAC----\n";
    cDaGiac dg;
    dg.NhapDaGiac();
    cout << "\n--- THONG TIN DA GIAC ---\n";
    dg.XuatDaGiac();

    cout << "Chu vi: " << dg.TinhChuVi() << "\n";
    cout << "Dien tich: " << dg.TinhDienTich() << "\n";


    cout << "\n--- THAO TAC TINH TIEN ---\n";
    cDaGiac dg_tinhtien = dg;
    double dx = NhapSoThuc("Nhap do doi dx: ");
    double dy = NhapSoThuc("Nhap do doi dy: ");
    dg_tinhtien.TinhTien(dx, dy);
    cout << "Da giac sau khi tinh tien: ";
    for(int i = 0; i < dg_tinhtien.GetSoDinh(); i++) {
        dg_tinhtien.GetDinh(i).XuatDiem();
        if (i < dg_tinhtien.GetSoDinh() - 1) cout << ", ";
    }
    cout << "\n";


    cout << "\n--- THAO TAC QUAY ---\n";
    cDaGiac dg_quay = dg;
    double goc_do = NhapSoThuc("Nhap goc quay: ");
    double goc_rad = goc_do * PI / 180.0;
    dg_quay.Quay(goc_rad);
    cout << "Da giac sau khi quay: ";
    for(int i = 0; i < dg_tinhtien.GetSoDinh(); i++) {
        dg_quay.GetDinh(i).XuatDiem();
        if (i < dg_quay.GetSoDinh() - 1) cout << ", ";
    }
    cout << "\n";


    cout << "\n--- THAO TAC PHONG TO / THU NHO ---\n";
    cDaGiac dg_phong = dg;
    double k;
    while (true){
        k=NhapSoThuc("Nhap he so phong to/thu nho: ");
        if(k>0) break;
        else cout<<"He so phai khac 0. Vui long nhap lai!\n";
    }
    dg_phong.PhongToThuNho(k);
    cout << "Da giac sau khi bien doi: ";
    for(int i = 0; i < dg_tinhtien.GetSoDinh(); i++) {
        dg_phong.GetDinh(i).XuatDiem();
        if (i < dg_phong.GetSoDinh() - 1) cout << ", ";
    }
    cout << "\n";
    return 0;
}
