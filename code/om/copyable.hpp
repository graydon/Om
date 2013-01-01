/*!
\file
	\brief
		Om hpp file.
	\version
		0.1.1
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
#if !defined( Om_Copyable_ )
	#define Om_Copyable_ Om::Copyable

	#include "om/copy.hpp"

namespace Om
{
	// MARK: - Om::Copyable
	/*!
	\brief
		An object that can be passed to #Copy to be copied.
	*/
	struct Copyable
	{
		template< typename TheCopyable >
		friend std::auto_ptr< TheCopyable > Copy( TheCopyable const & );

	public: // MARK: public (non-static)

		virtual ~Copyable() = 0;

	private: // MARK: private (non-static)

		Copyable & operator =( Copyable const & );

		/*!
		\return
			An owner pointer to a copy.
		*/
		virtual Copyable * Copy() const = 0;
	};
}

	#include "om/copyable.cpp"
#endif