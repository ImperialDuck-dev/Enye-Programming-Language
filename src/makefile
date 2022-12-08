exec = final.exe
sources = $(wildcard *.c)
objects = $(sources:.c=.ny)
flags = -g


$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.ny: %.c include/%.h
	gcc -c $(flags) $< -o $@


clean:
	-rm *.exe
	-rm *.ny
	-rm src/*.ny