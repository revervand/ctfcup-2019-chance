#include <stdio.h>

#define CODES_SIZE 8

typedef unsigned int DWORD;

int valid_codes[ CODES_SIZE ];

// flag - CupCTF{22db07f1ed2ffbfd4be1440d696d5454e0ea5b5baa9f43dfbc7965b2e2bf9245}
// 22db07f1
// ed2ffbfd
// 4be1440d
// 696d5454
// e0ea5b5b
// aa9f43df
// bc7965b2
// e2bf9245

void init_codes( void );
int check_code( int, int );

int main()
{
	init_codes();
	DWORD code;

	for ( int i = 0; i < CODES_SIZE; i++ )
	{
		printf( "[?] Enter the deactivation code [%d]: ", i + 1 );
		scanf( "%d", &code );

		if ( !check_code( code, i ) )
		{
			printf( "[-] Error code [%d]\nExit.\n", i + 1 );
			return -1;
		}
	}

	printf( "[+] Codes is valid!\n" );
	printf( "flag is CupCTF{" );

	for( int i = 0; i < CODES_SIZE; i++ )
	{
		printf("%x", valid_codes[ i ] );
	}

	printf( "}\n" );

	return 0;
};

void init_codes( void )
{
	valid_codes[ 0 ] = 0x22db07f1;
	valid_codes[ 1 ] = 0xed2ffbfd;
	valid_codes[ 2 ] = 0x4be1440d;
	valid_codes[ 3 ] = 0x696d5454;
	valid_codes[ 4 ] = 0xe0ea5b5b;
	valid_codes[ 5 ] = 0xaa9f43df;
	valid_codes[ 6 ] = 0xbc7965b2;
	valid_codes[ 7 ] = 0xe2bf9245;
};

int check_code( int code, int position )
{
	return code == valid_codes[ position ];
};