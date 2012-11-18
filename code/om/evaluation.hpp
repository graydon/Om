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
*/
#if !defined( Om_Evaluation_ )
	#define Om_Evaluation_ Om::Evaluation

	#include "om/expression.hpp"

namespace Om
{
	//! \cond
	struct Evaluator;
	//! \endcond

	// MARK: - Om::Evaluation
	/*!
	\brief
		The current state of an in-progress Operator resolution.

	Contains an Expression and a reference to an Evaluator, and prevents a more
	recursive evaluation algorithm that would overflow the stack in the event of
	a recursive Om program.

	Each Element that it takes is pushed onto a stack, resulting in a
	LIFO-ordered application of each Element to the Evaluator.  This is designed
	to be used from an Operator resolution algorithm.
	*/
	struct Evaluation
	{
	public: // MARK: public (non-static)

		virtual ~Evaluation();

		//! Constructs an Evaluation on the given Evaluator.
		explicit Evaluation( Evaluator & );

		//! Gives each Operand, if any, from the top of the Expression.
		void GiveOperands( Queue & );

		//! Gives the Operator, if any, from the top of the Expression.
		void GiveOperator( Queue & );

		template< typename TheEvaluand >
		void TakeEvaluand( std::auto_ptr< TheEvaluand > );

		template< typename TheOperand >
		void TakeOperand( TheOperand & );

		template< typename TheOperator >
		void TakeOperator( TheOperator & );

		template< typename TheQueue >
		void TakeQuotedQueue( TheQueue & );

		template< typename TheQueue >
		void TakeQueue( TheQueue & );

	private: // MARK: private (non-static)

		Evaluation( Evaluation const & );

		Evaluation const & operator =( Evaluation const & );

		//! The Expression.
		Expression thisExpression;

		//! The Evaluator.
		Evaluator & thisEvaluator;
	};
}

	#include "om/evaluation.cpp"
#endif
