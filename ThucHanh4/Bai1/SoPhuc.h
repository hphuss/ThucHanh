#ifndef SOPHUC_H_INCLUDED
#define SOPHUC_H_INCLUDED
class SoPhuc
{
private:
    double thuc, ao;
public:
    SoPhuc(double thuc=0, double ao=0);

    SoPhuc operator+(const SoPhuc& sp2) const;
    SoPhuc operator-(const SoPhuc& sp2) const;
    SoPhuc operator*(const SoPhuc& sp2) const;
    SoPhuc operator/(const SoPhuc& sp2) const;

    bool operator==(const SoPhuc& sp2) const;
    bool operator!=(const SoPhuc& sp2) const;

    friend std::istream& operator>>(std::istream& is, SoPhuc& sp);
    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& sp);
};


#endif // SOPHUC_H_INCLUDED
