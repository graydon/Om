/*!
\file
	\brief
		<a href="http://om-language.org">Om</a> source file.
	\version
		0.1.2
	\date
		2012-2013
	\copyright
		Copyright (c) Jason Erb. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#ifndef Om_Sources_CollectionBackSource_

	#include "om/sources/collection_back_source.hpp"

	#ifdef Om_Macros_Test_

		#ifndef Om_Macros_Precompilation_

			#include "boost/test/unit_test.hpp"

		#endif

namespace Om {

	namespace Sources {

		BOOST_AUTO_TEST_SUITE(CollectionBackSourceTest)

		BOOST_AUTO_TEST_SUITE_END()

	}

}

	#endif

#else

// MARK: - Om::Sources::CollectionBackSource

	#define Template_ \
	template < \
		typename ThisItem, \
		typename ThisIterator \
	>

	#define Type_ \
	Om::Sources::CollectionBackSource< \
		ThisItem, \
		ThisIterator \
	>

// MARK: public (non-static)

Template_
template <typename TheCollection>
inline Type_::CollectionBackSource(TheCollection & theCollection):
IteratorPairSource<
	ThisItem,
	ThisIterator
>(
	theCollection.rbegin(),
	theCollection.rend()
) {}

	#undef Type_
	#undef Template_

#endif