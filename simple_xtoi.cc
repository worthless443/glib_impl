#include<string.h>
#include<stdio.h>

#ifdef __cpp
#include<string>
#include<iostream>
namespace _std { 
	class DChar {
		private:
			std::string s_str;
			char *str;
			int int_rep;
		public:
			DChar(std::string s) { s_str = s;str=(char*)s_str.c_str();}
			DChar(const char *s) { str = (char*)s; s_str = std::string(s);}
			DChar(int s_rep) { int_rep = s_rep; }

			DChar operator=(std::string s) {return DChar(s);}
			DChar operator=(const char *s) {return DChar(s);}
			DChar operator=(DChar dchar) {return dchar;}

			void operator()(const char *s) {
				str = (char*)s;
				s_str = std::string(s);
			}
			void operator()(std::string s) {str = (char*)s.c_str();s_str = s;}
			const char *operator<<(const char *s) {
				return s;	
			}
			auto _int() {return int_rep;}
			auto getstr() {
				return s_str;
			}
	};
	
	DChar dtoi(DChar Dnumstr) {
		const char *numstr = Dnumstr.getstr().c_str();
		int t_num =  0;
		for(int i=0,ep=1;i<strlen(numstr);++i) {
			if(!(*(numstr + i) >= '0' && *(numstr + i)<='9')) {
				DChar _ = 0;
				_(Dnumstr.getstr());
				return _;
			}
			t_num*=ep-1;
			t_num+=*(numstr + i) - '0';
			if(ep<10) ep=11;
		}
		DChar dchar = t_num;
		dchar(Dnumstr.getstr().c_str());
		return dchar;
	}
};

// do not use templates
std::ostream &operator<<(std::ostream &s, _std::DChar c) { 
	s << c._int();
	return s;
}
#endif

int atoi(const char *numstr) {
	int t_num =  0;
	for(int i=0,ep=1;i<strlen(numstr);++i) {
		if(!(*(numstr + i) >= '0' && *(numstr + i)<='9')) return 0;
		t_num*=ep-1;
		t_num+=*(numstr + i) - '0';
		if(ep<10) ep=11;
	}
	return t_num;
}
// testing
int main() {
	printf("%d\n", atoi("1234152"));
#ifdef __cpp 
	_std::DChar prop = dtoi(_std::DChar("123"));
	 std::cout << prop << "\n";
#endif
}
