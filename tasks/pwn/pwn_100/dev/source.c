#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define USER_NAME_SIZE 16

void wlc_msg( void );
void init( void );
int roulette( void );
void private( void );
int menu( void );

int UserBalance = 100;
char Username[ USER_NAME_SIZE ];

int main()
{
	init();
	wlc_msg();

	printf( "Enter your name: " );
	scanf( "%16s", Username );

	menu();
};

void init( void )
{
	setvbuf( stdin,  NULL, _IONBF, 0 );
    	setvbuf( stdout, NULL, _IONBF, 0 );
    	setvbuf( stderr, NULL, _IONBF, 0 );

	alarm( 5 );
};

void wlc_msg( void )
{
	puts( "-----------------------------------" );
	puts( "Welcome to Online Casino 'Arbalest'" );
	puts( "-----------------------------------" );
};

int menu( void )
{
	while ( 1 ) 
	{
		printf( "Hello %s\n", Username );
		printf( "Your balance: %d\n", UserBalance );
		printf( "Select one of option: \n" );
		printf( "1. Play roulette\n" );
		printf( "2. Buy private access\n" );
		printf( "3. Exit\n" );
		printf( "> " );
		int option;

		scanf( "%d", &option );

		switch( option )
		{
			case 1:
				roulette();
				break;
			case 2:
				private();
				break;
			case 3:
			default:
				return -1;
		}
	}
};

int roulette( void )
{
	int seed = time( NULL ) + 1337 + 31337;
	srand( seed );

	int number;
	int rate;

	printf( "Choose a number (0-36): " );
	scanf( "%d", &number );

	printf( "Make a bet: " );
	scanf( "%d", &rate );

	if ( rate > UserBalance )
	{
		printf( "You don’t have enough money!\n" );
		return 1;
	}

	int roulet_number = rand() % 36;

	printf( "Roulette number is [%d]\n", roulet_number );

	if ( roulet_number == number )
	{
		printf( "[+] You won [%d]\n", rate * 36 );
		UserBalance *= 36;
	}
	else
	{
		printf( "[-] You loose!\n" );
		UserBalance -= rate;
	}

	return 1;
};

void private( void )
{
	if ( UserBalance > 1000000 )
	{
		system( "cat private.txt" );
	}
	else
	{
		printf( "[-] You need 1000000$ or more!\n" );
	}
}
