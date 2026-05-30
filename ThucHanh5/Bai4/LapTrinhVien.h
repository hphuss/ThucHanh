#ifndef LAPTRINHVIEN_H
#define LAPTRINHVIEN_H

#include "NhanVien.h"

class LapTrinhVien : public NhanVien {
private:
    int soGioOvertime;

public:
    void Nhap() override;
    void Xuat() const override;
    void TinhLuong() override;
};

#endif
