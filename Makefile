all: ep_crt et_crt para_mm

CC= gcc
CFLAGS= -g
IFLAGS= -I

ep_crt:	ep.o timing.o
		$(CC) -o ep_crt ep.o timing.o
et_crt: et.o timing.o
		$(CC) -o et_crt et.o timing.o
para_mm: para_mm.o timing.o
		$(CC) -o para_mm para_mm.o timing.o

clean:	rm ep.o et.o  timing.o ep_crt et_crt

depend:ep.c timing.c et.c para_mm.c
		makedepend $(IFLAGS) ep.c timing.c et.c para_mm.c