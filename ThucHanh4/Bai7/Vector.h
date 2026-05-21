#ifndef CVECTOR_H_INCLUDED
#define CVECTOR_H_INCLUDED

#include <iostream>

class CVector {
private:
    int n;                  // so chieu cua vector
    double* coordinates;    // Luu toa do
    friend class CMatrix;
public:

    CVector(int numElements = 0);
    CVector(const CVector& other);
    ~CVector();
    CVector& operator=(const CVector& other);

    int getChieu() const;

    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;
    double operator*(const CVector& other) const;

    friend std::istream& operator>>(std::istream& is, CVector& vec);
    friend std::ostream& operator<<(std::ostream& os, const CVector& vec);
};

#endif // CVECTOR_H_INCLUDED
