# Copyright (C) 2006-2007  Dmitry V. Levin <ldv@altlinux.org>

Name: gear
Version: 1.2.7
Release: alt1

Summary: Get Every Archive from git package Repository
License: GPL
Group: Development/Other
Packager: Dmitry V. Levin <ldv@altlinux.org>
BuildArch: noarch

Source: %name-%version.tar

# due to gear-srpmimport.
Requires: faketime

# due to git-commit --fast.
Requires: git-commit-fast

# due to git-diff-tree --no-ext-diff
Requires: git-core >= 0:1.5.3

# hasher>=1.0.30 supports tar packages made by gear utility.
Conflicts: hasher < 0:1.0.30

BuildPreReq: git-core, help2man

%description
This package contains a few utilities for managing gear repositories.
See %_docdir/%name-%version/QUICKSTART.ru_RU.KOI8-R for details.

%prep
%setup -q

%build
%make_build

%install
%make_install install DESTDIR=%buildroot

%files
%_bindir/*
%_mandir/man?/*
%doc QUICKSTART*

%changelog
* Tue Sep 18 2007 Dmitry V. Levin <ldv@altlinux.org> 1.2.7-alt1
- gear-srpmimport: Pass --fast option to git-commit (ldv).
- gear-update: Added --all and --exclude options (legion).

* Wed Aug 29 2007 Dmitry V. Levin <ldv@altlinux.org> 1.2.6-alt1
- gear-update (legion):
  + Added cpio* types support.
  + Allowed update of top directory.
- gear:
  + Robustify --commit (ldv).
- gear, gear-srpmimport, gear-update:
  + Run grep in C locale, run sort in C collation (ldv).
- gear-create-tag:
  + New utility, creates a signed release tag object (legion, ldv).

* Sun May 20 2007 Dmitry V. Levin <ldv@altlinux.org> 1.2.5-alt1
- gear-srpmimport:
  + Do not perform a noop merge (#11721).
  + Fixed import of archives with non-directory toplevel files.

* Tue Apr 10 2007 Dmitry V. Levin <ldv@altlinux.org> 1.2.4-alt1
- gear-sh-functions.in (chdir_to_toplevel): New function.
- gear, gear-srpmimport, gear-update: Use chdir_to_toplevel().
- gear-commit: Chdir to toplevel directory early.

* Mon Mar 12 2007 Dmitry V. Levin <ldv@altlinux.org> 1.2.3-alt1
- Added gear-rules(5) man page which describes the .gear-rules
  file format (vsu).

* Sun Mar 11 2007 Dmitry V. Levin <ldv@altlinux.org> 1.2.2-alt1
- Changed "git-COMMAND" style commands to "git COMMAND" style.
- gear-update: Suppressed "git rm" output.
- gear-update, gear-update-tag: Separated "git COMMAND"
  command-line options from lists of files where appropriate.
- QUICKSTART.ru_RU.KOI8-R:
  + Reworded git config recommendations using "git config" commands.
  + Updated examples.

* Sun Mar 04 2007 Dmitry V. Levin <ldv@altlinux.org> 1.2.1-alt1
- gear: Fixed suffix support (ldv, #11008).

* Wed Feb 28 2007 Dmitry V. Levin <ldv@altlinux.org> 1.2.0-alt1
- gear-update: New utility, replaces gear-update-archive and
  gear-update-directory (legion, ldv).
- gear-upload: Move to separate package, girar-utils (ldv).
- gear: Chdir to toplevel directory early (ldv).
- gear-srpmimport (ldv):
  + Chdir to toplevel directory early.
  + If --quiet option given, do commit and merge quietly.
  + Rename --no-untar option to --no-unpack.
  + Rewrite archive importer:
    - Use file(1) to recognize file types
      instead of suffix-based switch.
    - Handle zip archives.
    - Support arbitrary archive names.
- QUICKSTART.ru_RU.KOI8-R: Mention ~/.gitconfig (azol).

* Sat Dec 09 2006 Dmitry V. Levin <ldv@altlinux.org> 1.1.1-alt1
- gear-update-tag: Fix temporary directory removal (ldv).
- gear-update-tag: Treat "zip" directive as "tar" (raorn).
- gear: Implement suffix= option for tar-like rules (george).

* Wed Nov 22 2006 Dmitry V. Levin <ldv@altlinux.org> 1.1.0-alt1
- gear, gear-commit, gear-sh-functions.in:
  Reworked to implement .gear-rules "tags:" directive and
  .gear-tags directory support (vsu, raorn).
- gear-update-tag:
  New utility, updates list of stored tags
  in the package repository (vsu).
- gear-update-archive:
  Avoid loss of source files due to .gitignore (vsu).
- gear-release:
  Removed unneeded utility, the idea of release tags
  seems to be dead-end (ldv).
- Renamed info() to msg_info() to avoid ambiguity and
  unwanted package requirements (ldv).
- QUICKSTART.ru_RU.KOI8-R: Fix typos (#10229).
- gear-srpmimport:
  Removed implicit requirement for --branch (ldv, #10274).
- gear:
  Added keyword substitution in directory name (ldv, #10091).
  Replaced deprecated "git-tar-tree" with "git-archive --format=tar" (ldv).
  Implemented zip archive type support (raorn).
- gear-upload:
  New utility to ease initial upload of git repositories to git.alt (legion).

* Thu Oct 05 2006 Dmitry V. Levin <ldv@altlinux.org> 1.0.3-alt1
- Update copyright information.
- Add fresh git-core to package requirements.
- gear:
  + Process exclude directives without warnings (vsu).
- gear-sh-functions.in:
  + Fix checks for multiple specfiles (vsu).
- gear-release:
  + Create tags in refs/releases/ directory (ldv).
- gear-update-archive:
  + Fix old source removal (ldv).
  + Fix check for untracked or modified files (legion).
  + Implement top directory update (legion).
  + Fix destination directory validation (legion).
  + Fix typos (vsu).
- gear-hsh-build:
  + more flexible hasher support (raorn).
  + also pass --repo option to hasher (raorn).
  + honor "target" option from hasher config (raorn).
  + use $GIT_DIR/$CWD if no repositories given (raorn).
- Makefile:
  + Specify the program source for man pages (vsu).
  + Remove boldface from the NAME section of man pages (vsu).
- gear.1.inc:
  + Document operating modes of gear (vsu).
  + Document current limitations of gear (vsu).
- gear-commit.1.inc:
  + Fix short description (ldv).
- gear-update-archive.1.inc, gear-update-directory.1.inc:
  + Fix typos (vsu).

* Fri Sep 08 2006 Dmitry V. Levin <ldv@altlinux.org> 1.0.2-alt1
- gear:
  + New option: --update-spec (legion).
- gear-commit:
  + New option: --spec (legion).
- gear-release:
  + New option: --create (legion).
- gear-update:
  + Rename to gear-update-archive (legion).
- gear-hsh-build:
  + New utility (raorn).

* Mon Aug 28 2006 Dmitry V. Levin <ldv@altlinux.org> 1.0.1-alt1
- gear-release: Fix typo in option handling (legion).
- gear-update: New utility (legion, ldv).

* Tue Aug 22 2006 Dmitry V. Levin <ldv@altlinux.org> 1.0.0-alt1
- Initial revision.
