#ifndef DATHUC_H_INCLUDED
#define DATHUC_H_INCLUDED
class DaThuc
{
private:
    int bac;
    double *heso;
public:
    DaThuc(int b=0);
    DaThuc(const DaThuc& other);
    ~DaThuc();
    DaThuc& operator=(const DaThuc& other);

    DaThuc operator+(const DaThuc& other) const;
    DaThuc operator-(const DaThuc& other) const;
    DaThuc operator*(const DaThuc& other) const;

    friend std::istream& operator>>(std::istream& is, DaThuc& dt);
    friend std::ostream& operator<<(std::ostream& os, const DaThuc& dt);

};


#endif // DATHUC_H_INCLUDED
