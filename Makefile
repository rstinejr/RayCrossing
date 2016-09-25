.PHONY:	clean run

INCS = includes
MY_CFLAGS = -c -g -O0 -Wall -I$(INCS)
MY_LDFLAGS = -lstdc++ -lrt
OBJS = objs/main.o objs/geom.o

PGM = rayCrosses


all:	$(PGM)

$(OBJS):	objs

objs/%.o:	src/%.cpp
	g++ $(MY_CFLAGS) $< -o $@

obj/main.o:	includes/geom.h

obj/geom.o:	includes/geom.h

objs:	
	mkdir objs

$(PGM):	$(OBJS)
	g++ -o $@ $(OBJS) $(MY_LDFLAGS) 

clean:
	rm -rf objs $(PGM)
		
run:	$(PGM)
	./$(PGM)
