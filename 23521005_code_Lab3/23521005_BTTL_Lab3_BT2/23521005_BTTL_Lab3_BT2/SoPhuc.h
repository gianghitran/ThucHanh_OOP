#pragma once
#include<iostream>
using namespace std;
class SoPhuc {
private:
	double dThuc;
	double dAo;
public:
	SoPhuc();//Khoi tao constructor mac dinh
	SoPhuc(double thuc, double ao);//Khoi tao constructor truyen tham so
	friend SoPhuc operator +(SoPhuc z, SoPhuc z2); //Cong hai so phuc 
	friend SoPhuc operator - (SoPhuc z, SoPhuc z2); //Tru hai so phuc
	friend SoPhuc operator * (SoPhuc z, SoPhuc z2); //Nhan hai so phuc
	friend SoPhuc operator / (SoPhuc z, SoPhuc z2); //Chia hai so phuc

	friend bool operator == (SoPhuc z, SoPhuc z2); //So sanh bang
	friend bool operator != (SoPhuc z, SoPhuc z2); //so sanh khac
	friend istream& operator >> (istream& is, SoPhuc& z); //Nhap
	friend ostream& operator << (ostream& os, SoPhuc z); //Xuat

	SoPhuc(double thuc);// Constructor chuyen doi so thuc thanh so phuc
};