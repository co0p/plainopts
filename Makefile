
# settings
VERSION	= 0.1

# directories
SRCDIR = src
LIBDIR = lib
BUILDDIR = build
BINDIR = bin

# compiler
CC 		= g++
ARFLAGS = rcs
CFLAGS 	= -g -Wall -pedantic
LDFLAGS	= 

all: test demo

test: test/tester.cpp 
	@echo "building tests ..."
	$(CC) $(CFLAGS) $< -o $(BINDIR)/$@

run-tests:
	./bin/tests

demo: $(SRCDIR)/demo.cpp
	$(CC) $(CFLAGS) $< -o $(BINDIR)/$@

clean:
	@echo "cleaning ..."
	$(RM) $(BUILDDIR)/*