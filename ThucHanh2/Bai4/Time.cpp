#include <iostream>
#include "Time.h"
#include <string>
#include <limits>

using namespace std;
int Time::NhapSoNguyen()
{
    int n;
    while (true) {
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Vui long chi nhap so nguyen: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return n;
        }
    }
}

void Time::Nhap()
{
    //Nhap va kiem tra gio
    do{
        cout<<"Nhap gio: ";
        iGio=NhapSoNguyen();
        if(iGio<0||iGio>23) cout<<"Gio phai nam trong khoang [0;23]! Vui long nhap lai.\n";
    }while(iGio<0||iGio>23);
    //Nhap va kiem tra phut
    do{
        cout<<"Nhap phut: ";
        iPhut=NhapSoNguyen();
        if(iPhut<0||iPhut>59) cout<<"Phut phai nam trong khoang [0;59]! Vui long nhap lai.\n";
    }while(iPhut<0||iPhut>59);
    //Nhap va kiem tra giay
    do{
        cout<<"Nhap giay: ";
        iGiay=NhapSoNguyen();
        if(iGiay<0||iGiay>59) cout<<"Giay phai nam trong khoang [0;59]! Vui long nhap lai.\n";
    }while(iGiay<0||iGiay>59);
    cout<<"Thoi gian da nhap la: ";Xuat();
}
Time Time::TinhCongThemMotGiay()
{
    Time next = *this;
    next.iGiay++;
    if (next.iGiay == 60){
        next.iGiay=0;
        next.iPhut++;
        if(next.iPhut == 60){
            next.iPhut=0;
            next.iGio++;
            if(next.iGio == 24)
                next.iGio = 0;
        }
    }
    return next;
}
void Time::Xuat()
{
    //Phan biet AM va PM
    int h = iGio;
    string ampm = "AM";
    if(h==0){
        h=12;
        ampm = "AM";
    }
    else if(h==12) ampm = "PM";
    else if(h>12){
        h=h-12;
        ampm="PM";
    }
    //Xuat gio
    if(h<10) cout<<"0";
    cout<<h<<":";
    if(iPhut<10) cout<<"0";
    cout<<iPhut<<":";
    if(iGiay<10) cout<<"0";
    cout<<iGiay<<" "<<ampm<<"\n";
}
