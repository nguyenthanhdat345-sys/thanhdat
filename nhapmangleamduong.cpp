#include <stdio.h>
# define MAX 100
void nhapm(int a[], int& n);
void xuatm(const int a[], int n);
long long tongm(const int a[], int n);
long long tongc(const int a[], int n);
long long tongl(const int a[], int n);
long long tongam(const int a[], int n);
long long tongduong(const int a[], int n);
void xoavitri(int a[], int& n, int k);
void xoadau(int a[], int* n);
//HAM CHINH
void main()
{
	int a[MAX], n,k;
	nhapm(a, n);
	printf_s("\nmang vua nhap la: ");
	xuatm(a, n);
	long long t = tongm(a, n);
	printf_s("\ntong cac phan tu co trong mang la: %lld\n", t);
	long long tc = tongc(a, n);
	printf_s("\ntong cac phan tu chan co trong mang la: %lld\n", tc);
	long long tl = tongl(a, n);
	printf_s("\ntong cac phan tu le co trong mang la: %lld\n", tl);
	long long am = tongam(a, n);
	printf_s("\ntong cac phan tu am co trong mang la: %lld\n", am);
	long long duong = tongduong(a, n);
	printf_s("\ntong cac phan tu duong co trong mang la: %lld\n", duong);
	//hamxoa
	printf_s("nhap vi tri muon xoa: ");
	scanf_s("%d", &k);
	xoavitri(a, n, k);
	printf_s("sau khi xoa p tu dau:");
	xoadau(a, &n);
	xuatm(a, n);

}
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
//tong chan
long long tongc(const int a[], int n)
{

	long long s = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0)
			s = s + a[i];
	return s;
}
//tong le
long long tongl(const int a[], int n)
{
	long long s = 0;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 != 0)
			s = s + a[i];
	return s;
}
//tong am
long long tongam(const int a[], int n)
{
	long long s = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < 0)
			s = s + a[i];
	return s;
}
//tong duoong
long long tongduong(const int a[], int n)
{
	long long s = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			s = s + a[i];
	return s;
}
//xoavtribatki
void xoavitri(int a[], int& n, int k) {
	if ((k < 0) || (k > n - 1)) {
		printf_s("\n vi tri can xoa khong hop le!");
		return;
	}
	for (int i = k;i < n - 1;i++){
		a[i] = a[i + 1];
	}
	n--;
	printf_s("Mang sau khi xoa phan tu tai vi tri %d:\n", k);
	for (int i = 0; i < n; i++) {
		printf_s("%6d", a[i]);
	}
	printf_s("\n");
	}
//xoadau
void xoadau(int a[], int* n)
{
	if (*n <= 0) return;
	for (int i = 0;i < *n - 1;i++)
		a[i] = a[i + 1];
	(*n)--;
}


