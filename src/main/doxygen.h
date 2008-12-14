/*
   Copyright (C) 2001-2008 Graeme Walker <graeme_walker@users.sourceforge.net>
   
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

/* \htmlonly */

/*! \mainpage E-MailRelay Source code

This documentation has been generated by doxygen from the E-MailRelay's 
source code. The <a href="namespaces.html">Namespace List</a> is a good starting point
for browsing -- the detailed description section towards the end of each namespace
page gives a list of the namespace's key classes.

The E-MailRelay <a href="../developer.html">internals guide</a> gives an overview 
of the code structure, and there are a number of supporting diagrams:
<ul>
<li>GNet namespace <a href="../gnet-classes.png">class diagram</a></li>
<li>GSmtp namespace <a href="../gsmtp-classes.png">class diagram</a></li>
<li>Proxy-mode forwarding <a href="../sequence-3.png">sequence diagram</a></li>
<li>GNet::Client <a href="../gnet-client.png">state transition diagram</a></li>
<li>GSmtp::ServerProtocol <a href="../gsmtp-serverprotocol.png">state transition diagram</a></li>
<li><a href="../auth.png">Authentication usage</a></li>
</ul>

*/

/*! \namespace Main
\short 
Application-level classes.

The Main namespace contains application-level classes for
the E-MailRelay process.

Key classes are:
- Run
- CommandLine
- Configuration

 */

/*! \namespace GPop
\short 
POP3 classes.

The GPop namespace contains classes relating to the POP3
protocol.

Key classes are:
- Server
- ServerProtocol
- Store
- StoreLock

 */

/*! \namespace GSsl
\short 
TLS/SSL transport layer security classes.

The GSsl namespace contains classes that implement the TLS/SSL
security layer.

Key classes are:
- Protocol
- Library

 */

/*! \namespace GSmtp
\short 
SMTP and message-store classes.

The GSmtp namespace contains classes relating to the SMTP
protocol and to e-mail storage.

Key classes are:
- Client
- ClientProtocol
- ProtocolMessage
- MessageStore
- Server
- ServerProtocol

 */

/*! \namespace GAuth
\short 
SASL authentication classes.

The GAuth namespace contains classes relating to SASL
and PAM authentication.

Key classes are:
- SaslClient
- SaslServer
- SaslServerFactory
- Secrets

 */

/*! \namespace GNet
\short 
Network classes.

The GNet namespace contains network interface classes
based on the Berkley socket and WinSock system APIs.

Key classes are:
- Address
- EventHandler
- EventLoop
- MultiServer
- Resolver
- Server
- Socket
- Timer

*/

/*! \namespace G
\short 
Low-level classes.

The G namespace contains low-level classes for file-system abstraction, 
date and time representation, string utility functions, logging, 
command line parsing etc.

Key classes are:
- Directory
- File
- GetOpt
- Log
- LogOutput
- Path
- Process
- Str

*/

/*! \namespace md5
\short 
A standalone implementation of the MD5 hashing algorithm.

The md5 namespace is used for an implementation of the
RFC 1321 MD5 algorithm that is independent of the rest of 
the E-MailRelay library code.

Key classes are:
- digest_stream
- digest

*/

/* \endhtmlonly */
