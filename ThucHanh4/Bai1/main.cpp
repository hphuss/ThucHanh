#include <iostream>
#include "SoPhuc.h"

using namespace std;

int main()
{
    SoPhuc sp1, sp2;

    cout<<"--- NHAP SO PHUC 1---\n";
    cin>>sp1;

    cout<<"--- NHAP SO PHUC 2---\n";
    cin>>sp2;

    if(cin.fail())
    {
        cout<<"\nERROR\n";
        return 1;
    }


    cout<<"So phuc thu nhat: "<<sp1;
    cout<<"\nSo phuc thu hai: "<<sp2<<"\n";

    SoPhuc tong=sp1+sp2;
    SoPhuc hieu=sp1-sp2;
    SoPhuc tich=sp1*sp2;
    SoPhuc thuong=sp1/sp2;

    cout << "\nTong: " << tong;
    cout << "\nHieu: " << hieu;
    cout << "\nTich: " << tich;
    cout << "\nThuong: " << thuong << "\n";

    if (sp1 == sp2) cout << "\nHai so phuc bang nhau.\n";
    else cout << "\nHai so phuc khac nhau.\n";

    return 0;
}
