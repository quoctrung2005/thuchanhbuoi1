#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>

int tinhtuoi(int day, int month, int year){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int age = tm.tm_year + 1900 - year;
	if (tm.tm_mon + 1 < month || (tm.tm_mon + 1 == month &&tm.tm_mday < day)){
		age--;

	}
	return age;
	
}
void retirement_info(char*name, int day, int month, int year, char *gender){
	int age = tinhtuoi(day, month, year);
	if (age <18 || (age>60 && strcmp(gender, "nu") == 0) || (age >62 && strcmp(gender, "nam") == 0)){
		fprintf(stderr, "error 101:tuoi khong nam trong do tuoi lao dong\n");
		return;
	}
	if (strcmp(gender, "nam") != 0 && strcmp(gender, "nu") != 0){
		fprintf(stderr, "errcode\n");
		return;
	}
	int retirement_age = strcmp(gender, "nam") == 0 ? 62 : 60;
	int year_to_retirement = retirement_age - age;
	if (year_to_retirement > 0){
		printf("%s con %d nam nua den khi nghi huu", name, year_to_retirement);

	}
	else {
		printf("%s da du tuoi nghi huu\n",name);

	}
}
int main(){
	char name[100];
    char birthdate_str[11];
	char gender[4];
	int day, month, year;
	printf("nhap ten");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0';
	printf(" nhap ngay sinh dd/mm/yyyy");
	sscanf(birthdate_str, "%d%d%d", &day, &month, &year);
	printf("nhap gioi tinh");
	fgets(gender, sizeof(gender), stdin);
	retirement_info(name, day, month, year, gender);
	return 0;

}