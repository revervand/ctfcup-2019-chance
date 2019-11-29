import random 

orig_png   = '\x89\x50\x4e\x47\x0d\x0a\x1a\x0a\x00\x00\x00\x0d\x49\x48\x44\x52'
modify_png = '\x00\x0a\x48\x49\x1a\x0d\x00\x00\x4e\x52\x44\x0a\x50\x47\x0d\x89'
		   #    00  01  02  03  04  05  06  07  08  09  10  11  12  13  14  15 

# @keltecc code 
def shuffle(seed, array):
    random.seed(seed)
    array_ = array[:]
    random.shuffle(array_)
    return array_

# @keltecc code
def unshuffle(seed, array):
    indexes = list(range(len(array)))
    shuffled = shuffle(seed, indexes)
    trans = {i: shuffled.index(i) for i in indexes}
    return [array[trans[i]] for i in trans]

if __name__ == "__main__":
	seed = 0

	# found valid seed
	for i in range( 0, 8 * 256 ):

		if ''.join( unshuffle( i,  list(modify_png) ) ) == orig_png:
			seed = i
			break

	# read file 
	fd = open( 'enc', 'rb' )
	buf = fd.read()
	fd.close()

	blocks = []

	for i in range( 0, len( buf ), 16 ):
	 	blocks.append( buf[ i : i + 16 ] )

	res = ''

	# unshuffle file
	for i in blocks:
		block = list( i )

		res += ''.join( unshuffle( seed, block ) )

	# write result
	fd = open( 'dec.png', 'wb' )
	fd.write( res )
	fd.close()
