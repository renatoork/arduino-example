////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//     This software is supplied under the terms of a license agreement or    //
//     nondisclosure agreement with Mitov Software and may not be copied      //
//     or disclosed except in accordance with the terms of that agreement.    //
//         Copyright(c) 2002-2015 Mitov Software. All Rights Reserved.        //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#ifndef _MITOV_RANDOM_GENERATOR_h
#define _MITOV_RANDOM_GENERATOR_h

#include <Mitov.h>

namespace Mitov
{
	class RandomAnalogGenerator : public Mitov::CommonSource // Mitov::CommonGenerator
	{
		typedef Mitov::CommonSource inherited;

	protected:
		float	FValue;
//		unsigned long FLastTime;
		
	public:
        bool    Enabled;
		float	Min;
		float	Max;
		long	Seed;

	protected:
		virtual void SystemInit()
		{
			randomSeed( Seed );

			inherited::SystemInit();
		}

		virtual void SystemClock( unsigned long currentMicros )
		{
            if( Enabled )
            {
				if( Min == Max )
					FValue = Min;

				else
				{
					float AMin = min( Min, Max );
					float AMax = max( Min, Max );
//					double ARandom = random( -2147483648, 2147483647 );
					double ARandom = random( -1147483648, 1147483647 );
//					FValue = ARandom;
					ARandom += 1147483648;
					FValue = AMin + ( ARandom / ( (double)1147483647 + (double)1147483648 )) * (AMax - AMin);
				}
			}

			OutputPin.Notify( &FValue );
		}

	public:
		RandomAnalogGenerator() :
			FValue( 0 ),
			Min( 0 ),
			Max( 1 ),
//			FTime( 0 ),
            Enabled( true ),
			Seed( 0 )
		{
//			Rate = 1000;
		}

	};
//---------------------------------------------------------------------------
	class RandomIntegerGenerator : public Mitov::CommonSource
	{
		typedef Mitov::CommonSource inherited;

	protected:
		long	FValue;
		
	public:
        bool    Enabled;
		long	Min;
		long	Max;
		long	Seed;

	protected:
		virtual void SystemInit()
		{
			randomSeed( Seed );

			inherited::SystemInit();
		}

		virtual void SystemClock( unsigned long currentMicros )
		{
            if( Enabled )
            {
				if( Min == Max )
					FValue = Min;

				else
				{
					long AMin = min( Min, Max );
					long AMax = max( Min, Max );
					FValue = random( AMin, AMax + 1 );
				}
			}

			OutputPin.Notify( &FValue );
		}

	public:
		RandomIntegerGenerator() :
			FValue( 0 ),
			Min( -1000 ),
			Max( 1000 ),
//			FTime( 0 ),
            Enabled( true ),
			Seed( 0 )
		{
//			Rate = 1000;
		}

	};
//---------------------------------------------------------------------------
	class RandomUnsignedGenerator : public Mitov::CommonSource
	{
		typedef Mitov::CommonSource inherited;

	protected:
		unsigned long	FValue;
		
	public:
        bool    Enabled;
		unsigned long	Min;
		unsigned long	Max;
		long	Seed;

	protected:
		virtual void SystemInit()
		{
			randomSeed( Seed );

			inherited::SystemInit();
		}

		virtual void SystemClock( unsigned long currentMicros )
		{
            if( Enabled )
            {
				if( Min == Max )
					FValue = Min;

				else
				{
					unsigned long AMin = min( Min, Max );
					unsigned long AMax = max( Min, Max );
					FValue = random( AMin, AMax + 1 );
				}
			}

			OutputPin.Notify( &FValue );
		}

	public:
		RandomUnsignedGenerator() :
			FValue( 0 ),
			Min( 0 ),
			Max( 1000 ),
//			FTime( 0 ),
            Enabled( true ),
			Seed( 0 )
		{
//			Rate = 1000;
		}

	};
}

#endif
