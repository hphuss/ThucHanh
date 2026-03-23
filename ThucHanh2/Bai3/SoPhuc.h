#ifndef SOPHUC_H_INCLUDED
#define SOPHUC_H_INCLUDED
class SoPhuc{
private:
    double iThuc, iAo;

    int NhapSoNguyen();
public:
    void Nhap();
    void Xuat();

    SoPhuc Tong(SoPhuc sp2);
    SoPhuc Hieu(SoPhuc sp2);
    SoPhuc Tich(SoPhuc sp2);
    SoPhuc Thuong(SoPhuc sp2);
};


#endif // SOPHUC_H_INCLUDED
