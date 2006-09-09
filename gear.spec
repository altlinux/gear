Name: gear
Version: 1.0.2
Release: alt1

Summary: Get Every Archive from git package Repository
License: GPL
Group: Development/Other
Packager: Dmitry V. Levin <ldv@altlinux.org>
BuildArch: noarch

Source: %name-%version.tar

# due to gear-srpmimport.
Requires: faketime

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
