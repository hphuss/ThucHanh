#ifndef CTIME_H_INCLUDED
#define CTIME_H_INCLUDED
#include<iostream>
class cTime
{
private:
    int gio, phut, giay;

    void chuanhoa();
public:
    cTime(int g=0,int  p=0,int s=0);

    cTime operator+(int s) const;
    cTime operator-(int s) const;

    cTime& operator++();
    cTime& operator--();

    cTime operator++(int);
    cTime operator--(int);

    friend std::istream& operator>>(std::istream& is, cTime& t);
    friend std::ostream& operator<<(std::ostream& os, const cTime& t);
};


#endif // CTIME_H_INCLUDED
