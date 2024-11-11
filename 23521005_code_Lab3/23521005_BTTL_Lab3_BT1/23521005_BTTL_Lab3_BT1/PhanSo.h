#pragma once
#include<iostream>
using namespace std;
class PhanSo {
private:
    int iTu;
    int iMau;

public:
    PhanSo();
    PhanSo(int Tu , int Mau);
    int ucln(int a, int b);
    PhanSo rutGon();
    friend PhanSo operator +(PhanSo ps, PhanSo ps2);
    friend PhanSo operator - (PhanSo ps, PhanSo ps2);
    friend PhanSo operator * (PhanSo ps, PhanSo ps2);
    friend PhanSo operator / (PhanSo ps, PhanSo ps2);

    friend bool operator == (PhanSo ps, PhanSo ps2);
    friend bool operator != (PhanSo ps, PhanSo ps2);
    friend bool operator >= (PhanSo ps, PhanSo ps2);
    friend bool operator <= (PhanSo ps, PhanSo ps2);
    friend bool operator > (PhanSo ps, PhanSo ps2);
    friend bool operator < (PhanSo ps, PhanSo ps2);

    friend istream& operator >> (istream& is, PhanSo &p);
    friend ostream& operator << (ostream& os, PhanSo p);

    operator double() const;//Tu dong ep kieu sang double khi can
};

