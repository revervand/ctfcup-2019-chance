buf = '0110100001110100011101000111000001110011001110100010111100101111011100000110000101110011011101000110010101100010011010010110111000101110011000110110111101101101001011110110001100110111011010100110110100110100011101000101001000110111'

buf2 = open( 'text.txt', 'rb' ).read()
res = ''
key_offset = 0

for i in range( len( buf2 ) ):
	
	if key_offset == len( buf ):
		res += buf2[ i ]
		continue 

	if buf2[ i ] == 'i' and buf[ key_offset ] == '1':
		res += buf[ key_offset ]
		key_offset += 1
		continue
	if buf2[ i ] == 'o' and buf[ key_offset ] == '0':
		res += buf[ key_offset ]
		key_offset += 1
		continue

	res += buf2[ i ]

print res