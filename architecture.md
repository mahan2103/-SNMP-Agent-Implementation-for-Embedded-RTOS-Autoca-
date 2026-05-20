# 🏗️ System Architecture

The SNMP agent is designed with a modular structure:

## Components

- **SNMP Manager**
  - External system (e.g., PRTG)
  - Sends SNMP GET requests

- **SNMP Agent (Autoca)**
  - Receives requests
  - Processes OIDs
  - Sends responses

- **MIB (Management Information Base)**
  - Stores OID → value pairs
  - Acts as internal data storage

## Architecture Diagram

                ┌─────────────────────────┐
                │     SNMP Manager       │
                │   (PRTG / SNMP Tool)   │
                └──────────┬─────────────┘
                           │
                           │  SNMP GET Request (UDP Port 161)
                           ▼
                ┌─────────────────────────┐
                │      SNMP Agent        │
                │       (Autoca)         │
                └──────────┬─────────────┘
                           │
        ┌──────────────────┼──────────────────┐
        │                  │                  │
        ▼                  ▼                  ▼
┌──────────────┐   ┌──────────────┐   ┌──────────────┐
│  UDP Layer   │   │ SNMP Parser  │   │    MIB DB     │
│ (snmp_udp.c) │   │ (snmp_v1.c)  │   │ (snmp_mib.c)  │
└──────┬───────┘   └──────┬───────┘   └──────┬───────┘
       │                  │                  │
       │                  ▼                  │
       │           Extract OID               │
       │                  │                  │
       │                  ▼                  │
       │          Lookup Value ◄─────────────┘
       │                  │
       ▼                  ▼
  Send Response      Build Response
       │
       ▼
┌─────────────────────────┐
│     SNMP Manager        │
│ Receives Response Value │
└─────────────────────────┘
