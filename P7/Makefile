IN=loqsepide.c
DEPS=glob.h funciona.h
EXT=calificaciones.dat aprobados.dat reprobados.dat
LFLAGS=-lncurses
CFLAGS=-t -std=c99
OUT=registroCalif



$(OUT) : $(IN) $(DEPS)
	gcc -o $@ $(CFLAGS) $^ $(LFLAGS)
	touch $(EXT)
	sleep 2 && aplay DING.wav 1> /dev/null
	echo "[...] Everything is OK"

clean:
	rm $(OUT) $(EXT)
