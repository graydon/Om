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

#ifndef Om_Language_Operation_EnvironmentOperation_

	#include "om/language/operation/environment_operation.hpp"

	#ifdef Om_Macro_Test_

		#include "om/language/system.hpp"

		#ifndef Om_Macro_Precompilation_

			#include "boost/test/unit_test.hpp"

		#endif

namespace Om {

	namespace Language {

		namespace Operation {

			BOOST_AUTO_TEST_SUITE(EnvironmentOperationTest)

				BOOST_AUTO_TEST_CASE(DefinitionTest) {
					BOOST_CHECK_EQUAL(
						"{environment}",
						System::Get().Evaluate("drop find {environment} system")
					);
				}

				BOOST_AUTO_TEST_CASE(GeneralTest) {
					BOOST_CHECK_EQUAL(
						"{pass}",
						System::Get().Evaluate(
							"choose"
							" {fail}"
							" {pass}"
							" = define {a{A}} {environment} [lexicon]<- {a{A}} system"
						)
					);
				}

			BOOST_AUTO_TEST_SUITE_END()

		}

	}

}

	#endif

#else

// MARK: - Om::Language::Operation::EnvironmentOperation

	#define Type_ \
	Om::Language::Operation::EnvironmentOperation

// MARK: public (static)

inline char const * Type_::GetName() {
	return Om_Language_Operation_EnvironmentOperation_GetName_();
}

inline void Type_::Give(Evaluation & theEvaluation) {
	Lexicon theLexicon;
	theEvaluation.GetTranslator().GiveElements(theLexicon);
	theEvaluation.TakeQuotedProducer(theLexicon);
}

	#undef Type_

#endif
