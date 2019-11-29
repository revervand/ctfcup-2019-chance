buf = open( 'out_text.txt', 'rb' ).read()

res = ''

for i in buf:
	if i == '0' or i == '1':
		res += i

print res
