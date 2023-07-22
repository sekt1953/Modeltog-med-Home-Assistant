# OPNsense Firewall

* Sources and inspiration
  * [Set Up a Fully Functioning Home Network Using OPNsense](https://homenetworkguy.com/how-to/set-up-a-fully-functioning-home-network-using-opnsense/ "Home Network Guy")
  * [Videos](https://www.youtube.com/playlist?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy")
    * [Set up a Full Network using OPNsense (Part 1: Overview)](https://youtu.be/54JWsGedXpo?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy")
    * [Set up a Full Network using OPNsense (Part 2: OPNsense)](https://youtu.be/h2_cQxTkh3Q?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy")
    * [Set up a Full Network using OPNsense (Part 3: Switch)](https://youtu.be/4HP-YAJX56E?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy")
    * [Set up a Full Network using OPNsense (Part 4: Wireless Access Point)](https://youtu.be/xiugRYzO3lQ?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy"))

## Firewall > Aliases

||**PrivateNetworks**|**HomeAssistantServer**|**HPPrinter**||**AdminPCs**|
|:---|:---|:---|:---|:---|:---|
|Enabled|**Checked**|**Checked**|**Checked**|**Checked**|**Checked**|
|Name|**PrivateNetworks**|**HomeAssistantServer**|**HPPrinter**|**HPE1820**|**AdminPCs**|
|Type|**Network(s)**|**Host(s)**|**Host(s)**|**Host(s)**|**Host(s)**|**Host(s)**|
|Categories|||||
|Content|**__lan_network, __opt1_network, __opt2_network,__opt3_network**|**192.168.120.8**|**192.168.110.8**|**192.168.101.2**|**192.168.110.16-192.168.110.24**|
|Statistics|**Unchecked**|**Unchecked**|**Unchecked**|**Unchecked**|
|Description|**All my local networks**|**Home Assistant Server for Train software**|**HP Printer**|**PC that can manage network item**|

## Firewall > NAT > Port Forward

***!!!! These rules are only for testing at home, from my workplace, so it is easier to create documentation.  
!!! Important they must be disabled or deleted during installation.***

|Server|OPNsense|HPE 1820|Home Assistant|
|:---|:---|:---|:---|
|Disabled|**Checked**|**Checked**|**Checked**|
|No RDR (NOT)|Unchecked|Unchecked|Unchecked|
|Interface|**WAN**|**WAN**|**WAN**|
|TCP/IP Version|**IPv4**|**IPv4**|**IPv4**|
|Protocol|**TCP**|**TCP**|**TCP**|
|Destination / Invert|Unchecked|Unchecked|Unchecked|
|Destination|**WAN address**|**WAN address**|**WAN address**|
|Destination port range from:|**HTTP**|**(other) 8080**|**(other) 8123**|
|Destination port range to:|**HTTP**|**(other) 8080**|**(other) 8123**|
|Redirect target IP|**Single host or Network**|**Single host or Network**|**Single host or Network**|
||**192.168.101.1**|**192.168.101.2**|**192.168.120.8**|
|Redirect target port|**HTTP**|**HTTP**|**8123**|
|Pool Options:|Default|Default|Default|
|Log|Unchecked|Unchecked|Unchecked|
|Category|||
|Description|**Nat to OPNsense**|**Nat to HPE 1820**|**Nat to Home Assistant**|
|Set local tag|||
|Match local tag||||
|No XMLRPC Sync|Unchecked|Unchecked|Unchecked|
|NAT reflection|Use system default|Use system default|Use system default|
|Filter rule association|**Pass**|**Pass**|**Pass**|

## Firewall > Rules > WAN

***Only Automatically generated rules here***

## Firewall > Rules > LAN

|Option|DNS|NTP Time|ICMP|HomeAssistant|HPPrinter|Access only to Internet|
|:---|:---|:---|:---|:---|:---|:---|
|Action|**Pass**|**Pass**|**Pass**|**Pass**|**Pass**|**Pass**|
|TCP/IP Version|**IPv4**|**IPv4**|**IPv4**|**IPv4**|**IPv4**|**IPv4**|
|Protocol|**TCP/UDP**|**UDP**|**ICMP**|**TCP**|**TCP/UDP**|**any**|
|Source|**LAN net**|**LAN net**|**LAN net**|**AdminPCs**|**AdminPCs**|
|Destination / Invert|**Unchecked**|**Unchecked**|**Unchecked**|**Unchecked**|**Unchecked**|**Checked**|
|Destination|**LAN address**|**LAN address**|**any**|**HomeAssistantServer**|**HPPrinter**|**PrivateNetworks**|
|Destination port range from:|**DNS**|**NTP**|**any**|**(other) 8123**|**any**|**any**|
|Destination port range to:|**DNS**|**NTP**|**any**|**(other) 8123**|**any**|**any**|
|Description|**Allow access to DNS**|**Allow access to NTP**|**Allow ICMPv4 from LAN to all network**|**Allow access for Admins to Home Assistant server**|**Allow access to Printer for Admins PC**|**Allow access only to Internet**|

## Firewall > Rules > Office

|Option|DNS|NTP Time|HomeAssistant|HPE1820|Access only to Internet|
|:---|:---|:---|:---|:---|:---|
|Action|**Pass**|**Pass**|**Pass**|**Pass**|**Pass**|
|TCP/IP Version|**IPv4**|**IPv4**|**IPv4**|**IPv4**|**IPv4**|
|Protocol|**TCP/UDP**|**UDP**|**TCP**|**TCP**|**any**|
|Source|**Office net**|**Office net**|**AdminPCs**|**AdminPCs**|**Office net**|
|Destination / Invert|**Unchecked**|**Unchecked**|**Unchecked**|**Unchecked**|**Checked**|
|Destination|**Office address**|**Office address**|**HomeAssistantServer**|**HPE1820**|**PrivateNetworks**|
|Destination port range from:|**DNS**|**NTP**|**(other) 8123**|**HTTP**|**any**|
|Destination port range to:|**DNS**|**NTP**|**(other) 8123**|**HTTP**|**any**|
|Description|**Allow access to DNS**|**Allow access to NTP**|**Admin Accesss to Home Assistant Server**|**Admin Accesss to HPE 1820**|**Allow access only to Internet**|

## Firewall > Rules > Train

|Option|DNS|NTP Time|Home Assistatnt|
|:---|:---|:---|:---|
|Action|**Pass**|**Pass**|**Pass**|
|TCP/IP Version|**IPv4**|**IPv4**|**IPv4**|
|Protocol|**TCP/UDP**|**UDP**|**any**|
|Source|**LAN net**|**LAN net**|**192.168.120.8**|
|Destination / Invert|**Unchecked**|**Unchecked**|**Checked**|
|Destination|**LAN address**|**LAN address**|**PrivateNetworks**|
|Destination port range from:|**DNS**|**NTP**|**any**|
|Destination port range to:|**DNS**|**NTP**|**any**|
|Description|**Allow access to DNS**|**Allow access to NTP**|**Allow HA Server access only to Internet**|

## Firewall > Rules > IPCam
