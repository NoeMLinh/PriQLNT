#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
#include "thuoc.h"
using namespace std;

int main() {
	Thuoc thuoc[100];
	int n = 0;
	string path = "C:\\Users\\admin\\Documents\\database.txt";
	int choice;
	do {
		printMenu(path);
		cout << "Nhap lua chon cua ban: ";
		cin >> choice;
		switch (choice) {
		case 1:
			menuThemThuoc();
			int choice1;
			cout << "Nhap lua chon cua ban: ";
			cin >> choice1;
			switch (choice1) {
			case 1:
			{
				char c;
				do {
					themThuoc(thuoc[n]);
					n++;
					cout << "\nBan co muon nhap them thuoc khong? (y/n): ";
					cin >> c;
				} while (c == 'y');
				break;
			}
			case 2:
			{
				system("cls");
				string path1;
				cout << "File don thuoc co dinh dang nhu sau: " << endl;
				cout << "(So loai thuoc can nhap kho)" << endl << "(Ten thuoc),(Ma so),(Gia ban),(So luong)" << endl;
				cout << "Vi du: " << endl;
				cout << "3" << endl;
				cout << "Thuoc1,MS1,10000,10" << endl;
				cout << "Thuoc2,MS2,20000,20" << endl;
				cout << "Thuoc3,MS3,30000,30" << endl;
				cout << "Nhap duong dan file(bo dau ngoac kep hai dau duong dan): ";
				cin >> path1;
				ifstream file;
				file.open(path1);
				int x;
				file >> x;
				string lineThuoc;
				for (int i = 0; i < x; i++) {
					file >> lineThuoc;
					tachDauPhay(lineThuoc, thuoc[n+i]);
				}
				n += x;
				file.close();
				cout << "Nhap thanh cong!" << endl;
				break;
			}
			default:
				cout << "Lua chon khong hop le." << endl;
				break;
			}
			system("pause");
			break;
		case 2:
			xemThuoc(thuoc, n);
			capNhatThuoc(thuoc, n);
			break;
		case 3:
			xoaThuoc(thuoc, n);
			break;
		case 4:
			xemThuoc(thuoc, n);
			break;
		case 5:
			printMenuBanThuoc();
			int choiceBanThuoc;
			cout << "Nhap lua chon cua ban: ";
			cin >> choiceBanThuoc;
			switch (choiceBanThuoc) {
			case 1:
				xemThuoc(thuoc, n);
				banThuocNgoai(thuoc, n);
				break;
			case 2:
				banThuocTheoDon(thuoc, n);
				break;
			default:
				cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
			}
			break;
		case 6:
			xuatFileDS(thuoc, n);
			break;
		case 7:
			int choiceTim;
			printMenuTimThuoc();
			cout << "\nNhap lua chon cua ban: ";
			cin >> choiceTim;
			switch (choiceTim) {
			case 1:
				timThuocTheoTen(thuoc, n);
				break;
			case 2:
				timThuoc(thuoc, n);
				break;
			default:
				cout << "\nLua chon khong hop le." << endl;
			}
			break;
		case 8:
		{
			system("cls");
			cout << "--------------------------------------------------" << endl;
			ofstream file;
			file.open("C:\\Users\\admin\\Documents\\DanhSachThuoc.txt");
			file << n << endl;
			for (int i = 0; i < n; i++) {
				file << thuoc[i].TenThuoc << "," << thuoc[i].MaSo << "," << thuoc[i].GiaBan << "," << thuoc[i].soLuongThuoc << endl;
			}
			file.close();
			exit(0);
			break;
		}
		default:
			cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
			system("pause");
			printMenu(path);
			cout << "Nhap lua chon cua ban: ";
			cin >> choice;
			break;
		}
	} while (choice != 9);
	return 0;
}
