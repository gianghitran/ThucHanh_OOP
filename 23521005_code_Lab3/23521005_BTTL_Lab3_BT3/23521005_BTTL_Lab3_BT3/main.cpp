// 23521005_BTTL_Lab3_BT3.cpp
#include "ThoiGian.h"
#include <iostream>

int main()
{
	ThoiGian tg_cons;//Khoi tao constructor mac dinh
	ThoiGian tg_para(1, 1, 1);//Khoi tao constructor co tham so
	cout << "Nhap thoi gian thu nhat: ";
	ThoiGian tg;  cin >> tg;
	cout << "Thoi gian thu nhat: " << tg<<endl;//Nhap thoi gian thu nhat
	cout << "Thoi gian tinh theo giay: " << tg.TinhGiay()<<" giay " << endl;//Tinh tong so giay
	
	cout << "Tang thoi gian them n giay: ";
	cout << "Nhap n: ";
	int n; cin >> n;//Nhap so giay muon cong vao 
	cout << "Thoi gian sau khi tang them " << n << " giay: " << tg+n<<endl;

	cout << "Giam thoi gian m giay: ";
	cout << "Nhap m: ";
	int m; cin >> m;//Nhap so giay muon tru
	cout << "Thoi gian sau khi giam " << m << " giay: " << tg - m << endl;

	
	cout << "Nhap thoi gian thu hai: "; //Nhap thoi gian thu hai 
	ThoiGian tg2;	cin >> tg2;
	cout << "Thoi gian thu hai: " << tg2<<endl;

	cout << "Cong hai thoi gian: ";
	cout << tg + tg2 << endl;//Phep cong

	cout << "Tru hai thoi gian: ";
	cout << tg - tg2 << endl;//Phep tru

	cout <<"Thoi gian thu nhat ++ = ";
	cout << ++tg<<endl; //Toan tu ++ voi doi tuong thu nhat

	cout << "Thoi gian thu hai -- = ";
	cout << --tg2 << endl;// Toan tu -- voi doi tuong thu hai

	//Thuc hien cac operators so sanh: ==,!=,>=,<=,>,<
	if (tg == tg2)cout << tg<<"== "<<tg2<<endl;
	if (tg != tg2)cout << tg << "!= " << tg2 << endl;
	if (tg >= tg2)cout << tg << ">= " << tg2 << endl;
	if (tg <= tg2)cout << tg << "<= " << tg2 << endl;
	if (tg > tg2)cout << tg << "> " << tg2 << endl;
	if (tg < tg2)cout << tg << "< " << tg2 << endl;

	return 0;
}
