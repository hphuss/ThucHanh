#include <iostream>
#include "PhanSo.h"
#include <string>
#include <cmath>

using namespace std;

int UCLN(int a, int b)
{
    a=abs(a);
    b=abs(b);
    if (b==0) return a;
    return UCLN(b, a%b);
}
void PhanSo::RutGon()
{
    if(mau==0) return;
    int ucln=UCLN(tu, mau);
    tu /=ucln;
    mau /=ucln;

    if(mau<0){
        tu=-tu;
        mau=-mau;
    }
}
PhanSo::PhanSo(int t, int m): tu(t), mau(m)
{
    RutGon();
}
PhanSo PhanSo::operator+(const PhanSo& ps) const
{
    return PhanSo(tu*ps.mau+mau*ps.tu, mau*ps.mau);
}

PhanSo PhanSo::operator-(const PhanSo &ps) const
{
    return PhanSo(tu*ps.mau-mau*ps.tu, mau*ps.mau);
}

PhanSo PhanSo::operator*(const PhanSo &ps) const
{
    return PhanSo(tu*ps.tu, mau*ps.mau);
}

PhanSo PhanSo::operator/(const PhanSo &ps) const
{
    return PhanSo(tu*ps.mau, mau*ps.tu);
}

bool PhanSo::operator==(const PhanSo &ps) const
{
    return (tu*ps.mau==mau*ps.tu);
}

bool PhanSo::operator>(const PhanSo &ps) const
{
    return (tu*ps.mau>mau*ps.tu);
}

bool PhanSo::operator<(const PhanSo &ps) const
{
    return (tu*ps.mau<mau*ps.tu);
}

istream& operator>>(istream& is, PhanSo& ps)
{
    bool isError=is.fail();
    if(isError) is.clear();
    cout<<"Nhap tu so: ";
    if(!(is>>ps.tu)){
        isError=true;
        is.clear();
        string rac;
        cin>>rac;
    }

    cout<<"Nhap mau so: ";
    if(!(is>>ps.mau)){
        isError=true;
        is.clear();
        string rac;
        is>>rac;
    }
    else if(ps.mau==0)
        isError=true;

    if(isError)
        is.setstate(ios::failbit);
    else
        ps.RutGon();
    return is;
}
ostream& operator<<(ostream& os, const PhanSo& ps)
{
    if(ps.tu==0) os<<0;
    else if(ps.mau==1) os<<ps.tu;
    else os<<ps.tu<<"/"<<ps.mau;
    return os;
}
