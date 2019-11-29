#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>

void init( void );
int readSlotMachineBanner( void );
void menu( void );
int game( int );
void saveFeedback( char* );
void backdoor( void );

int UserCount = 100;

int main()
{
	init();

	while ( 1 )
	{
		char tmp_buf[8];
		int bet;

		menu();
		puts( "For quit enter 'q' or 'Q'" );
		printf( "You have %d$\n", UserCount );
		printf( "Enter your bet: " );

		read( 0, tmp_buf, 8 );

		if ( tmp_buf[ 0 ] == 'q' || tmp_buf[ 0 ] == 'Q' )
			exit( -1 );

		bet = atoi( tmp_buf );

		game( bet );

	}

	return 0;
};

void init( void )
{
	setvbuf( stdin,  NULL, _IONBF, 0 );
	setvbuf( stdout, NULL, _IONBF, 0 );
	setvbuf( stderr, NULL, _IONBF, 0 );

	alarm( 10 );
};

void menu( void )
{
	readSlotMachineBanner();
};

int readSlotMachineBanner( void )
{
	FILE *fd = fopen( "slot_machine_banner.txt", "r" );

	if ( fd == NULL )
	{
		return -1;
	}

	char ch;

	while ( ( ch = fgetc( fd ) ) != EOF )
	{
		printf( "%c", ch );
	}

	return 0;
};

int game( int bet )
{
	int lose;

	if ( bet > UserCount )
	{
		puts( "[-] Not enough money!" );
		return 0;
	}
	int numbers[ 3 ];

	for ( int i = 0; i < 3; i++ )
	{
		numbers[ i ] = random() % 10;
	}

	puts( "Slot machine result!" );
	printf( "%d-%d-%d\n", numbers[ 0 ], numbers[ 1 ], numbers[ 2 ] );

	if ( numbers[ 0 ] == numbers[ 1 ] && numbers[ 1 ] == numbers[ 2 ] )
	{
		puts( "[+] You win!" );
		UserCount += bet * bet;
	}
	else
	{
		puts( "[-] You lose!" );
		UserCount -= bet;
		lose = 1;
	}

	if ( lose )
	{
		fflush( stdout );
		fflush( stdin );

		puts( "[?] You can leave feedback equal to your lose bet" );
		char feedback[ 256 ];

		if ( feedback == NULL )
		{
			printf( "[-] Some internal error!\nTell admin!\n" );
			exit( -3 );
		}

		fflush( stdout );
		fflush( stdin );

		read( 0, feedback, bet );

		saveFeedback( feedback );
	}

	return bet;
};

void saveFeedback( char* buf )
{
	puts( "TODO" );
};
