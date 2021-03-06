/*!
\file
	\brief
		<a href="http://github.com/sparist/Om">Om</a> header file.
	\version
		0.1.3
	\date
		2012-2014
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\author
		Jason Erb

\defgroup om__operation__quote_operation__ quote
	\ingroup om__operation__
	\brief
		Encloses an \ref om__operand__ in braces.
	\par Input
		<tt>{A}</tt>
	\par Output
		<tt>{{A}}</tt>
	\par Implementation
		Om::Language::Operation::QuoteOperation
*/

#ifndef Om_Language_Operation_QuoteOperation_

	#define Om_Language_Operation_QuoteOperation_ \
	Om::Language::Operation::QuoteOperation

	#include "om/language/operation/default_incomplete_operation.hpp"
	#include "om/language/system.hpp"

	#define Om_Language_Operation_QuoteOperation_GetName_() \
	"quote"

namespace Om {

	namespace Language {

		namespace Operation {

			// MARK: - Om::Language::Operation::QuoteOperation

			/*!
			\brief
				The \ref om__operation__quote_operation__ operation implementation.
			*/
			class QuoteOperation:
			public DefaultIncompleteOperation<QuoteOperation> {

			public: // MARK: public (static)

				static char const * GetName();

				template <typename TheQuoteOperation>
				static void GiveElements(
					TheQuoteOperation &,
					Consumer &
				);

			public: // MARK: public (non-static)

				template <typename TheOperand>
				bool TakeOperand(
					Evaluation &,
					TheOperand &
				);

				template <typename TheProducer>
				bool TakeQuotedProducer(
					Evaluation &,
					TheProducer &
				);

			};

			namespace {

				static System::Definition<QuoteOperation> const theQuoteDefinition;

			}

		}

	}

}

	#include "om/language/operation/quote_operation.cpp"

#endif

