/*!
\file
	\brief
		Om hpp file.
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

\defgroup back_pull_separator_operation elements->separator
	\ingroup operations
	\brief
		Casts to \ref literal and pops the last \ref separator (if any), quoted.
	\par Input
		<tt>{A B }</tt>
	\par Output
		<tt>{ } {A B}</tt>
	\par Implementation
		Om#Operations#BackPullSeparatorOperation
*/
#if !defined( Om_Operations_BackPullSeparatorOperation_ )
	#define Om_Operations_BackPullSeparatorOperation_ \
	Om::Operations::BackPullSeparatorOperation

	#include "om/definition.hpp"

	#define Om_Operations_BackPullSeparatorOperation_GetName_() \
	"elements->separator"

namespace Om
{
	//! \cond
	struct Literal;
	//! \endcond

	namespace Operations
	{
		// MARK: - Om::Operations::BackPullSeparatorOperation
		/*!
		\brief
			The \ref back_pull_separator_operation Operation implementation.
		*/
		struct BackPullSeparatorOperation
		{
		public: // MARK: public (static)

			static char const * GetName();

			static void Give( Evaluation & );

			//! The callback for PullOperation.
			template< typename TheQueue >
			static void Pull( Literal &, TheQueue & );
		};

		namespace
		{
			static Definition<
				BackPullSeparatorOperation
			> const theBackPullSeparatorDefinition;
		}
	}
}

	#include "om/operations/back_pull_separator_operation.cpp"
#endif
