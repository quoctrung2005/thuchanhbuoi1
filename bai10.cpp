#include <stdio.h>
#include <ctype.h>
#include <string.h>


void printCharacters(const char* str) {
    const char* ptr = str;
    while (*ptr != '\0') {
        printf("%c\n", *ptr);
        ptr++;
    }
}


void toUpperCase(char* str) {
    char* ptr = str;
    while (*ptr != '\0') {
        *ptr = toupper(*ptr);
        ptr++;
    }
}


void capitalizeWords(char* str) {
    int newWord = 1; 
    char* ptr = str;
    while (*ptr != '\0') {
        if (isspace(*ptr)) {
            newWord = 1;
        }
        else if (newWord) {
            *ptr = toupper(*ptr);
            newWord = 0;
        }
        ptr++;
    }
}

int main() {
    char st[100];

    
    printf("Nhap vao chuoi: ");
    fgets(st, sizeof(st), stdin);
    st[strcspn(st, "\n")] = '\0';

    
    printf("Xuat gia tri tung ky tu cua chuoi:\n");
    printCharacters(st);

 
    toUpperCase(st);
    printf("Chuoi sau khi chuyen sang chu hoa: %s\n", st);

  
    for (int i = 0; st[i]; i++) {
        st[i] = tolower(st[i]);
    }
    capitalizeWords(st);
    printf("Chuoi sau khi chuyen ky tu dau moi tu sang chu hoa: %s\n", st);

    return 0;
}
