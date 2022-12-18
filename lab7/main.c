#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'j')){
			i++;

			int paramIsNumber = 1;
            for (int j = 0; j < strlen(param); j++) {
				if (!isdigit(param[j])) {
					paramIsNumber = 0;
					break;
				}
            }

			if (paramIsNumber) {
				int i, len, temp;
				len = strlen(param);
				long decimalnum, quotient, remainder;
				int k, j = 0;
				char hexadecimalnum[100]; 
				char output[100];
				int decimal_number = atoi(param);
				sprintf(hexadecimalnum, "%x", decimal_number);
				for (int l=0; l<strlen(hexadecimalnum); l++) {
					if (hexadecimalnum[l] == 'a'){
						hexadecimalnum[l] = 'g';
					} else if (hexadecimalnum[l] == 'b'){
						hexadecimalnum[l] = 'h';
					} else if (hexadecimalnum[l] == 'c'){
						hexadecimalnum[l] = 'i';
					} else if (hexadecimalnum[l] == 'd'){
						hexadecimalnum[l] = 'j';
					} else if (hexadecimalnum[l] == 'e'){
						hexadecimalnum[l] = 'k';
					} else if (hexadecimalnum[l] == 'f'){
						hexadecimalnum[l] = 'l';
					}
				}
				printf(hexadecimalnum);
			} else {
				puts("");
				return 0;
			}
		
		}else
			putchar(format_string[i]);
	}
	puts("");
	return 0;
}

int main(int argc, char *argv[]){
	char buf[1024],buf2[1024];
	while(gets(buf)){
		gets(buf2);
		my_printf(buf,buf2);
	}
	return 0;
}
