// 23521005_BTTL_Lab3_BT2.cpp 
#include "SoPhuc.h"
#include <iostream>
using namespace std;
int main()
{
    SoPhuc z_cons;//Khoi tao constructor mac dinh
    SoPhuc z_cons_para(1,1);////Khoi tao constructor co tham so
    cout << "Nhap so phuc thu nhat: ";
    SoPhuc z; cin >> z;
    cout << "Nhap so phuc thu hai: ";
    SoPhuc z2; cin >> z2;

    //Cong hai so phuc
    cout << "Cong hai so phuc: ";
    cout << z + z2 << endl;

    //Cong so phuc voi so thuc
    cout << "Cong so phuc voi so thuc: ";
    cout <<"("<< z << ") + " << 2.5 << " = ";
    cout << z + 2.5 <<  endl;

    //Tru hai so phuc
    cout << "Tru hai so phuc: ";
    cout << z - z2 << endl;

    //Tru so phuc voi so thuc
    cout << "Tru so phuc voi so thuc: ";
    cout << "(" << z << ") - " << 3.5 << " = ";
    cout << z - 3.5 << endl;

    //Nhan hai so phuc
    cout << "Nhan hai so phuc: ";
    cout << z * z2 << endl;

    //Nhan so phuc voi so thuc
    cout << "Nhan so phuc voi so thuc: ";
    cout << "(" << z << ") * " << 4.5 << " = ";
    cout << z * 4.5 << endl;

    //Chia hai so phuc
    cout<< "Chia hai so phuc : ";
    cout << z / z2 << endl;

    //Chia so phuc voi so thuc
    cout << "Chia so phuc voi so thuc: ";
    cout << "(" << z << ") / " << 6 << " = ";
    cout << z / 6 << endl;

    if (z == z2) cout << z << " == " << z2<<endl;
    if (z != z2) cout << z << " != " << z2 << endl;
    return 0;
}

