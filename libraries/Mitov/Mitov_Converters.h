////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//     This software is supplied under the terms of a license agreement or    //
//     nondisclosure agreement with Mitov Software and may not be copied      //
//     or disclosed except in accordance with the terms of that agreement.    //
//         Copyright(c) 2002-2015 Mitov Software. All Rights Reserved.        //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#ifndef _MITOV_CONVERTERS_h
#define _MITOV_CONVERTERS_h

#include <Mitov.h>

namespace Mitov
{
//---------------------------------------------------------------------------
	class IntegerToAnalog : public CommonFilter
	{
		typedef CommonFilter inherited;

	public:
		float	Scale;

	protected:
		virtual void DoReceive( void *_Data )
		{
			float AFloatValue = ( *(long*)_Data ) * Scale;
			OutputPin.Notify( &AFloatValue );
		}

	public:
		IntegerToAnalog() : Scale( 1.0 )
		{
		}
	};
//---------------------------------------------------------------------------
	class AnalogToInteger : public CommonFilter
	{
		typedef CommonFilter inherited;

	public:
		bool	Round;

	protected:
		virtual void DoReceive( void *_Data )
		{
			float AFloatValue = *(float*)_Data;
			if( Round )
				AFloatValue += 0.5f;

			long AIntValue = AFloatValue;
			OutputPin.Notify( &AIntValue );
		}

	public:
		AnalogToInteger() : Round( true )
		{
		}
	};
//---------------------------------------------------------------------------
	class AnalogToText : public CommonFilter
	{
		typedef CommonFilter inherited;

	public:
		int	MinWidth;
		int	Precision;

	protected:
		virtual void DoReceive( void *_Data )
		{
			float AFloatValue = *(float*)_Data;
			char AText[ 50 ];
			dtostrf( AFloatValue,  MinWidth, Precision, AText );
			OutputPin.Notify( AText );
		}

	public:
		AnalogToText() :
			MinWidth( 1 ),
			Precision( 3 )
		{
		}
	};
//---------------------------------------------------------------------------
	class IntegerToText : public CommonFilter
	{
		typedef CommonFilter inherited;

	public:
		int	Base;

	protected:
		virtual void DoReceive( void *_Data )
		{
			long AValue = *(long*)_Data;
			char AText[ 50 ];
			itoa( AValue, AText, Base );
			OutputPin.Notify( AText );
		}

	public:
		IntegerToText() :
			Base( 10 )			
		{
		}
	};
//---------------------------------------------------------------------------
	class DigitalToText : public CommonFilter
	{
		typedef CommonFilter inherited;

	public:
		String	TextTrue;
		String	TextFalse;

	protected:
		virtual void DoReceive( void *_Data )
		{
			bool AValue = *(bool *)_Data;
			const char *AText;
			if( AValue )
				AText = TextTrue.c_str();

			else
				AText = TextFalse.c_str();

			OutputPin.Notify( (void*)AText );
		}

	public:
		DigitalToText() :
			TextTrue( "true" ),
			TextFalse( "false" )
		{
		}
	};
//---------------------------------------------------------------------------
	class TextToAnalog : public CommonFilter
	{
		typedef CommonFilter inherited;

	protected:
		virtual void DoReceive( void *_Data )
		{
			char * AText = (char*)_Data;
			float AValue = strtod( AText, NULL );
			OutputPin.Notify( &AValue );
		}

	};
//---------------------------------------------------------------------------
	class TextToInteger : public CommonFilter
	{
		typedef CommonFilter inherited;

	protected:
		virtual void DoReceive( void *_Data )
		{
			char * AText = (char*)_Data;
			long AValue = atoi( AText );
			OutputPin.Notify( &AValue );
		}

	};
//---------------------------------------------------------------------------
	class UnsignedToInteger : public CommonFilter
	{
		typedef CommonFilter inherited;

	protected:
		bool Constrain;

	protected:
		virtual void DoReceive( void *_Data )
		{
			unsigned long AValue = *(unsigned long*)_Data;
			if( Constrain )
				AValue &= 0x7FFFFFFF;

			OutputPin.Notify( &AValue );
		}

	public:
		UnsignedToInteger() :
			Constrain( true )
		{
		}

	};
//---------------------------------------------------------------------------
	class IntegerToUnsigned : public CommonFilter
	{
		typedef CommonFilter inherited;

	protected:
		bool Constrain;

	protected:
		virtual void DoReceive( void *_Data )
		{
			long AValue = *(long*)_Data;
			if( Constrain )
				AValue &= 0x7FFFFFFF;

			OutputPin.Notify( &AValue );
		}

	public:
		IntegerToUnsigned() :
			Constrain( true )
		{
		}

	};
//---------------------------------------------------------------------------
}

#endif
