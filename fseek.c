#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>

#include<stdio_defs.h>

struct stat_flags_ {
	int orstatus_flags, flags1, flags2;
};

int fseek__(FILE *fp , off_t offset,int which, struct stat_flags_ *stat) {
	struct stat st;
	fpos_t target;
	off_t curoff;
	size_t n;
	int hasops;

	fpos_t (*seekfn)(void *, fpos_t, int);

	if((stat->orstatus_flags = fp->_flags &  (S_IREAD | S_IWRITE)) == 0) return -1;
	if(stat->flags1 = fp->_flags & __SOFF)	curoff = fp->_old_offset ;
	else {
		//curoff = seekfn((void*)1, (fpos_t)0, SEEK_CUR);
	}
	//if((seekfn = fp->_seek) == NULL) return 0;
	
	uintptr_t curaddr, addrintr, endaddr, startaddr;
	int offaddr;
	uintptr_t newaddr;
	int setoff;

	addrintr = (uintptr_t)fp->_IO_read_ptr + (uintptr_t)fp->_IO_read_base;
	if((intptr_t)fp->_IO_read_base==0) return -1;
	for(setoff=1;(*(int*)(fp->_IO_read_end + setoff))!=0;setoff++);
switch(which)  {
case SEEK_SET:
	curaddr = 0;
	if(setoff != 0) {
		fp->_IO_read_ptr -= setoff - 1 - offset;			
		fp->_IO_read_end += setoff - 1 - offset;			
		fp->_flags  &= ~__SEOF;
		return 0;
	}

	
case SEEK_CUR:
	fp->_IO_read_ptr -= offset;
	fp->_IO_read_end += offset; // fp->_IO_read_end;
	fp->_flags  &= ~__SEOF;
	return 0;
default:
 	return -1;

	}
}

int main() {
 	FILE *f = fopen("file.txt", "r");
	struct stat_flags_ st;
	char buf[1];
	while(fread(buf,1,1,f)) printf("%s\n", buf);
	int ret = fseek__(f,1,SEEK_CUR, &st);
	printf("%d\n", ret);
	while(fread(buf,1,1,f)) printf("%s\n", buf);
}
