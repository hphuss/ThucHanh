#ifndef NGAYTHANG_H_INCLUDED
#define NGAYTHANG_H_INCLUDED
class NgayThang
{
    private:
    int ngay, thang, nam;
    bool KiemTraHopLe() const;

public:
    NgayThang();
    NgayThang(int ngay, int thang, int nam);

    void Nhap();
    void Xuat() const;

    //ho tro loc giao dich theo thang, nam
    int GetThang() const;
    int GetNam() const;
};


#endif // NGAYTHANG_H_INCLUDED
