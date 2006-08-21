#
# Copyright (C) 2006  Dmitry V. Levin <ldv@altlinux.org>
# 
# Makefile for the gear project.
#
# This file is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
#

PROJECT = gear
VERSION = $(shell sed '/^Version: */!d;s///;q' gear.spec)
PROGRAMS = gear gear-commit gear-release gear-srpmimport
MAN1PAGES = $(PROGRAMS:=.1)
TARGETS = gear-sh-functions $(MAN1PAGES)

bindir = /usr/bin
datadir = /usr/share
mandir = $(datadir)/man
man1dir = $(mandir)/man1
DESTDIR =

HELP2MAN1 = env PATH=":$$PATH" help2man -N -s1
INSTALL = install
LN_S = ln -s
MKDIR_P = mkdir -p
TOUCH_R = touch -r

.PHONY:	all install clean

all: $(TARGETS)

$(MAN1PAGES): gear-sh-functions

$(MAN7PAGES):

%: %.in
	sed \
		-e 's,@VERSION@,$(VERSION),g' \
		<$< >$@
	$(TOUCH_R) $< $@
	chmod --reference=$< $@

%.1: % %.1.inc gear-sh-functions
	$(HELP2MAN1) -i $@.inc ./$< >$@

install: all
	$(MKDIR_P) -m755 $(DESTDIR)$(bindir)
	$(INSTALL) -p -m755 gear-sh-functions $(PROGRAMS) $(DESTDIR)$(bindir)/
	$(MKDIR_P) -m755 $(DESTDIR)$(man1dir)
	$(INSTALL) -p -m644 $(MAN1PAGES) $(DESTDIR)$(man1dir)/

clean:
	$(RM) $(TARGETS) *~
