/*
   Copyright (C) 2001-2011 Graeme Walker <graeme_walker@users.sourceforge.net>
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or 
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//
// mingw.c
//
// A nasty little hack to create the files normally
// generated by microsoft's "mc" message compiler.
// There is currently no message compiler in mingw.
//

#include <stdio.h>

int main( int argc , char * argv [] )
{
	static unsigned int i , bin[] = { 
	0x03, 0x00, 0x00, 0x00, 0xe9, 0x03, 0x00, 0x40, 0xe9, 0x03, 0x00, 0x40, 0x28, 0x00, 0x00, 0x00 ,
	0xea, 0x03, 0x00, 0x80, 0xea, 0x03, 0x00, 0x80, 0x34, 0x00, 0x00, 0x00, 0xeb, 0x03, 0x00, 0xc0 ,
	0xeb, 0x03, 0x00, 0xc0, 0x40, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x25, 0x31, 0x21, 0x73 ,
	0x21, 0x0d, 0x0a, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x25, 0x31, 0x21, 0x73, 0x21, 0x0d, 0x0a, 0x00 ,
	0x0c, 0x00, 0x00, 0x00, 0x25, 0x31, 0x21, 0x73, 0x21, 0x0d, 0x0a, 0x00 } ;
	FILE * fp_rc = fopen( "messages.rc" , "wt" ) ;
	FILE * fp_bin = fopen( "MSG00001.bin" , "wb" ) ;
	if( !fp_rc || !fp_bin ) { fprintf( stderr , "%s: failed\n" , argv[0] ) ; return 1 ; }
	for( i = 0 ; i < (sizeof(bin)/sizeof(bin[0])) ; i++ ) fprintf( fp_bin , "%c" , (char)(bin[i]) ) ;
	fprintf( fp_rc , "LANGUAGE 0x9,0x1\n" ) ;
	fprintf( fp_rc , "1 11 MSG00001.bin\n" ) ;
	fclose( fp_rc ) ;
	fclose( fp_bin ) ;
	return 0 ;
}

