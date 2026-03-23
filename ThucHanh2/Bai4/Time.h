#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
class Time
{
private:
    int iGio, iPhut, iGiay;

    int NhapSoNguyen();
public:
    void Nhap();
    void Xuat();
    Time TinhCongThemMotGiay();
};
#endif // TIME_H_INCLUDED
