/*!
\file
	\brief
		<a href="http://om-language.org">Om</a> header file.
	\version
		0.1.3
	\date
		2012-2014
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>. All rights reserved. This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.

\defgroup om__operation__separator_operation__ separator
	\ingroup om__operation__
	\brief
		Normalizes the \ref om__operand__ as a quoted \ref om__separator__.
	\par Implementation
		Om::Operation::SeparatorOperation
*/

#ifndef Om_Operation_SeparatorOperation_

	#define Om_Operation_SeparatorOperation_ \
	Om::Operation::SeparatorOperation

	#include "om/operation/program_operation.hpp"
	#include "om/system.hpp"

namespace Om {

	namespace Operation {

		/*!
		\brief
			The \ref om__operation__separator_operation__ operation implementation.
		*/
		typedef ProgramOperation<Separator> SeparatorOperation;

		namespace {

			static System::Definition<SeparatorOperation> const theSeparatorDefinition;

		}

	}

}

#endif
