#include <iostream>
#include <windows.h>
#include "CTime.h"
#include <cmath>

using namespace std;


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    cTime t;

    cout << "--- CAI DAT DONG HO ---\n";
    cin >> t;

    if (cin.fail()) {
        cout << "ERROR\n";
        return 1;
    }

    int soGiay;
    cout << "Nhap so giay muon them bot (nhap so duong de them, so am de bot): ";
    cin >> soGiay;

    if (cin.fail()) {
        cout << "ERROR\n";
        return 1;
    }


    cTime tSauThemBot = t + soGiay;
    cout<<"\nThoi gian da nhap: "<<t<<"\n";
    if(soGiay>0)
        cout << "\nThoi gian sau khi them " << soGiay << " giay: " << tSauThemBot << "\n";
    else if(soGiay<0)
        cout<<"\nThoi gian sau khi bot "<< abs(soGiay) <<" giay: "<<tSauThemBot<<"\n";
    else
        cout<<"\nThoi gian khong doi\n;";

    cTime tThem1Giay = t+1;
    cout << "Thoi gian ban dau khi them 1 giay: " << tThem1Giay << "\n";
    cTime tBot1Giay = t-1;
    cout << "Thoi gian ban dau khi them 1 giay: " << tBot1Giay << "\n";
    cout << "\nAn Enter de bat dau hien thi dong ho chay tu dong...";
    cin.ignore();
    cin.get();

    system("cls");


    while (true) {
        gotoxy(90, 1);

        cout << "[" << t << "]";

        Sleep(1000);

        t++;
    }

    return 0;
}
