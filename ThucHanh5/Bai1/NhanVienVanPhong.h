#ifndef NHANVIENVANPHONG_H
#define NHANVIENVANPHONG_H

#include "NhanVien.h"

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;

public:
    void Nhap() override;
    void TinhLuong() override;
    void Xuat() const override;
};

#endif
