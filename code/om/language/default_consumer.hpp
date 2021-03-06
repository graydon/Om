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

#ifndef Om_Language_DefaultConsumer_

	#define Om_Language_DefaultConsumer_ \
	Om::Language::DefaultConsumer

	#include "om/language/consumer.hpp"

namespace Om {

	namespace Language {

		// MARK: - Om::Language::DefaultConsumer

		/*!
		\brief
			A partial implementation of Consumer.
		*/
		template <
			typename ThisImplementation,
			typename ThisInterface = Consumer
		>
		class DefaultConsumer:
		public ThisInterface {

		public: // MARK: public (non-static)

			virtual ~DefaultConsumer() = 0;

			virtual void TakeElement(Operand &);

			virtual void TakeElement(Operand const &);

			virtual void TakeElement(Operator &);

			virtual void TakeElement(Operator const &);

			virtual void TakeElement(Separator &);

			virtual void TakeElement(Separator const &);

			virtual void TakeElements(Producer &);

			virtual void TakeElements(Producer const &);

			virtual void TakeQuotedElements(Producer &);

			virtual void TakeQuotedElements(Producer const &);

		private: // MARK: private (non-static)

			DefaultConsumer & operator =(DefaultConsumer const &);

		};

	}

}

	#include "om/language/default_consumer.cpp"

#endif
