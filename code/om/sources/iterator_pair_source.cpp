/*!
\file
	\brief
		Om cpp file.
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
#if defined( Om_Sources_IteratorPairSource_ )

// MARK: Om::Sources::IteratorPairSource

	#define Template_ template< typename ThisItem, typename ThisIterator >

	#define Type_ Om::Sources::IteratorPairSource< ThisItem, ThisIterator >

// MARK: public (non-static)

Template_
inline Type_::IteratorPairSource(
	ThisIterator theStart,
	ThisIterator const theEnd
)
:
thisIterator( theStart ),
thisEnd( theEnd )
{
}

Template_
inline Type_ & Type_::operator =( IteratorPairSource theIteratorPairSource )
{
	this->Swap( theIteratorPairSource );
	return( *this );
}

Template_
inline bool Type_::operator ==( IteratorPairSource const & theSource ) const
{
	return( this->thisIterator == theSource.thisIterator );
}

Template_
inline bool Type_::operator !() const
{
	return( this->thisEnd == this->thisIterator );
}

Template_
inline ThisItem & Type_::operator *() const
{
	assert( this->thisEnd != this->thisIterator );
	return( *this->thisIterator );
}

Template_
inline void Type_::End()
{
	this->thisIterator = this->thisEnd;
}

Template_
inline void Type_::Pop()
{
	assert( this->thisEnd != this->thisIterator );
	++this->thisIterator;
}

Template_
inline void Type_::Swap( IteratorPairSource & theIteratorPairSource )
{
	boost::swap(
		this->thisIterator,
		theIteratorPairSource.thisIterator
	);
	boost::swap( this->thisEnd, theIteratorPairSource.thisEnd );
}

	#undef Type_
	#undef Template_

// MARK: -
// MARK: boost

template< typename ThisItem, typename ThisIterator >
inline void boost::swap(
	Om::Sources::IteratorPairSource< ThisItem, ThisIterator > & theFirst,
	Om::Sources::IteratorPairSource< ThisItem, ThisIterator > & theSecond
)
{
	theFirst.Swap( theSecond );
}

#else
	#include "om/sources/iterator_pair_source.hpp"
#endif
