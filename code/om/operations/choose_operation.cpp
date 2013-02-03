/*!
\file
	\brief
		<a href="http://om-language.org">Om</a> source file.
	\version
		0.1.2
	\date
		2012-2013
	\copyright
		Copyright (c) <a href="http://sparist.com">Sparist</a>.  All rights reserved.  This program and the accompanying materials are made available under the terms of the <a href="http://www.eclipse.org/legal/epl-v10.html">Eclipse Public License, Version 1.0</a>, which accompanies this distribution.
	\authors
		Jason Erb - Initial API, implementation, and documentation.
*/

#if defined( Om_Operations_ChooseOperation_ )

	#include "om/literal.hpp"

// MARK: Om::Operations::ChooseOperation

	#define Type_ \
	Om::Operations::ChooseOperation

// MARK: public (static)

inline char const * Type_::GetName() {
	return( Om_Operations_ChooseOperation_GetName_() );
}

template< typename TheChooseOperation >
inline void Type_::GiveElements(
	TheChooseOperation & theChooseOperation,
	Queue & theQueue
) {
	theQueue.TakeElement( GetOperator() );
	if( 0 < theChooseOperation.thisOperandCount ) {
		theQueue.TakeElement( theChooseOperation.thisEmptyCase );
		if( 1 < theChooseOperation.thisOperandCount ) {
			theQueue.TakeElement( theChooseOperation.thisNonEmptyCase );
		}
	}
}

// MARK: public (non-static)

inline Type_::ChooseOperation():
thisEmptyCase(),
thisNonEmptyCase(),
thisOperandCount() {}

template< typename TheQueue >
inline bool Type_::TakeQuotedQueue(
	Evaluation & theEvaluation,
	TheQueue & theQueue
) {
	Operand theOperand( theQueue.GiveProgram() );
	return(
		this->TakeOperand(
			theEvaluation,
			theOperand
		)
	);
}

template< typename TheOperand >
inline bool Type_::TakeOperand(
	Evaluation & theEvaluation,
	TheOperand & theOperand
) {
	assert( !theOperand.IsEmpty() );
	assert( this->thisOperandCount < 3 );
	switch( this->thisOperandCount++ ) {
	case 0:
		this->thisEmptyCase.Take( theOperand );
		return( false );
	case 1:
		this->thisNonEmptyCase.Take( theOperand );
		return( false );
	default:
		{
			TheOperand const & theConstOperand = theOperand;
			theEvaluation.TakeOperand(
				theConstOperand.GetProgram()->IsEmpty()?
				this->thisEmptyCase:
				this->thisNonEmptyCase
			);
		}
		return( true );
	}
}

	#undef Type_

#else

	#include "om/operations/choose_operation.hpp"

	#if defined( Om_Macros_Test_ )

		#include "om/system.hpp"
		#include "UnitTest++.h"

// MARK: -
namespace Om {
	namespace Operations {
		SUITE( ChooseOperation ) {
			TEST( Definition ) {
				CHECK_EQUAL(
					"{choose}",
					System::Get().Evaluate( "drop find {choose} system" )
				);
			}

			TEST( General ) {
				CHECK_EQUAL(
					"{empty}",
					System::Get().Evaluate( "choose{empty}{non-empty}{}" )
				);

				CHECK_EQUAL(
					"{non-empty}",
					System::Get().Evaluate( "choose{empty}{non-empty}{some operators}" )
				);
			}
		}
	}
}

	#endif

#endif
