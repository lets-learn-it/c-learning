# iptables

## Introduction

### firewall

It is a network security system monitors and control incoming and outgoing based on predetermined security rules. It typically establishes a barrier between trusted internal networks and untrusted external networks.

### netfilter

firewall solution for linux is netfilter. It is inside linux kernel so all linux based systems already has it. It enables **packet filtering, NAT, PAT, Port forwarding, packet mangling etc**. It is controlled by `iptables` command. Netfilter belongs to kernels space while iptables belongs to user-space.

### Packet Process

- Every packet is inspected by firewall rules. Firewall rules determine what traffic your firewall allows and what is blocked.
- The iptables firewall uses **tables** to organize its rules.
- within each iptables table, rules are further organized within separate **CHAINS**. *Rules are placed within a specific chain of a specific table*.
- within a chain,  a packet starts at the top of the chain and is matched rule by rule.
- when a match is found the target is executed.
- A target is the action that is triggered when a packet meets the matching criteria of the rule. If the target is terminating no other rule will evaluate the packet.

$$iptables  \rightarrow Tables  \rightarrow Chains  \rightarrow Rules$$

## Built in tables and chains

### In-built chains
- **INPUT**: used for filtering *incoming packets*. our host is packet destination.
- **OUTPUT**: used for filtering *outgoing packet*. Our host is the source of the packet.
- **FORWARD**: used for filtering *routed packets*. our host is router.
- **PREROUTING**: used for DNAT / port forwarding.
- **POSTROUTING**: used for SNAT (MASQUERADE)

>**NAT (Network Address Translation)** occurs when one of the IP address (Source or Destination) in IP packet header is changed. SNAT (Source address changed) and DNAT (Destination address changed).
>**masquerade** is form of NAT used to perform many-to-one IP address translation.

### In-built tables
- **Filter Table**: it is default table for iptables and has INPUT, OUTPUT, and FORWARD chains.
- **NAT table**: It is specialized for SNAT and DNAT (Part Forwarding) and has PREROUTING, POSTROUTING, and OUTPUT (for locally generated packets) chains.
- **Mangle table**: It is specialized for packet alteration and has PREROUTING, INPUT, OUTPUT, FORWARD and POSTROUTING chains
- **Raw table**: It is only used to set a mark on packets that should not be handled by the connection tracking system. This is done by using NOTRACK target on packet. has PREROUTING and OUTPUT chains.

## Commands

![iptable commands](./iptables-command.png)
