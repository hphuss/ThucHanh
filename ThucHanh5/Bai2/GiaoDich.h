#ifndef GIAODICH_H
#define GIAODICH_H


#include <string>
#include "NgayThang.h"

class GiaoDich {
protected:
    std::string maGiaoDich;
    NgayThang ngayGiaoDich;
    double donGia;
    double dienTich;
    double thanhTien;

public:
    GiaoDich();
    virtual ~GiaoDich();

    virtual void Nhap();
    virtual void Xuat() const;
    virtual void TinhThanhTien() = 0;

    double GetThanhTien() const;
    NgayThang GetNgayGiaoDich() const;
};

#endif // GIAODICH_H_INCLUDED
