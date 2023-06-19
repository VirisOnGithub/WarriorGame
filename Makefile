all: compile&run

run:
	.\main

compile&run:
	g++ main.cpp -o main
	.\main

clean:
	rm -f main

cleanall:
	rm -f *.exe
