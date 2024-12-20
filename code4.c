/*Merging the strings: Given two strings str1 and str2 in two files 
file1 and file2, write a program to create a third string str3 with one character from each array 
alternatively. If one string is longer than the other, append the extra characters to str3. Write 
str3 into a different text file called file3.*/

#include <stdio.h>
#include <stdlib.h>

void mergeStrings(const char *file1, const char *file2, const char *file3) {
	FILE *fp1 = fopen(file1, "r");
	FILE *fp2 = fopen(file2, "r");
	FILE *fp3 = fopen(file3, "w");

	if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
		printf("Error opening files.\n");
		exit(1);
	}

	char ch1 = fgetc(fp1);
	char ch2 = fgetc(fp2);

	while (ch1 != EOF || ch2 != EOF) {
		if (ch1 != EOF) {
			fputc(ch1, fp3);
			ch1 = fgetc(fp1);
		}
		if (ch2 != EOF) {
			fputc(ch2, fp3);
			ch2 = fgetc(fp2);
		}
	}

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}

int main() {
	const char *file1 = "file1.txt";
	const char *file2 = "file2.txt";
	const char *file3 = "file3.txt";

	mergeStrings(file1, file2, file3);

	printf("Strings merged successfully into %s\n", file3);

	return 0;
}
