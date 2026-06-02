3. snmp_udp.c — NETWORK LISTENER
🎯 Purpose
👉 Handles network communication

Listens on UDP port 161
Receives SNMP requests
Sends responses


🧠 Why UDP?

Lightweight ✅
Fast ✅
No connection needed ✅ [dpstele.com]


🔥 What happens inside?
Step 1: Wait for packet
ApiSock_recvfrom(...)


Step 2: Receive SNMP packet
Example (raw bytes):
30 82 00 2B 02 01 00 ...


Step 3: Send to parser (snmp_v1.c)

Step 4: Send back response
ApiSock_sendto(...)


🧠 Real Understanding
👉 This file = door of your system

All communication comes here
Nothing enters without this
