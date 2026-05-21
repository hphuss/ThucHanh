#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    CVector v1, v2;

    cout << "--- NHAP VECTOR 1 ---\n";
    cin >> v1;
    //if (cin.fail()) { cout << "ERROR\n"; return 1; }

    cout << "\n--- NHAP VECTOR 2 ---\n";
    cin >> v2;
    if (cin.fail()) { cout << "ERROR\n"; return 1; }

    cout << "\n========================================\n";
    cout << "Vector 1: " << v1 << "\n";
    cout << "Vector 2: " << v2 << "\n";

    // Kiểm tra tính hợp lệ về mặt toán học (Cùng số chiều mới tính toán được)
    if (v1.getChieu() != v2.getChieu()) {
        cout << "\nLoi: Hai vector khong cung so chieu, khong the thuc hien phep toan!\n";
    } else {
        CVector tong = v1 + v2;
        CVector hieu = v1 - v2;
        double tichVoHuong = v1 * v2;

        cout << "\nTong v1 + v2: " << tong << "\n";
        cout << "Hieu v1 - v2: " << hieu << "\n";
        cout << "Tich vo huong v1 * v2: " << tichVoHuong << "\n";
    }
    cout << "========================================\n";

    return 0;
}
