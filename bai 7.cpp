#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include<conio.h>

// a. Tim phan tu lon nhat cua a, xuat ra phan tu lon nhat va dia chi cua no thong qua con tro mang.
void timmax(int* a, int size, int** max, int** diachi) {
    *max = a;
    *diachi = a;
    for (int i = 1; i < size; i++) {
        if (a[i] > **max) {
            *max = &a[i];
            *diachi = &a[i];
        }
    }
}

// b. Xuat dia chi cua phan tu chan lon nhat va phan tu le nho nhat
void maxchanminle(int* a, int size, int** max, int** min) {
    *max = NULL;
    *min = NULL;
    for (int i = 0; i < size; i++) {
        if (a[i] % 2 == 0) {
            if (*max == NULL || **max < a[i]) {
                *max = &a[i];
            }
        }
        else {
            if (*min == NULL || **min > a[i]) {
                *min = &a[i];
            }
        }
    }
}

// c. Xoa phan tu co gia tri 0.
int xoa(int* a, int size) {
    int newsize = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] != 0) {
            a[newsize++] = a[i];
        }
    }
    return newsize;
}

// d. Them phan tu x vao sau phan tu dau tien
int them(int* a, int size, int x) {
    for (int i = size; i > 1; i--) {
        a[i] = a[i - 1];
    }
    a[1] = x;
    return size + 1;
}

// e. Tinh tong cac phan tu la so chinh phuong
bool sochinhphuong(int a) {
    int root = sqrt(a);
    return root * root == a;
}

int tongsochinhphuong(int* a, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (sochinhphuong(a[i])) {
            sum += a[i];
        }
    }
    return sum;
}

// f. Tim so cuc dai
void timcucdai(int* a, int size, int** vitrisocucdai, int* count) {
    *count = 0;
    if (size > 0 && a[0] > a[1]) {
        vitrisocucdai[(*count)++] = &a[0];
    }
    for (int i = 1; i < size - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            vitrisocucdai[(*count)++] = &a[i];
        }
    }
    if (size > 1 && a[size - 1] > a[size - 2]) {
        vitrisocucdai[(*count)++] = &a[size - 1];
    }
}

// Nhap gia tri vao mang
void nhap(int* a, int size) {
    for (int i = 0; i < size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf_s("%d", &a[i]);
    }
}

int main() {
    int size;
    printf("Nhap kich thuoc mang: ");
    scanf_s("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    nhap(arr, size);

    int* max = NULL;
    int* address = NULL;
    timmax(arr, size, &max, &address);
    printf("Phan tu lon nhat: %d\n", *max);
    printf("Dia chi cua phan tu lon nhat: %p\n", (void*)address);

    int* evenMax = NULL;
    int* oddMin = NULL;
    maxchanminle(arr, size, &evenMax, &oddMin);
    if (evenMax) {
        printf("Dia chi cua phan tu chan lon nhat: %p\n", (void*)evenMax);
    }
    else {
        printf("Khong co phan tu chan trong mang\n");
    }
    if (oddMin) {
        printf("Dia chi cua phan tu le nho nhat: %p\n", (void*)oddMin);
    }
    else {
        printf("Khong co phan tu le trong mang\n");
    }

    size = xoa(arr, size);
    printf("Mang sau khi xoa cac phan tu co gia tri 0:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int x = 9;
    size = them(arr, size, x);
    printf("Mang sau khi them phan tu %d sau phan tu dau tien:\n", x);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sum = tongsochinhphuong(arr, size);
    printf("Tong cac phan tu la so chinh phuong: %d\n", sum);

    int* localMaxima[9];
    int localMaximaCount = 0;
    timcucdai(arr, size, localMaxima, &localMaximaCount);
    printf("Cac so cuc dai trong mang:\n");
    for (int i = 0; i < localMaximaCount; i++) {
        printf("%d ", *localMaxima[i]);
    }
    printf("\n");

    getch();

    return 0;
}
