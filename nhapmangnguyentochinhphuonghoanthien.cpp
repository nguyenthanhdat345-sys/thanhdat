#include <stdio.h>
#include <stdbool.h>
#include <math.h>
# define MAX 100
void nhapm(int a[], int& n);
void xuatm(const int a[], int n);
long long ngto(const int a[], int n);
bool ktnt(int x);
long long hthien(const int a[], int n);
bool ktht(int x);
int demsoht(int a[], int n);
long long tongcp(const int a[], int n);
bool ktcp(int x);
void main()
{
	int a[MAX], n;
	nhapm(a, n);
	printf_s("\nmang vua nhap la: ");
	xuatm(a, n);
	long long tongngto = ngto(a, n);
	printf_s("\ntong so nguyen to la: %lld ", tongngto);
	long long tonghthien = hthien(a, n);
	printf_s("\ntong so hoan thien la: %lld", tonghthien);
	long long tcp = tongcp(a, n);
	printf_s("\ntong cac so chinh phuong: %lld", tcp);
	int dem=demsoht(a,n);
	printf_s("\ncac so hoan thien: %d", dem);

}
//viet cac ham
void nhapm(int a[], int& n)
{
	//nhap so phan tu thc su co trong mang
	do
	{
		printf_s("nhap so phan tu cua mang n>0: ");
		scanf_s("%d", &n);
		if (n <= 0 || n >= 100)
			printf_s("\n nhap sai nhap lai n>=1 va <=%d\n", MAX);
	} while (n <= 0 || n >= 100);
	//nhap du lieu cho tung phan tu mang
	for (int i = 0; i < n; i++)
	{
		printf_s("a[%d]= ", i);
		scanf_s("%d", &a[i]);
	}
}
void xuatm(const int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf_s("%6d", a[i]);
}
long long tongm(const int a[], int n)
{
	long long s = 0;
	for (int i = 0; i < n; i++)
		s = s + a[i];
	return s;
}
//kiem tra nguyen to
bool ktnt(int x)
{
	if (x <2) return false;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)return false;
	return true;
}
//tong so nguyen to 
long long ngto(const int a[], int n)
{
	long long s=0;
	for (int i = 0; i < n; i++)
		if (ktnt(a[i]))
			s = s + a[i];
	return s;
}
//kiem tra hoan thien
bool ktht(int x)
{
	if (x < 2)return false;
	int s = 0;
	for (int i = 1; i <= x / 2; i++)
		if (x % i == 0)
			s = s + i;
	return s == x;
}
//tonghoan thien
long long hthien(const int a[], int n)
{
	long long s = 0;
	for (int i = 0; i < n; i++)
		if (ktht(a[i]))
			s += a[i];
	return s;
}
//kiem tra cp
bool ktcp(int x)
{
	int t = sqrt(x);
	if (t * t == x)
		return 1;
	return 0;
}
//tong chinh phuong
long long tongcp(const int a[], int n)
{
	long long s = 0;
	for (int i = 0; i < n; i++)
		if (ktcp(a[i]))
			s = s + a[i];
	return s;
}

int demsoht(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (ktht(a[i]))
			dem++;
	return dem;
}