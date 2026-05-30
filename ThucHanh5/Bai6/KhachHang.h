#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <string>

class KhachHang {
protected:
    std::string hoTen;
    int soLuong;
    double donGia;
    double soTienPhaiTra;

public:
    KhachHang();
    virtual ~KhachHang();

    virtual void Nhap();
    virtual void TinhTien() = 0;
    virtual void Xuat() const;

    double GetSoTien() const;
};

#endif
