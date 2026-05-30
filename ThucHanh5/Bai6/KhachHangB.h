#ifndef KHACHHANGB_H
#define KHACHHANGB_H

#include "KhachHang.h"

class KhachHangB : public KhachHang {
private:
    int soNamThanThiet;

public:
    void Nhap() override;
    void TinhTien() override;
};

#endif
