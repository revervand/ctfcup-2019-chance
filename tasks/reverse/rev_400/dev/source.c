#include "source.h"

BYTE hash_0[SHA256_BLOCK_SIZE] = {0x2e,0x7d,0x2c,0x3,0xa9,0x50,0x7a,0xe2,0x65,0xec,0xf5,0xb5,0x35,0x68,0x85,0xa5,0x33,0x93,0xa2,0x2,0x9d,0x24,0x13,0x94,0x99,0x72,0x65,0xa1,0xa2,0x5a,0xef,0xc6};
BYTE hash_1[SHA256_BLOCK_SIZE] = {0x2e,0x7d,0x2c,0x3,0xa9,0x50,0x7a,0xe2,0x65,0xec,0xf5,0xb5,0x35,0x68,0x85,0xa5,0x33,0x93,0xa2,0x2,0x9d,0x24,0x13,0x94,0x99,0x72,0x65,0xa1,0xa2,0x5a,0xef,0xc6};
BYTE hash_2[SHA256_BLOCK_SIZE] = {0x4b,0x22,0x77,0x77,0xd4,0xdd,0x1f,0xc6,0x1c,0x6f,0x88,0x4f,0x48,0x64,0x1d,0x2,0xb4,0xd1,0x21,0xd3,0xfd,0x32,0x8c,0xb0,0x8b,0x55,0x31,0xfc,0xac,0xda,0xbf,0x8a};
BYTE hash_3[SHA256_BLOCK_SIZE] = {0xe7,0xf6,0xc0,0x11,0x77,0x6e,0x8d,0xb7,0xcd,0x33,0xb,0x54,0x17,0x4f,0xd7,0x6f,0x7d,0x2,0x16,0xb6,0x12,0x38,0x7a,0x5f,0xfc,0xfb,0x81,0xe6,0xf0,0x91,0x96,0x83};
BYTE hash_4[SHA256_BLOCK_SIZE] = {0xef,0x2d,0x12,0x7d,0xe3,0x7b,0x94,0x2b,0xaa,0xd0,0x61,0x45,0xe5,0x4b,0xc,0x61,0x9a,0x1f,0x22,0x32,0x7b,0x2e,0xbb,0xcf,0xbe,0xc7,0x8f,0x55,0x64,0xaf,0xe3,0x9d};
BYTE hash_5[SHA256_BLOCK_SIZE] = {0x2e,0x7d,0x2c,0x3,0xa9,0x50,0x7a,0xe2,0x65,0xec,0xf5,0xb5,0x35,0x68,0x85,0xa5,0x33,0x93,0xa2,0x2,0x9d,0x24,0x13,0x94,0x99,0x72,0x65,0xa1,0xa2,0x5a,0xef,0xc6};
BYTE hash_6[SHA256_BLOCK_SIZE] = {0x6b,0x86,0xb2,0x73,0xff,0x34,0xfc,0xe1,0x9d,0x6b,0x80,0x4e,0xff,0x5a,0x3f,0x57,0x47,0xad,0xa4,0xea,0xa2,0x2f,0x1d,0x49,0xc0,0x1e,0x52,0xdd,0xb7,0x87,0x5b,0x4b};
BYTE hash_7[SHA256_BLOCK_SIZE] = {0x19,0x58,0x1e,0x27,0xde,0x7c,0xed,0x0,0xff,0x1c,0xe5,0xb,0x20,0x47,0xe7,0xa5,0x67,0xc7,0x6b,0x1c,0xba,0xeb,0xab,0xe5,0xef,0x3,0xf7,0xc3,0x1,0x7b,0xb5,0xb7};
BYTE hash_8[SHA256_BLOCK_SIZE] = {0x2e,0x7d,0x2c,0x3,0xa9,0x50,0x7a,0xe2,0x65,0xec,0xf5,0xb5,0x35,0x68,0x85,0xa5,0x33,0x93,0xa2,0x2,0x9d,0x24,0x13,0x94,0x99,0x72,0x65,0xa1,0xa2,0x5a,0xef,0xc6};
BYTE hash_9[SHA256_BLOCK_SIZE] = {0x4b,0x22,0x77,0x77,0xd4,0xdd,0x1f,0xc6,0x1c,0x6f,0x88,0x4f,0x48,0x64,0x1d,0x2,0xb4,0xd1,0x21,0xd3,0xfd,0x32,0x8c,0xb0,0x8b,0x55,0x31,0xfc,0xac,0xda,0xbf,0x8a};
BYTE hash_10[SHA256_BLOCK_SIZE] = {0xd1,0xb,0x36,0xaa,0x74,0xa5,0x9b,0xcf,0x4a,0x88,0x18,0x58,0x37,0xf6,0x58,0xaf,0xaf,0x36,0x46,0xef,0xf2,0xbb,0x16,0xc3,0x92,0x8d,0xe,0x93,0x35,0xe9,0x45,0xd2};

BYTE* hashes[ 11 ] = {
	&hash_0[0],&hash_1[0],&hash_2[0],
	&hash_3[0],&hash_4[0],&hash_5[0],
	&hash_6[0],&hash_7[0],&hash_8[0],
	&hash_9[0],&hash_10[0]
};

BYTE xor_res[ 13 ] = { 120, 96, 139, 231, 45, 162, 127, 235, 14, 214, 76, 193, 28 };

static unsigned long int next = 0x1337;


// first part - XOR with LCG
// second part - CRC32 of each char
// third part - sha256 of each char

int main()
{

	int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;

    char buf[ 1024 ];
    time_t ticks;

    listenfd = socket( AF_INET, SOCK_STREAM, 0 );

    memset( &serv_addr, 0x0, sizeof( serv_addr ) );
    memset( buf, 0x0, sizeof( buf ) );

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl( INADDR_ANY );
    serv_addr.sin_port = htons( 1337 );

    bind( listenfd, (struct sockaddr*)&serv_addr, sizeof( serv_addr ) );

    listen( listenfd, 10 );

    while( 1 ) 
    {
        connfd = accept( listenfd, (struct sockaddr*)NULL, NULL );

        int nbytes = recv( connfd, &buf[ 0 ], 1024, 0 );

        if ( check_buffer( &buf[ 0 ] ) )
        {
        	send( connfd, "{+} Correct!\n", 13, 0 );	
        }
        else
        {
        	send( connfd, "{+} Incorrect!\n", 15, 0 );
        }

        close( connfd );
    }

	return 1;
};

// Cup{96f0f08c0188ba04898ce8cc465c19c4}

int check_buffer( char* buf )
{
	if( strlen( buf ) != 38 )
	{
		return 0;
	}

	char part1[ 14 ];
	int cur_buf_idx = 0;

	for ( int i = 0; i < 13; i++ )
	{
		part1[ i ] = buf[ cur_buf_idx ];
		cur_buf_idx++;
	}

	part1[ 13 ] = '\0';

	char part2[ 14 ];

	for ( int i = 0; i < 13; i++ )
	{
		part2[ i ] = buf[ cur_buf_idx ];
		cur_buf_idx++;
	}

	part2[ 13 ] = '\0';

	char part3[ 12 ];

	for ( int i = 0; i < 11; i++ )
	{
		part3[ i ] = buf[ cur_buf_idx ];
		cur_buf_idx++;
	}

	part3[ 11 ] = '\0';

	if ( !check_milk_part( &part1[ 0 ] ) )
	{
		printf( "[-] first part!\n" );
		return 0;
	}

	if ( !check_coffee_part( &part2[ 0 ] ) )
	{
		puts( "[-] second part!\n" );
		return 0;
	}

	if ( !check_cookie_part( &part3[ 0 ] ) )
	{
		puts( "[-] third part!\n" );
		return 0;
	}

	return 1;
};

int check_milk_part( char* buf )
{
	if ( strlen( buf ) != 13 )
	{
		return 0;
	}

	for ( int i = 0; i < 13; i++ )
	{
		printf( "0x%x,", get_byte() );
		// if ( (get_byte() ^ buf[ i ]) != xor_res[ i ] )
		// {
		// 	return 0;
		// }
	}

	return 1;
};

int check_coffee_part( char* buf )
{
	if ( strlen( buf ) != 13 )
	{
		return 0;
	}

	for ( int i = 0; i < 13; i++ )
	{
		if ( my_best_algo( &buf[ i ], 1, 0xFFFFFFFF ) != valid_sums[ i ] )
		{
		 	return 0;
		}
	}

	puts( "" );

	return 1;
};

int check_cookie_part( char* buf )
{
	if ( strlen( buf ) != 11 )
	{
		return 0;
	}

	for ( int i = 0; i < 11; i++ )
	{
		const BYTE part = buf[ i ];
		

		BYTE buf[ SHA256_BLOCK_SIZE ];
		SHA256_CTX ctx;

		int idx;
		int pass = 1;

		hash_init( &ctx );
		hash_update( &ctx, &part, 1 );
		hash_final( &ctx, buf );

		pass = pass && !memcmp( hashes[ i ], buf, SHA256_BLOCK_SIZE );

		if ( pass != 1 )
		{
			return 0;
		}
	}

	return 1;
};


int get_byte(void)
{
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 0xff;
};