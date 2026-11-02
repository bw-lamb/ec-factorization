SRCS := ec.c
MAINSRC := main.c
TESTSRC := test.c

CC := gcc
CFLAGS	:= -Wall -g 
LIBS := 
TESTLIBS := -lcriterion

build: $(SRCS) $(MAINSRC)
	$(CC) $(CFLAGS) $^ $(LIBS)

test: $(SRCS) $(TESTSRC)
	$(CC) $(CFLAGS) $^ $(LIBS) $(TESTLIBS)
