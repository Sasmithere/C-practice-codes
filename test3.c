#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
int main() {
  char line[MAX];
  int count_line=0,count_words=0;
  printf("Enter multiple line string :(ctrl + d to end input)\n");
  while(fgets(line,MAX,stdin)){
    count_line++;
    int in_word = 0; 
    for (int i = 0; i < strlen(line); i++) {
        if (isalnum(line[i])) {
            if (!in_word) {
                count_words++;
                in_word = 1;
            }
        } else {
            in_word = 0;
      }
  }
}
  printf("No of lines: %d\nNo of words: %d\n", count_line, count_words);
  return 0;
}
