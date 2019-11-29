import sys
from pwn import * 
#import qrtools

CONNECTION_TIMEOUT = 5 
IMAGE_NAME = 'cur_round_image.png'

def ReadQR( Filename ):
	p = process( ["zbarimg", Filename] )
	data = p.recvline().strip().split( ':' )[ 1 ]
	p.close()

	return data

def SaveImage( Filename, Data ):
	fd = open( Filename, 'wb' )
	fd.write( Data )
	fd.close()

if __name__ == "__main__":

	if len( sys.argv ) > 2:
		host = sys.argv[ 1 ]
		port = int( sys.argv[ 2 ] )
	else:
		print "Usage: python " + sys.argv[ 0 ] + " <host> <port>"
		sys.exit( -1 )


	sock = remote( host, port )

	sock.recvuntil( "(Y/N): " ) # skip banner and menu

	sock.send( "Y\n" )
	
	while 1:
	
		ImageData = sock.recvline().strip()
		if "CupCTF" in ImageData:
			print ImageData
			sys.exit( -1 )

		sock.recvuntil( ": " )

		ImageData = ImageData.decode( 'hex' )
		SaveImage( IMAGE_NAME, ImageData )


		answer = ReadQR( IMAGE_NAME )
		
		print "answer = ", answer

		sock.send( answer + '\n' )

		result = sock.recvline()	

		if "Correct" in result:
			continue 
		else:
			sock.close()
			break
