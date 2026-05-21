#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
class Date
{
private:
    int ngay, thang, nam;

    bool namnhuan(int n)const;
    int ngaytrongthang(int month, int year) const;
    void chuanhoa();
    int quydoingay() const;
public:
    Date(int d=1, int m=1, int y=2000);

    Date operator+(int days) const;
    Date operator-(int days) const;

    Date& operator++();
    Date& operator--();

    Date operator++(int);
    Date operator--(int);

    int operator-(const Date& other) const;

    friend std::istream& operator>>(std::istream& is, Date& other);
    friend std::ostream& operator<<(std::ostream& os, const Date& other);

};


#endif // DATE_H_INCLUDED
