#include "my_best_algo.h"
#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 





#define BUF_SIZE 256

int check_buffer( char* buf );
int check_milk_part( char* buf );
int check_coffee_part( char* buf );
int check_cookie_part( char* buf );
int get_byte(void);



unsigned int valid_sums[ 13 ] = {
	0x9efbcf93, 0xbc323f9c,
	0xbc323f9c, 0xeb2f424d,
	0xe66c6494, 0x9a3ad224,
	0x893ea4f8, 0xbc323f9c,
	0xb8f3222b, 0xbc323f9c,
	0xefee5ffa, 0xf5681248,
	0xbc323f9c
};

