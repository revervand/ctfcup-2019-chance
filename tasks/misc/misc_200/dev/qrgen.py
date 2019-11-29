import random
import string
import os

import pyqrcode

alph = string.ascii_lowercase + string.ascii_uppercase + string.digits


def idg( size = 8, chars=alph ):
	return ''.join( random.choice( chars ) for _ in range( size ) )

def FileRead( Filename ):
	fd = open( Filename, 'rb' )
	buf = fd.read()
	fd.close()

	return buf.encode( 'hex' )

def GetRandomQR():
	Filename = idg()
	Data = idg()

	qr = pyqrcode.create( Data )
	qr.png( Filename, scale = 6 )
	
	FileData = FileRead( Filename )	
	os.system( "rm " + Filename )
	
	return FileData, Data