#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>

class NhanVien {
protected:
    std::string maNV;
    std::string hoTen;
    int tuoi;
    std::string sdt;
    std::string email;
    double luongCoBan;
    double luong;

public:
    NhanVien();
    virtual ~NhanVien();

    virtual void Nhap();
    virtual void Xuat() const;
    virtual void TinhLuong() = 0;

    double GetLuong() const;
    std::string GetHoTen() const;
};

#endif
