#include "Matrix.h"
#include <string>

using namespace std;


CMatrix::CMatrix(int r, int c) : rows(r), cols(c) {
    if (rows < 0) rows = 0;
    if (cols < 0) cols = 0;

    if (rows > 0 && cols > 0) {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0.0;
            }
        }
    } else {
        data = nullptr;
    }
}

CMatrix::CMatrix(const CMatrix& other) : rows(other.rows), cols(other.cols) {
    if (rows > 0 && cols > 0) {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    } else {
        data = nullptr;
    }
}

CMatrix::~CMatrix() {
    if (data != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
}

CMatrix& CMatrix::operator=(const CMatrix& other) {
    if (this != &other) {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }
        rows = other.rows;
        cols = other.cols;
        if (rows > 0 && cols > 0) {
            data = new double*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new double[cols];
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        } else {
            data = nullptr;
        }
    }
    return *this;
}

int CMatrix::getRows() const { return rows; }
int CMatrix::getCols() const { return cols; }

// --- CÁC PHÉP TOÁN ĐẠI SỐ ---

CMatrix CMatrix::operator+(const CMatrix& other) const {
    if (rows != other.rows || cols != other.cols) return CMatrix(0, 0);
    CMatrix ketQua(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ketQua.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return ketQua;
}

CMatrix CMatrix::operator-(const CMatrix& other) const {
    if (rows != other.rows || cols != other.cols) return CMatrix(0, 0);
    CMatrix ketQua(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ketQua.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return ketQua;
}


CMatrix CMatrix::operator*(const CMatrix& other) const {
    if (cols != other.rows) return CMatrix(0, 0);
    CMatrix ketQua(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                ketQua.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return ketQua;
}


CVector CMatrix::operator*(const CVector& vec) const {
    if (cols != vec.getChieu()) return CVector(0);

    CVector ketQua(rows);
    for (int i = 0; i < rows; ++i) {
        double sum = 0.0;
        for (int j = 0; j < cols; ++j) {
            sum += data[i][j] * vec.coordinates[j];
        }
        ketQua.coordinates[i] = sum;
    }

    return ketQua;
}



istream& operator>>(istream& is, CMatrix& mat) {
    bool isError = is.fail();
    if (isError) is.clear();

    cout << "Nhap so hang cua ma tran: ";
    int r;
    if (!(is >> r) || r < 0) { isError = true; is.clear(); string rac; is >> rac; }

    cout << "Nhap so cot cua ma tran: ";
    int c;
    if (!(is >> c) || c < 0) { isError = true; is.clear(); string rac; is >> rac; }

    if (!isError) {
        if (mat.data != nullptr) {
            for (int i = 0; i < mat.rows; ++i) delete[] mat.data[i];
            delete[] mat.data;
        }

        mat.rows = r;
        mat.cols = c;

        if (mat.rows > 0 && mat.cols > 0) {
            mat.data = new double*[mat.rows];
            for (int i = 0; i < mat.rows; ++i) {
                mat.data[i] = new double[mat.cols];
                for (int j = 0; j < mat.cols; ++j) {
                    cout << "Nhap phan tu [" << i << "][" << j << "]: ";
                    if (!(is >> mat.data[i][j])) {
                        isError = true;
                        is.clear();
                        string rac;
                        is >> rac;
                    }
                }
            }
        } else {
            mat.data = nullptr;
        }
    }

    if (isError) {
        is.setstate(ios::failbit);
        if (mat.data != nullptr) {
            for (int i = 0; i < mat.rows; ++i) delete[] mat.data[i];
            delete[] mat.data;
            mat.data = nullptr;
        }
        mat.rows = 0; mat.cols = 0;
    }
    return is;
}

ostream& operator<<(ostream& os, const CMatrix& mat) {
    if (mat.rows == 0 || mat.cols == 0) {
        os << "[]";
        return os;
    }
    os << "\n";
    for (int i = 0; i < mat.rows; ++i) {
        os << "\t";
        for (int j = 0; j < mat.cols; ++j) {
            os << mat.data[i][j] << "\t";
        }
        os << "\n";
    }
    return os;
}
