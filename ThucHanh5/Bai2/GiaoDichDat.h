#ifndef GIAODICHDAT_H
#define GIAODICHDAT_H

#include "GiaoDich.h"
#include <string>

class GiaoDichDat : public GiaoDich {
private:
    std::string loaiDat;

public:
    void Nhap() override;
    void TinhThanhTien() override;
    void Xuat() const override;
};

#endif
