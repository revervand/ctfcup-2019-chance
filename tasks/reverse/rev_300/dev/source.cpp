#include <iostream>
#include <string>
#include <vector>

// Cup{b3b8b014f2029a41e4d2a545f8cf84393b72008cc86c3c40a880be8c453266f9}
#define SECRET_SIZE 16 
#define FLAG_SIZE 69 

typedef unsigned int DWORD;

int hashed_first_part [] = { 138, 43, 170, 192, 202, 232, 185, 
	140, 14, 170, 120, 74, 17, 57, 60, 9, 141, 44, 172, 202, 
	201, 237, 188, 141, 14, 160, 43, 30, 16, 108, 59, 1 };

class Checker {
	private:
		std::vector<int> secret;
	public:
		Checker( DWORD seed );
		virtual bool check( std::string );
		std::vector<int> GetSecret( void );
};

class FormatCheck : public Checker
{
	public:
		FormatCheck( DWORD seed ) : Checker( seed ) {}

		virtual bool check( std::string );
};

class FirstPartCheck : public Checker
{
	public:
		FirstPartCheck( DWORD seed ) : Checker( seed ) {}

		virtual bool check( std::string );
};

class SecondPartCheck : public Checker
{
	public:
		SecondPartCheck( DWORD seed ) : Checker( seed ) {}

		virtual bool check( std::string );
};


int main()
{
	std::string SecertKey;

	std::cout << "[?] Enter the key: ";
	std::cin >> SecertKey;

	Checker *flag_checker;

	FormatCheck flag_format_check = FormatCheck( 0x1337 );
	flag_checker = &flag_format_check;

	if ( !flag_checker->check( SecertKey ) )
	{
		std::cout << "[-] Invalid key!" << std::endl;
		return -1;
	}

	FirstPartCheck flag_first_part_check = FirstPartCheck( 0x1338 );
	flag_checker = &flag_first_part_check;

	if ( !flag_checker->check( SecertKey ) )
	{
		std::cout << "[-] Invalid key!" << std::endl;
		return -2;
	}

	SecondPartCheck flag_second_part_check = SecondPartCheck( 0x1339 );
	flag_checker = &flag_second_part_check;

	if ( !flag_checker->check( SecertKey ) )
	{
		std::cout << "[-] Invalid key!" << std::endl;
		return -3;
	}

	std::cout << "[+] Valid key!" << std::endl;

	return 0;
};

Checker::Checker( DWORD seed )
{
	int value = seed;

	DWORD multipyly = 1337;
	DWORD added = 0x10303070;

	for ( int i = 0; i < SECRET_SIZE; i++ )
	{
		value = ( ( value * multipyly ) + added ) % 0x1000000;
		secret.push_back( value & 0xff );
	}
};

bool Checker::check( std::string buf )
{
	return true;
};

bool FormatCheck::check( std::string buf )
{
	if ( buf.size() != FLAG_SIZE )
		return false;

	if ( buf[ 0 ] != 'C' )
		return false;

	if ( buf[ 1 ] != 'u' )
		return false;

	if ( buf[ 2 ] != 'p' )
		return false;

	if ( buf[ 3 ] != '{' )
		return false;

	if ( buf[ 68 ] != '}' ) 
		return false;

	return true;
};

bool FirstPartCheck::check( std::string buf )
{
	// b3b8b014f2029a41e4d2a545f8cf8439

	std::string first_part = buf.substr( 4, 32 );

	for ( int i = 0; i < first_part.size(); i++ )
	{
		int val = first_part[ i ] ^ this->GetSecret()[ i % this->GetSecret().size() ];

		if ( val != hashed_first_part[ i ] )
		{
			return false;
		}
	}

	return true;
};

bool SecondPartCheck::check( std::string buf )
{	
	// 3b72008cc86c3c40a880be8c453266f9

	int second_part_hash[] = { 227, 178, 231, 226, 224, 224, 232, 179,
		179, 232, 230, 179, 227, 179, 228, 224, 177, 232, 232, 224, 
		178, 181, 232, 179, 228, 229, 227, 226, 230, 230, 182, 233
	};

	std::string second_part = buf.substr( 36, 32 );

	int sum_of_secret = 0;

	for ( int i = 0; i < this->GetSecret().size(); i++ )
	{
		sum_of_secret += this->GetSecret()[ i ];
	}

	int xor_key = sum_of_secret % 256;

	for ( int i = 0; i < second_part.size(); i++ )
	{
		int val = second_part[ i ] ^ xor_key;

		if ( val != second_part_hash[ i ] )
		{
			return false;
		}
	}

	return true;
};

std::vector<int> Checker::GetSecret( void )
{
	return secret;
}
