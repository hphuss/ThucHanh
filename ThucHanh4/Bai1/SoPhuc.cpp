#include <iostream>
#include "SoPhuc.h"
#include <cmath>

using namespace std;


SoPhuc::SoPhuc(double t, double a): thuc(t), ao(a){}

SoPhuc SoPhuc::operator+(const SoPhuc& sp2)const
{
    return SoPhuc(thuc+sp2.thuc, ao+sp2.ao);
}
SoPhuc SoPhuc::operator-(const SoPhuc& sp2)const
{
    return SoPhuc(thuc-sp2.thuc, ao-sp2.ao);
}
SoPhuc SoPhuc::operator*(const SoPhuc& sp2)const
{
    return SoPhuc(thuc*sp2.thuc-ao*sp2.ao,
           thuc*sp2.ao+ao*sp2.thuc);
}
SoPhuc SoPhuc::operator/(const SoPhuc& sp2)const
{
    double mau=sp2.thuc*sp2.thuc+sp2.ao*sp2.ao;
    if(mau==0) return SoPhuc(0,0);
    double thucMoi=(thuc*sp2.thuc+ao*sp2.ao)/mau;
    double aoMoi=(ao*sp2.thuc-thuc*sp2.ao)/mau;
    return SoPhuc(thucMoi, aoMoi);
}

bool SoPhuc::operator==(const SoPhuc& sp2)const
{
    return(thuc ==sp2.thuc && ao ==sp2.ao);
}
bool SoPhuc::operator!=(const SoPhuc &sp2)const
{
    return !(*this==sp2);
}

istream& operator>>(istream& is, SoPhuc& sp)
{
    bool isError=is.fail();
    if(isError) is.clear();
    cout<<"Nhap phan thuc: ";
    if(!(is>>sp.thuc)){
        isError=true;
        is.clear();
        string rac;
        is>>rac;
    }
    cout<<"Nhap phan ao: ";
    if(!(is>>sp.ao)){
        isError=true;
        is.clear();
        string rac;
        is>>rac;
    }
    if (isError) {
        is.setstate(ios::failbit);
    }

    return is;
}
ostream& operator<<(ostream& os, const SoPhuc& sp)
{
    double thucIn=round(sp.thuc*100.0)/100.0;
    double aoIn=round(sp.ao*100.0)/100.0;
    if(thucIn==0 && aoIn==0) os<<0;
    else{
        if(thucIn==0 && aoIn!=0) os<<aoIn<<"i";
        else if(thucIn!=0 && aoIn==0) os<<thucIn;
        else {
                os<<thucIn;
            if (aoIn >= 0) os << " + " << aoIn << "i";
            else os << " - " << std::abs(aoIn) << "i";
        }
    }
    return os;
}
