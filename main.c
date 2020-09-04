#include<stdio.h>

#define MAXBUFFER 256

int main() {
	FILE *fp = fopen("input.txt", "r");
	char string[MAXBUFFER];

	int first_number = 0;
	int second_number = 0;
	int equals = 0;
	int level = 0;

	while((fscanf(fp, "%s", string)) != EOF) {
		first_number = 0;
		second_number	= 0;
		equals = 0;
		level = 0;

		for(int i = 0; string[i] != '\0'; i++) {
			if(string[i] == '-'){
				if(level == 0) {
					first_number++;
				} else if (level == 1) {
					second_number++;
				} else if (level == 2) {
					equals++;
				}
			} else {
			   level++;	
			}
		}

		printf("(%s): ", string);

		if((first_number+second_number) == equals) {
			printf("Correct\n");
		} else {
			printf("Incorrect\n");
		}
	}

	return 0;
}
