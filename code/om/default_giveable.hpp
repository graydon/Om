/*!
\file
	\brief
		Om hpp file.
	\version
		0.1
	\date
		2012
	\copyright
		Copyright (c) Jason Erb.
		All rights reserved.  This program and the accompanying materials are
		made available under the terms of the
		<a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse
		Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/
#if !defined( Om_DefaultGiveable_ )
	#define Om_DefaultGiveable_ Om::DefaultGiveable

	#include "om/default_copyable.hpp"
	#include "om/default_moveable.hpp"
	#include "om/giveable.hpp"

namespace Om
{
	// MARK: - Om::DefaultGiveable
	/*!
	\brief
		A partial implementation of Giveable.
	*/
	template< typename ThisImplementation, typename ThisInterface = Giveable >
	struct DefaultGiveable
	:
	DefaultMoveable<
		ThisImplementation,
		DefaultCopyable< ThisImplementation, ThisInterface >
	>
	{
	public:  // MARK: public (non-static)

		virtual ~DefaultGiveable() = 0;

	private: // MARK: private (non-static)

		DefaultGiveable & operator =( DefaultGiveable const & );
	};
}

	#include "om/default_giveable.cpp"
#endif
