#include<stdio.h>
#include<math.h>
#include<conio.h>
int main() {
	float a = 5.7, b = 4.8;
	float* pa = &a;
	float* pb = &b;
	printf("\nDia chi cua a: %x", pa);
	printf("\nDia chi cua b: %x", pb);
	float tong, hieu, tich, thuong;
	float* p_tong = &tong, * p_tich = &tich, * p_hieu = &hieu, * p_thuong = &thuong;
	*p_tong = *pa + *pb;
	*p_hieu = *pa - *pb;
	*p_tich = (*pa) * (*pb);
	*p_thuong =(float) (*pa) / (*pb);
	// Xuat ket qua va dia chi cac o nho
	printf("\nTong: %f, Dia chi: %p\n", *p_tong, (void*)p_tong);
	printf("Hieu: %f, Dia chi: %p\n", *p_hieu, (void*)p_hieu);
	printf("Tich: %f, Dia chi: %p\n", *p_tich, (void*)p_tich);
	printf("Thuong: %.2f, Dia chi: %p\n", *p_thuong, (void*)p_thuong);

}
