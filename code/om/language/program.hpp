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

\defgroup om__program__ Program
	\brief
		A data type that presents as a list containing 0 or more elements.
	\par Implementation
		Each \ref om__program__ is a concrete implementation of Om::Language::Program.
*/

#ifndef Om_Language_Program_

	#define Om_Language_Program_ \
	Om::Language::Program

	#include "om/giveable.hpp"
	#include "om/language/consumer.hpp"
	#include "om/language/producer.hpp"
	#include "om/shareable.hpp"

namespace Om {

	//! \cond
	namespace Source {

		template <typename ThisItem>
		class Source;

	}
	//! \endcond

	namespace Language {

		//! \cond
		class Element;
		//! \endcond

		// MARK: - Om::Language::Program

		/*!
		\brief
			The \ref om__program__ implementation.

		A Program is a Giveable, Shareable Producer and Consumer whose entire state is represented by an Element collection.

		Each concrete derivation must have a GetName() function that returns a null-terminated, NFD-normalized UTF-8 string to be used as a corresponding Operator name.
		*/
		class Program:
		public Consumer,
		public Giveable,
		public Producer,
		public Shareable<> {

		public: // MARK: public (non-static)

			virtual ~Program() = 0;

			virtual void Clear() = 0;

			virtual bool Equals(Program const &) const = 0;

			/*!
			\return
				A non-null owner pointer to a new Element range.
			*/
			virtual std::auto_ptr<
				Om::Source::Source<Element const>
			> GetElementRange() const = 0;

			virtual std::auto_ptr<Program> GiveProgram();

			virtual std::auto_ptr<Program> GiveProgram() const;

			/*!
			\return
				True if there is no Element.
			*/
			virtual bool IsEmpty() const = 0;

		private: // MARK: private (non-static)

			Program & operator =(Program const &);

		};

		// MARK: - Om::Language::

		bool operator ==(
			Program const &,
			Program const &
		);

		bool operator !=(
			Program const &,
			Program const &
		);

	}

}

	#include "om/language/program.cpp"

#endif
