
/*

Copyright (C) 2007 Coolsoft Company. All rights reserved.

http://www.coolsoft-sd.com/

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the
use of this software. 

Permission is granted to anyone to use this software for any purpose, including
commercial applications, and to alter it and redistribute it freely, subject to
the following restrictions: 

 * The origin of this software must not be misrepresented; you must not claim that
   you wrote the original software. If you use this software in a product, an
   acknowledgment in the product documentation would be appreciated but is not required.
 * Altered source versions must be plainly marked as such, and must not be misrepresented
   as being the original software. 
 * This notice may not be removed or altered from any source distribution. 

*/

#include "base64.h"

#ifndef _MANAGED

#include <iostream>

#endif

void main()
{
	STRING testStr = L"1234567890";
	STRING code;

	for( int i = 1; i <= 10; i++ )
	{

		wcout << L"text: ";
		wcout.width( 17 - i );
		wcout.write( testStr.c_str(), i );

		Base64::Encode( (BYTE_DATA_IN)testStr.c_str(), i * sizeof( STRING::value_type ), code );

		wcout << L" code: ";
		wcout.width( 28 );
		wcout << code;

		int len = Base64::GetDataLength( (int)code.length() );
		unsigned char* data = new unsigned char[ len ];
		int realLen = Base64::Decode( code, (int)code.length(), data );

		wcout << L" decoded: ";
		wcout << STRING( (STRING::value_type*)data, realLen / sizeof( STRING::value_type ) );

		delete[] data;

		wcout << '\n';

	}
}
