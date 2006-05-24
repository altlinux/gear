MAN1PAGES = gear.1 git-srpmimport.1

TARGETS = $(MAN1PAGES)

HELP2MAN1 = help2man -N -s1

all: $(TARGETS)

%.1: % %.1.inc Makefile
	$(HELP2MAN1) -i $@.inc ./$< >$@
