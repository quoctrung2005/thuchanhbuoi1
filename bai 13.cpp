#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <stdlib.h>
void nhapmang(int *arr, int n, char ten) {
	for (int i = 0; i < n; i++) {
		printf("nhap phan tu thu %d vao mang %c", i + 1, ten); 
		scanf_s("%d", &arr[i]);
	}
} 
void chiaMang(int* a, int* b, int n) {
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            printf("Phep chia a[%d] / b[%d] khong hop le (mau so = 0)\n", i, i);
        }
        else {
            printf("a[%d] / b[%d] = %f\n", i, i, (float)a[i] / b[i]);
        }
    }
}
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf_s("%d", &n);


    int* a = (int*)malloc(n * sizeof(int));
    int* b = (int*)malloc(n * sizeof(int));

   
    nhapmang(a, n, 'a');
    nhapmang(b, n, 'b');

  
    chiaMang(a, b, n);

    free(a);
    free(b);

    return 0;
}