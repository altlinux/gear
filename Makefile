#
# Copyright (C) 2006-2010  Dmitry V. Levin <ldv@altlinux.org>
# Copyright (C) 2006-2011  Alexey Gladkov <legion@altlinux.org>
# Copyright (C) 2006,2009  Alexey I. Froloff <raorn@altlinux.org>
# Copyright (C) 2006-2007  Sergey Vlasov <vsu@altlinux.org>
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
PROGRAMS = \
	gear \
	gear-buildreq \
	gear-changelog \
	gear-commit \
	gear-create-tag \
	gear-edit-spec \
	gear-hsh \
	gear-hsh-build \
	gear-import \
	gear-merge \
	gear-mock \
	gear-remote \
	gear-remote-hsh \
	gear-remote-rpm \
	gear-rpm \
	gear-srpmimport \
	gear-store-tags \
	gear-update \
	#
HELPERS = \
	gear-changelog-deb \
	gear-changelog-gnu \
	gear-changelog-rpm \
	gear-command-hasher \
	gear-command-mock \
	gear-command-remote-build \
	gear-command-rpmbuild \
	gear-command-tar \
	gear-update-sh-functions \
	gear-update-src-cpio \
	gear-update-src-cpio.bz2 \
	gear-update-src-cpio.gz \
	gear-update-src-cpio.xz \
	gear-update-src-cpio.zst \
	gear-update-src-dir \
	gear-update-src-gem \
	gear-update-src-tar \
	gear-update-src-zip \
	#
DATAFILES = gear-import-rules
MAN1PAGES = $(PROGRAMS:=.1)
MAN5PAGES = gear-rules.5 gear-merge-rules.5 gear-changelog-rules.5 \
	    gear-import-rules.5
MANPAGES = $(MAN1PAGES) $(MAN5PAGES)
HTMLPAGES = $(MANPAGES:=.html)
TARGETS = gear-sh-functions gear-import $(MANPAGES)

bindir = /usr/bin
datadir = /usr/share
geardatadir = $(datadir)/$(PROJECT)
mandir = $(datadir)/man
man1dir = $(mandir)/man1
man5dir = $(mandir)/man5
DESTDIR =

CP = cp -a
HELP2MAN1 = env PATH=":$$PATH" help2man -N -s1 -S '$(PROJECT) $(VERSION)'
INSTALL = install
LN_S = ln -s
MAN2HTML = man2html -r
MKDIR_P = mkdir -p
TOUCH_R = touch -r
CHMOD = chmod

.PHONY:	all check install verify clean

all: $(TARGETS)

$(MAN1PAGES): gear-sh-functions

$(MAN7PAGES):

%: %.in
	sed \
		-e 's,@VERSION@,$(VERSION),g' \
		-e 's,@geardatadir@,$(geardatadir),g' \
		<$< >$@
	$(TOUCH_R) $< $@
	chmod --reference=$< $@

%.1: % %.1.inc gear-sh-functions
	$(HELP2MAN1) -i $@.inc ./$< >$@

%.html: %
	$(MAN2HTML) $< >$@
	sed -i -e '/^Content-type: /d' -e '/^Time: /d' -e '/index\.html/d' \
		-e 's|HREF="\.\./man./gear|HREF="gear|g' \
		-e 's|<A HREF="\.\./man./[^/]\+\.html">\([^<]\+\)</A>|\1|g' \
		-e 's|<A HREF="mailto:[^"]\+">\([^@<]\+@[^<]\+\)</A>|\1|' \
		-e 's|\(@altlinux\)\.[a-z]\+|\1|' \
		-e 's|.*\(man2html\).*|\1|' \
		$@

html: $(HTMLPAGES)

check: tests/run
	cd tests && ./run

install: all
	$(MKDIR_P) -m755 $(DESTDIR)$(bindir)
	$(INSTALL) -p -m644 gear-sh-functions $(DESTDIR)$(bindir)/
	$(CHMOD) 755 $(PROGRAMS) $(HELPERS)
	$(CP) $(PROGRAMS) $(HELPERS) $(DESTDIR)$(bindir)/
	$(MKDIR_P) -m755 $(DESTDIR)$(man1dir)
	$(INSTALL) -p -m644 $(MAN1PAGES) $(DESTDIR)$(man1dir)/
	$(MKDIR_P) -m755 $(DESTDIR)$(man5dir)
	$(INSTALL) -p -m644 $(MAN5PAGES) $(DESTDIR)$(man5dir)/
	$(MKDIR_P) -m755 $(DESTDIR)$(geardatadir)
	$(INSTALL) -p -m644 $(DATAFILES) $(DESTDIR)$(geardatadir)/

# See https://github.com/koalaman/shellcheck/wiki/SC1090 for more information.
SHELLCHECK_EXCLUDE =
SHELLCHECK_EXCLUDE += SC1090 # ShellCheck is not able to include sourced files from paths that are determined at runtime.
SHELLCHECK_EXCLUDE += SC1091 # ShellCheck, for whichever reason, is not able to access the source file.
SHELLCHECK_EXCLUDE += SC2004 # $/${} is unnecessary on arithmetic variables.
SHELLCHECK_EXCLUDE += SC2006 # Use $(...) notation instead of legacy backticked `...`.
SHELLCHECK_EXCLUDE += SC2015 # Note that A && B || C is not if-then-else.
SHELLCHECK_EXCLUDE += SC2034 # Variable appears unused. Verify it or export it.
SHELLCHECK_EXCLUDE += SC2035 # Use ./*glob* or -- *glob* so names with dashes won't become options.
SHELLCHECK_EXCLUDE += SC2086 # Double quote to prevent globbing and word splitting.
SHELLCHECK_EXCLUDE += SC2103 # Use a ( subshell ) to avoid having to cd back.
SHELLCHECK_EXCLUDE += SC2119 # Use foo "$@" if function's $1 should mean script's $1.
SHELLCHECK_EXCLUDE += SC2120 # function references arguments, but none are ever passed.
SHELLCHECK_EXCLUDE += SC2154 # var is referenced but not assigned.
SHELLCHECK_EXCLUDE += SC2163 # export takes a variable name, but you give it an expanded variable instead.

verify:
	exclude="$$(printf '%s,' $(SHELLCHECK_EXCLUDE))"; \
	exclude="$${exclude%,}"; \
	for f in *; do \
	    [ -e "$$f" ] || continue; \
	    ftype=$$(file -b "$$f"); \
	    [ -n "$${ftype##*shell script*}" ] || \
	    shellcheck -s dash $${exclude:+-e $$exclude} "$$f"; \
	done

clean:
	$(RM) $(TARGETS) $(HTMLPAGES) *~
