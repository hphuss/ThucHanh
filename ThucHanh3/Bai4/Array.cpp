#include "Array.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

cArray::cArray(): a(nullptr), n(0){}

cArray::~cArray()
{
    if(a != nullptr)
        delete[] a;
}
cArray::cArray(const cArray& khac) {
    n = khac.n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = khac.a[i];
    }
}

cArray& cArray::operator=(const cArray& khac) {
    if (this == &khac) return *this;
    if (a != nullptr) delete[] a;

    n = khac.n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = khac.a[i];
    }
    return *this;
}

// === HAM HO TRO ===
bool cArray::KiemTraSoNguyenTo(int so) const {
    if (so < 2) return false;
    for (int i = 2; i <= sqrt(so); i++) {
        if (so % i == 0) return false;
    }
    return true;
}

// === CHUC NANG CHINH ===
void cArray::TaoNgauNhien(int kichThuoc) {
    if (a != nullptr) delete[] a;

    n = kichThuoc;
    a = new int[n];

    // Tao seed ngau nhien dua vao thoi gian thuc
    srand((unsigned int)time(0));

    for (int i = 0; i < n; i++) {
        // Tao so ngau nhien tu -50 den 99 de test ca so am va duong
        a[i] = rand() % 150 - 50;
    }
}

void cArray::XuatMang() const {
    if (n == 0) {
        cout << "Mang rong\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "\n";
}

int cArray::DemGiaTri(int x) const {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) dem++;
    }
    return dem;
}

bool cArray::KiemTraTangDan() const {
    if (n <= 1) return true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

bool cArray::TimLeNhoNhat(int& ketQua) const {
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) { // La so le (hoat dong ca voi so am)
            if (!timThay || a[i] < ketQua) {
                ketQua = a[i];
                timThay = true;
            }
        }
    }
    return timThay;
}

bool cArray::TimNguyenToLonNhat(int& ketQua) const {
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (KiemTraSoNguyenTo(a[i])) {
            if (!timThay || a[i] > ketQua) {
                ketQua = a[i];
                timThay = true;
            }
        }
    }
    return timThay;
}

void cArray::SapXepTangDan() {
    for (int i = 0; i < n - 1; i++) {
        int viTriMin = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[viTriMin]) viTriMin = j;
        }
        swap(a[i], a[viTriMin]);
    }
}

void cArray::SapXepGiamDan() {
    for (int i = 0; i < n - 1; i++) {
        int viTriMax = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[viTriMax]) viTriMax = j;
        }
        swap(a[i], a[viTriMax]);
    }
}
