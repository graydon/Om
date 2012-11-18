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
#if !defined( Om_DefaultCopyable_ )
	#define Om_DefaultCopyable_ Om::DefaultCopyable

	#include "om/copyable.hpp"

namespace Om
{
	// MARK: - Om::DefaultCopyable
	/*!
	\brief
		A partial implementation of Copyable.
	*/
	template< typename ThisImplementation, typename ThisInterface = Copyable >
	struct DefaultCopyable
	:
	ThisInterface
	{
		template< typename TheCopyable >
		friend std::auto_ptr< TheCopyable > Copy( TheCopyable const & );

	public: // MARK: public (non-static)

		virtual ~DefaultCopyable() = 0;

	private: // MARK: private (non-static)

		DefaultCopyable & operator =( DefaultCopyable const & );

		/*!
		\return
			An owner pointer to a copy.
		*/
		virtual ThisInterface * Copy() const;
	};
}

	#include "om/default_copyable.cpp"
#endif
