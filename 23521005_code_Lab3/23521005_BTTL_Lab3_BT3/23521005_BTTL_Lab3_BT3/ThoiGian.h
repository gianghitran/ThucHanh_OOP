#pragma once
#include<iostream>
using namespace std;
class ThoiGian {
private:
	int iGio;
	int iPhut;
	int iGiay;
public:
	ThoiGian();//Khoi tao constructor mac dinh
	ThoiGian(int Gio, int Phut, int Giay);//Khoi tao constructor co tham so
	int TinhGiay();
	ThoiGian TinhLaiGio(int Giay);
	ThoiGian operator +(int Giay);
	ThoiGian operator -(int Giay);
	ThoiGian operator +(ThoiGian a);
	ThoiGian operator -(ThoiGian a);

	ThoiGian& operator++();       
	ThoiGian& operator--();

	friend bool operator == (ThoiGian tg,ThoiGian tg2);
	friend bool operator != (ThoiGian tg, ThoiGian tg2);
	friend bool operator >= (ThoiGian tg, ThoiGian tg2);
	friend bool operator <= (ThoiGian tg, ThoiGian tg2);
	friend bool operator > (ThoiGian tg, ThoiGian tg2);
	friend bool operator < (ThoiGian tg, ThoiGian tg2);
	
	friend istream& operator >> (istream& is, ThoiGian& tg);
	friend ostream& operator << (ostream& os, ThoiGian tg);
};