# OPNsense Firewall

## Firewall > Aliases

## Firewall > NAT > Port Forward

### Access to

|Option|OPNsense|
|:---|:---|
|Disabled|Unchecked|
|No RDR (NOT)|Unchecked|
|Interface|WAN|
|TCP/IP Version|IPv4|
|Protocol|TCP|
|Destination||
|Destination / Invert|Unchecked|
|Destination|WAN address|
|Destination port range from:|HTTP|
|Destination port range to:|HTTP|
|Redirect target IP|Single host or Network|
||192.168.101.1|
|Redirect target port|HTTP|
|Pool Options:|Default|
|Log|Unchecked|
|Category||
|Description|Nat to OPNsense|
|Set local tag||
|Match local tag||
|No XMLRPC Sync||
|NAT reflection|Use system default|
|Filter rule association|Pass|

## Firewall > Rules > WAN

## Firewall > Rules > LAnviaUSB > Default settings

***This roles wil bee disabled and replaced wit 3 new roles see below***

|Option|Input|Comment|
|:---|:---|:---|
|Action|Pass||
|Disabled|Unchecked|Disable this rule|
|Quick|Unchecked|Apply the action immediately on match.|
|Interface|LANviaUSB||
|Direction|in||
|TCP/IP Version|IPv4||
|Protocol|any||
|Source / Invert|Unchecked|Use this option to invert the sense of the match.|
|Source|LANviaUSB net||
Source	
|Destination / Invert|Unchecked|Use this option to invert the sense of the match.|
|Destination|any||
|Destination port range from:|any||
|Destination port range to:|any||
|Log|Unchecked|Log packets that are handled by this rule|
|Category|||
|Description|Default allow LAN to any rule||
|No XMLRPC Sync|Unchecked||
|Schedule|none||
|Gateway|default||

## Firewall > Rules > LAnviaUSB > 01. Allow access to DNS

|Option|Input|Comment|
|:---|:---|:---|
|Action|Pass||
|TCP/IP Version|IPv4||
|Protocol|TCP/UDP||
|Source|LANviaUSB net||
|Destination / Invert|Unchecked|Use this option to invert the sense of the match.|
|Destination|LANviaUSB address||
|Destination port range from:|DNS||
|Destination port range to:|DNS||
|Description|Allow access to DNS||

## Firewall > Rules > LAnviaUSB > 02. Allow ICMPv4 from LAN to all network

|Option|Input|Comment|
|:---|:---|:---|
|Action|Pass||
|TCP/IP Version|IPv4||
|Protocol|TCP/UDP||
|Source|LANviaUSB net||
|Destination / Invert|Unchecked|Use this option to invert the sense of the match.|
|Destination|LANviaUSB address||
|Destination port range from:|DNS||
|Destination port range to:|DNS||
|Description|Allow ICMPv4 from LAN to all network||

## Firewall > Rules > LAnviaUSB > 03. Allow access only to Internet

|Option|Input|Comment|
|:---|:---|:---|
|Action|Pass||
|TCP/IP Version|IPv4||
|Protocol|any||
|Source|LANviaUSB net||
|Destination / Invert|Checked|Use this option to invert the sense of the match.|
|Destination|PrivateNetworks||
|Destination port range from:|any||
|Destination port range to:|any||
|Description|Allow access only to Internet||

## Firewall > Rules > Office

## Firewall > Rules > Train

## Firewall > Rules > IPCam
