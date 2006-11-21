.\" Copyright (C) 2006  Dmitry V. Levin <ldv@altlinux.org>
.\" Copyright (C) 2006  Sergey Vlasov <vsu@altlinux.org>
.\"
.\" Additional documentation for the gear command.
.\"
.\" This file is free software; you can redistribute it and/or modify
.\" it under the terms of the GNU General Public License as published by
.\" the Free Software Foundation; either version 2 of the License, or
.\" (at your option) any later version.
.\"
.\" This program is distributed in the hope that it will be useful,
.\" but WITHOUT ANY WARRANTY; without even the implied warranty of
.\" MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
.\" GNU General Public License for more details.
.\"
.\" You should have received a copy of the GNU General Public License
.\" along with this program; if not, write to the Free Software
.\" Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.

[NAME]
gear \- Get Every Archive from git package Repository

[USAGE]
\fBgear\fR can perform several different operations, one of
which is selected by command line options.
.SS "Create a tar archive with source files"
When no options which specify another operation are
specified, \fBgear\fR requires a single non-option argument
\fIoutput-tarball-name\fR.  In this mode \fBgear\fR extracts
source files from the repository and packs them into a tar
archive with the specified name.  By default the archive is
compressed with \fBgzip\fR; this may be changed with the
\fB\-\-no\-compress\fR or \fB\-\-bzip2\fR options.
.SS "Extract source files to a directory"
When the \fB\-\-export\-dir\fR=\fIdirname\fR option is
specified, \fBgear\fR does not accept any non-option
arguments.  In this mode \fBgear\fR extracts source files
from the repository and puts them into the specified
directory.
.SS "Execute hsh-like command"
When the \fB\-\-hasher\fR option is specified, \fBgear\fR
requires one or more non-option arguments
\fIhsh-command\fR..., which specify the command to execute
and parameters for it.  In this mode \fBgear\fR extracts
source files from the repository, creates a temporary tar
archive with these files and invokes \fIhsh-command\fR,
appending the archive file name to its parameters.  When
\fIhsh-command\fR completes, \fBgear\fR removes the
temporary tar archive.
.SS "Execute rpmbuild-like command"
When the \fB\-\-rpmbuild\fR option is specified, \fBgear\fR
requires one or more non-option arguments
\fIrpmbuild-command\fR..., which specify the command to
execute and parameters for it.  In this mode \fBgear\fR
extracts source files from the repository to a temporary
directory and invokes \fIrpmbuild-command\fR, appending the
following parameters to it:
.RS 4
.PP
\-\-define "_specdir \fI$dir\fR"
\-\-define "_sourcedir \fI$dir\fR"
"\fI$spec\fR"
.RE
.PP
where \fI$dir\fR is the name of the temporary directory, and
\fI$spec\fR is the full name of the extracted spec file.
When \fIrpmbuild-command\fR completes, \fBgear\fR optionally
copies the spec file from the temporary directory to the
working copy of the repository (if requested by the
\fB\-\-update\-spec\fR option), and then removes the
temporary source directory.
.SS "Describe the package"
When the \fB\-\-describe\fR options is specified, \fBgear\fR
does not accept any non-option arguments.  In this mode
\fBgear\fR just prints the package name, version and release
strings found in the spec file, and does not proceed to
extract source files from the repository.

[ENVIRONMENT]
.TP
.B GIT_DIR
If the
.B GIT_DIR
environment variable is set then it specifies a path to use instead of
the default for the base of the repository.

[BUGS]
\fBgear\fR does not get correct package name, version and
release from spec files which use RPM macros to define these
fields.
.PP
\fBgear \-\-commit\fR loses the merge information saved by
\fBgit\-merge\fR.

[SEE ALSO]
.BR gear-commit (1),
.BR gear-srpmimport (1),
.BR hsh (1),
.BR git (7),
.BR rpmbuild (8).
