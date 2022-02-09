 CC = gcc
 CXXFLAGS = -w -o
 SOURCES = CodeScribe.c
 OBJECTS = CodeScribe.o
 INCFLAGS = 
 LDFLAGS = -Wl,-rpath,/usr/local/lib
 LDLIBS =$(shell pkg-config --cflags --libs vte-2.91 gtk+-3.0 gtksourceview-3.0)
 GTKFLAGS=-export-dynamic `pkg-config --cflags --libs vte-2.91 gtk+-3.0 gtksourceview-3.0`

all: CodeScribe
foobar: $(OBJECTS)
	$ $(CC) $(SOURCES) `pkg-config --cflags --libs vte-2.91 gtk+-3.0 gtksourceview-3.0` $(CXXFLAGS)  $(OBJECTS)

.SUFFIXES:
.SUFFIXES: .c .cc .C .cpp .o

.c.o :
	$ $(CC) $(SOURCES) `pkg-config --cflags --libs vte-2.91 gtk+-3.0 gtksourceview-3.0` $(CXXFLAGS) $(OBJECTS)

count:
	wc *.c *.cc *.C *.cpp *.h *.hpp

clean:
	rm -f *.o

.PHONY: all
.PHONY: count
.PHONY: clean

