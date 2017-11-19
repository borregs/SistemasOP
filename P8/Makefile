IN=imc.c
DEPS=bar.h foo.h
EXT=imc.dat
LFLAGS=-lncurses -lm
CFLAGS=-t -std=c99
OUT=IMCalcCmd

$(OUT) : $(IN) $(DEPS)
	gcc -o $@ $(CFLAGS) $^ $(LFLAGS)
	touch $(EXT)
	sleep 2 && aplay ~/DING.wav &> /dev/null
	echo "[...] Everything is OK"

clean:
	rm $(OUT) $(EXT)
