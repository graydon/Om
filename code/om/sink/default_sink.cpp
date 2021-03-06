/*!
\file
	\brief
		<a href="http://github.com/sparist/Om">Om</a> source file.
	\version
		0.1.3
	\date
		2012-2014
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\author
		Jason Erb
*/

#ifndef Om_Sink_DefaultSink_

	#include "om/sink/default_sink.hpp"

#else

// MARK: - Om::Sink::DefaultSink

	#define Template_ \
	template < \
		typename ThisItem, \
		typename ThisImplementation \
	>

	#define Type_ \
	Om::Sink::DefaultSink< \
		ThisItem, \
		ThisImplementation \
	>

// MARK: public (non-static)

Template_
inline Type_::~DefaultSink() {}

Template_
inline ThisImplementation & Type_::operator ++() {
	assert(
		dynamic_cast<ThisImplementation *>(this)
	);
	return static_cast<ThisImplementation &>(*this);
}

Template_
inline ThisImplementation Type_::operator ++(int) {
	assert(
		dynamic_cast<ThisImplementation *>(this)
	);
	return static_cast<ThisImplementation &>(*this);
}

	#undef Type_
	#undef Template_

#endif
