#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int main() {
    CMatrix A, B;
    CVector v;

    cout << "--- NHAP MA TRAN A ---\n";
    cin >> A;

    cout << "\n--- NHAP MA TRAN B ---\n";
    cin >> B;

    cout << "\n--- NHAP VECTOR V ---\n";
    cin >> v;

    if (cin.fail()) {
        cout << "ERROR\n";
        return 1;
    }

    cout << "\n================ KET QUA KHOI TAO ================\n";
    cout << "Ma tran A (" << A.getRows() << "x" << A.getCols() << "):" << A;
    cout << "\nMa tran B (" << B.getRows() << "x" << B.getCols() << "):" << B;
    cout << "\nVector v: " << v << "\n";
    cout << "==================================================\n";

    // 1. Phép cộng, trừ ma trận
    cout << "\n--- KIEM TRA PHEP CONG / TRU MA TRAN ---";
    if (A.getRows() == B.getRows() && A.getCols() == B.getCols()) {
        CMatrix tong = A + B;
        CMatrix hieu = A - B;
        cout << "\nTong A + B:" << tong;
        cout << "Hieu A - B:" << hieu;
    } else {
        cout << "\n-> Khong the cong/tru vi A va B khong cung kich thuoc!\n";
    }

    // 2. Yêu cầu: Tích hai ma trận A * B
    cout << "\n--- KIEM TRA TICH HAI MA TRAN (A * B) ---";
    if (A.getCols() == B.getRows()) {
        CMatrix tichMaTran = A * B;
        cout << "\nTich A * B:" << tichMaTran;
    } else {
        cout << "\nKhong the nhan vi so cot cua A (" << A.getCols() << ") khac so hang cua B (" << B.getRows() << ")!\n";
    }

    // 3. Yêu cầu: Tích ma trận và vector A * v
    cout << "\n--- KIEM TRA TICH MA TRAN VA VECTOR (A * v) ---";
    if (A.getCols() == v.getChieu()) {
        CVector tichVector = A * v;
        cout << "\nTich A * v = " << tichVector << "\n";
    } else {
        cout << "\nKhong the nhan vi so cot cua A (" << A.getCols() << ") khac so chieu cua vector v (" << v.getChieu() << ")!\n";
    }

    return 0;
}
