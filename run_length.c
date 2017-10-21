#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 150

int main()
{
	FILE *fptr;
	FILE *codefile;
	int count, i = 0, j = 0, k = 0;
	int nn;
	char arr[MAX], temp_count;
	int str[MAX];
	char  temp_str, char_value;
	fptr = fopen("file1.txt", "r");
	if(fptr < 0) {
		printf("Erro in opening the file.\n");
		exit(1);
	}
	fread(arr, sizeof(char), 100, fptr);
	arr[100] = '\0';
	
	while(arr[i] != '\0') {
		temp_str = arr[i];
		count = 0;
		while(arr[i] == temp_str) {
			count = count + 1;
			i++;
		}
		str[j++] = temp_str;
		str[j++] = count;
	}
	if((codefile = fopen("file2.txt", "w+")) < 0) {
		printf("Error in opening coded file\n");
		exit(1);
	}
	
	for(k = 0;k < j;k++) {
		if(k % 2 == 0) {
		//	char_value = (char)(str[k]);
		//	printf("%c",char_value);
			fputc(char_value, codefile);
			fseek(codefile, 0, SEEK_END);
		} else {
			char_value = (char)(str[k]);
			fputc(char_value, codefile);
			fseek(codefile, 0, SEEK_END);
		}
	}
	fclose(fptr);
	fclose(codefile);
	return 0;
}
