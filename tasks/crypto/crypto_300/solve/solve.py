from des import DesKey

key = '1F1F1F1F0E0E0E0E'.decode( 'hex' )
data = '8c5107ff7a06d2b3f4f161a437db6d227dfdd76822349d941261223d43cfc86e96edff6ed4b840471d4d547ec8eba886ae5d93f75fe9a41e82b65f67dafbd3524f7a3c08f1e6bcb5'.decode('hex')

key = DesKey( key )
dec = key.encrypt( data )

print dec