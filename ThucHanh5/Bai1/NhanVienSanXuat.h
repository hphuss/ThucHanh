#ifndef NHANVIENSANXUAT_H
#define NHANVIENSANXUAT_H

#include "NhanVien.h"

class NhanVienSanXuat : public NhanVien {
private:
    double luongCanBan;
    int soSanPham;

public:
    void Nhap() override;
    void TinhLuong() override;
    void Xuat() const override;
};

#endif
