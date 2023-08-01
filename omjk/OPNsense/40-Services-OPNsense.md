# OPNsense Services

* Sources and inspiration
  * [Set Up a Fully Functioning Home Network Using OPNsense](https://homenetworkguy.com/how-to/set-up-a-fully-functioning-home-network-using-opnsense/ "Home Network Guy")
  * [Videos](https://www.youtube.com/playlist?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy")
    * [Set up a Full Network using OPNsense (Part 1: Overview)](https://youtu.be/54JWsGedXpo?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy")
    * [Set up a Full Network using OPNsense (Part 2: OPNsense)](https://youtu.be/h2_cQxTkh3Q?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy")
    * [Set up a Full Network using OPNsense (Part 3: Switch)](https://youtu.be/4HP-YAJX56E?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy")
    * [Set up a Full Network using OPNsense (Part 4: Wireless Access Point)](https://youtu.be/xiugRYzO3lQ?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy"))

## DHCP Configuration

Once the interfaces are enabled, you will most likely want to enable DHCP on the interfaces so that all of your devices will automatically be assigned IP addresses when they are plugged into your network switch or join your WiFi network.

For the DHCP settings, I am going use consistent values with all my networks. You may want to enable a wider range of IP addresses if you have more than 100 devices on any of your networks, but for most users the ranges I specify below will be sufficient.

If you plan to have some devices use static IP addresses (which is recommended when hosting various apps/services on your network), I recommend that you do not set the DHCP IP address range to include the full subnet (192.168.1.2 - 192.168.1.254, for example) so that you have some available addresses for static IPs.

Do not forget to click the ***“Save”*** button after configuring each interface.

## Services > DHCPv4 > [Pages]

To reduce the length of this guide, refer to the table below to enter the IP address ranges for each interface’s DHCPv4 page by going to the “Services > DHCPv4” section and clicking on each interface’s page.

For every interface below, be sure to click the “Enable” checkbox.

|Page|[LAN]|[Office]|[Train]|[IPCam]|
|:---|:---|:---|:---|:---|
|Enable|**Checked**|**Checked**|**Checked**|**Checked**|
|Deny unknown clients|**Unchecked**|**Unchecked**|**Unchecked**|**Unchecked**|
|Ignore Client UIDs|**Unchecked**|**Unchecked**|**Unchecked**|**Unchecked**|
|Subnet|**192.168.101.0**|**192.168.110.0**|**192.168.120.0**|**192.168.130.0**|
|Subnet mask|**255.255.255.0**|**255.255.255.0**|**255.255.255.0**|**255.255.255.0**|
|Available range|192.168.101.1 - 192.168.101.254|192.168.110.1 - 192.168.110.254|192.168.120.1 - 192.168.120.254|192.168.130.1 - 192.168.130.254|
|Range from:|**192.168.101.128**|**192.168.110.128**|**192.168.120.128**|**192.168.130.128**|
|Range to|**192.168.101.254**|**192.168.110.254**|**192.168.120.254**|**192.168.130.254**|
|DNS servers|**192.168.101.1**|**192.168.110.1**|**192.168.120.1**|**192.168.130.1**|
|Gateway|**192.168.101.1**|**192.168.110.1**|**192.168.120.1**|**192.168.130.1**|
|Static ARP|**Unchecked**|**Unchecked**|**Unchecked**|**Unchecked**|
|Time format change|**Unchecked**|**Unchecked**|**Unchecked**|**Unchecked**|

## Services > DHCPv4 > Leases

You can add static DHCP reservations directly from the ***“Services > DHCPv4 > Leases”*** page. It has the added benefit of prefilling the MAC address. Either way, you will need to enter the same information.

For demonstration purposes, I will use several static DHCPv4 IP reservations that will be referenced by firewall rule aliases and included in several firewall rules. I am using randomly generated MAC addresses in the table as examples, but you will need to use your actual MAC addresses.

### LAN net

|Interface|IP address|MAC address|Hostname|Description|Lease type|
|:---|:---|:---|:---|:---|:---|
|LAN|192.168.101.1|||OPNsense|**Hardcoded**|
|LAN|192.168.101.2|54:80:28:59:7d:a0||HPE1820|static|
|LAN|***192.168.101.16***|50:7b:9d:4e:5d:09|T450-01|SEKT's PC|static|
|LAN|***192.168.101.128-192.168.101.254***|||User*|DHCP|
### Office net

|Interface|IP address|MAC address|Hostname|Description|Lease type|
|:---|:---|:---|:---|:---|:---|
|Office|192.168.110.1|||OPNsense|**Hardcoded**|
|Office|192.168.110.2||WR940N|AccessPoint|**Hardcoded**|
|Office|***192.168.110.16***|50:7b:9d:4e:5d:09|T450-01|SEKT's PC|static|
|Office|***192.168.110.8***|||Printer|static|
|Office|***192.168.110.9***|||TV-PC|static|
|Office|***192.168.110.12***|||WD My Cloud|static|
|Office|***192.168.110.128-192.168.110.254***|||User*|DHCP|

### Train net

|Interface|IP address|MAC address|Hostname|Description|Lease type|
|:---|:---|:---|:---|:---|:---|
|Train|192.168.120.1|||OPNsense|**Hardcoded**|
|Train|192.168.120.2|||AccessPoint|**Hardcoded**|
|Train|***192.168.120.8***||ha-pc0-omjk||static|
|Train|***192.168.120.9***|***70:71:BC:5C:B1:A1***|ha-pc1-omjk||static|
|Train|***192.168.120.32-192.168.120.63***||trackSensor-x|ESP32|static|
|Train|***192.168.120.64-192.168.120.127***||trackLed-x|ESP32|static|
|Train|***192.168.120.128-192.168.120.254***||||DHCP|