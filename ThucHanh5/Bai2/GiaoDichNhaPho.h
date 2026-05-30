#ifndef GIAODICHNHAPHO_H
#define GIAODICHNHAPHO_H

#include "GiaoDich.h"
#include <string>

class GiaoDichNhaPho : public GiaoDich {
private:
    std::string loaiNha;
    std::string diaChi;

public:
    void Nhap() override;
    void TinhThanhTien() override;
    void Xuat() const override;
};

#endif
