#include <stdio.h>
#include <string.h>

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