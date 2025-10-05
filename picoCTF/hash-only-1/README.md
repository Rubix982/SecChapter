# Hash Only 1

Here is a binary that has enough privilege to read the content of the flag file but will only let you know its hash. If only it could just give you the actual content!
Connect using ssh ctf-player@shape-facility.picoctf.net -p 50775 with the password, d65a1577 and run the binary named "flaghasher".
You can get a copy of the binary if you wish: scp -P 50775 ctf-player@shape-facility.picoctf.net:~/flaghasher .