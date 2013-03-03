/*!
\file
	\brief
		<a href="http://om-language.org">Om</a> header file.
	\version
		0.1.2
	\date
		2012-2013
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#if !defined( Om_Sources_EmptySource_ )

	#define Om_Sources_EmptySource_ \
	Om::Sources::EmptySource

	#include "om/sources/default_source.hpp"

namespace Om {

	namespace Sources {

		// MARK: - Om::Sources::EmptySource
		/*!
		\brief
			An empty Source.
		*/
		template< typename ThisItem >
		class EmptySource:
		public DefaultSource<
			ThisItem,
			EmptySource< ThisItem >
		> {
		public: // MARK: public (static)

			static EmptySource & Get();

		public: // MARK: public (non-static)

			EmptySource();

			EmptySource & operator =( EmptySource );

			bool operator ==( EmptySource const & ) const;

			virtual bool operator !() const;

			virtual ThisItem & operator *() const;

			virtual void Pop();

			void Swap( EmptySource & );

		};

	}

}

// MARK: - boost
namespace boost {

	template< typename ThisItem >
	void swap(
		Om::Sources::EmptySource< ThisItem > &,
		Om::Sources::EmptySource< ThisItem > &
	);

}

	#include "om/sources/empty_source.cpp"

#endif
