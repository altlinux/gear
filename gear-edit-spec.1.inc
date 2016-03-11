.\" Copyright (C) 2016  Gleb Fotengauer-Malinovskiy <glebfm@altlinux.org>
.\"
.\" Additional documentation for the gear-edit-spec command.
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
.\" along with this program.  If not, see <http://www.gnu.org/licenses/>.

[NAME]
gear\-edit\-spec \- invoke editor for specfile

[ENVIRONMENT]
.TP
.B EDITOR, VISUAL
If either
.B EDITOR
or
.B VISUAL
environment variable is set then it specifies the program
to invoke instead of default vim(1).
