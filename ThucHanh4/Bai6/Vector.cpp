#include "Vector.h"
#include <string>

using namespace std;

CVector::CVector(int numElements) : n(numElements)
{
    if(n<0) n=0;
    coordinates = new double[n];
    for(int i=0; i<n; i++)
        coordinates[i]=0.0;
}

CVector::CVector(const CVector& other) : n(other.n)
{
    coordinates = new double[n];
    for(int i=0; i<n; i++)
        coordinates[i]=other.coordinates[i];
}
CVector::~CVector()
{
    delete[] coordinates;
}
CVector& CVector::operator=(const CVector& other)
{
    if(this!=&other){
        delete[] coordinates;
        n = other.n;
        coordinates = new double[n];
        for(int i=0; i<n; i++)
            coordinates[i]=other.coordinates[i];
    }
    return *this;
}
int CVector::getChieu()const
{
    return n;
}
CVector CVector::operator+(const CVector& other) const {
    if (n != other.n){
        return CVector(0); // Trả về vector rỗng nếu lệch số chiều
    }
    CVector ketQua(n);
    for (int i = 0; i < n; ++i) {
        ketQua.coordinates[i] = coordinates[i] + other.coordinates[i];
    }
    return ketQua;
}

// Phép trừ 2 vector
CVector CVector::operator-(const CVector& other) const {
    if (n != other.n) {
        return CVector(0);
    }
    CVector ketQua(n);
    for (int i = 0; i < n; ++i) {
        ketQua.coordinates[i] = coordinates[i] - other.coordinates[i];
    }
    return ketQua;
}

// Tích vô hướng (Vector * Vector -> Số thực)
double CVector::operator*(const CVector& other) const {
    if (n != other.n) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += coordinates[i] * other.coordinates[i];
    }
    return sum;
}

// NHẬP XUẤT

// Toán tử nhập (Hút rác bộ đệm + check định dạng)
istream& operator>>(istream& is, CVector& vec) {
    bool isError = is.fail();
    if (isError) is.clear();

    cout << "Nhap so chieu cua vector: ";
    int dim;
    if (!(is >> dim) || dim < 0) {
        isError = true;
        is.clear();
        string rac;
        is >> rac;
        dim = 0;
    }

    delete[] vec.coordinates;
    vec.n = dim;
    vec.coordinates = new double[vec.n];

    for (int i = 0; i < vec.n; ++i) {
        cout << "Nhap thanh phan thu " << i + 1 << ": ";
        if (!(is >> vec.coordinates[i])) {
            isError = true;
            is.clear();
            string rac;
            is >> rac;
        }
    }

    if (isError) {
        is.setstate(ios::failbit);
    }

    return is;
}

// Toán tử xuất (Định dạng toán học chuẩn: (v1, v2, ..., vn))
ostream& operator<<(ostream& os, const CVector& vec) {
    os << "(";
    for (int i = 0; i < vec.n; ++i) {
        os << vec.coordinates[i];
        if (i < vec.n - 1) os << ", ";
    }
    os << ")";
    return os;
}
