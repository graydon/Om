/*!
\file
	\brief
		<a href="http://om-language.org">Om</a> header file.
	\version
		0.1.2
	\date
		2012-2013
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>.  All rights reserved.  This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#if !defined( Om_Give_ )

	#define Om_Give_ \
	Om::Give

	#include "external.hpp"

// MARK: - Om
namespace Om {

	/*!
	\brief
		Calls #Move on the object.
	\return
		The resulting object.
	*/
	template< typename TheGiveable >
	std::auto_ptr< TheGiveable > Give( TheGiveable & );

	/*!
	\brief
		Transfers pointer ownership.
	\return
		The resulting object.
	*/
	template< typename TheGiveable >
	std::auto_ptr< TheGiveable > Give(
		std::auto_ptr< TheGiveable > &
	);

	/*!
	\brief
		Calls #Copy on the object.
	\return
		The resulting object.
	*/
	template< typename TheGiveable >
	std::auto_ptr< TheGiveable > Give( TheGiveable const & );

	/*!
	\brief
		Transfers pointer ownership.
	\return
		The resulting object.

	This is useful in situations where the argument auto_ptr is a member of a const class.
	*/
	template< typename TheGiveable >
	std::auto_ptr< TheGiveable > Give(
		std::auto_ptr< TheGiveable > const &
	);

}

	#include "om/give.cpp"

#endif