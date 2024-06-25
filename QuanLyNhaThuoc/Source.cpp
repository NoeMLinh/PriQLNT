#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <math.h>
#include "thuoc.h"
using namespace std;

int main() {
	Thuoc thuoc[100];
	int n = 0;
	int choice;
	do {
		printMenu();;
		cout << "Nhap lua chon cua ban: ";
		cin >> choice;
		switch (choice) {
		case 1:
			menuThemThuoc();
			char banChoice;
			switch (banChoice) {
			case 1: {
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
				string path;
				cout << "Nhap duong dan file: ";
				cin.ignore();
				getline(cin, path);
				tachPhanTuTuFile(path);
				break;
				}
			default:
				cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
				break;
			}
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
			break;
		default:
			cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
			break;
		}
	} while (choice != 8);
	return 0;
}