#ifndef PHANSO_H_INCLUDED
#define PHANSO_H_INCLUDED
class PhanSo
{
private:
    int tu, mau;

    void RutGon();
public:
    PhanSo(int tu=0, int mau=1);

    PhanSo operator+(const PhanSo& ps) const;
    PhanSo operator-(const PhanSo& ps) const;
    PhanSo operator*(const PhanSo& ps) const;
    PhanSo operator/(const PhanSo& ps) const;

    bool operator==(const PhanSo& ps) const;
    bool operator>(const PhanSo& ps) const;
    bool operator<(const PhanSo& ps) const;

    friend std::istream& operator>>(std::istream& is, PhanSo& ps);
    friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps);
};


#endif // PHANSO_H_INCLUDED
