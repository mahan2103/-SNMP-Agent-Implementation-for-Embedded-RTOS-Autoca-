snmp_mib.c — THE DATABASE (MOST IMPORTANT FILE)
 Purpose
 This file stores all data that SNMP will return.
Think:
OID → Value

Example:
"1.3.6.1.2.1.1.5.0" → "autoca 103"


 Internal Design
 Structure
Array of entries (32 slots)
Each entry = OID + VALUE

Like:
Slot 0 → OID: systemName → "autoca 103"
Slot 1 → OID: location → "Beckum"


 Key Functions
 SNMP_MIB_Init()
 Creates the database

Sets count = 0
Sets ready flag = TRUE


SNMP_MIB_AddOrUpdate()
Adds new OID OR updates existing
Logic:
IF OID exists:
    update value
ELSE:
    add new entry


SNMP_MIB_Get()
Searches for OID
Logic:
for each entry:
    if oid matches:
        return value
if not found:
        return error


 Important Concept: g_bReady
 This is a safety switch
If not checked:

MIB might not be initialized ❌
Could crash or give garbage


 Real Understanding
 This file = brain memory of device
Everything SNMP returns comes from here.
