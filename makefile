tester: List.o
	g++ -g -o tester tester.cc List.o

writer: List.o
	g++ -g -o writer writer.cc List.o

List: List.h
	g++ -g -c List.cc

clean:
	rm -r *.o tester writer
