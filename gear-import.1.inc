.\" Copyright (C) 2009  Alexey Gladkov <legion@altlinux.org>
.\"
.\" Additional documentation for the gear-import command.
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
gear\-import \- import source code into repository

[DESCRIPTION]
The
.B gear\-import
allows to import a project sources from the archives into gear repository.
Each archive is added as subdirectory by individual commit and has the
tag with its version. Subdirectory name and tag name is calculated
from the archive name.

[ENVIRONMENT]
.TP
.B IMPORT_RULES
Specifies a custom gear-import rules filename.

[SEE ALSO]
.BR gear-update (1),
.BR gear-import-rules (5)
