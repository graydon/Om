/*!
\file
	\brief
		<a href="http://om-language.org">Om</a> header file.
	\version
		0.1.2
	\date
		2012-2013
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>.  All rights reserved.  This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#if !defined( Om_Operations_EnvironmentOperation_ )

	#define Om_Operations_EnvironmentOperation_ \
	Om::Operations::EnvironmentOperation

	#include "om/definition.hpp"

	#define Om_Operations_EnvironmentOperation_GetName_() \
	"environment"

namespace Om {
	namespace Operations {

		// MARK: - Om::Operations::EnvironmentOperation
		/*!
		\brief
			The \ref system_operation Operation implementation.
		*/
		struct EnvironmentOperation {
		public: // MARK: public (static)

			static char const * GetName();

			static void Give( Evaluation & );
		};

		namespace {
			static Definition< EnvironmentOperation > const theEnvironmentDefinition;
		}
	}
}

	#include "om/operations/environment_operation.cpp"

#endif
