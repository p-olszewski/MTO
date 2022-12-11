#include <stdio.h>
#include <string.h>
#include <ctype.h>

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == '.') && (isdigit(format_string[i+2]))){
			
			// count number length in string
			int number_length = 0;
            for (int j = i + 2; j < strlen(format_string); j++) {
                if (format_string[j] == 'g') {
                    number_length = j;
                } else if (!isdigit(format_string[j])) {
                    break;
                }
            } 

			if (number_length == 0) {
                putchar(format_string[i]);
            } else {
				int paramIsNumber = 1;
            	for (int j = 0; j < strlen(param); j++) {
					if (!isdigit(param[j])) {
						paramIsNumber = 0;
						break;
					}
            	}

				if (!paramIsNumber) break;
			
				int number = 0;
				char number_array[number_length + 1];

				// change string from numbers to integer number
                memcpy(number_array, &format_string[i + 2], number_length);
                number_array[number_length] = '\0';
                number = atoi(number_array);

				// loop to number
				for(int l=0; l<number; l++){	
					if (param[l] == '0') {
						param[l] = '9';
					} else  {
						int old_digit = param[l];
						int new_digit = (old_digit*9+1)%10;
						param[l] = new_digit;
					}
					printf("%s", param);
				}
				}
				i = i + number_length;
			} else
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