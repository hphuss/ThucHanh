#ifndef CMATRIX_H_INCLUDED
#define CMATRIX_H_INCLUDED

#include <iostream>
#include "Vector.h"
class CMatrix {
private:
    int rows;       // Số hàng (m)
    int cols;       // Số cột (n)
    double** data;  // Mảng hai chiều cấp phát động
    friend class CVector;

public:
    CMatrix(int r = 0, int c = 0);
    CMatrix(const CMatrix& other);
    ~CMatrix();
    CMatrix& operator=(const CMatrix& other);

    int getRows() const;
    int getCols() const;

    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator-(const CMatrix& other) const;

    CMatrix operator*(const CMatrix& other) const;

    CVector operator*(const CVector& vec) const;

    friend std::istream& operator>>(std::istream& is, CMatrix& mat);
    friend std::ostream& operator<<(std::ostream& os, const CMatrix& mat);
};

#endif // CMATRIX_H_INCLUDED
