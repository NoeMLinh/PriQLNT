#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
struct Thuoc {
	string TenThuoc;
	int GiaBan;
	string MaSo;
	int soLuongThuoc;
};
void inDanhSachThuoc(Thuoc thuoc[], int n);
void timThuoc(Thuoc thuoc[], int n);
void printMenu(string path);
void xoaThuoc(Thuoc thuoc[], int &n);
void printMenuBanThuoc();
void xuatFileDS(Thuoc thuoc[], int n);
void themThuoc(Thuoc &thuoc);
void capNhatThuoc(Thuoc thuoc[], int n);
void xemThuoc(Thuoc thuoc[], int n);
void xemThuoc(Thuoc thuoc);
void banThuocNgoai(Thuoc thuoc[], int n);
void banThuocTheoDon(Thuoc thuoc[], int n);
void printMenuTimThuoc();
void timThuocTheoTen(Thuoc thuoc[], int n);
void menuThemThuoc();
void menuThoat();
void tachDauPhay(string s, Thuoc &thuoc);
void tachDauPhayBanThuoc(string s, Thuoc &thuoc);
