#ifndef DAGIAC_H_INCLUDED
#define DAGIAC_H_INCLUDED
#include "Diem.h"
#include <string>

using namespace std;
class cDaGiac
{
private:
    int n;
    cDiem* dinh;
public:
    cDaGiac();
    ~cDaGiac();
    cDaGiac(const cDaGiac& khac);

    void NhapDaGiac();
    void XuatDaGiac() const;

    bool KiemTraHopLe() const;
    double TinhChuVi() const;
    double TinhDienTich() const;

    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongToThuNho(double k);

    int GetSoDinh() const { return n; }
    cDiem GetDinh(int viTri) const { return dinh[viTri]; }
};


#endif // DAGIAC_H_INCLUDED
