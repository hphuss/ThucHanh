#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
#include "NgayThang.h"

class NhanVien {
protected:
    std::string hoTen;
    NgayThang ngaySinh;
    double luong;

public:
    NhanVien();
    virtual ~NhanVien();

    virtual void Nhap();
    virtual void Xuat() const;
    virtual void TinhLuong() = 0;

    double GetLuong() const;
    NgayThang GetNgaySinh() const;
};

#endif
