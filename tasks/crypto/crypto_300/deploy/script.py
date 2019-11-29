from des import DesKey
import sys

SECRET = bin(XXXXXXXXX)[2:]

def pad( msg ):
	while len( msg ) % 8 != 0:
		msg += '\x00'
	return msg

def SaveFile( Filename, FileData ):
	fd = None

	try:
		fd = open( Filename, 'wb' )
	except:
		print "[-] Error in file <%s> open!" % Filename
		return None

	fd.write( FileData )
	fd.close()

	return True

def ReadFile( Filename ):
	fd = None

	try:
		fd = open( Filename, 'rb' )
	except:
		print "[-] Error in file <%s> open!" % Filename
		return None

	buf = fd.read()

	if len( buf ) == 0:
		print "[-] Error file <%s> is empty!" % Filename
		return None

	return buf

def encode( Blocks, Keys ):
	max_len = len( Blocks ) if len( Blocks ) > len( Keys ) else len( Keys )

	enc_blocks = []

	for i in range( 0, max_len ):
		key = DesKey( Keys[ i % len( Keys ) ].decode( 'hex' ) )

		enc_block = key.encrypt( pad( Blocks[ i % len( Blocks ) ] ) )

		if int( SECRET[ i % len( SECRET ) ] ) == 1:
			enc_block = key.encrypt( enc_block )

		enc_blocks.append( enc_block.encode( 'hex' ) )

	return enc_blocks

if __name__ == "__main__":

	if len( sys.argv ) > 3:
		InpFilename  = sys.argv[ 1 ]
		OutFilename  = sys.argv[ 2 ]
		KeysFilename = sys.argv[ 3 ]
	else:
		print "Usage: python " + sys.argv[ 0 ] + " <input> <output> <keys>"
		sys.exit( -1 )

	InpFileData = ReadFile( InpFilename )
	InpFileData = InpFileData.split( '\n' )

	Keys = ReadFile( KeysFilename )
	Keys = Keys.split('\n')

	OutFileData = '\n'.join( encode( InpFileData, Keys ) )

	SaveFile( OutFilename, OutFileData )
