#include "stdio.h"

void multiplication_table(){
	int start; 
	int end;
	int ch;
	printf("Enter the number you want to print the table of: \n");
	scanf("%d",&ch);
	printf("enter range of table (Start):\n");
	scanf("%d",&start);
	printf("enter range of table (unitl):\n");
	scanf("%d",&end);

	FILE *fp; //file pointer

	fp = fopen("multiplication_table.txt","w");
	
	for(int i=start;i<=end;i++){
		fprintf(fp,"%d x %d = %d\n",i,ch,i*ch);
	}

}

int main(){
	multiplication_table();
}
