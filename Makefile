CFILES	= $(wildcard *.c)
OFILES	= $(CFILES:.c=.o)

LIB		= lib

%.o: %.c
	clang -std=c17 -O2 -c -o $@ $<

$(LIB)/strconv.a: $(OFILES)
	@[ -d $(LIB) ] || mkdir -p $(LIB)
	ar rcs $@ $^