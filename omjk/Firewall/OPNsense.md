# Firewall OPNsense

## IP Plan

| addr. | vlan1 | vlan10 | vlan20 |
|:---:  |:---:  |:---:   |:---:|
|*|Management|Office|Train|
|*|192.168.101.0/24|192.168.110.0/24|192.168.120.0/24|
|.001|Firewall|Firewall|Firewall|
|.004|*|WiFi-AP|WiFi-AP|
|.008|*|Printer|*|
|.009|*|TV-PC|*|
|.012|*|WD My Cloud|*|
|.016-.032|*|*|TrainServer|
|.128-.254|DHCP|DHCP|*|
|.128-.159|*|*|TrackSensor|
|.160-.254|*|*|LedControler|

## OPNsense Dokumentation

* [Welcome to OPNsense’s documentation!](https://docs.opnsense.org/)
  * [OPNsense Download](https://opnsense.org/download/)
  * [OPNsense VLANs](https://docs.opnsense.org/manual/other-interfaces.html)
* Tech Tutorials - David McKone
  * [How to Install OPNsense firewall](https://youtu.be/-v7MFDpjI9g?list=PLOUG593yAwIGHmd1Au6aTDOG91iGFCBA9)
* [Home Network Guy](https://www.youtube.com/playlist?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I)
  * [(Part 1: Overview)](https://youtu.be/54JWsGedXpo)
  * [(Part 2: OPNsense)](https://youtu.be/h2_cQxTkh3Q)
  * [Written guides](https://homenetworkguy.com/how-to/set-up-a-fully-functioning-home-network-using-opnsense/)
* [Gateway IT Tutorials](https://www.youtube.com/@GatewayITTutorials/search?query=OPNsense)
  * [OPNSense Firewall Rules Explained](https://youtu.be/kYFNa_zpeII)
* [Dev Odyssey](https://www.youtube.com/@DevOdyssey/search?query=opnsense)
  * [Let's make a Router Firewall // How to install OPNsense on a PC](https://youtu.be/pXSucWm7JhE)
  * [Make more networks with this feature - How to Create a VLAN // OPNsense Firewall](https://youtu.be/GxTA0b1gAsU)

