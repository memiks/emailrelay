//
// Copyright (C) 2001-2010 Graeme Walker <graeme_walker@users.sourceforge.net>
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
//
// gverifierfactory_exec_disabled.cpp
//

#include "gdef.h"
#include "gsmtp.h"
#include "gfactoryparser.h"
#include "gexception.h"
#include "gverifierfactory.h"
#include "ginternalverifier.h"
#include <stdexcept>

std::string GSmtp::VerifierFactory::check( const std::string & s )
{
	if( !s.empty() )
		throw std::runtime_error( "external verifiers are not supported: not enabled at build-time" ) ;
	return std::string() ;
}

GSmtp::Verifier * GSmtp::VerifierFactory::newVerifier( const std::string & , unsigned int )
{
	return new InternalVerifier ;
}

/// \file gverifierfactory_exec_disabled.cpp
