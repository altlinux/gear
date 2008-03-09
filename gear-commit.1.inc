.\" Copyright (C) 2006-2008  Alexey Gladkov <legion@altlinux.org>
.\" Copyright (C) 2006  Dmitry V. Levin <ldv@altlinux.org>
.\" Copyright (C) 2006  Sergey Vlasov <vsu@altlinux.org>
.\"
.\" Additional documentation for the gear-commit command.
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
gear\-commit \- invoke git\-commit using last changelog entry from spec file as commit message

[OPTIONS]
.TP
.B --spec=FILE
don't search specfile in repository and use a
.B <FILE>
instead;
.TP
.B -m, --message=TEXT
use the given
.B <TEXT>
as the commit message;
.TP
.B -V, --version
print program version and exit;
.TP
.B -h, --help
show this text and exit.

[ENVIRONMENT]
.TP
.B GIT_DIR
If the
.B GIT_DIR
environment variable is set then it specifies a path to use instead of
the default for the base of the repository.
.TP
.B RULES
Specifies a gear rules filename.
.TP
.B TREE_ID
Specifies a commit-ish git object where to look for spec file.

[SEE ALSO]
.BR gear (1),
.BR git-commit (1).
