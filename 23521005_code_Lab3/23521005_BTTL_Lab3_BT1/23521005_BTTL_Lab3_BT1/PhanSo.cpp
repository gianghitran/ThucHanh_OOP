#include "PhanSo.h"
#include <iostream>
using namespace std;

PhanSo::PhanSo() : iTu(0), iMau(1) {} //Khoi tao constructor mac dinh

PhanSo::PhanSo(int Tu, int Mau) { //Khoi tao constructor co tham so
	iTu = Tu;
	iMau = Mau;
}

//Tim Uoc chung lon nhat
int PhanSo::ucln(int a, int b) {
	if (b == 0)
		return a;//Neu b=0, a la ucln
	return ucln(b, a % b);//b!=0,goi de quy voi a = a %b
}
//Rut gon phan so
PhanSo PhanSo::rutGon() {
	int uocChung = 1;
	uocChung = ucln(iTu, iMau);

	int tuMoi = iTu / uocChung;
	int mauMoi = iMau / uocChung;
	if (mauMoi < 0) { //Neu mau am, tu duong
		tuMoi = -tuMoi;
		mauMoi = -mauMoi;
	}
	return PhanSo(tuMoi, mauMoi);
}
//Nhap phan so
istream& operator >> (istream& is, PhanSo& p) {
	is >> p.iTu;
	is >> p.iMau;
	while (p.iMau == 0)
	{
		cout << "Mau = 0. Khong hop le! Nhap lai phan so: ";
		is >> p.iTu;
		is >> p.iMau;
	}
	return is;
}
//In phan so
ostream& operator << (ostream& os, PhanSo p) {
	if (p.iMau == 0) cout << "Mau = 0. Khong hop le!";//kiem tra mau = 0
	else {
		os << p.iTu<<"/";
		os << p.iMau;
	}
	return os;
}


//Cong hai phan so
PhanSo operator + (PhanSo ps, PhanSo ps2) {
	int tu = ps.iTu*ps2.iMau + ps2.iTu* ps.iMau;
	int mau = ps.iMau * ps2.iMau;
	return PhanSo(tu,mau).rutGon();
}
//Tru hai phan so
PhanSo operator - (PhanSo ps, PhanSo ps2){
	int tu = ps.iTu * ps2.iMau - ps2.iTu * ps.iMau;
	int mau = ps.iMau * ps2.iMau;
	return PhanSo(tu, mau).rutGon();
}
//Nhan hai phan so
PhanSo operator * (PhanSo ps, PhanSo ps2){
	int tu = ps.iTu * ps2.iTu;
	int mau = ps.iMau * ps2.iMau;
	return PhanSo(tu, mau).rutGon();
}
//Chia hai phan so
PhanSo operator / (PhanSo ps, PhanSo ps2){
	int tu = ps.iTu * ps2.iMau;
	int mau = ps.iMau * ps2.iTu;
	return PhanSo(tu, mau).rutGon();
}
//Toan tu ==
bool operator == (PhanSo ps, PhanSo ps2) {
	return (ps.iTu * ps2.iMau == ps2.iTu * ps.iMau);
}
//Toan tu !=
bool operator != (PhanSo ps, PhanSo ps2) {
	return (ps.iTu * ps2.iMau != ps2.iTu * ps.iMau);
}
//Toan tu >=
bool operator >= (PhanSo ps, PhanSo ps2) {
	return (ps.iTu * ps2.iMau >= ps2.iTu * ps.iMau);
}
//Toan tu <=
bool operator <= (PhanSo ps, PhanSo ps2){
	return (ps.iTu * ps2.iMau <= ps2.iTu * ps.iMau);
}
//Toan tu >
bool operator > (PhanSo ps, PhanSo ps2) {
	return (ps.iTu * ps2.iMau > ps2.iTu * ps.iMau);
}
//Toan tu <
bool operator < (PhanSo ps, PhanSo ps2) {
	return (ps.iTu * ps2.iMau < ps2.iTu * ps.iMau);
}
// Chuyen doi tu dong doi tuong thuoc class PhanSo thanh kieu double khi can 
PhanSo::operator double() const { 
	return static_cast<double>(iTu) / iMau;
}