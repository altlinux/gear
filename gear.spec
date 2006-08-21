Name: gear
Version: 1.0.0
Release: alt1

Summary: Get Every Archive from git package Repository
License: GPL
Group: Development/Other
Packager: Dmitry V. Levin <ldv@altlinux.org>
BuildArch: noarch

Source: %name-%version.tar

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
* Tue Aug 22 2006 Dmitry V. Levin <ldv@altlinux.org> 1.0.0-alt1
- Initial revision.
