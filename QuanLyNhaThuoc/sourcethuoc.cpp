#include "thuoc.h"
#define SPT(x) (sizeof(x) / sizeof(x[0]))
void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void printMenu() {
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
	cout << "8. Thoat" << endl;
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
			soLuongThuoc--;
			cout << "Xoa thanh cong!" << endl;
			return;
		}
	}
	cout << "Khong tim thay thuoc co ma so " << maSoCanXoa << endl;
	cout << "--------------------------------------------------";
	system("pause");
}
void banThuocNgoai(Thuoc thuoc[], int n) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "Nhap ten thuoc can ban: ";
	string tenThuocCanBan;
	cin.ignore();
	getline(cin, tenThuocCanBan);
	for (int i =  0; i < n; i++) {
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
			}
		}
	}
	cout << "--------------------------------------------------";
	system("pause");
}
void banThuocTheoDon(Thuoc thuoc[], int n) {
	system("cls");
	string path;
	cout << "--------------------------------------------------" << endl;
	cout << "Nhap duong dan den file don thuoc: ";
	cin.ignore();
	getline(cin, path);
	ifstream file;
	file.open(path);
	int soThuocCanMua;
	file >> soThuocCanMua;
	cout << soThuocCanMua;
	for (int i = 0; i < soThuocCanMua; i++) {
		file >> thuoc[i].TenThuoc;
		for (int j = 0; j < n; j++) {
			if (thuoc[j].TenThuoc == thuoc[i].TenThuoc) {
				file >> thuoc[i].soLuongThuoc;
				if (thuoc[j].soLuongThuoc < thuoc[i].soLuongThuoc) {
					cout << "So luong thuoc " << thuoc[j].TenThuoc << " khong du de ban!" << endl;
				}
				else {
					thuoc[j].soLuongThuoc -= thuoc[i].soLuongThuoc;
					cout << "Ban thuoc " << thuoc[j].TenThuoc << " thanh cong!" << endl;
					int giaBan = thuoc[j].GiaBan * thuoc[i].soLuongThuoc;
					cout << "Tong tien: " << giaBan << endl;
				}
			}
		}
	}
	file.close();
	system("pause");
}
void xuatFileDS(Thuoc thuoc[], int n) {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	ofstream file;
	file.open("DanhSachThuoc.txt");
	file << "Danh sach thuoc trong kho" << endl;
	file << "--------------------------------------------------" << endl;
	file << "Ten thuoc\t\tMa so\t\tGia ban\t\tSo luong" << endl;
	file << "--------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		file << thuoc[i].TenThuoc << "\t\t" << thuoc[i].MaSo << "\t\t" << thuoc[i].GiaBan << "\t\t" << thuoc[i].soLuongThuoc << endl;
	}
	file << "--------------------------------------------------" << endl;
	cout << "Xuat file thanh cong!" << endl;
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
Thuoc tachPhanTuTuFile(string path) {
	string s;
	ifstream file;
	file.open(path);
	int soThuocCanMua;
	file >> soThuocCanMua;
	Thuoc result; 
	vector<string> tokens; 
	tokens = tachChuoiBangDauPhay(s);
	if (tokens.size() > 5 || tokens.size() < 2) {
		cout << "Loi: So luong phan tu sai!" << endl;
		return result; 
	}
	result.TenThuoc = tokens[0];
	result.MaSo = tokens[1];
	stringstream ss1(tokens[2]);
	ss1 >> result.GiaBan;

	stringstream ss2(tokens[3]);
	ss2 >> result.soLuongThuoc;

	// Kiểm tra lỗi chuyển đổi
	if (ss1.fail() || ss2.fail()) {
		cout << "Lỗi: Dữ liệu không hợp lệ!" << endl;
		return result;
	}

	return result;
}
vector<string> tachChuoiBangDauPhay(string s) {
	vector<string> tokens; 
	string token;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ',') { 
			if (!token.empty()) { 
				tokens.push_back(token);
				token.clear(); 
			}
		}
		else {
			token += s[i];
		}
	}

	if (!token.empty()) { 
		tokens.push_back(token);
	}

	return tokens;
}
void menuThemThuoc() {
	system("cls");
	cout << "--------------------------------------------------" << endl;
	cout << "1. Them thuoc tu ban phim" << endl;
	cout << "2. Them thuoc tu file" << endl;
	cout << "--------------------------------------------------" << endl;
}
