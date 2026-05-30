#include "NgayThang.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

NgayThang::NgayThang() : ngay(1), thang(1), nam(2000) {}

NgayThang::NgayThang(int n, int t, int nm) : ngay(n), thang(t), nam(nm) {}

bool NgayThang::KiemTraHopLe() const {
    if (nam <= 0 || thang < 1 || thang > 12 || ngay < 1) {
        return false;
    }

    int ngayToiDa = 31;
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
        ngayToiDa = 30;
    } else if (thang == 2) {
        bool namNhuan = (nam % 400 == 0) || ((nam % 4 == 0) && (nam % 100 != 0));
        ngayToiDa = namNhuan ? 29 : 28;
    }

    return ngay <= ngayToiDa;
}

void NgayThang::Nhap() {
    bool isError = cin.fail();
    if (isError) cin.clear();

    cout << "Nhap ngay, thang, nam giao dich (cach nhau boi khoang trang): ";
    if (!(cin >> ngay)) {
        isError = true;
        cin.clear();
        string rac;
        cin >> rac;
    }
    if (!(cin >> thang)) {
        isError = true;
        cin.clear();
        string rac;
        cin >> rac;
    }
    if (!(cin >> nam)) {
        isError = true;
        cin.clear();
        string rac;
        cin >> rac;
    }

    if (!isError) {
        if (!KiemTraHopLe()) {
            isError = true;
        }
    }

    if (isError) {
        cin.setstate(ios::failbit);
    }
}

void NgayThang::Xuat() const {
    cout << setfill('0') << setw(2) << ngay << "/"
         << setw(2) << thang << "/"
         << setw(4) << nam << setfill(' ');
}

int NgayThang::GetThang() const { return thang; }
int NgayThang::GetNam() const { return nam; }
