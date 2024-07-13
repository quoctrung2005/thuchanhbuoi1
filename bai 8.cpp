#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
struct phanso {
	int mau;
	int tu;
};
typedef struct phanso phanso;
//ham nhap phan so
void nhapphanso(phanso* ps) {
	printf("nhap tu so");
	scanf_s ("%d", &ps->tu);
	do
	{
		printf("nhap mau so khac 0");
		scanf_s ("%d", &ps->mau);
		if (ps->mau == 0) {
			printf("nhap mau khac khong");
		}

	} while (ps->mau == 0);
}
// ham xuat phan so
void xuat(const phanso* ps) {
	printf("%d / %d\n", ps->tu, ps->mau);

}
// ham nhap mang phan so 
void nhapmang(phanso* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("nhap phan so thu %d", i + 1);
		nhapphanso(&arr[i]);
	}
} // Ham xuat mang phan so
void xuatmang(const phanso * arr, int n) {
	for (int i = 0; i < n; ++i) {
		xuat(&arr[i]);
		printf(" ");
	}
	printf("\n");
}
// ham xuat cac phan tu co mau >tu
void xuatmaulonhontu(phanso* arr, int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i].tu < arr[i].mau) {
			xuat(&arr[i]);
		}
		printf(" ");

	}
	printf("\n");
}
int demphantucomauvatuchan(phanso* arr, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].mau % 2 == 0 && arr[i].tu % 2) {
			cnt++;

		}
	}
	return cnt;
}
// ham tim uoc chung lon nhat cua hia so
int ucln(int a, int b) {
	while (b != 0) {
		int temp = b;
	        b=a%b;
		    a = temp;
	}
	return a;
}
//ham rut gon phan so
void rutgonphanso(phanso* ps) {
	int temp = ucln(abs(ps->tu), abs(ps->mau));
	ps->tu /= temp;
	ps->mau /= temp;

}
// Ham tinh tich cac phan so trong mang
phanso tichCacPhanSo(const phanso* arr, int n) {
	phanso tich = { 1, 1 }; // Khoi tao tich la phan so 1
	for (int i = 0; i < n; ++i) {
		tich.tu *= arr[i].tu;
		tich.mau *= arr[i].mau;
	}
	rutgonphanso(&tich);
	return tich;
}

// Ham tim phan so lon nhat trong mang
phanso timPhanSoLonNhat(const phanso* arr, int n) {
	phanso maxPhanSo = arr[0];
	for (int i = 1; i < n; ++i) {
		if ((double)arr[i].tu / arr[i].mau > (double)maxPhanSo.tu / maxPhanSo.mau) {
			maxPhanSo = arr[i];
		}
	}
	return maxPhanSo;
}
int main() {
	int n;
	printf("Nhap so luong phan so: ");
	scanf_s ("%d", &n);

	// Cap phat dong mang phan so
	phanso* arr = (phanso*)malloc(n * sizeof(phanso));

	// Nhap mang phan so
	nhapmang(arr, n);

	// Xuat mang phan so
	printf("Mang phan so: ");
	xuatmang(arr, n);

	// Xuat cac phan so co mau > tu
	printf("Cac phan so co mau lon hon tu: ");
	xuatmaulonhontu(arr, n);

	// Dem so phan so co mau va tu chan
	int soLuongChan = demphantucomauvatuchan(arr, n);
	printf("So phan so co mau va tu chan: %d\n", soLuongChan);

	// Rut gon cac phan so trong mang
	for (int i = 0; i < n; ++i) {
		rutgonphanso(&arr[i]);
	}
	printf("Mang phan so sau khi rut gon: ");
	xuatmang(arr, n);

	// Tinh tich cac phan so trong mang
	phanso tich = tichCacPhanSo(arr, n);
	printf("Tich cua cac phan so: ");
	xuat(&tich);
	printf("\n");

	// Tim phan so lon nhat trong mang
	phanso maxPhanSo = timPhanSoLonNhat(arr, n);
	printf("Phan so lon nhat: ");
	xuat(&maxPhanSo);
	printf("\n");

	// Giai phong bo nho
	free(arr);

	return 0;
}