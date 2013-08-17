
# settings
VERSION	= 0.1

# directories
SRCDIR = src
BINDIR = bin

# compiler
CC 		= g++
CFLAGS 	= -g -Wall -pedantic
LDFLAGS	= 

all: test demo

tests: test/tester.cpp $(SRCDIR)/plainopts.h
	@echo "building tests ..."
	$(CC) $(CFLAGS) $< -o $(BINDIR)/$@

run-tests:
	@echo "starting tests ..."
	./$(BINDIR)/tests

demo: $(SRCDIR)/demo.cpp
	$(CC) $(CFLAGS) $< -o $(BINDIR)/$@

clean:
	@echo "cleaning ..."
	$(RM) $(BINDIR)/*

.PHONY: clean