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

#ifndef Om_Language_Producer_

	#include "om/language/producer.hpp"

#else

	#ifndef Om_Macro_Precompilation_

		#include <cassert>
		#include <stdexcept>

	#endif

// MARK: - Om::Language::Producer

	#define Type_ \
	Om::Language::Producer

// MARK: public (non-static)

inline Type_::~Producer() {}

inline void Type_::GiveElements(Consumer &) {
	assert(0);
	throw std::logic_error("Pure virtual function called.");
}

inline void Type_::GiveElements(Consumer &) const {
	assert(0);
	throw std::logic_error("Pure virtual function called.");
}

inline std::auto_ptr<Om::Language::Program> Type_::GiveProgram() {
	assert(0);
	throw std::logic_error("Pure virtual function called.");
}

inline std::auto_ptr<Om::Language::Program> Type_::GiveProgram() const {
	assert(0);
	throw std::logic_error("Pure virtual function called.");
}

	#undef Type_

#endif
