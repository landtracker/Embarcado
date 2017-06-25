arecord -v -f S16_LE -c 1 -r 192000 -d 0 -Dplug:default | nc 192.168.25.9 7777  2>&1 &
