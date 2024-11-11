#pragma once
#include<iostream>
using namespace std;
class NgayThangNam {
private:
	int iNgay;//ngay
	int iThang;//thang
	int iNam;//nam
public:
	NgayThangNam();//Khoi tao constructor mac dinh
	NgayThangNam(int Nam, int Thang, int Ngay);//Khoi tao constructor co tham so
	int KTThang(NgayThangNam n);//Kiem tra thang co may ngay
	int TinhNgay();
	NgayThangNam operator +(int Ngay); //Cong them ngay
	NgayThangNam operator -(int Ngay); //Tru ngay
	int operator -(NgayThangNam a);//Tinh khoang cach giua 2 ngay 

	NgayThangNam& operator++(); //ngay ++
	NgayThangNam& operator--(); //ngay --
	
	//Cac toan tu so sanh 
	friend bool operator == (NgayThangNam n, NgayThangNam n2);
	friend bool operator != (NgayThangNam n, NgayThangNam n2);
	friend bool operator >= (NgayThangNam n, NgayThangNam n2);
	friend bool operator <= (NgayThangNam n, NgayThangNam n2);
	friend bool operator > (NgayThangNam n, NgayThangNam n2);
	friend bool operator < (NgayThangNam n, NgayThangNam n2);
	
	//Cac toan tu nhap xuat
	friend istream& operator >> (istream& is, NgayThangNam& n);
	friend ostream& operator << (ostream& os, NgayThangNam n);
};