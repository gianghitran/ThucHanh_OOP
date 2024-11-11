// 23521005_BTTL_Lab3_BT1.cpp 
#include "PhanSo.h"
#include <iostream>
int main()
{
	PhanSo cons;//Khoi tao constructor mac dinh
	PhanSo cons_para(1,1);//Khoi tao constructor co tham so
	cout << "Nhap phan so thu nhat: ";
	PhanSo ps;
	cin >> ps;
	cout << "Nhap phan so thu hai: ";
	PhanSo ps2;
	cin >> ps2;
	//Cong hai phan so
	cout << "Cong hai phan so: ";
	cout << (ps + ps2);
	cout << endl;

	//Cong phan so voi so thuc
	cout << "Cong phan so thu nhat voi so thuc "<<ps <<" + 2.5 = ";
	cout << (ps + 2.5);
	cout << endl;

	//Tru hai phan so
	cout << "Tru hai phan so: ";
	cout << ps - ps2;
	cout << endl;
	//Tru phan so voi so thuc
	cout << "Tru phan so thu nhat voi so thuc " << ps << " - 3.5 = ";
	cout << (ps - 3.5);
	cout << endl;


	//Nhan hai phan so
	cout << "Nhan hai phan so: ";
	cout << ps * ps2;
	cout << endl;
	//Nhan phan so voi so thuc
	cout << "Nhan phan so thu nhat voi so thuc " << ps << " x 2.0 = ";
	cout << (ps * 2.0);
	cout << endl;


	//Chia hai phan so
	cout << "Chia hai phan so: ";
	cout << ps / ps2;
	cout << endl;
	//Chia phan so voi so thuc
	cout << "Chia phan so thu nhat voi so thuc " << ps << " / 2.0 = ";
	cout << (ps / 2.0);
	cout << endl;


	//so sanh ==
	if (ps == ps2) cout << "Hai phan so bang nhau.";
	else cout<< "Hai phan so khong bang nhau.";
	cout << endl;
	//so sanh !=
	if (ps != ps2) cout << "Hai phan so khong bang nhau.";
	else cout << "Hai phan so bang nhau.";
	cout << endl;
	//so sanh >=
	if (ps >= ps2) cout << "Phan so thu nhat lon hon hoac bang phan so thu hai";
	else cout << "Phan so thu nhat khong lon hon hoac bang phan so thu hai";
	cout << endl;
	//so sanh <=
	if (ps <= ps2) cout << "Phan so thu nhat be hon hoac bang phan so thu hai";
	else cout <<  "Phan so thu nhat khong be hon hoac bang phan so thu hai";
	cout << endl;
	//so sanh >
	if (ps > ps2) cout << "Phan so thu nhat lon hon phan so thu hai";
	else cout <<  "Phan so thu nhat khong lon hon phan so thu hai";
	cout << endl;
	//so sanh <
	if (ps < ps2) cout << "Phan so thu nhat be hon phan so thu hai";
	else cout << "Phan so thu nhat khong be hon phan so thu hai";
	cout << endl;

	return 0;
}

