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

#if !defined( Om_Operations_BackPullSeparatorOperation_ )

	#define Om_Operations_BackPullSeparatorOperation_ \
	Om::Operations::BackPullSeparatorOperation

	#include "om/definition.hpp"

	#define Om_Operations_BackPullSeparatorOperation_GetName_() \
	"elements->separator"

namespace Om {

	//! \cond
	class Literal;
	//! \endcond

	namespace Operations {

		// MARK: - Om::Operations::BackPullSeparatorOperation
		/*!
		\brief
			The \ref back_pull_separator_operation Operation implementation.
		*/
		class BackPullSeparatorOperation {
		public: // MARK: public (static)

			static char const * GetName();

			static void Give( Evaluation & );

			/*!
			\brief
				The callback for PullOperation.
			*/
			template< typename TheQueue >
			static void Pull(
				Literal &,
				TheQueue &
			);

		};

		namespace {

			static Definition< BackPullSeparatorOperation > const theBackPullSeparatorDefinition;

		}

	}

}

	#include "om/operations/back_pull_separator_operation.cpp"

#endif