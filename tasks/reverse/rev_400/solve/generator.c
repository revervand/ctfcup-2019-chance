#include <stdio.h>

static unsigned long int next = 0x1337;

int get_byte(void)
{
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 0xff;
};

int main()
{
	for ( int i = 0; i < 13; i++ )
	{
		printf( "0x%x,", get_byte() );
	}

	return 1;
};