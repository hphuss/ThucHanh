#include "DaGiac.h"
#include <iostream>
#include <cmath>

using namespace std;

const double EPSILON = 1e-5;
bool isEqual(double a, double b)
{
    return abs(a-b)<EPSILON;
}

cDaGiac::cDaGiac():n(0), dinh(nullptr){}
cDaGiac::~cDaGiac() {
    if (dinh != nullptr) {
        delete[] dinh;
    }
}
cDaGiac::cDaGiac(const cDaGiac& khac) {
    n = khac.n;
    dinh = new cDiem[n];
    for (int i = 0; i < n; i++) {
        dinh[i] = khac.dinh[i];
    }
}

void cDaGiac::NhapDaGiac()
{
    bool hopLe = false;
    do {
        while (true) {
            cout << "Nhap so luong dinh cua da giac (n >= 3): ";
            if (cin >> n && n >= 3) {
                break;
            } else {
                cout << "So dinh phai la so nguyen >= 3. Vui long nhap lai!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        if (dinh != nullptr) {
            delete[] dinh;
        }
        dinh = new cDiem[n];
        for (int i = 0; i < n; i++) {
            cout << "Nhap dinh thu " << i + 1 << ":\n";
            dinh[i].NhapDiem();
        }
        hopLe = KiemTraHopLe();
        if (!hopLe) {
            cout << "\nCac dinh nay khong tao thanh da giac hop le!\n";
            cout << "VUI LONG NHAP LAI TOAN BO!\n\n";
        }

    } while (!hopLe);
}
void cDaGiac::XuatDaGiac() const
{
    cout << "Da giac co " << n << " dinh: ";
    for (int i = 0; i < n; i++) {
        dinh[i].XuatDiem();
        if (i < n - 1) cout << ",";
    }
    cout << "\n";
}
bool cDaGiac::KiemTraHopLe() const
{
    if (n < 3) return false;

    for (int i = 0; i < n; i++) {
        int hienTai = i;
        int tiepTheo1 = (i + 1) % n;
        int tiepTheo2 = (i + 2) % n;

        if (dinh[hienTai].TinhKhoangCach(dinh[tiepTheo1]) < EPSILON) {
            return false;
        }
        double x1 = dinh[hienTai].GetX();
        double y1 = dinh[hienTai].GetY();
        double x2 = dinh[tiepTheo1].GetX();
        double y2 = dinh[tiepTheo1].GetY();
        double x3 = dinh[tiepTheo2].GetX();
        double y3 = dinh[tiepTheo2].GetY();

        double tichCoHuong = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);

        if (abs(tichCoHuong) < EPSILON) {
            return false;
        }
    }
    return true;
}
double cDaGiac::TinhChuVi() const
{
    if (n < 3) return 0;
    double chuVi = 0;
    for (int i = 0; i < n; i++) {
        int tiepTheo = (i + 1) % n;
        chuVi += dinh[i].TinhKhoangCach(dinh[tiepTheo]);
    }
    return chuVi;
}
double cDaGiac::TinhDienTich() const
{
   if (n < 3) return 0;
    double dienTich = 0;
    for (int i = 0; i < n; i++) {
        int tiepTheo = (i + 1) % n;
        dienTich += (dinh[i].GetX() * dinh[tiepTheo].GetY())
                  - (dinh[tiepTheo].GetX() * dinh[i].GetY());
    }
    return abs(dienTich) / 2.0;
}
void cDaGiac::TinhTien(double dx, double dy) {
    for (int i = 0; i < n; i++) {
        dinh[i].TinhTien(dx, dy);
    }
}
void cDaGiac::Quay(double goc_rad) {
    for (int i = 0; i < n; i++) {
        dinh[i].Quay(goc_rad);
    }
}
void cDaGiac::PhongToThuNho(double k) {
    for (int i = 0; i < n; i++) {
        dinh[i].PhongToThuNho(k);
    }
}
