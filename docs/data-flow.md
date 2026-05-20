# 🔄 Data Flow

## Boot Process

1. Initialize SNMP module
2. Create MIB storage
3. Insert system values:
   - System Name
   - Location
4. Start heartbeat update thread
5. Start UDP listener

---

## Request Handling

When a request arrives:

1. SNMP Manager sends GET request
2. UDP listener receives packet
3. SNMP parser extracts OID
4. MIB searches value
5. Response packet is created
6. Response sent back to Manager

---

## Example

Request:GET 1.3.6.1.2.1.1.5.0
Response: autoca 103
