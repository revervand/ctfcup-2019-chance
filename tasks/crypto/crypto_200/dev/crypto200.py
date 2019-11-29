import sys 
import random

def SplitDataToBlocks( Data ):
	Blocks = []

	for i in range( 0, len( Data ), 16 ):
		Blocks.append( Data[ i : i + 16 ] )

	return Blocks

def ShuffleBlocks( Blocks, Key ):
	for i in range( len( Blocks ) ):
		Blocks[ i ] = ShuffleBlock( Blocks[ i ], Key )

	return Blocks

def ShuffleBlock( InpBlock, Key ):
	ShuffleSeed = 0

	Block = list( InpBlock )

	for i in Key:
		ShuffleSeed += ord( i )

	random.seed( ShuffleSeed )
	random.shuffle( Block )

	return ''.join( Block )

def ReadFile( Filename ):
	fd = None

	try:
		fd = open( Filename, 'rb' )
	except:
		print "Error in file <%s> open!" % Filename
		sys.exit( -2 )

	Filedata = fd.read()

	if len( Filedata ) == 0:
		print "Error file <%s> is empty!" % Filename
		sys.exit( -3 )

	return Filedata

def SaveFile( Filename, Data ):
	fd = open( Filename, 'wb' )
	fd.write( Data )
	fd.close()


if __name__ == "__main__":

	if len( sys.argv ) > 3:
		InpFilename = sys.argv[ 1 ]
		OutFilename = sys.argv[ 2 ]
		Password    = sys.argv[ 3 ]
	else:
		print "Usage: python " + sys.argv[ 0 ] + " <input> <output> <pass>"
		sys.exit( -1 )

	if len( Password ) > 8:
		print "[-] Too big pass!"
		sys.exit( -1 )

	InpFileData = ReadFile( InpFilename )
	Blocks = SplitDataToBlocks( InpFileData )
	Blocks = ShuffleBlocks( Blocks, Password )

	OutFileData = ''.join( Blocks )

	SaveFile( OutFilename, OutFileData )
