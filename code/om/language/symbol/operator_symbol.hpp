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
*/

#ifndef Om_Language_Symbol_OperatorSymbol_

	#define Om_Language_Symbol_OperatorSymbol_ \
	Om::Language::Symbol::OperatorSymbol

	#include "om/macro.hpp"

	/*!
	\brief
		Gets the bare hexadecimal code for Om::Language::Symbol::theEncodeOperatorSymbol.
	*/
	#define Om_Language_Symbol_OperatorSymbol_GetEncodeHex_() \
	60

	/*!
	\brief
		A string literal representation of Om::Language::Symbol::theEncodeOperatorSymbol.
	*/
	#define Om_Language_Symbol_OperatorSymbol_GetEncodeString_() \
	Om_Macro_GetString_( \
		Om_Language_Symbol_OperatorSymbol_GetEncodeHex_() \
	)

namespace Om {

	namespace Language {

		namespace Symbol {

			/*!
			\brief
				An Operator symbol.
			*/
			enum OperatorSymbol {

				/*!
				Encodes the next #CodePoint as an Operator #CodePoint. Redundant when followed by a non-symbol #CodePoint.
				*/
				theEncodeOperatorSymbol = Om_Macro_GetNumber_(
					Om_Language_Symbol_OperatorSymbol_GetEncodeHex_()
				)

			};

		}

	}

}

#endif
