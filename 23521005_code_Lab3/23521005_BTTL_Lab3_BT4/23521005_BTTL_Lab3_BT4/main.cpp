// 23521005_BTTL_Lab3_BT4
#include "NgayThangNam.h"
#include <iostream>

int main()
{
	NgayThangNam nn_cons;//constructor mac dinh
	NgayThangNam nn_para(1, 1, 1);//constructor co tham so
	NgayThangNam nn;
	cout << "Nhap ngay thu nhat: ";
	cin >> nn; //Nhap ngay thang nam 
	cout << "Ngay/Thang/Nam da nhap: " << nn<<endl;

	cout << "Tong so ngay: " << nn.TinhNgay()<<endl;
	//Phuong thuc +(int Ngay)
	cout << "Tang thoi gian len n ngay: " <<endl;
	cout << "Nhap n: ";
	int n; cin >> n; //Nhap so ngay muon tang 
	cout << "Thoi gian sau khi tang len " << n << " ngay: " << nn + n<<endl;
	//Phuong thuc -(int Ngay)
	cout << "Giam thoi gian xuong m ngay: " << endl;
	cout << "Nhap m: ";
	int m; cin >> m; //Nhap so ngay muon giam
	cout << "Thoi gian sau khi giam " << m << " ngay: " << nn -m << endl;

	cout << "Thoi gian ++ : " << ++nn<<endl;
	cout << "Thoi gian -- : " << --nn << endl;

	cout << "Nhap thoi gian muon tinh khoang cach: ";
	NgayThangNam nn3; cin >> nn3;
	//phep -. Tinh khoang cach giua hai ngay 
	cout << "Khoang cach giua hai ngay: " << nn - nn3 <<" ngay" << endl;

	//Nhap ngay thu hai
	cout << "Nhap ngay thu hai: ";
	NgayThangNam ngay2; cin >> ngay2;
	//cac operator so sanh
	if(nn==ngay2)cout << nn << " == " << ngay2<<endl;
	if (nn != ngay2)cout << nn << " != " << ngay2 << endl;
	if (nn >= ngay2)cout << nn << " >= " << ngay2 << endl;
	if (nn <= ngay2)cout << nn << " <= " << ngay2 << endl;
	if (nn > ngay2)cout << nn << " > " << ngay2 << endl;
	if (nn < ngay2)cout << nn << " < " << ngay2 << endl;

	return 0;
}
