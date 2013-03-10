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

#ifndef Om_Operations_SystemOperation_

	#define Om_Operations_SystemOperation_ \
	Om::Operations::SystemOperation

	#include "om/definition.hpp"

	#define Om_Operations_SystemOperation_GetName_() \
	"system"

namespace Om {

	namespace Operations {

		// MARK: - Om::Operations::SystemOperation
		/*!
		\brief
			The \ref om__operations__system_operation__ operation implementation.
		*/
		class SystemOperation {
		public: // MARK: public (static)

			static char const * GetName();

			static void Give(Evaluation &);

		};

		namespace {

			static Definition<SystemOperation> const theSystemDefinition;

		}

	}

}

	#include "om/operations/system_operation.cpp"

#endif
