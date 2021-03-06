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

#ifndef Om_Language_Operation_EqualsOperation_

	#include "om/language/operation/equals_operation.hpp"

	#ifdef Om_Macro_Test_

		#include "om/language/system.hpp"

		#ifndef Om_Macro_Precompilation_

			#include "boost/test/unit_test.hpp"

		#endif

namespace Om {

	namespace Language {

		namespace Operation {

			BOOST_AUTO_TEST_SUITE(EqualsOperationTest)

				BOOST_AUTO_TEST_CASE(DefinitionTest) {
					BOOST_CHECK_EQUAL(
						"{=}",
						System::Get().Evaluate("drop find {=} system")
					);
				}

				BOOST_AUTO_TEST_CASE(GeneralTest) {
					BOOST_CHECK_EQUAL(
						"{{A}}",
						System::Get().Evaluate("= {A} {A}")
					);

					BOOST_CHECK_EQUAL(
						"{}",
						System::Get().Evaluate("= {A} {Not A}")
					);

					BOOST_CHECK_EQUAL(
						"{{}}",
						System::Get().Evaluate("= {} {}")
					);

					BOOST_CHECK_EQUAL(
						"{}",
						System::Get().Evaluate("= {} {Not empty}")
					);
				}

			BOOST_AUTO_TEST_SUITE_END()

		}

	}

}

	#endif

#else

	#include "om/language/expression.hpp"

// MARK: - Om::Language::Operation::EqualsOperation

	#define Type_ \
	Om::Language::Operation::EqualsOperation

// MARK: public (static)

inline char const * Type_::GetName() {
	return Om_Language_Operation_EqualsOperation_GetName_();
}

template <typename TheEqualsOperation>
inline void Type_::GiveElements(
	TheEqualsOperation & theEqualsOperation,
	Consumer & theConsumer
) {
	theConsumer.TakeElement(
		GetOperator()
	);
	if (
		!theEqualsOperation.thisOperand.IsEmpty()
	) {
		theConsumer.TakeElement(theEqualsOperation.thisOperand);
	}
}

// MARK: public (non-static)

inline Type_::EqualsOperation():
thisOperand() {}

template <typename TheOperand>
inline bool Type_::TakeOperand(
	Evaluation & theEvaluation,
	TheOperand & theOperand
) {
	assert(
		!theOperand.IsEmpty()
	);
	if (
		this->thisOperand.IsEmpty()
	) {
		this->thisOperand.Take(theOperand);
		return false;
	}
	Expression theExpression;
	if (this->thisOperand == theOperand) {
		theExpression.TakeOperand(this->thisOperand);
	}
	theEvaluation.TakeQuotedProducer(theExpression);
	return true;
}

template <typename TheProducer>
inline bool Type_::TakeQuotedProducer(
	Evaluation & theEvaluation,
	TheProducer & theProducer
) {
	if (
		this->thisOperand.IsEmpty()
	) {
		this->thisOperand.SetProgram(
			theProducer.GiveProgram()
		);
		return false;
	}
	Expression theExpression;
	if (
		this->IsMatch(theProducer)
	) {
		theExpression.TakeOperand(this->thisOperand);
	}
	theEvaluation.TakeQuotedProducer(theExpression);
	return true;
}

// MARK: private (non-static)

template <typename TheProducer>
inline bool Type_::IsMatch(TheProducer & theProducer) const {
	assert(
		this->thisOperand.GetProgram()
	);
	Program const & theProgram = *this->thisOperand.GetProgram();
	Program const * const theProducerProgram = dynamic_cast<Program const *>(&theProducer);
	if (theProducerProgram) {
		return *theProducerProgram == theProgram;
	}
	Literal theProducerLiteral;
	theProducerLiteral.TakeElements(theProducer);
	return theProducerLiteral.Equals(theProgram);
}

	#undef Type_

#endif
