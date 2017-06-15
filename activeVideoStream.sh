raspivid -vf -n -w 640 -h 480 -o - -t 0 -b 2000000 | nc 192.168.25.9 5777
