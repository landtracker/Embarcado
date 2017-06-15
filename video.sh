raspivid -vf -n -w 640 -h 480 -o - -t 0 -b 200000 | nc 192.168.43.50 2234 &
