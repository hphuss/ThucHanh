#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
class cArray
{
private:
    int *a;
    int n;

    bool KiemTraSoNguyenTo(int so) const;
public:
    cArray();
    ~cArray();
    cArray(const cArray& khac);
    cArray& operator=(const cArray& khac);

    void TaoNgauNhien(int kichThuoc);
    void XuatMang() const;
    int DemGiaTri(int x) const;
    bool KiemTraTangDan() const;

    bool TimLeNhoNhat(int& kq) const;
    bool TimNguyenToLonNhat(int &kq) const;

    void SapXepTangDan();
    void SapXepGiamDan();
};


#endif // ARRAY_H_INCLUDED
