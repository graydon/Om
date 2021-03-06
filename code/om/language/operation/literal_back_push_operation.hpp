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

\defgroup om__operation__literal_back_push_operation__ [literal]<-
	\ingroup om__operation__
	\brief
		Pushes the contents of an \ref om__operand__ onto the back of a \ref om__literal__ (quoted).
	\par Input
		<tt>{A} {B}</tt>
	\par Output
		<tt>{BA}</tt>
	\par Implementation
		Om::Language::Operation::LiteralBackPushOperation
*/

#ifndef Om_Language_Operation_LiteralBackPushOperation_

	#define Om_Language_Operation_LiteralBackPushOperation_ \
	Om::Language::Operation::LiteralBackPushOperation

	#include "om/language/system.hpp"

	#define Om_Language_Operation_LiteralBackPushOperation_GetName_() \
	"[literal]<-"

namespace Om {

	namespace Language {

		namespace Operation {

			// MARK: - Om::Language::Operation::LiteralBackPushOperation

			/*!
			\brief
				The \ref om__operation__literal_back_push_operation__ operation implementation.
			*/
			class LiteralBackPushOperation {

			public: // MARK: public (static)

				static char const * GetName();

				static void Give(Evaluation &);

			};

			namespace {

				static System::Definition<LiteralBackPushOperation> const theLiteralBackPushDefinition;

			}

		}

	}

}

	#include "om/language/operation/literal_back_push_operation.cpp"

#endif
