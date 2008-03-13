.\" Copyright (C) 2008  Alexey Gladkov <legion@altlinux.org>
.\"
.\" Additional documentation for the gear-remote command.
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
gear-remote \- run gear build command on the remote host

[DESCRIPTION]
Utility transfers sources into <hostname> and used <workdir>
as working directory to build sources. Results tranfered into <OUTDIR>
after build complete. Remote data do not removed by default and next
data transmission will occur more quickly.

[SEE ALSO]
.BR gear (1)
