a.out : texteditor.o Rope.o RopeHelper.o
	gcc texteditor.o Rope.o RopeHelper.o

texteditor.o: texteditor.c Rope.h
	gcc -c texteditor.c

Rope.o : Rope.c Rope.h RopeHelper.h
	gcc -c Rope.c

RopeHelper.o : RopeHelper.c RopeHelper.h
	gcc -c RopeHelper.c
