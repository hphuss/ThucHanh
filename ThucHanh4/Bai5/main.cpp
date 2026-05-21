#include <iostream>
#include "DaThuc.h"

using namespace std;

int main() {
    DaThuc dt1, dt2;

    cout << "--- NHAP DA THUC 1 ---\n";
    cin >> dt1;

    if (cin.fail()) {
        cout << "ERROR\n";
        return 1;
    }

    cout << "\n--- NHAP DA THUC 2 ---\n";
    cin >> dt2;

    if (cin.fail()) {
        cout << "ERROR\n";
        return 1;
    }

    cout << "\n====================================\n";
    cout << "Da thuc 1: " << dt1 << "\n";
    cout << "Da thuc 2: " << dt2 << "\n";

    DaThuc tong = dt1 + dt2;
    DaThuc hieu = dt1 - dt2;
    DaThuc tich = dt1 * dt2;

    cout << "\nTong (P1 + P2): " << tong << "\n";
    cout << "Hieu (P1 - P2): " << hieu << "\n";
    cout << "Tich (P1 * P2): " << tich << "\n";
    cout << "====================================\n";

    return 0;
}
