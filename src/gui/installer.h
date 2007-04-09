//
// Copyright (C) 2001-2007 Graeme Walker <graeme_walker@users.sourceforge.net>
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later
// version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
// 
// ===
///
/// \file installer.h
///

#ifndef INSTALLER_H__
#define INSTALLER_H__

#include "gpath.h"
#include <string>

class InstallerImp ; 

/// \class Installer
/// A class that interprets a GPage configuration 
/// dump and then executes a series of installation tasks 
/// using an iteration interface.
///
class Installer 
{
public:
	explicit Installer( G::Path argv0 ) ;
		///< Constructor. Initialise with start().

	~Installer() ;
		///< Destructor.

	void start( std::istream & dump_stream ) ;
		///< Initialisation.

	bool next() ;
		///< Iterator. Returns true if there is something
		///< to run().

	std::string beforeText() ;
		///< Returns the current task description.

	std::string afterText() ;
		///< Returns the current task's status.

	void run() ;
		///< Runs the current task.

	bool done() const ;
		///< Returns true if next() returned false.

	bool failed() const ;
		///< Returns true if done() and failed.
		///< Precondition: done()

private:
	Installer( const Installer & ) ;
	void operator=( const Installer & ) ;
	void cleanup( const std::string & = std::string() ) ;

private:
	G::Path m_argv0 ;
	InstallerImp * m_imp ;
	std::string m_reason ;
} ;

#endif