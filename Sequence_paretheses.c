#include <stdio.h>
#include <string.h>

int check(char *string)
{
	char *hug = "[]";
	char *parenthesis = "()";
	if ((strcmp(string, hug) == 0) || (strcmp(string, parenthesis) == 0)) {
		return 1;
	}
	if (((string[0] == '(') && string[strlen(string) - 1] == ')') || ((string[0] == '[') && string[strlen(string) - 1] == ']')) {
		string[strlen(string) - 1] = '\0';
		string ++;
		check(string);
	} else {
		return 0;
	}
}

int main(int argc, char **argv)
{
	if (argc <= 1) {
		printf("Put a string as argument please \n");
		return 1;
	}

	for (int counter = 0; counter < strlen(argv[1]); counter++) {
		if ((argv[1][counter] != '(') && (argv[1][counter] != ')') && (argv[1][counter] != '[') && (argv[1][counter] != ']')) {
			printf("Put a valid string please \nmust contains just '[]()'\n");
			return 1;
		}
	}

	printf("%d\n", check(argv[1]));
	return 0;
}
