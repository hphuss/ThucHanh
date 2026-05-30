#ifndef SINHVIENDAIHOC_H
#define SINHVIENDAIHOC_H

#include "SinhVien.h"
#include <string>

class SinhVienDaiHoc : public SinhVien {
private:
    std::string tenLuanVan;
    double diemLuanVan;

public:
    void Nhap() override;
    void Xuat() const override;
    bool KiemTraTotNghiep() const override;
};

#endif
