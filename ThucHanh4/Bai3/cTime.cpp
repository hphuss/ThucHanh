#include "cTime.h"
#include <string>
#include <iomanip>

using namespace std;

void cTime::chuanhoa()
{
    long long TongGiay=gio*3600+phut*60+giay;


    TongGiay=(TongGiay%86400+86400)%86400;

    gio=TongGiay/3600;
    phut=(TongGiay%3600)/60;
    giay=TongGiay%60;

}
cTime::cTime(int g, int p, int s): gio(g), phut(p), giay(s)
{
    chuanhoa();
}
cTime cTime::operator+(int s)const
{
    return cTime(gio, phut, giay+s);
}
cTime cTime::operator-(int s)const
{
    return cTime(gio, phut, giay-s);
}
cTime& cTime::operator++()
{
    giay++;
    chuanhoa();
    return *this;
}
cTime cTime::operator++(int)
{
    cTime tam=*this;
    giay++;
    chuanhoa();
    return tam;
}

cTime& cTime::operator--()
{
    giay--;
    chuanhoa();
    return *this;
}
cTime cTime::operator--(int)
{
    cTime tam=*this;
    giay--;
    chuanhoa();
    return tam;
}
istream& operator>>(istream& is, cTime& t)
{
    bool isError=is.fail();
    if(isError) is.clear();

    cout<<"Nhap gio: ";
    if(!(is>>t.gio)){isError=true; is.clear(); string rac; is>>rac;}

    cout<<"Nhap phut: ";
    if(!(is>>t.phut)){isError=true; is.clear(); string rac; is>>rac;}

    cout<<"Nhap giay: ";
    if(!(is>>t.giay)){isError=true; is.clear(); string rac; is>>rac;}

    if(isError)
        is.setstate(ios::failbit);
    else
        t.chuanhoa();
    return is;
}
ostream& operator<<(ostream& os, const cTime& t)
{
    int h=t.gio;
    string ampm="AM";
    if(h==0){
        h=12;
        ampm="AM";
    }
    else if(h==12) ampm="AM";
    else if(h>12){
        h=h-12;
        ampm="PM";
    }
    os << setfill('0') << setw(2) << t.gio << ":"
       << setfill('0') << setw(2) << t.phut << ":"
       << setfill('0') << setw(2) << t.giay<<" "<<ampm;
    return os;
}
