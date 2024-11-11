#include"ThoiGian.h"
#include<iostream>
using namespace std;

//Khoi tao constructor mac dinh
ThoiGian::ThoiGian() :iGio(0), iPhut(0), iGiay(0) {} 
//Khoi tao constructor co tham so
ThoiGian::ThoiGian(int Gio, int Phut, int Giay) {
	iGio = Gio;
	iPhut = Phut;
	iGiay = Giay;
}
// Nhap thoi gian lan luot: gio, phut, giay
// Kiem tra xem thoi gian co hop le hay khong (gio < 24, phut < 60, giay < 60)
istream& operator >> (istream& is, ThoiGian& tg) {
	cout << "Nhap lan luot gio, phut, giay: ";
	is >> tg.iGio;  // Nhap gio
	is >> tg.iPhut; // Nhap phut
	is >> tg.iGiay; // Nhap giay
	// Kiem tra dieu kien thoi gian hop le, neu khong thi yêu c?u nh?p l?i
	while ((tg.iGio < 0 || tg.iGio > 23) || (tg.iPhut < 0 || tg.iPhut > 59) || (tg.iGiay < 0 || tg.iGiay > 59)) {
		cout << "Thoi gian khong hop le! Nhap lai: ";
		is >> tg.iGio;
		is >> tg.iPhut;
		is >> tg.iGiay;
	}
	return is;
}

// Xuat thoi gian ra man hinh theo dinh dang: gio phut giay
ostream& operator << (ostream& os, ThoiGian tg) {
	os << tg.iGio << " gio ";      // Xuat gio
	os << tg.iPhut << " phut ";    // Xuat phut
	os << tg.iGiay << " giay ";    // Xuat giay
	return os;
}

// Tinh tong so giay tu thoi gian: (gio * 3600) + (phut * 60) + giay
int ThoiGian::TinhGiay() {
	return(iGio * 3600 + iPhut * 60 + iGiay); // Tinh so giay
}

// Tinh lai gio, phut, giay tu so giay cho truoc
ThoiGian ThoiGian::TinhLaiGio(int Giay) {
	int gio, phut, giay = Giay;
	gio = giay / 3600; // Tinh gio tu giay
	giay %= 3600;      // Giay con lai sau khi tru gio
	phut = giay / 60;  // Tinh phut tu giay con lai
	giay %= 60;        // Giay con lai sau khi tru phut
	return ThoiGian(gio, phut, giay);  // Tra ve ThoiGian moi
}

// Cong them giay vao thoi gian
ThoiGian ThoiGian::operator +(int Giay) {
	ThoiGian tgnew(iGio, iPhut, iGiay);  // Tao ThoiGian moi tu gia tri hien tai
	return tgnew.TinhLaiGio(tgnew.TinhGiay() + Giay);  // Tinh lai thoi gian sau khi cong them giay
}

// Tru giay ra khoi thoi gian
ThoiGian ThoiGian::operator -(int Giay) {
	ThoiGian tgnew(iGio, iPhut, iGiay);  // Tao ThoiGian moi tu gia tri hien tai
	return tgnew.TinhLaiGio(tgnew.TinhGiay() - Giay);  // Tinh lai thoi gian sau khi tru giay
}

// Cong hai thoi gian voi nhau
ThoiGian ThoiGian::operator +(ThoiGian a) {
	int gio = iGio + a.iGio;    // Cong gio cua hai thoi gian
	int phut = iPhut + a.iPhut; // Cong phut cua hai thoi gian
	int giay = iGiay + a.iGiay; // Cong giay cua hai thoi gian
	ThoiGian tgnew(gio, phut, giay);  // Tao thoi gian moi
	return tgnew.TinhLaiGio(tgnew.TinhGiay());  // Tinh lai thoi gian hop le
}

// Tru hai thoi gian
ThoiGian ThoiGian::operator -(ThoiGian a) {
	int gio = abs(iGio - a.iGio);    // Tru gio cua hai thoi gian (luon lay gia tri tuyet doi)
	int phut = abs(iPhut - a.iPhut); // Tru phut cua hai thoi gian (luon lay gia tri tuyet doi)
	int giay = abs(iGiay - a.iGiay); // Tru giay cua hai thoi gian (luon lay gia tri tuyet doi)
	ThoiGian tgnew(gio, phut, giay);  // Tao thoi gian moi
	return tgnew.TinhLaiGio(tgnew.TinhGiay());  // Tinh lai thoi gian hop le
}

// Tang thoi gian len 1 giay
ThoiGian& ThoiGian::operator++() {
	
	if (iGiay < 60) iGiay++; // Tang giay neu gia tri < 60
	else if (iGiay == 60) {
		iGiay = 0; // Reset giay ve 0
		if (iPhut < 60)iPhut++; // Tang phut neu gia tri < 60
		else {
			iPhut = 0;  // Reset phut ve 0
			iGio++;     // Tang gio
		}
	}
	*this=TinhLaiGio(TinhGiay());  // Tinh lai thoi gian hop le
	return *this;
}

// Giam thoi gian xuong 1 giay
ThoiGian& ThoiGian::operator--() {
	if (iGiay > 0) iGiay--;  // Giam giay neu gia tri > 0
	else if (iGiay == 0) {
		iGiay = 59; // Reset giay ve 59
		if (iPhut > 0) iPhut--; // Giam phut neu gia tri > 0
		else {
			iPhut = 59;  // Reset phut ve 59
			iGio--;      // Giam gio
		}
	}
	*this =TinhLaiGio(TinhGiay());  // Tinh lai thoi gian hop le
	return *this;
}

// So sanh hai thoi gian ==
// Tra ve true neu hai thoi gian giong nhau, false neu khong giong nhau
bool operator == (ThoiGian tg, ThoiGian tg2) {
	return (tg.iGio == tg2.iGio && tg.iPhut == tg2.iPhut && tg.iGiay == tg2.iGiay);
}

// So sanh hai thoi gian !=
// Tra ve true neu hai thoi gian khac nhau, false neu giong nhau
bool operator != (ThoiGian tg, ThoiGian tg2) {
	return (tg.iGio != tg2.iGio || tg.iPhut != tg2.iPhut || tg.iGiay != tg2.iGiay);
}

// So sanh hai thoi gian >=
// Tra ve true neu thoi gian tg >= tg2, false neu khong
bool operator >= (ThoiGian tg, ThoiGian tg2) {
	if (tg.iGio < tg2.iGio) return false;  // Neu gio cua tg < tg2, tra ve false
	else {
		if (tg.iGio > tg2.iGio) return true;  // Neu gio cua tg > tg2, tra ve true
		else {  // (tg.iGio == tg2.iGio)
			if (tg.iPhut > tg2.iPhut) return true;  // Neu phut cua tg > tg2, tra ve true
			else  // (tg.iPhut == tg2.iPhut)
				return (tg.iGiay >= tg2.iGiay);  // So sanh giay
		}
	}
}

// So sanh hai thoi gian <=
// Tra ve true neu thoi gian tg <= tg2, false neu khong
bool operator <= (ThoiGian tg, ThoiGian tg2) {
	if (tg.iGio > tg2.iGio) return false;  // Neu gio cua tg > tg2, tra ve false
	else {
		if (tg.iGio < tg2.iGio) return true;  // Neu gio cua tg < tg2, tra ve true
		else {  // (tg.iGio == tg2.iGio)
			if (tg.iPhut < tg2.iPhut) return true;  // Neu phut cua tg < tg2, tra ve true
			else  // (tg.iPhut == tg2.iPhut)
				return (tg.iGiay <= tg2.iGiay);  // So sanh giay
		}
	}
}

// So sanh hai thoi gian >
// Tra ve true neu thoi gian tg > tg2, false neu khong
bool operator > (ThoiGian tg, ThoiGian tg2) {
	return (!(tg <= tg2));  // Neu khong thoa man <=, thi tg > tg2
}

// So sanh hai thoi gian <
// Tra ve true neu thoi gian tg < tg2, false neu khong
bool operator < (ThoiGian tg, ThoiGian tg2) {
	return (!(tg >= tg2));  // Neu khong thoa man >=, thi tg < tg2
}
