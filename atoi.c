#include<string.h>
int _atoi(const char *numstr) {
	int t_num =  0;
	for(int i=0,ep=1;i<strlen(numstr);++i) {
		if(!(*(numstr + i) >= '0' && *(numstr + i)<='9')) return 0;
		t_num*=ep-1;
		t_num+=*(numstr + i) - '0';
		if(ep<10) ep=11;
	}
	return t_num;
}
