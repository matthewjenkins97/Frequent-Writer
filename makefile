writer: List.o
	g++ -g -o writer writer.cc List.o

List: List.h
	g++ -g -c List.cc

clean:
	rm -r *.o writer
