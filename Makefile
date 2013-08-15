# ideas from http://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/


#
# settings
#
VERSION	= 0.1

# directories
SRCDIR = src
BUILDDIR = build
DESTDIR = lib
BINDIR = bin

# compiler
CC 		= g++
CFLAGS 	= -g -Wall -pedantic
LDFLAGS	= 
INC 	= -I include
SRCEXT 	= cpp
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

TARGET = demo

#
# targets
#
$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@mkdir -p $(BINDIR)
	@echo "$(CC) $^ -o $(BINDIR)/$(TARGET) $(LIB)"; $(CC) $^ -o $(BINDIR)/$(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

tester:
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o $(BINDIR)/tester

run-tests: tester
	@echo "running tests..."
	@cd $(BINDIR) && ./tester

clean:
	@echo "Cleaning..."; 
	@echo "$(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)
	@echo "$(RM) -r $(BINDIR) $(TARGET)"; $(RM) -r $(BINDIR) $(TARGET)

.PHONY: clean