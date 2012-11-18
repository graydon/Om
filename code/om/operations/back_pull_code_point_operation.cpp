/*!
\file
	\brief
		Om cpp file.
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
#if defined( Om_Operations_BackPullCodePointOperation_ )

	#include "om/operations/pull_operation.hpp"

// MARK: Om::Operations::BackPullCodePointOperation

	#define Type_ Om::Operations::BackPullCodePointOperation

// MARK: public (static)

inline char const * Type_::GetName()
{
	return( Om_Operations_BackPullCodePointOperation_GetName_() );
}

inline void Type_::Give( Evaluation & theEvaluation )
{
	theEvaluation.TakeEvaluand(
		std::auto_ptr< Evaluand >(
			new PullOperation< Operator, BackPullCodePointOperation >
		)
	);
}

template< typename TheQueue >
inline void Type_::Pull( Operator & theOperator, TheQueue & theQueue )
{
	theOperator.BackGiveCodePoint( theQueue );
}

	#undef Type_

#else
	#include "om/operations/back_pull_code_point_operation.hpp"

	#if defined( Om_Macros_Test_ )

		#include "om/environment.hpp"
		#include "UnitTest++.h"

namespace Om
{
	namespace Operations
	{
		// MARK: -
		SUITE( BackPullCodePointOperation )
		{
			TEST( General )
			{
				CHECK_EQUAL(
					"{e}{1`{2`}thre}",
					Environment().Evaluate( "codepoints-> {1{2}three}" )
				);

				CHECK_EQUAL(
					"{` }{}",
					Environment().Evaluate( "codepoints-> {` }" )
				);

				CHECK_EQUAL(
					"{" "\xCC\x81" "}{a" "\xC3\x98" "}",
					Environment().Evaluate( "codepoints-> {a" "\xC7\xBE" "}" )
				);

				CHECK_EQUAL(
					"{` }{}",
					Environment().Evaluate( "codepoints-> { }" )
				);

				CHECK_EQUAL(
					"{}{}",
					Environment().Evaluate( "codepoints-> {}" )
				);

				CHECK_EQUAL(
					"codepoints->",
					Environment().Evaluate( "codepoints->" )
				);
			}

			TEST( MultiCodePointCharacter )
			{
				CHECK_EQUAL(
					(
						"{" "\xE1\x85\xA1" "}{"
							"\xE1\x86\xAB" "\xE1\x84\x80"
						"}"
					),
					Environment().Evaluate(
						"codepoints->"
						"{" "\xE1\x86\xAB" "\xE1\x84\x80" "\xE1\x85\xA1" "}"
					)
				);
			}
		}
	}
}

	#endif

#endif
