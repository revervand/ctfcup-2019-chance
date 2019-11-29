#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILE_NOT_FOUND 1313
#define FILE_BUF_SIZE 256


void banner( void );
void init( void );
void ReadAdminInfo( void );
int CheckUsername( char* );

int main()
{
	init();
	banner();

	char Username[ 24 ];
	printf( "Enter username: " );

	int nbytes = read( 0, Username, 24 );
	Username[ nbytes - 1 ] = '\0';

	int is_admin = 0;
	is_admin = CheckUsername( &Username[ 0 ] );

	if ( is_admin )
	{
		ReadAdminInfo();
	}

	return 0;
};

void banner( void )
{
	puts( "--------------------------" );
	puts( "-- Private Casino Panel --" );
	puts( "--------------------------" );
	puts( "Service work in test mode!" );
};

void init( void )
{
	setvbuf( stdin,  NULL, _IONBF, 0 );
	setvbuf( stdout, NULL, _IONBF, 0 );
	setvbuf( stderr, NULL, _IONBF, 0 );

	alarm( 5 );
};

int CheckUsername( char* buf )
{
	FILE* fd;
	char FileData[ FILE_BUF_SIZE ];

	fd = fopen( "admin_login.txt", "r" );

	if ( fd == NULL )
	{
		puts( "[-] Server error! Tell admin!" );
		exit( FILE_NOT_FOUND );
	}
	
	fgets( FileData, FILE_BUF_SIZE, fd );
	fclose( fd );

	if ( !strcmp( FileData, buf ) )
	{
		puts( "Welcome admin!" );
		return 1;
	}
	else
	{
		printf( buf );
		printf( " is not correct name!\n" );
		return 0;
	}

	return 0;
};

void ReadAdminInfo( void )
{
	system( "/bin/cat admin_info.txt" );
};
