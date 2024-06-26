.\" Copyright (C) 2006-2017  Alexey Gladkov <legion@altlinux.org>
.\" Copyright (C) 2006-2018  Dmitry V. Levin <ldv@altlinux.org>
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
gear\-commit \- invoke git\-commit using last changelog entry from spec file for commit message

[CONFIGURATION]
.TP
.B gear.commit.edit-message
If set to
.IR true ,
an editor is invoked for further editing of the generated commit message.
.br
If set to
.IR false ,
the generated commit message is used without invoking an editor.
.br
The default is
.IR true .
.TP
.B gear.commit.require-message-save
If set to
.IR true ,
requires the generated commit message to be edited and saved by the user;
If the user exits the editor without saving a modified commit message,
the commit is aborted.
.br
The default is
.IR false .

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
.TP
.B GEAR_COMMIT
.B gear\-commit
always exports \fBGEAR_COMMIT\fR=\fI1\fR to the environment.
.TP
.B GEAR_COMMIT_AMEND
If
.I \-\-amend
option is given,
.B gear\-commit
also exports \fBGEAR_COMMIT_AMEND\fR=\fI1\fR.

[SEE ALSO]
.BR gear (1),
.BR git\-config (1).
.BR git\-commit (1).
