from hashlib import sha256
import binascii

_hashes = []

flag = "cc465c19c4}"

for i in range(0,11):
	print( "&hash_%d[0]," % i, end='' )

for i in range( 0, len( flag ) ):
	part = flag[ i ].encode('utf-8')

	_hashes.append( sha256( part ).hexdigest() )

for i in range( len( _hashes ) ):
	string = 'hash[' + str( i ) + "][SHA256_BLOCK_SIZE] = {" 
	
	_hash = _hashes[ i ]

	for j in range( 0, len( _hash ), 2 ):
		elem = hex(ord(binascii.unhexlify( _hash[ j : j + 2 ] )))
		string += elem + ","
		
	string += "};"


	print( string.replace( ',}', '}' ) )