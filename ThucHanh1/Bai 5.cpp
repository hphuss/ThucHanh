#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct HocSinh {
    string maHS;
    string hoTen;
    string gioiTinh;
    float diemToan, diemLy, diemHoa, diemTB;
};

void nhapThongTin(HocSinh &hs) {
    cout << "Ma HS: ";
    getline(cin, hs.maHS);

    cout << "Ho ten: ";
    getline(cin, hs.hoTen);

    cout << "Gioi tinh: ";
    getline(cin, hs.gioiTinh);

    cout << "Diem Toan, Ly, Hoa: ";
    cin >> hs.diemToan >> hs.diemLy >> hs.diemHoa;

    hs.diemTB = (hs.diemToan + hs.diemLy + hs.diemHoa) / 3.0;
}

void xuatThongTin(HocSinh hs) {
    cout << "\nTHONG TIN HS\n";
    cout << "Ma HS: " << hs.maHS << "\n";
    cout << "Ho ten: " << hs.hoTen << "\n";
    cout << "Gioi tinh: " << hs.gioiTinh << "\n";
    cout << "Toan: " << hs.diemToan << " | Ly: " << hs.diemLy << " | Hoa: " << hs.diemHoa << "\n";
    cout << "Diem Trung Binh: " << fixed << setprecision(2) << hs.diemTB << "\n";
}

int main() {
    HocSinh hs;
    nhapThongTin(hs);
    xuatThongTin(hs);
    return 0;
}

