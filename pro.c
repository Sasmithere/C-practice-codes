#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int is_keyword(char *str) {
	char *keywords[] = {"int", "float", "if", "else", "return", "while", "for", "do", "char", "double", NULL};
	for (int i = 0; keywords[i] != NULL; i++) {
		if (strcmp(str, keywords[i]) == 0)
			return 1;
	}
	return 0;
}

int is_identifier(char *str) {
	if (!isalpha(str[0]) && str[0] != '_')
		return 0;
	for (int i = 1; str[i] != '\0'; ++i) {
		if (!isalnum(str[i]) && str[i] != '_')
			return 0;
	}
	return !is_keyword(str);
}
int isConst(char *str){
	if(!isdigit(str[0])){
		return 0;
	}
	for(int i=1;str[i]!='\0';i++){
		if(!isdigit(str[i])){
			return 0;
		}
	}
		return 1;
}


int main() {
	char line[MAX_LENGTH];
	printf("Enter a line of code: ");
	fgets(line, MAX_LENGTH, stdin);
	line[strcspn(line, "\n")] = '\0';

	char *token = strtok(line, " \t\n");
	while (token != NULL) {
		if (is_keyword(token)) {
			printf("Keyword: %s\n", token);
		} else if (is_identifier(token)) {
			printf("Identifier: %s\n", token);
		}
		  else if(isConst(token)){
			  printf("Constant : %s\n",token);
		  }
		  else {
			printf("Other: %s\n", token);
		}
		token = strtok(NULL, " \t\n");
	}

	return 0;
}