#include <iostream>
#include "Date.h"
#include <iomanip>
#include <string>

using namespace std;

bool Date::namnhuan(int nam) const
{
    return(nam%400==0 || nam%4==0 && nam%100!=0);
}
int Date::ngaytrongthang(int month, int year) const
{
    switch(month)
    {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return namnhuan(nam)? 29:28;
    default:
        return 31;

    }
}
void Date::chuanhoa()
{
    while(ngay>ngaytrongthang(thang, nam)){
        ngay-=ngaytrongthang(thang, nam);
        thang++;
        if(thang>12){
            thang=1;
            nam++;
        }
    }
    while (ngay<=0){
        thang--;
        if(thang<1){
            thang=12;
            nam--;
        }
        ngay+=ngaytrongthang(thang, nam);
    }
}
int Date::quydoingay()const
{
    int days=ngay;

    for(int m=1; m<thang; m++) days+=ngaytrongthang(m, nam);
    int y=nam-1;
    days += y*365+y/4-y/100+y/400;

    return days;
}
Date::Date(int d, int m, int y): ngay(d), thang(m), nam(y)
{
    chuanhoa();
}

Date Date::operator+(int days)const
{
    Date tmp=*this;
    tmp.ngay+=days;
    tmp.chuanhoa();
    return tmp;
}
Date Date::operator-(int days)const
{
    Date tmp=*this;
    tmp.ngay-=days;
    tmp.chuanhoa();
    return tmp;
}

Date& Date::operator++()
{
    ngay++;
    chuanhoa();
    return *this;
}
Date Date::operator++(int)
{
    Date tmp=*this;
    ngay++;
    chuanhoa();
    return tmp;
}

Date& Date::operator--()
{
    ngay--;
    chuanhoa();
    return *this;
}
Date Date::operator--(int)
{
    Date tmp=*this;
    ngay--;
    chuanhoa();
    return tmp;
}

int Date::operator-(const Date& other)const
{
    return this->quydoingay() - other.quydoingay();
}
istream& operator>>(istream& is, Date& date)
{
    bool isError=is.fail();
    if(isError) is.clear();

    cout<<"Nhap ngay: ";
    if(!(is>>date.ngay)) {isError=true; is.clear(); string rac; is>>rac;}
    cout<<"Nhap thang: ";
    if(!(is>>date.thang)) {isError=true; is.clear(); string rac; is>>rac;}
    cout<<"Nhap nam: ";
    if(!(is>>date.nam)) {isError=true; is.clear(); string rac; is>>rac;}

    if(!isError)
        if(date.nam<0||date.thang<1||date.thang>12||date.ngay<1||date.ngay>date.ngaytrongthang(date.thang, date.nam))
            isError=true;
    if(isError) is.setstate(ios::failbit);
    return is;
}
ostream& operator<<(ostream& os,const Date& date)
{
    os<<setfill('0')<<setw(2)<<date.ngay<<"/"
      <<setfill('0')<<setw(2)<<date.thang<<"/"
      <<setfill('0')<<setw(4)<<date.nam;
    return os;
}
