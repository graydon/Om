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

#if !defined( Om_Operations_BackPullPairOperation_ )

	#include "om/operations/back_pull_pair_operation.hpp"

	#if defined( Om_Macros_Test_ )

		#include "om/system.hpp"

		#if !defined( Om_Macros_Precompilation_ )

			#include "boost/test/unit_test.hpp"

		#endif

namespace Om {

	namespace Operations {

		BOOST_AUTO_TEST_SUITE( BackPullPairOperationTest )

			BOOST_AUTO_TEST_CASE( DefinitionTest ) {
				BOOST_CHECK_EQUAL(
					"{pairs->}",
					System::Get().Evaluate( "drop find {pairs->} system" )
				);
			}

			BOOST_AUTO_TEST_CASE( GeneralTest ) {
				BOOST_CHECK_EQUAL(
					"{4{5}}{1{2}}",
					System::Get().Evaluate( "pairs-> {1{2}4{5}}" )
				);

				BOOST_CHECK_EQUAL(
					"{2}{1}",
					System::Get().Evaluate( "pairs-> {1 2}" )
				);

				BOOST_CHECK_EQUAL(
					"{{2}}{}",
					System::Get().Evaluate( "pairs-> {{1}{2}}" )
				);

				BOOST_CHECK_EQUAL(
					"{}{}",
					System::Get().Evaluate( "pairs-> {}" )
				);

				BOOST_CHECK_EQUAL(
					"{only}{}",
					System::Get().Evaluate( "pairs-> {only}" )
				);

				BOOST_CHECK_EQUAL(
					"{{c}}{a{b}}",
					System::Get().Evaluate( "pairs->{a{b}{c}}" )
				);

				BOOST_CHECK_EQUAL(
					"{a{b}}{{c}}",
					System::Get().Evaluate( "pairs->{{c}a{b}}" )
				);
			}

			BOOST_AUTO_TEST_CASE( FlushTest ) {
				BOOST_CHECK_EQUAL(
					"pairs->",
					System::Get().Evaluate( "pairs->" )
				);
			}

		BOOST_AUTO_TEST_SUITE_END()

	}

}

	#endif

#else

	#include "om/lexicon.hpp"
	#include "om/operations/pull_operation.hpp"

// MARK: - Om::Operations::BackPullPairOperation

	#define Type_ \
	Om::Operations::BackPullPairOperation

// MARK: public (static)

inline char const * Type_::GetName() {
	return(
		Om_Operations_BackPullPairOperation_GetName_()
	);
}

inline void Type_::Give( Evaluation & theEvaluation ) {
	theEvaluation.TakeOperation(
		std::auto_ptr< Operation >(
			new PullOperation<
				Lexicon,
				BackPullPairOperation
			>
		)
	);
}

template< typename TheQueue >
inline void Type_::Pull(
	Lexicon & theLexicon,
	TheQueue & theQueue
) {
	theLexicon.BackGivePair( theQueue );
}

	#undef Type_

#endif
