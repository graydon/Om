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

\defgroup om__operation__front_pull_character_operation__ <-[characters]
	\ingroup om__operation__
	\brief
		Pops the first character, quoted.
	\par Implementation
		Om::Language::Operation::FrontPullCharacterOperation
*/

#ifndef Om_Language_Operation_FrontPullCharacterOperation_

	#define Om_Language_Operation_FrontPullCharacterOperation_ \
	Om::Language::Operation::FrontPullCharacterOperation

	#include "om/language/system.hpp"

	#define Om_Language_Operation_FrontPullCharacterOperation_GetName_() \
	"<-[characters]"

namespace Om {

	namespace Language {

		namespace Operation {

			// MARK: - Om::Language::Operation::FrontPullCharacterOperation

			/*!
			\brief
				The \ref om__operation__front_pull_character_operation__ operation implementation.
			*/
			class FrontPullCharacterOperation {

			public: // MARK: public (static)

				static char const * GetName();

				static void Give(Evaluation &);

				/*!
				\brief
					The callback for PullOperation.
				*/
				template <typename TheConsumer>
				static void Pull(
					Operator &,
					TheConsumer &
				);

			};

			namespace {

				static System::Definition<FrontPullCharacterOperation> const theFrontPullCharacterDefinition;

			}

		}

	}

}

	#include "om/language/operation/front_pull_character_operation.cpp"

#endif
