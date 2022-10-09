#include <stdio.h>
#include <string.h>
#include <ctype.h>

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'k')){
			i++;

			for(int k=0;k<strlen(param);k++){
				char letter = param[k];
				int ascii_value = (int) letter;
				if (ascii_value >= 65 && ascii_value <= 90) {
					ascii_value = ascii_value + 32;
				} else if (ascii_value >= 97 && ascii_value <= 122) {
					ascii_value = ascii_value - 32;
				}
				putchar(ascii_value); 
			}
			// Na wzór przykładu proszę przygotować implementację "printf" wykorzystująca #k 
			// jako zamiennik %s, który dodatkowo dla drukowanego stringa zmienia 
			// wielkość liter (małe na wielkie, wielkie na małe). 
			// Proszę zaimplementować obsługę długości drukowanego stringa korzystając zapisu #.Xk 
			//(tożsamego z %.Xs), gdzie X to dowolna liczba.
		} else if((format_string[i] == '#') && (format_string[i+1] == '.') && (isdigit(format_string[i+2]))){
			i++;

			int number_length = 0;
            for (int j = i + 2; j < strlen(format_string); j++) {
                if (format_string[j] == 'k') {
                    number_length = j;
                } else if (!isdigit(format_string[j])) {
                    break;
                }
            } 

			if (number_length == 0) {
                putchar(format_string[i]);
            } else {
				int number = 0;
				char number_array[number_length + 1];

				// change string from numbers to integer number
                memcpy(number_array, &format_string[i + 2], number_length);
                number_array[number_length] = '\0';
                number = atoi(number_array);

				// loop to number or to param length if its shorter
				for(int l=0; l<number && l<strlen(param); l++){
					char letter = param[l];
					int ascii_value = (int) letter;
					if (ascii_value >= 65 && ascii_value <= 90) {
						ascii_value = ascii_value + 32;
					} else if (ascii_value >= 97 && ascii_value <= 122) {
						ascii_value = ascii_value - 32;
					}
					putchar(ascii_value); 
				}
			}
			
		}else
			putchar(format_string[i]);
	}
	puts("");
}

int main(int argc, char *argv[]){
	char buf[1024],buf2[1024];
	while(gets(buf)){
		gets(buf2);
		my_printf(buf,buf2);
	}
	return 0;
}
