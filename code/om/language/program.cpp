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

#ifndef Om_Language_Program_

	#include "om/language/program.hpp"

#else

// MARK: - Om::Language::Program

	#define Type_ \
	Om::Language::Program

// MARK: public (non-static)

inline Type_::~Program() {}

inline void Type_::Clear() {
	assert(0);
	throw std::logic_error("Pure virtual function called.");
}

inline bool Type_::Equals(Program const &) const {
	assert(0);
	throw std::logic_error("Pure virtual function called.");
}

inline std::auto_ptr<
	Om::Source::Source<Om::Language::Element const>
> Type_::GetElementRange() const {
	assert(0);
	throw std::logic_error("Pure virtual function called.");
}

inline std::auto_ptr<Om::Language::Program> Type_::GiveProgram() {
	return Give(*this);
}

inline std::auto_ptr<Om::Language::Program> Type_::GiveProgram() const {
	return Give(*this);
}

inline bool Type_::IsEmpty() const {
	assert(0);
	throw std::logic_error("Pure virtual function called.");
}

// MARK: - Om::Language::

inline bool Om::Language::operator ==(
	Type_ const & theFirst,
	Type_ const & theSecond
) {
	return theFirst.Equals(theSecond);
}

inline bool Om::Language::operator !=(
	Type_ const & theFirst,
	Type_ const & theSecond
) {
	return !theFirst.Equals(theSecond);
}

	#undef Type_

#endif
