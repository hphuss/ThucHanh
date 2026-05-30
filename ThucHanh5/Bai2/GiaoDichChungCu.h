#ifndef GIAODICHCHUNGCU_H
#define GIAODICHCHUNGCU_H

#include "GiaoDich.h"
#include <string>

class GiaoDichChungCu : public GiaoDich {
private:
    std::string maCan;
    int viTriTang;

public:
    void Nhap() override;
    void TinhThanhTien() override;
    void Xuat() const override;
};

#endif
