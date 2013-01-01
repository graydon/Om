/*!
\file
	\brief
		Om hpp file.
	\version
		0.1.1
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
#if !defined( Om_Element_ )
	#define Om_Element_ Om::Element

	#include "om/program.hpp"

namespace Om
{
	// MARK: - Om::Element
	/*!
	\brief
		An "elemental" Program comprised of a single item.
	*/
	struct Element
	:
	Program
	{
	public: // MARK: public (non-static)

		virtual ~Element() = 0;

		virtual bool operator ==( Element const & ) const = 0;

		virtual Program & operator *() = 0;

		virtual Program const & operator *() const = 0;

		Program * operator ->();

		Program const * operator ->() const;

		using Program::GetElementRange;

		/*!
		\return
			An Element range containing only this Element.
		*/
		virtual std::auto_ptr< Source< Element > > GetElementRange() = 0;

		/*!
		\return
			True if the Element could be merged.
		*/
		virtual bool Merge( Operator & );

		/*!
		\overload
		*/
		virtual bool Merge( Operator const & );

		/*!
		\overload
		*/
		virtual bool Merge( Separator & );

		/*!
		\overload
		*/
		virtual bool Merge( Separator const & );

	private: // MARK: private (non-static)

		Element & operator =( Element const & );
	};

	// MARK: - Om
	/*!
	\cond internal_symbols
	\return
		An owner pointer to a new copy.
	\note
		Required by boost#ptr_container classes.
	*/
	Element * new_clone( Element const & );
	/*!
	\endcond
	*/
}

	#include "om/element.cpp"
#endif