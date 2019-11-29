#include <iostream>
#include <string>
#include <vector>

bool checkSecondPart( std::string buf );
bool checkFirstPart( std::string buf );
unsigned int htoi( std::string );

// Cup{f2355edaad2deb2ad456947412ed4cc8c49c1d96828aaa781bd6be73f34dae82}

int main()
{
	std::string UserInput;

	std::cout << "[?] Enter the valid key: ";
	std::cin >> UserInput;

	if ( checkFirstPart( UserInput ) )
	{
		if ( checkSecondPart( UserInput ) )
		{
			std::cout << "[+] Valid key!" << std::endl;
			return 1;
		}
	}

	std::cout << "[-] Invalid key!" << std::endl;
	return 0;
};	

bool checkFirstPart( std::string buf )
{
	if ( buf[ 0 ] != 'C' ) return false;
	if ( buf[ 1 ] != 'u' ) return false;
	if ( buf[ 2 ] != 'p' ) return false;
	if ( buf[ 3 ] != '{' ) return false;
	if ( buf[ 4 ] != 'f' ) return false;
	if ( buf[ 5 ] != '2' ) return false;
	if ( buf[ 6 ] != '3' ) return false;
	if ( buf[ 7 ] != '5' ) return false;

	if ( buf[ 8 ]  * 2 != 106 ) return false;
	if ( buf[ 9 ]  * 3 != 303 ) return false;
	if ( buf[ 10 ] * 4 != 400 ) return false;
	if ( buf[ 11 ] * 5 != 485 ) return false;
	if ( buf[ 12 ] * 6 != 582 ) return false;
	if ( buf[ 13 ] * 7 != 700 ) return false;
	if ( buf[ 14 ] * 8 != 400 ) return false;
	if ( buf[ 15 ] * 9 != 900 ) return false;

	if ( ( buf[ 16 ] ^ 1 ) != 100 ) return false;
	if ( ( buf[ 17 ] ^ 2 ) != 96  ) return false;
	if ( ( buf[ 18 ] ^ 3 ) != 49  ) return false;
	if ( ( buf[ 19 ] ^ 4 ) != 101 ) return false;
	if ( ( buf[ 20 ] ^ 5 ) != 97  ) return false;
	if ( ( buf[ 21 ] ^ 6 ) != 50  ) return false;
	if ( ( buf[ 22 ] ^ 7 ) != 50  ) return false;
	if ( ( buf[ 23 ] ^ 8 ) != 62  ) return false;

	if ( buf[ 24 ] != ( buf[ 6 ] + 6 )  ) return false;
	if ( buf[ 25 ] != ( buf[ 7 ] - 1 )  ) return false;
	if ( buf[ 26 ] != ( buf[ 5 ] + 5 )  ) return false;
	if ( buf[ 27 ] !=   buf[ 25 ]       ) return false;
	if ( buf[ 28 ] != ( buf[ 5 ] - 1 )  ) return false;
	if ( buf[ 29 ] !=   buf[ 5 ]        ) return false;
	if ( buf[ 30 ] != ( buf[ 4 ] - 1 )  ) return false;
	if ( buf[ 31 ] != ( buf[ 30 ] - 1 ) ) return false;

	return true;
};

bool checkSecondPart( std::string buf )
{
	if ( buf[ 32 ] != '4' ) return false;
	if ( buf[ 33 ] != ( buf[ 4 ] - 3 ) ) return false;
	if ( buf[ 34 ] != buf[ 33 ] ) return false;
	if ( buf[ 35 ] != ( buf[ 32 ] + 4 ) ) return false;
	if ( buf[ 36 ] != buf[ 34 ] ) return false;
	if ( buf[ 37 ] != buf[ 32 ] ) return false;
	if ( buf[ 38 ] != ( buf[ 32 ] + 5 ) ) return false;
	if ( buf[ 39 ] != buf[ 36 ] ) return false;

	std::string part = buf.substr( 40, 8 );
	if ( part != "1d96828a" ) return false;

	if ( ( ( buf[ 48 ] - 10 ) << 1 ) != 174 ) return false;
	if ( buf[ 49 ] != buf[ 48 ] ) return false;
	if ( buf[ 50 ] != ( buf[ 32 ] + 3 ) ) return false;
	if ( buf[ 51 ] != ( buf[ 50 ] + 1 ) ) return false;
	if ( buf[ 52 ] != ( buf[ 51 ] - 7 ) ) return false;
	if ( buf[ 53 ] != 'b' ) return false;
	if ( buf[ 54 ] != 'd' ) return false;
	if ( buf[ 55 ] != '6' ) return false;

	if ( buf[ 56 ] != buf[ 53 ] ) return false;
	if ( buf[ 57 ] != 'e' ) return false;
	if ( buf[ 58 ] != ( buf[ 55 ] + 1 ) ) return false;
	if ( buf[ 59 ] != ( buf[ 58 ] - 4 ) ) return false;
	if ( buf[ 60 ] != ( buf[ 57 ] + 1 ) ) return false;
	if ( buf[ 61 ] != buf[ 59 ] ) return false;
	if ( buf[ 62 ] != ( buf[ 61 ] + 1 ) ) return false;
	if ( buf[ 63 ] != 'd' ) return false;

	if ( buf[ 64 ] != 'a' ) return false;
	if ( buf[ 65 ] != ( buf[ 64 ] + 4 ) ) return false;
	if ( buf[ 66 ] != ( buf[ 55 ] + 2 ) ) return false;
	if ( buf[ 67 ] != ( buf[ 66 ] - 6 ) ) return false;
	if ( buf[ 68 ] != '}' ) return false;

	return true;
};
