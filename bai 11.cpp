#include <stdio.h>
#include <stdbool.h>

// Ham xuat cac so cuc tieu trong mang
void xuatCucTieu(int a[], int n) {
    printf("Cac so cuc tieu trong mang: ");
    if (n > 0) {
        if (n == 1 || a[0] < a[1]) {
            printf("%d ", a[0]);
        }
        for (int i = 1; i < n - 1; i++) {
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
                printf("%d ", a[i]);
            }
        }
        if (n > 1 && a[n - 1] < a[n - 2]) {
            printf("%d ", a[n - 1]);
        }
    }
    printf("\n");
}

// Ham xoa phan tu tai vi tri k
void xoaPhanTu(int a[], int *n, int k) {
    if (k < 0 || k >= *n) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    for (int i = k; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
}

// Ham them phan tu x tai vi tri k
void themPhanTu(int a[], int *n, int x, int k) {
    if (k < 0 || k > *n) {
        printf("Vi tri k khong hop le\n");
        return;
    }
    for (int i = *n; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;
    (*n)++;
}

// Ham chuyen so chan len dau mang, so le xuong cuoi mang
void chuyenChanLe(int a[], int n) {
    int chan[n], le[n];
    int soChan = 0, soLe = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            chan[soChan++] = a[i];
        } else {
            le[soLe++] = a[i];
        }
    }

    for (int i = 0; i < soChan; i++) {
        a[i] = chan[i];
    }
    for (int i = 0; i < soLe; i++) {
        a[soChan + i] = le[i];
    }
}

// Ham kiem tra mang co chua chan le xen ke khong
bool kiemTraChanLeXenKe(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0)) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[100];
    int n, x, k;

    // Nhap mang
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // a. Xuat cac so cuc tieu trong mang
    xuatCucTieu(a, n);

    // b. Xoa phan tu tai vi tri k
    printf("Nhap vi tri k can xoa: ");
    scanf("%d", &k);
    xoaPhanTu(a, &n, k);
    printf("Mang sau khi xoa phan tu tai vi tri %d: ", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // c. Them phan tu x tai vi tri k
    printf("Nhap phan tu x can them: ");
    scanf("%d", &x);
    printf("Nhap vi tri k can them: ");
    scanf("%d", &k);
    themPhanTu(a, &n, x, k);
    printf("Mang sau khi them phan tu %d tai vi tri %d: ", x, k);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // d. Chuyen so chan len dau mang, so le xuong cuoi mang
    chuyenChanLe(a, n);
    printf("Mang sau khi chuyen so chan len dau, so le xuong cuoi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // e. Kiem tra mang co chua chan le xen ke khong
    if (kiemTraChanLeXenKe(a, n)) {
        printf("Mang co chua chan le xen ke.\n");
    } else {
        printf("Mang khong chua chan le xen ke.\n");
    }

    return 0;
}

