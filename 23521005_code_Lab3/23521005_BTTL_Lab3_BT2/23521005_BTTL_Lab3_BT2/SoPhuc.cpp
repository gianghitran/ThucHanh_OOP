#include "SoPhuc.h"
#include <iostream>
using namespace std;

SoPhuc::SoPhuc() :dThuc(0), dAo(0) {}//Khoi tao constructor mac dinh

SoPhuc::SoPhuc(double thuc, double ao) {//Khoi tao constructor co tham so
	dThuc = thuc;
	dAo = ao;
}

//Nhap so phuc
istream& operator >> (istream& is, SoPhuc& z) {
	is >> z.dThuc;
	is >> z.dAo;
	return is;
}

//In so phuc 
ostream& operator << (ostream& os, SoPhuc z) {
	if (z.dAo == 0) os << z.dThuc;
	else if (z.dThuc == 0) os << z.dAo<<"i";
	else {
		os << z.dThuc; 
		if (z.dAo >0)os << "+";//Neu phan ao duong thi in dau +
		os << z.dAo << "i";
	}
	return os;
}

//Cong hai so phuc
SoPhuc operator + (SoPhuc z, SoPhuc z2) {
	//z1 = a + bi và z2 = c + di
	//z1 + z2 = (a + c) + (b + d)i
	double thuc = z.dThuc + z2.dThuc;
	double ao = z.dAo + z2.dAo;
	return SoPhuc(thuc, ao);
}

//Tru hai so phuc
SoPhuc operator - (SoPhuc z, SoPhuc z2) {
	//z1 = a + bi và z2 = c + di
	//z1 - z2 = (a - c) + (b - d)i
	double thuc = z.dThuc - z2.dThuc;
	double ao = z.dAo - z2.dAo;
	return SoPhuc(thuc, ao);
}

//Nhan hai so phuc
SoPhuc operator * (SoPhuc z, SoPhuc z2) {
	//z1 = a + bi và z2 = c + di
	//z1.z2 = (ac - bd) + (ad + bc)i
	double thuc = (z.dThuc * z2.dThuc) - (z.dAo * z2.dAo);//(ac - bd)
	double ao = (z.dThuc * z2.dAo) + (z.dAo*z2.dThuc);//(ad + bc)
	return SoPhuc(thuc, ao);
}

//Chia hai so phuc
SoPhuc operator / (SoPhuc z, SoPhuc z2) {
	//z1 = a + bi va z2 = c + di
	// z1/z2= [(ac+bd)/(c^2+d^2)] + [(bc-ad)/(c^2+d^2)]i
	double mau = z2.dThuc * z2.dThuc + z2.dAo * z2.dAo; // (c^2+d^2)
	double thuc = ((z.dThuc * z2.dThuc) + (z.dAo * z2.dAo))/mau;//[(ac+bd)/(c^2+d^2)]
	double ao = ((z.dAo * z2.dThuc) - (z.dThuc * z2.dAo)) / mau;//[(bc-ad)/(c^2+d^2)] 
	return SoPhuc(thuc, ao);
}

//So sanh == hai so phuc
bool operator == (SoPhuc z, SoPhuc z2) {
	//== khi thuc = thuc VA ao = ao
	return (z.dThuc == z2.dThuc && z.dAo == z2.dAo);
}
//So sanh != hai so phuc
bool operator != (SoPhuc z, SoPhuc z2) {
	//!= khi thuc != thuc HOAC ao != ao
	return (z.dThuc != z2.dThuc || z.dAo != z2.dAo);
}

SoPhuc::SoPhuc (double thuc) : dThuc(thuc), dAo(0) {}// Constructor chuyen doi so thuc thanh so phuc