//
// Copyright (C) 2001-2008 Graeme Walker <graeme_walker@users.sourceforge.net>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or 
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ===
///
/// \file make-setup.sh
///
#!/bin/sh
#
# make-setup.sh
#
# Builds a "setup" self-extracting archive derived from running 
# "make install" into a temporary directory.
#
# usage: make-setup.sh [-d] <output> <gui> <pack>
#
# Normally run by "make setup" in the "src/gui".
#
# The packed files are those that appear under "/usr", which 
# matches the default installation directory presented in the 
# gui (see Dir::os_install()).
#
# There is only one level of packing, so the gui executable 
# should be statically linked or repacked with its shared 
# libraries if targeting other machines.
#

# parse the command line
debug="0" ; if test "$1" = "-d" ; then shift ; debug="1" ; fi
setup="$1"
gui="$2"
pack="$3"

# define temporary directories and cleanup code
tmp="/tmp/`basename $0 .sh`.$$.tmp"
install="$tmp/install"
list="$tmp/list"
trap Cleanup 0 
trap Fail 1 2 3 13 15
Cleanup()
{
	if test "$debug" -eq 0
	then
		rm -rf "$tmp"
	fi
}
Fail()
{
	Cleanup
	exit 1
}

# check the command-line
if test "$setup" = "" -o ! -x "$gui" -o ! -x "$pack"
then
	echo usage: `basename $0` '<setup> <gui> <pack>' >&2
	exit 2
fi

# run "make install"
echo `basename $0`: running make install into $install
mkdir -p $install
( cd ../.. && make install HAVE_DOXYGEN=no DESTDIR=$install ) > /dev/null 2>&1

# build a file list
Filter()
{
	fgrep -v /doxygen/ | fgrep -v /emailrelay-gui
}
Edit()
{
	sed 's: \./: :' | sed 's: etc/: \$etc/:' | sed 's: usr/: :'
}
find $install -type f | Filter | grep -n . | sed 's/:/1 /' > $list
( cd $install && find . -type f ) | Filter | grep -n . | sed 's/:/2 /' | Edit >> $list
sort -n $list | sed 's/^[0-9][0-9]* //' > $list.tmp && mv $list.tmp $list

# create the packed file
PATH=".:$PATH"
$pack -q -f "$list" $setup $gui

