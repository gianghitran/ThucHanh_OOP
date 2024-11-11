#include"NgayThangNam.h"
#include<iostream>
using namespace std;

NgayThangNam::NgayThangNam() :iNam(0), iThang(0), iNgay(0) {} //Khoi tao constructor mac dinh

NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay) {//Khoi tao constructor co tham so
	iNgay = Ngay;
	iThang = Thang;
	iNam = Nam;
}
//Kiem tra thang co may ngay
int NgayThangNam::KTThang(NgayThangNam n)
{
	//input: thoi gian (ngay/thang/nam)
	//output: ngay cuoi cung cua thang 
	if (n.iThang == 1 || n.iThang == 3 || n.iThang == 5 || n.iThang == 7 || n.iThang == 8 || n.iThang == 10 || n.iThang == 12) return 31;
	else if (n.iThang == 2)
	{//Neu la thang 2 thi kiem tra nam nhuan
		if ((n.iNam % 4 == 0 && n.iNam % 100 != 0) || (n.iNam % 400 == 0))return 29;
		else return 28;
	}
	else return 30;
}
//Nhap ngay thang nam
istream& operator >> (istream& is, NgayThangNam& n) {
	cout << "Nhap lan luot ngay,thang,nam: ";
	is >> n.iNgay;
	is >> n.iThang;
	is >> n.iNam;
	if (n.iThang > 12 || n.iThang < 1) //Thang khong hop le khi nam ngoai khoang [1,12]
	{
		cout << "Thoi gian nhap vao khong hop le! Vui long nhap lai!\n";
		is >> n.iNgay;
		is >> n.iThang;
		is >> n.iNam;
	}
	if (n.iNgay < 1 || n.KTThang(n) < n.iNgay) //Ngay am la khong hop le 
	{
		cout << "Thoi gian nhap vao khong hop le! Vui long nhap lai!\n";
		is >> n.iNgay;
		is >> n.iThang;
		is >> n.iNam;
	}
	return is;
}

//Xuat Ngay/thang/nam
ostream& operator << (ostream& os, NgayThangNam n) {
	if (n.iNgay < 10)os << "0"; //in ngay
	os << n.iNgay << "/";
	if (n.iThang < 10)os << "0"; //in thang 
	os << n.iThang << "/";
	os << n.iNam ; //in nam 
	return os;
}

//Tinh tong so ngay cua nam do
int NgayThangNam::TinhNgay() {
	int TongNgay=0;
	for (int i = 1; i < iThang; i++) {
		NgayThangNam temp(1, i, iNam);
		TongNgay += KTThang(temp);
	}
	TongNgay += iNgay;
	return TongNgay;
}

//Operator + so ngay
NgayThangNam NgayThangNam::operator+(int Ngay) {
	int Ngay_new = iNgay + Ngay;
	int Thang_new = iThang;
	int Nam_new = iNam;

	while (Ngay_new > KTThang(NgayThangNam(Nam_new, Thang_new, 1))) {
		Ngay_new -= KTThang(NgayThangNam(Nam_new, Thang_new, 1));
		Thang_new++;
		if (Thang_new > 12) {
			Thang_new = 1;
			Nam_new++;
		}
	}
	return NgayThangNam(Nam_new, Thang_new, Ngay_new);
}
//Operator - so ngay
NgayThangNam NgayThangNam::operator-(int Ngay) {
	int Ngay_new = iNgay - Ngay;
	int Thang_new = iThang;
	int Nam_new = iNam;

	while (Ngay_new < 1) {
		Thang_new--;
		if (Thang_new < 1) {
			Thang_new = 12;
			Nam_new--;
		}
		Ngay_new += KTThang(NgayThangNam(Nam_new, Thang_new, 1));
	}
	return NgayThangNam(Nam_new, Thang_new, Ngay_new);
}

//Operator NgayThangNam - NgayThangNam
int NgayThangNam::operator -(NgayThangNam a) {
	int Ngay_new = abs(TinhNgay() - a.TinhNgay());
	return Ngay_new;
}
2
//Toan tu ++
NgayThangNam& NgayThangNam::operator++() {
	iNgay++;
	if (iNgay > KTThang(*this)) {
		iNgay = 1;
		iThang++;
		if (iThang > 12) {
			iThang = 1;
			iNam++;
		}
	}
	return *this;
}
//Toan tu --, giam 1 ngay
NgayThangNam& NgayThangNam::operator--() {
	iNgay--;
	if (iNgay == 0) {
		iThang--;
		if (iThang == 0) {
			iThang = 12;
			iNam--;
		}
		iNgay = KTThang(*this);
	}
	return *this;
}

//so sanh ==
bool operator == (NgayThangNam n, NgayThangNam n2) {
	return ((n.iNam == n2.iNam) && (n.iThang == n2.iThang) && (n.iNgay == n2.iNgay));
}
//so sanh !=
bool operator != (NgayThangNam n, NgayThangNam n2) {
	return(!(n == n2));
}
//so sanh >=
bool operator >= (NgayThangNam n, NgayThangNam n2) {
	if (n.iNam < n2.iNam)return false;
	else if (n.iNam > n2.iNam)return true;
	else {//nam bang nhau
		if (n.iThang < n2.iThang)return false;
		else if (n.iThang > n2.iThang)return true;
		else {//thang bang
			if (n.iNgay < n2.iNgay)return false;
			else return true;//Ngay thu nhat >= ngay thu hai
		}
	}
}
//so sanh <=
bool operator <= (NgayThangNam n, NgayThangNam n2) {
	if (n.iNam > n2.iNam)return false;
	else if (n.iNam < n2.iNam)return true;
	else {//nam bang nhau
		if (n.iThang > n2.iThang)return false;
		else if (n.iThang < n2.iThang)return true;
		else {//thang bang
			if (n.iNgay > n.iNgay)return false;
			else return true;//Ngay thu nhat <= ngay thu hai
		}
	}
}
//so sanh >
bool operator > (NgayThangNam n, NgayThangNam n2) {
	return (!(n <= n2));
}
//so sanh <
bool operator < (NgayThangNam n, NgayThangNam n2) {
	return (!(n >= n2));
}