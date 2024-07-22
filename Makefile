CFLAGS:= -O3 -m32 -Wall -g
ASMFLAGS:= -f elf32
CC:=gcc
ASM:=nasm

all: integral

test: integral
	#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	#Тестирование функции integral для...
	#функции ln(x): 
	./integral -I 1:1:2.718281828:1e-9:1
	#функции -2х+14:
	./integral -I 2:-10:10:1e-9:280
	#функции 1/(2-х)+6:
	./integral -I 3:2.001:3:1e-10:-0.9137552789
	#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	#Тестирование функции root для...
	#функций 100x+123 и -2x+14:
	./integral -R 4:2:-5:5:1e-10:-1.0686274509
	#функций -2x+14 и 1/(2-x)+6:
	./integral -R 2:3:-100:1.9999999999:1e-10:1.7752551286
	#функций 100x+123 и 1/(2-x)+6:
	./integral -R 4:3:-100000:0:1e-10:-1.1668422803
	#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

integral: main.o integralf.o rootf.o f1.o f2.o f3.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	
main.o: main.c
	$(CC) $(CFLAGS) $^ -lm -c -o $@
	
rootf.o: rootf.c
	$(CC) $(CFLAGS) $^ -c -o $@
	
integralf.o: integralf.c
	$(CC) $(CFLAGS) $^ -c -o $@
	
f1.o: f1.asm
	$(ASM) $(ASMFLAGS) $^
	
f2.o: f2.asm
	$(ASM) $(ASMFLAGS) $^
	
f3.o: f3.asm
	$(ASM) $(ASMFLAGS) $^

clean:
	rm -rf *.o integral
