OBJ=atoi.o  xtoi.o
LIB=libgimpl.a

all: $(LIB)
$(OBJ):%.o:%.c
	gcc -c -I./ $^ -o $@
$(LIB):$(OBJ)
	ar rcs $@ $^
clean:
	rm -rf *.a *.so *.o
