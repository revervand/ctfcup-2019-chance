socat -d TCP4-LISTEN:$1,reuseaddr,fork,keepalive exec:./pwn200
