.\" Copyright (C) 2006-2007  Alexey Glagkov <legion@altlinux.org>
.\" Copyright (C) 2006-2008  Dmitry V. Levin <ldv@altlinux.org>
.\" Copyright (C) 2006-2007  Sergey Vlasov <vsu@altlinux.org>
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
gear\-update \- update subdirectory from source directory or archive file

[CONFIGURATION]
\fBgear\-update\fR reads following configuration options from git\-config:
.PP
gear.update.exclude\-pattern
.RS 4
default expression for \-\-pattern option.
.RE

[ENVIRONMENT]
.TP
.B GIT_DIR
If the
.B GIT_DIR
environment variable is set then it specifies a path to use instead of
the default for the base of the repository.

[SEE ALSO]
.BR gear (1),
.BR gear\-rules (5),
.BR git-config (1).
