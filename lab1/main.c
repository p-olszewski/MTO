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
