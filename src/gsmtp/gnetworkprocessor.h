//
// Copyright (C) 2001-2007 Graeme Walker <graeme_walker@users.sourceforge.net>
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
/// \file gnetworkprocessor.h
///

#ifndef G_SMTP_NETWORK_PROCESSOR_H
#define G_SMTP_NETWORK_PROCESSOR_H

#include "gdef.h"
#include "gsmtp.h"
#include "gprocessor.h"
#include "gclientptr.h"
#include "grequestclient.h"

/// \namespace GSmtp
namespace GSmtp
{
	class NetworkProcessor ;
}

/// \class GSmtp::NetworkProcessor
/// A Processor class that passes the name of a
/// message file to a remote process over the network.
///
class GSmtp::NetworkProcessor : public GSmtp::Processor 
{
public:
	NetworkProcessor( const std::string & , unsigned int connection_timeout , unsigned int response_timeout , 
		bool lazy = true ) ;
			///< Constructor. If lazy then the internal client object
			///< is retained from one start() request to the next.

	virtual ~NetworkProcessor() ;
		///< Destructor.

	virtual G::Signal1<bool> & doneSignal() ;
		///< From Processor.

	virtual void start( const std::string & path ) ;
		///< From Processor.

	virtual void abort() ;
		///< From Processor.

	virtual std::string text() const ;
		///< From Processor. 

	virtual bool cancelled() const ;
		///< From Processor.

	virtual bool repoll() const ;
		///< From Processor.

private:
	NetworkProcessor( const NetworkProcessor & ) ; // not implemented
	void operator=( const NetworkProcessor & ) ; // not implemented
	void clientEvent( std::string , std::string ) ;

private:
	G::Signal1<bool> m_done_signal ;
	GNet::ResolverInfo m_resolver_info ;
	unsigned int m_connection_timeout ;
	unsigned int m_response_timeout ;
	bool m_lazy ;
	GNet::ClientPtr<RequestClient> m_client ;
	std::string m_text ;
} ;

#endif
