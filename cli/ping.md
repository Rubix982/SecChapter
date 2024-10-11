# Ping

## Flags

### `-A`

**Adaptive ping**: Automatically adjust intervals between pings based on the round-trip time (RTT). This helps avoid network congestion or performance degradation.

```sh
ping -A -c 4 google.com
PING google.com (142.251.37.238): 56 data bytes
64 bytes from 142.251.37.238: icmp_seq=0 ttl=114 time=146.895 ms
64 bytes from 142.251.37.238: icmp_seq=1 ttl=114 time=146.908 ms
64 bytes from 142.251.37.238: icmp_seq=2 ttl=114 time=155.874 ms
64 bytes from 142.251.37.238: icmp_seq=3 ttl=114 time=148.450 ms

--- google.com ping statistics ---
4 packets transmitted, 4 packets received, 0.0% packet loss
round-trip min/avg/max/stddev = 146.895/149.532/155.874/3.716 ms
```

### `-a`

**Audible ping**: Makes a sound (beep) when the destination responds, which can be useful when monitoring the connectivity of a host without staring at the terminal.

```sh
ping -a -c 4 google.com
PING google.com (142.251.37.238): 56 data bytes
64 bytes from 142.251.37.238: icmp_seq=0 ttl=114 time=150.847 ms
64 bytes from 142.251.37.238: icmp_seq=1 ttl=114 time=151.684 ms
64 bytes from 142.251.37.238: icmp_seq=2 ttl=114 time=155.741 ms
^C
--- google.com ping statistics ---
3 packets transmitted, 3 packets received, 0.0% packet loss
round-trip min/avg/max/stddev = 150.847/152.757/155.741/2.137 ms
```

### `-D`

**Set the Don't Fragment bit**.

```sh
$ ping -s 1400 google.com
PING google.com (216.58.205.206): 1400 data bytes
Request timeout for icmp_seq 0
Request timeout for icmp_seq 1
1408 bytes from 216.58.205.206: icmp_seq=2 ttl=114 time=148.802 ms
1408 bytes from 216.58.205.206: icmp_seq=3 ttl=114 time=153.675 ms
1408 bytes from 216.58.205.206: icmp_seq=4 ttl=114 time=148.035 ms
1408 bytes from 216.58.205.206: icmp_seq=5 ttl=114 time=149.434 ms
1408 bytes from 216.58.205.206: icmp_seq=6 ttl=114 time=160.118 ms
```

```sh
$ ping -D -s 1400 -c 4 google.com
PING google.com (142.250.203.238): 1400 data bytes
ping: sendto: Message too long
Request timeout for icmp_seq 0
ping: sendto: Message too long
Request timeout for icmp_seq 1
ping: sendto: Message too long
Request timeout for icmp_seq 2

--- google.com ping statistics ---
4 packets transmitted, 0 packets received, 100.0% packet loss
```

### `-d`

**Enable debugging**: Outputs detailed information useful for diagnosing issues in ping or the network. Set the SO_DEBUG option on the socket being used.

```sh
$ ping -d -s 64 -c 9 google.com

PING google.com (142.250.203.238): 64 data bytes
72 bytes from 142.250.203.238: icmp_seq=0 ttl=114 time=147.345 ms
72 bytes from 142.250.203.238: icmp_seq=1 ttl=114 time=150.100 ms
72 bytes from 142.250.203.238: icmp_seq=2 ttl=114 time=148.130 ms
72 bytes from 142.250.203.238: icmp_seq=3 ttl=114 time=149.267 ms
72 bytes from 142.250.203.238: icmp_seq=4 ttl=114 time=150.005 ms
72 bytes from 142.250.203.238: icmp_seq=5 ttl=114 time=149.362 ms
72 bytes from 142.250.203.238: icmp_seq=6 ttl=114 time=153.743 ms
72 bytes from 142.250.203.238: icmp_seq=7 ttl=114 time=148.258 ms
72 bytes from 142.250.203.238: icmp_seq=8 ttl=114 time=147.613 ms
--- google.com ping statistics ---
9 packets transmitted, 9 packets received, 0.0% packet loss
round-trip min/avg/max/stddev = 147.345/149.314/153.743/1.826 ms
```

### `-f`

**Flood ping**: Sends pings as fast as possible without waiting for replies, which tests the limits of the network. This option requires root (administrator) privileges. 

Outputs packets as fast as they come back or one hundred times per second, whichever is more.
For every ECHO_REQUEST sent a period “.” is printed, while for every ECHO_REPLY received a backspace is printed.
This provides a rapid display of how many packets are being dropped.  Only the super-user may use this option.
This can be very hard on a network and should be used with caution.

```sh
sudo ping -f 127.0.0.1
Password:
PING 127.0.0.1 (127.0.0.1): 56 data bytes
..Request timeout for icmp_seq 0
.Request timeout for icmp_seq 1
.Request timeout for icmp_seq 2
.Request timeout for icmp_seq 3
.Request timeout for icmp_seq 4
.Request timeout for icmp_seq 5
.Request timeout for icmp_seq 6
.Request timeout for icmp_seq 7
.Request timeout for icmp_seq 8
.Request timeout for icmp_seq 9
.Request timeout for icmp_seq 10
.Request timeout for icmp_seq 11
.Request timeout for icmp_seq 12
.Request timeout for icmp_seq 13
.Request timeout for icmp_seq 14
.Request timeout for icmp_seq 15
.Request timeout for icmp_seq 16
.Request timeout for icmp_seq 17
.Request timeout for icmp_seq 18
.Request timeout for icmp_seq 19
.Request timeout for icmp_seq 20
...
^C
--- 127.0.0.1 ping statistics ---
99 packets transmitted, 0 packets received, 100.0% packet loss
```

### `-n`

**Numeric output only**: Displays only IP addresses, without trying to resolve hostnames.
This makes the output faster since no DNS lookups are performed.
No attempt will be made to lookup symbolic names for host addresses.

```sh
$ ping -n google.com
PING google.com (142.251.37.206): 56 data bytes
64 bytes from 142.251.37.206: icmp_seq=0 ttl=114 time=148.339 ms
64 bytes from 142.251.37.206: icmp_seq=1 ttl=114 time=147.037 ms
64 bytes from 142.251.37.206: icmp_seq=2 ttl=114 time=148.608 ms
64 bytes from 142.251.37.206: icmp_seq=3 ttl=114 time=148.888 ms
64 bytes from 142.251.37.206: icmp_seq=4 ttl=114 time=148.732 ms
64 bytes from 142.251.37.206: icmp_seq=5 ttl=114 time=152.680 ms
^C
--- google.com ping statistics ---
6 packets transmitted, 6 packets received, 0.0% packet loss
round-trip min/avg/max/stddev = 147.037/149.047/152.680/1.735 ms
```

### `-o`

**Exit on the first received reply**: The ping command stops as soon as the first reply is received, which is useful for quickly checking connectivity.

```sh
ping -o google.com
```

### `-Q`

**Somewhat quiet output**. Don't display ICMP error messages that are in response to our query messages.
Originally, the -v flag was required to display such errors, but -v displays all ICMP error messages.
On a busy machine, this output can be overbearing.
Without the -Q flag, ping prints out any ICMP error messages caused by its own ECHO_REQUEST messages.

```sh
ping -Q -c 4 google.com
PING google.com (142.251.37.206): 56 data bytes
64 bytes from 142.251.37.206: icmp_seq=0 ttl=114 time=146.813 ms
64 bytes from 142.251.37.206: icmp_seq=1 ttl=114 time=147.065 ms
64 bytes from 142.251.37.206: icmp_seq=2 ttl=114 time=149.612 ms
64 bytes from 142.251.37.206: icmp_seq=3 ttl=114 time=150.833 ms

--- google.com ping statistics ---
4 packets transmitted, 4 packets received, 0.0% packet loss
round-trip min/avg/max/stddev = 146.813/148.581/150.833/1.700 ms
```

### `-q`

**Quiet output**.  Nothing is displayed except the summary lines at startup time and when finished.

```sh
ping -q -c 4 google.com
PING google.com (142.251.37.206): 56 data bytes

--- google.com ping statistics ---
4 packets transmitted, 4 packets received, 0.0% packet loss
round-trip min/avg/max/stddev = 147.580/149.904/152.124/1.656 ms
```

### `-R`

**Record route**. Includes the RECORD_ROUTE option in the ECHO_REQUEST packet and displays the route buffer on returned packets.
This option is deprecated and is now a no-op.

### `-r`

Bypass the normal routing tables and send directly to a host on an attached network.
If the host is not on a directly-attached network, an error is returned.
This option can be used to ping a local host through an interface that has no route through it (e.g., after the interface was dropped by routed(8)).

```sh
ping -r -c 4 google.com
PING google.com (142.251.37.206): 56 data bytes
ping: sendto: Network is unreachable
Request timeout for icmp_seq 0
ping: sendto: Network is unreachable
Request timeout for icmp_seq 1
ping: sendto: Network is unreachable
Request timeout for icmp_seq 2

--- google.com ping statistics ---
4 packets transmitted, 0 packets received, 100.0% packet loss
```

### `-v`

**Verbose output**. ICMP packets other than ECHO_RESPONSE that are received are listed.

```sh
ping -v -c 4 google.com
PING google.com (142.250.203.238): 56 data bytes
64 bytes from 142.250.203.238: icmp_seq=0 ttl=114 time=161.915 ms
64 bytes from 142.250.203.238: icmp_seq=1 ttl=114 time=147.565 ms
64 bytes from 142.250.203.238: icmp_seq=2 ttl=114 time=149.092 ms
64 bytes from 142.250.203.238: icmp_seq=3 ttl=114 time=161.027 ms

--- google.com ping statistics ---
4 packets transmitted, 4 packets received, 0.0% packet loss
round-trip min/avg/max/stddev = 147.565/154.900/161.915/6.601 ms
```



    

