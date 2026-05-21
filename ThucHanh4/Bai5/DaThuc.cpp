#include <iostream>
#include "DaThuc.h"
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

DaThuc::DaThuc(int b): bac(b)
{
    if(bac<0) bac=0;
    heso = new double[bac+1];
    for(int i=0; i<=bac; ++i)
        heso[i]=0.0;
}
DaThuc::DaThuc(const DaThuc& other) : bac(other.bac)
{
    heso = new double [bac+1];
    for(int i=0; i<=bac; ++i)
        heso[i]=other.heso[i];
}

DaThuc::~DaThuc()
{
    delete[] heso;
}
DaThuc& DaThuc::operator=(const DaThuc& other)
{
    if(this!=&other){
        delete[] heso;
        bac=other.bac;
        heso=new double[bac+1];
        for(int i=0; i<=bac; ++i)
            heso[i]=other.heso[i];
        }
        return *this;
}

DaThuc DaThuc::operator+(const DaThuc& other) const
{
    int bacMoi=max(bac, other.bac);
    DaThuc ketqua(bacMoi);
    for (int i = 0; i <= bacMoi; ++i) {
        double hs1 = (i <= bac) ? heso[i] : 0.0;
        double hs2 = (i <= other.bac) ? other.heso[i] : 0.0;
        ketqua.heso[i] = hs1 + hs2;
    }
    return ketqua;
}

DaThuc DaThuc::operator-(const DaThuc& other) const
{
    int bacMoi=max(bac, other.bac);
    DaThuc ketqua(bacMoi);
    for (int i = 0; i <= bacMoi; ++i) {
        double hs1 = (i <= bac) ? heso[i] : 0.0;
        double hs2 = (i <= other.bac) ? other.heso[i] : 0.0;
        ketqua.heso[i] = hs1 - hs2;
    }
    return ketqua;
}

DaThuc DaThuc::operator*(const DaThuc& other) const
{
    int bacMoi = bac + other.bac;
    DaThuc ketQua(bacMoi);

    for (int i = 0; i <= bac; ++i) {
        for (int j = 0; j <= other.bac; ++j) {
            ketQua.heso[i + j] += heso[i] * other.heso[j];
        }
    }
    return ketQua;
}

istream& operator>>(istream& is, DaThuc& dt)
{
    bool isError = is.fail();
    if (isError) is.clear();

    cout << "Nhap bac cua da thuc: ";
    int b;
    if (!(is >> b) || b < 0) {
        isError = true;
        is.clear();
        string rac;
        is >> rac;
    }
    if (!isError) {
        // Nếu người dùng nhập bậc mới, ta phải cấp phát lại mảng
        if (b != dt.bac) {
            delete[] dt.heso;
            dt.bac = b;
            dt.heso = new double[dt.bac + 1];
        }

        // Nhập hệ số từ bậc cao nhất xuống bậc 0
        for (int i = dt.bac; i >= 0; --i) {
            cout << "Nhap he so cua x^" << i << ": ";
            if (!(is >> dt.heso[i])) {
                isError = true;
                is.clear();
                string rac;
                is >> rac;
            }
        }
    }

    if (isError) {
        is.setstate(ios::failbit);
    }
    return is;
}
ostream& operator<<(ostream& os, const DaThuc& dt) {
    bool isFirst = true;
    bool isZero = true;

    for (int i = dt.bac; i >= 0; --i) {
        if (dt.heso[i] != 0) {
            isZero = false;

            // Xử lý in dấu
            if (dt.heso[i] > 0 && !isFirst) os << " + ";
            else if (dt.heso[i] < 0) {
                if (isFirst) os << "-";
                else os << " - ";
            }

            double val = abs(dt.heso[i]);

            // Xử lý in hệ số (Bỏ qua số 1 trừ khi nó là hằng số tự do)
            if (val != 1 || i == 0) os << val;

            // Xử lý in ẩn x
            if (i > 0) {
                os << "x";
                if (i > 1) os << "^" << i;
            }

            isFirst = false;
        }
    }

    if (isZero) os << "0";
    return os;
}
