#include "libraryC.h"

bool check_name()
{
	for(i=0; t_name[i] != '\0'; i++)
	{
		if((!((t_name[i] >= 'a' && t_name[i] <= 'z') || (t_name[i] >= 'A' && t_name[i] <= 'Z'))) && (t_name[i] != ' '))
		{
			printf("\tPlease enter your name again\n");
			return false;
		}
	}
	return true;
}
bool check_email()
{
	int atIndex = -1, dotIndex = -1;
    int len = strlen(t_email);
    if(len < 15)
    {
    	printf("\tPlease enter your email again\n");
    	return false;
	}
    for (i = 0; i < len; i++) {
        if (t_email[i] == '@') {
            atIndex = i;
            break;
        }
    }
    for (i = atIndex; i < len; i++) {
        if (t_email[i] == '.') {
            dotIndex = i;
            break;
        }
    }
    if (atIndex < 1 || dotIndex < atIndex + 2 || dotIndex == len - 1) {
    	printf("\tPlease enter your email again\n");
        return false;
    }
    return true;
}
 
int check_password() {
    int length = strlen(t_password1);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    if (length < 8) {
    	printf("\tPassword too short\n");
        return false;
    }
    for (i = 0; i < length; i++) {
        char c = t_password1[i];
        if (isupper(c)) {
            hasUpper = 1;
        } else if (islower(c)) {
            hasLower = 1;
        } else if (isdigit(c)) {
            hasDigit = 1;
        } else if (ispunct(c) || c == ' ') {
            hasSpecial = 1;
        }
    }
    if(strcmp(t_password1, t_password2) != 0)
    {
    	printf("\tYour password and confirm password are different\n");
    	return false;
	}
	else if( !(hasUpper && hasLower && hasDigit && hasSpecial))
	{
		printf("\tYour password is not valid\n");
		return 0;
	} else return hasUpper && hasLower && hasDigit && hasSpecial;
}

bool check_phone_and_age()
{
	if(t_mobile[0] != '0' || strlen(t_mobile) < 10 || strlen(t_mobile) > 10)
	{
		printf("\tPLease enter your phone number again\n");
		return false;
	}
	for(i=1; t_mobile[i] != '\0'; i++)
	{
		if(!(t_mobile[i] >= 48 && t_mobile[i] <= 57))
		{
			printf("\tPLease enter your phone number again\n");
			return false;
		}
	}
	if(t_age < 18)
	{
		printf("\tYou don't have to be old enough to use this app\n");
		return false;
	}
	return true;
}


void login()
{
	char tmp_password[100];
	char tmp_email[100];
	int check_status = 0;
	system("cls");
	printf("\t\t\t\t\t**********WELCOME TO LOG IN**********\n");
	printf("\tPlease enter your email : ");
	scanf("%s", tmp_email);
	printf("\n");
	printf("\tPlease enter your password : ");
	scanf("%s", tmp_password);
	if(t_email == "" || t_password1 =="")
	{
		printf("\tPLease sign up\n");
		system("pause");
		sigup();
		check_status = 1;
	}
	if(strcmp(t_email, tmp_email) != 0)
	{
		printf("\tError with your email\n");
		system("pause");
		login();
		check_status = 1;
	}
	if(strcmp(t_password1, tmp_password) != 0)
	{
		printf("\tError with your password\n");
		system("pause");
		login();
		check_status = 1;
	}
	if(check_status)
	{
		printf("\t\t\t\t\t**********YOUR ARE SUCCESSFULLY LOGGED IN**********\n");
		system("pause");
		FILE *file_loggin;
		file_loggin = fopen("thongtindangnhap.txt", "a");
		fprintf(file_loggin, "%s\n", t_email);
		fprintf(file_loggin, "%s\n", t_password1);
		fclose(file_loggin);
	}
}

void signup()
{
	system("cls");
	fflush(stdin);
	printf("\t\t\t\t\t**********WELCOME TO SIGN UP**********\n");
	printf("\tPlease enter your name : ");
	gets(t_name);
	printf("\n");
	printf("\tPlease enter your email : ");
	gets(t_email);
	printf("\n");
	printf("\tPlease enter your password : ");
	gets(t_password1);
	printf("\n");
	printf("\tConfirm password : ");
	gets(t_password2);
	printf("\n");
	printf("\tPlease enter your phone number : ");
	scanf("%s", t_mobile);
	printf("\n");
	printf("\tPlease enter your age : ");
	scanf("%d", &t_age);
	check_name(); 
	check_email(); 
	check_password(); 
	check_phone_and_age();
	if(check_name() && check_email() && check_password() && check_phone_and_age())
	{
		file = fopen("thongtinuser.txt", "a");
		fprintf(file, "%s\n", t_name);
		fprintf(file, "%s\n", t_email);
		fprintf(file, "%s\n",t_password1);
		fprintf(file, "%s\n", t_mobile);
		fprintf(file, "%d\n", t_age);
		fclose(file);
		login();
	}
}
