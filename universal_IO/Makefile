test1: test1.c test1.h
	gcc test1.c -o test1

debug_test1: test1.c test1.h
	gcc test1.c -o test1 -DDEBUG_CODE -g

clean:
	rm -f test1 file1

.PHONY = clean

