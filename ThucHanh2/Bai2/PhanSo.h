#ifndef PHANSO_H_INCLUDED
#define PHANSO_H_INCLUDED

class PhanSo
{
private:
    int iTu, iMau;
    int timUCLN(int a, int b);
    int nhapSoNguyen();
public:
    void Nhap();
    void Xuat();
    void RutGon();

    PhanSo Tong (PhanSo ps2);
    PhanSo Hieu (PhanSo ps2);
    PhanSo Tich (PhanSo ps2);
    PhanSo Thuong(PhanSo ps2);

    int SoSanh (PhanSo ps2);
};


#endif // PHANSO_H_INCLUDED
