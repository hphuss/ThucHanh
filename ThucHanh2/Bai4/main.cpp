#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
    Time t1;
    t1.Nhap();
    Time t2;
    t2 = t1.TinhCongThemMotGiay();
    cout<<"Thoi gian sau khi cong them 1 giay la: "; t2.Xuat();
    return 0;
}
