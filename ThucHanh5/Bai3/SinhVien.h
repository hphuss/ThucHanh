#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <string>

class SinhVien {
protected:
    std::string maSV;
    std::string hoTen;
    std::string diaChi;
    int tongSoTinChi;
    double diemTrungBinh;

public:
    SinhVien();
    virtual ~SinhVien();

    virtual void Nhap();
    virtual void Xuat() const;

    // Ham thuan ao: Moi he se co cach tinh tot nghiep rieng
    virtual bool KiemTraTotNghiep() const = 0;

    double GetDiemTrungBinh() const;
};

#endif
