#include "thuoc.h"
void printMenu(string path) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "            He thong quan ly nha thuoc            " << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "1. Them thuoc moi" << endl;
	cout << "2. Cap nhat thong tin thuoc" << endl;
	cout << "3. Xoa thuoc" << endl;
	cout << "4. Xem danh sach thuoc con lai trong kho" << endl;
	cout << "5. Ban thuoc" << endl;
	cout << "6. Xuat file danh sach thuoc" << endl;
	cout << "7. Tim thuoc" << endl;
	cout << "8. Thoat(thong tin da nhap se duoc luu o " << path << ")" << endl;
	cout << "--------------------------------------------------" << endl;
}
void printMenuBanThuoc() {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "\n\n\n            He thong quan ly nha thuoc            " << endl;
	cout << "\n\n\n--------------------------------------------------" << endl;
	cout << "\n\n\n1. Ban thuoc" << endl;
	cout << "\n\n\n2. Ban thuoc theo don" << endl;
	cout << "\n\n\n--------------------------------------------------" << endl;
}
void themThuoc(Thuoc &thuoc) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "Nhap ten thuoc: ";
	cin.ignore();
	getline(cin, thuoc.TenThuoc);
	cout << "Nhap ma so: ";
	cin >> thuoc.MaSo;
	cout << "Nhap gia ban: ";
	cin >> thuoc.GiaBan;
	cout << "Nhap so luong thuoc: ";
	cin >> thuoc.soLuongThuoc;
	cout << "--------------------------------------------------";
}
void capNhatThuoc(Thuoc thuoc[], int n) {
	cout << "--------------------------------------------------" << endl;
	cout << "Nhap ma so thuoc can cap nhat: ";
	string maSoCanCapNhat;
	cin >> maSoCanCapNhat;
	bool found = false;
	for (int i = 0; i < n; i++) {
		if (thuoc[i].MaSo.find(maSoCanCapNhat) != string::npos) {
			found = true;
			cout << "Nhap ten thuoc: ";
			cin.ignore();
			getline(cin, thuoc[i].TenThuoc);
			cout << "Nhap ma so: ";
			cin >> thuoc[i].MaSo;
			cout << "Nhap gia ban: ";
			cin >> thuoc[i].GiaBan;
		}
	}
	if (!found) {
		cout << "Khong tim thay thuoc co ma so " << maSoCanCapNhat << endl;
	}
	cout << "--------------------------------------------------";
	system("pause");	
}
void xemThuoc(Thuoc thuoc[], int n) {
	system("cls");
	for (int i = 0; i < n; i++) {
		cout << "--------------------------------------------------" << endl;
		cout << "Ten thuoc: " << thuoc[i].TenThuoc << endl;
		cout << "Ma so: " << thuoc[i].MaSo << endl;
		cout << "Gia ban: " << thuoc[i].GiaBan << endl;
		cout << "So luong thuoc: " << thuoc[i].soLuongThuoc << endl;
		cout << "--------------------------------------------------\n";
    }
	system("pause");
}
void xemThuoc(Thuoc thuoc) {
	cout << "--------------------------------------------------" << endl;
	cout << "Ten thuoc: " << thuoc.TenThuoc << endl;
	cout << "Ma so: " << thuoc.MaSo << endl;
	cout << "Gia ban: " << thuoc.GiaBan << endl;
	cout << "So luong thuoc: " << thuoc.soLuongThuoc << endl;
	cout << "--------------------------------------------------\n";
	system("pause");
}
void inDanhSachThuoc(Thuoc thuoc[], int n) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	if (n == 0) {
		cout << "Khong co thuoc nao trong kho!" << endl;
		cout << "--------------------------------------------------";
		system("pause");
		return;
	}
	for (int i = 0; i < n; i++) {
		cout << "Thuoc thu " << i + 1 << endl;
		xemThuoc(thuoc[i]);
	}
	cout << "--------------------------------------------------";
	system("pause");
}
void timThuoc(Thuoc thuoc[], int n) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	string maSoCanTim;
	cout << "Nhap ma so thuoc can tim: ";
	cin.ignore();
	getline(cin, maSoCanTim);
	bool timThay = false;
	for (int i = 0; i < n; i++) {
		if (thuoc[i].MaSo.find(maSoCanTim) != string::npos) {
			xemThuoc(thuoc[i]);
			timThay = true;
		}
	}
	if (!timThay) {
		cout << "Khong tim thay thuoc co ma so " << maSoCanTim << endl;
		cout << "--------------------------------------------------";
	}
	system("pause");
}
void xoaThuoc(Thuoc thuoc[], int &soLuongThuoc) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "Nhap ma so thuoc can xoa: ";
	string maSoCanXoa;
	cin.ignore();
	getline(cin, maSoCanXoa);
	for (int i = 0; i < soLuongThuoc; i++) {
		if (thuoc[i].MaSo == maSoCanXoa) {
			for (int j = i; j < soLuongThuoc - 1; j++) {
				thuoc[j] = thuoc[j + 1];
			}
			--soLuongThuoc;
			cout << "Xoa thanh cong!" << endl;
			system("pause");
			return;
		}
	}
	cout << "Khong tim thay thuoc co ma so " << maSoCanXoa << endl;
	cout << "--------------------------------------------------";
	system("pause");
}
void banThuocNgoai(Thuoc thuoc[], int n) {
	cout << "--------------------------------------------------" << endl;
	int x = 0;
	char a = 'y';
	Thuoc banThanhCong[100];
	do {
		cout << "Nhap ten thuoc can ban: ";
		string tenThuocCanBan;
		cin.ignore();
		getline(cin, tenThuocCanBan);
		for (int i = 0; i < n; i++) {
			if (thuoc[i].TenThuoc == tenThuocCanBan) {
				cout << "Nhap so luong thuoc can ban: ";
				int soLuongCanBan;
				cin >> soLuongCanBan;
				if (soLuongCanBan > thuoc[i].soLuongThuoc) {
					cout << "So luong thuoc trong kho khong du de ban!" << endl;
				}
				else {
					thuoc[i].soLuongThuoc -= soLuongCanBan;
					int giaBan = thuoc[i].GiaBan * soLuongCanBan;
					cout << "Tong tien: " << giaBan << endl;
					banThanhCong[x].TenThuoc = thuoc[i].TenThuoc;
					banThanhCong[x].GiaBan = giaBan;
					x++;
				}
			}
		}
		cout << "Ban co muon mua them thuoc khong? (y/n): ";
		cin >> a;
	} while (a == 'y');
	cout << "Ban co muon xuat file hoa don khong? (y/n): ";
	char c;
	cin >> c;
	if (c == 'y') {
		ofstream file;
		string path = "C:\\Users\\admin\\Documents\\HoaDonBanThuoc.xls";
		file.open("C:\\Users\\admin\\Documents\\HoaDonBanThuoc.xls");
		file << "Hoa don ban thuoc" << endl;
		file << "Ten thuoc\tGia ban" << endl;
		for (int i = 0; i < x; i++) {
			file << banThanhCong[i].TenThuoc << "\t" << banThanhCong[i].GiaBan << endl;
		}
		cout << "Xuat file thanh cong!" << endl;
		cout << "File duoc luu tai: " << path << endl;
		file.close();
	}
	cout << "--------------------------------------------------\n";
	system("pause");
}
void banThuocTheoDon(Thuoc thuoc[], int n) {
	system("cls");
	string path;
	cout << "--------------------------------------------------" << endl;
	cout << "Nhap duong dan den file don thuoc(bo dau ngoac kep hai dau duong dan): ";
	cin >> path;
	ifstream file;
	file.open(path);
	int soThuocCanMua;
	file >> soThuocCanMua;
	Thuoc *muaThuoc = new Thuoc[soThuocCanMua];
	string *line = new string[soThuocCanMua];
	int x = 0;
	Thuoc banThanhCong[100];
	for (int i = 0; i < soThuocCanMua; i++) {
		file >> line[i];
		tachDauPhayBanThuoc(line[i], muaThuoc[i]);
	}
	for (int a = 0; a < soThuocCanMua; a++) {
		bool timThay = false;
		for (int b = 0; b < n; b++) {
			if (muaThuoc[a].TenThuoc == thuoc[b].TenThuoc) {
				timThay = true;
				if (muaThuoc[a].soLuongThuoc > thuoc[b].soLuongThuoc) {
					cout << "So luong thuoc " << muaThuoc[a].TenThuoc << " trong kho khong du de ban!" << endl;
				}
				else {
					thuoc[b].soLuongThuoc -= muaThuoc[a].soLuongThuoc;
					int giaBan = muaThuoc[a].soLuongThuoc * thuoc[b].GiaBan;
					cout << "Ten thuoc: " << muaThuoc[a].TenThuoc << endl;
					cout << "Tong tien: " << giaBan << endl;
					banThanhCong[x] = muaThuoc[a];
					x++;
					continue;
				}
			} else {
				timThay = false;
			}
		}
		if (!timThay) {
			cout << "Khong tim thay thuoc " << muaThuoc[a].TenThuoc << " trong kho!" << endl;
		}
	}
	cout << "--------------------------------------------------" << endl;
	cout << "Ban co muon xuat file hoa don khong? (y/n): ";
	char c;
	cin >> c;
	if (c == 'y') {
		ofstream file;
		string path = "C:\\Users\\admin\\Documents\\HoaDonBanThuoc.xls";
		file.open("C:\\Users\\admin\\Documents\\HoaDonBanThuoc.xls");
		file << "Hoa don ban thuoc" << endl;
		file << "Ten thuoc\tSo luong\tGia ban" << endl;
		for (int i = 0; i < x; i++) {
			file << muaThuoc[i].TenThuoc << "\t" << muaThuoc[i].soLuongThuoc << "\t" << muaThuoc[i].soLuongThuoc * thuoc[i].GiaBan << endl;
		}
		cout << "Xuat file thanh cong!" << endl;
		cout << "File duoc luu tai: " << path << endl;
		cout << "--------------------------------------------------\n" << endl;
		file.close();
	}
	file.close();
	delete [] muaThuoc;
	delete [] line;
	system("pause");
}
void xuatFileDS(Thuoc thuoc[], int n) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	ofstream file;
	string path = "C:\\Users\\admin\\Documents\\DanhSachThuoc.xls";
	file.open("C:\\Users\\admin\\Documents\\DanhSachThuoc.xls");
	file << "Danh sach thuoc trong kho" << endl;
	file << "Ten thuoc\tMa so\tGia ban\tSo luong" << endl;
	for (int i = 0; i < n; i++) {
		file << thuoc[i].TenThuoc << "\t*" << thuoc[i].MaSo << "\t" << thuoc[i].GiaBan << "\t" << thuoc[i].soLuongThuoc << endl;
	}
	cout << "Xuat file thanh cong!" << endl;
	cout << "File duoc luu tai: " << path << endl;
	cout << "--------------------------------------------------" << endl;
	file.close();
	system("pause");
}
void printMenuTimThuoc() {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "\n\n1. Tim thuoc theo ten" << endl;
	cout << "\n\n2. Tim thuoc theo ma so" << endl;
	cout << "--------------------------------------------------" << endl;
}
void timThuocTheoTen(Thuoc thuoc[], int n) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	string tenThuocCanTim;
	cout << "Nhap ten thuoc can tim: ";
	cin.ignore();
	getline(cin, tenThuocCanTim);
	for (int i = 0; i < n; i++) {
		if (thuoc[i].TenThuoc.find(tenThuocCanTim) != string::npos) {
			xemThuoc(thuoc[i]);
		}
	}
    cout << "--------------------------------------------------";
	system("pause");
}
void menuThemThuoc() {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "1. Them thuoc tu ban phim" << endl;
	cout << "2. Them thuoc tu file" << endl;
	cout << "--------------------------------------------------" << endl;
}
void menuThoat() {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "1. Luu va thoat" << endl;
	cout << "2. Thoat" << endl;
	cout << "--------------------------------------------------" << endl;
}
void tachDauPhay(string s, Thuoc &thuoc) {
	char arr[100];
	string arr2[4];
	int x = s.length();
	for (int i = 0; i < x; i++) {
		arr[i] = s[i];
	}
	int a = 0;
	for (int i = 0; i < x; i++) {
		if (arr[i] == ',') {
			a++;
			continue;
		}
		arr2[a] += arr[i];
	}
	thuoc.TenThuoc = arr2[0];
	thuoc.MaSo = arr2[1];
	thuoc.GiaBan = stoi(arr2[2]);
	thuoc.soLuongThuoc = stoi(arr2[3]);
}
void tachDauPhayBanThuoc(string s, Thuoc &thuoc) {
	char arr[100];
	string arr2[2];
	int x = s.length();
	for (int i = 0; i < x; i++) {
		arr[i] = s[i];
	}
	int a = 0;
	for (int i = 0; i < x; i++) {
		if (arr[i] == ',') {
			a++;
			continue;
		}
		arr2[a] += arr[i];
	}
	thuoc.TenThuoc = arr2[0];
	thuoc.soLuongThuoc = stoi(arr2[1]);
}
