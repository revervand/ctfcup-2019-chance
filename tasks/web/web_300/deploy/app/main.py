from flask import Flask, render_template, request, render_template_string

app = Flask(__name__)

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

@app.route( '/' )
def hello():
    return render_template( 'index.html' )

@app.route( '/login', methods=[ 'POST' ] )
def login():
	if request.method == 'POST':
		
		username = request.form[ 'username' ]
		password = request.form[ 'password' ]
	
	buf = 'Test login for user - {{%s}}' % username
	return render_template_string( buf )


if __name__ == '__main__':
    app.run( host = '0.0.0.0', port = 8989, debug = True )