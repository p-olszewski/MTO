#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse_str(char *str1)  {
    int i, len, temp;
    len = strlen(str1);
    for (i = 0; i < len/2; i++) {
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}

int my_printf(char *format_string, char *param){
	for(int i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'g')){
			i++;

			int paramIsNumber = 1;
            for (int j = 0; j < strlen(param); j++) {
				if (!isdigit(param[j])) {
					paramIsNumber = 0;
					break;
				}
            }

			if (paramIsNumber) {
				reverse_str(param);
				printf("%d",atoi(param));
			} else {
				puts("");
				return 0;
			}
			
		} else if((format_string[i] == '#') && (isdigit(format_string[i+1])) && (format_string[i+2] == 'g')) {
			int paramIsNumber = 1;
            for (int j = i + 2; j < strlen(param); j++) {
				if (!isdigit(param[j])) {
					paramIsNumber = 0;
					break;
				}
            }

			if (paramIsNumber) {
				for (int k = i + 2; k < strlen(param); k++) {
					if (param[k] == '0') {
        				param[k] = '9';
					} else if (param[k] == '1') {
						param[k] = '0';
					} else if (param[k] == '2') {
						param[k] = '1';
					} else if (param[k] == '3') {
						param[k] = '2';
					} else if (param[k] == '4') {
						param[k] = '3';
					} else if (param[k] == '5') {
						param[k] = '4';
					} else if (param[k] == '6') {
						param[k] = '5';
					} else if (param[k] == '7') {
						param[k] = '6';
					} else if (param[k] == '8') {
						param[k] = '7';
					} else if (param[k] == '9') {
						param[k] = '8';
					}
            	}
				printf("%s", param);
			} else {
				puts("");
				return 0;
			}
		}
		else
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
