#ifndef NGAYTHANG_H
#define NGAYTHANG_H

class NgayThang {
private:
    int ngay, thang, nam;

    bool KiemTraHopLe() const;

public:
    NgayThang();
    NgayThang(int ngay, int thang, int nam);

    void Nhap();
    void Xuat() const;
    bool LonTuoiHon(const NgayThang& khac) const;
};

#endif
