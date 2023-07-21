# Firewall OPNsense

## IP Plan

| addr. | VLAN 1 | VLAN 10 | VLAN 20 |
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

### Articles

* [Welcome to OPNsense’s documentation!](https://docs.opnsense.org/)
  * [OPNsense Download](https://opnsense.org/download/)
  * [OPNsense VLANs](https://docs.opnsense.org/manual/other-interfaces.html)
* [Home Network Guy - Dustin Casto](https://homenetworkguy.com/)
  * [Set Up a Fully Functioning Home Network Using OPNsense](https://homenetworkguy.com/how-to/set-up-a-fully-functioning-home-network-using-opnsense/ "Dustin Casto")
    * [How to Install and Configure OPNsense](https://homenetworkguy.com/how-to/install-and-configure-opnsense/ "Dustin Casto")
    * [How to Configure LAGG/LACP and VLANs using SFP Ports on Two TP-Link Switches](https://homenetworkguy.com/how-to/configure-lag-lacp-on-sfp-ports-two-tp-link-switches-with-vlans/ "Dustin Casto")
    * [How to Configure VLANs in OPNsense](https://homenetworkguy.com/how-to/configure-vlans-opnsense/ "Dustin Casto")
    * [How to Configure DHCP When Using VLANs in OPNsense](https://homenetworkguy.com/how-to/configure-dhcp-vlans-opnsense/ "Dustin Casto")
    * [How to Create a VLAN Only Interface in OPNsense](https://homenetworkguy.com/how-to/create-vlan-only-interface-opnsense/ "Dustin Casto")
* HPE 1820 J9983A
  * [How to set up LACP link aggregation with a HP 1810-8G v2 switch and FreeBSD 10.0-RELEASE](https://gist.github.com/pvalkone/9568061)
  
### YouTube Videos

* [Home Network Guy - Dustin Casto
  * [Set Up a Fully Functioning Home Network Using OPNsense](https://www.youtube.com/playlist?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Dustin Casto")
    * [(Part 1: Overview)](https://youtu.be/54JWsGedXpo "Dustin Casto")
    * [(Part 2: OPNsense)](https://youtu.be/h2_cQxTkh3Q "Dustin Casto")
    * [(Part 3: Switch)](https://www.youtube.com/watch?v=4HP-YAJX56E&list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I&index=3&pp=iAQB "Dustin Casto")
    * [(Part 4: Wireless Access Point)](https://www.youtube.com/watch?v=xiugRYzO3lQ&list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I&index=4&pp=iAQB "Dustin Casto")
* Tech Tutorials - David McKone
  * [How to Install OPNsense firewall](https://youtu.be/-v7MFDpjI9g?list=PLOUG593yAwIGHmd1Au6aTDOG91iGFCBA9)
* [How to make LAN & WAN interface assignments and IP address configuration on OPNsense CLI](https://youtu.be/CocyuQ-AyOY "Zenarmor")
* [Gateway IT Tutorials](https://www.youtube.com/@GatewayITTutorials/search?query=OPNsense)
  * [OPNSense Firewall Rules Explained](https://youtu.be/kYFNa_zpeII)
* [Dev Odyssey](https://www.youtube.com/@DevOdyssey/search?query=opnsense)
  * [Let's make a Router Firewall // How to install OPNsense on a PC](https://youtu.be/pXSucWm7JhE)
  * [Make more networks with this feature - How to Create a VLAN // OPNsense Firewall](https://youtu.be/GxTA0b1gAsU)
* HPE 1820
  * [ITCU Solutions - HPE 1820 Switch Configuration](https://youtu.be/BgZAbDSmU24)

## Install OPNsense

### Hardware

* Server
  * [HP Compaq 6200 Pro SFF PC](https://support.hp.com/us-en/product/hp-compaq-6200-pro-small-form-factor-pc/5037900/model/5037907?sku=XL506AV)
* Extra NIC card
  * 2 stk. [tp-link TG-3468](https://www.tp-link.com/dk/home-networking/pci-adapter/tg-3468/)  
* Wi-Fi Range Extender
  * 1 stk. [tp-link RE205 AC750 Wi-Fi Range Extender](https://www.tp-link.com/dk/home-networking/range-extender/re205/)
* VLAN Switch
  * 1 stk. [HPE 1820-24G-PoE+ (185W) Switch (J9983A)](https://support.hpe.com/hpesc/public/docDisplay?docId=c04625990&docLocale=en_US#N1092E)

### Configure * Wi-Fi Range Extender [tp-link RE205 AC750 Wi-Fi Range Extender](<https://www.tp-link.com/dk/>

* !!! To bee completed

### [Install](https://youtu.be/-v7MFDpjI9g "Tech Tutorials - David McKone")

* Boot ***'HP Compaq 6200 Pro SFF PC'***
  * Press ***'F9'*** to select Boot option
  * Please select boot devise
    * EFI boot source
      * KingstonDataTraveler 3.0
      * Press ***'Enter'***
  * Wait for ***'Login Prompt'***
    * login as ***installer***, with password ***"opnsense"***
  * Keymap Selection
    * Select Keyboard : ***'Danish'***
    * Select : ***'Continue with dk.kbd keymap'***
    * Press ***'Enter'***
  * OPNsense 23.x
    * Select : ***'Install (ZFS)'***
      * Press ***'Enter'***
    * ZFS Configuration
      * Select Virtual Device Type: ***'Stripe - No Redundancy'***
      * Press ***'Enter'***
      * Select Harddrive for Installation:
        * Press ***'SpaceBar'*** to select ***'ada0'***
      * Press ***'Enter'***
      * Last Chanced Warning
        * Press ***'YES'***
  * Final Configuration
    * Select ***'Complete Install Exit and reboot'***
    * Press ***'Enter'***
    * Remove USB-key when system reboot

### [Set LAN & WAN interface](https://youtu.be/CocyuQ-AyOY "Zenarmor")

* Boot from hardrive
* When prompt for Login, then login as ***root*** with password ***"opnsense"***
  * Select option 1
    * Press ***'n'*** we don't to configure LAGGs
    * Press ***'n'*** we don't to configure VLANs
    * Enter the WAN interface name: ***'em0'***
    * Enter the LAN interface name: ***'ue0'***
    * Press Enter to finished ***'[ENTER]'***
    * Press ***'y'*** to confirm the interface assignment
  * select Option 0 ***'Logout'***
    * Press ***'Enter'***

### [Set interface IP address]()

* When prompt for Login, then login as ***root*** with password ***"opnsense"***
  * Select option: 2
  * Select option: 1 - LAN (re0 -static, track6)
    * IPv4
      * Configure IPv4 address LAN interface via DHCP?: Press ***'Enter'***
      * Enter the new LAN IPv4 address: ***'Enter 192.168.101.1'***
      * Enter ten new LAN IPv4 subnet bit count: ***'Enter 24'***
      * For a LAN, press <ENTER> for none: ***'Press Enter'***
    * IPv6
      * Configure IPv6 address LAN interface via WAN tracking:  ***'Press N'***
      * Configure IPv6 address LAN interface via DHCPv6 tracking:  ***'Press N'***
      * Enter the new LAN IPv6 address.: ***'Press Enter'***
    * Enable DHCP LAN
      * Do you want to enable the DHCP server on LAN: ***'Press y'***
      * Enter the start address of the IPv4 client address range: ***'Enter 192.168.101.128'***
      * Enter the end address of the IPv4 client address range: ***'Enter 192.168.101.254'***
      * Do you want to change the web GUI protocol from HTTPS to HTTP?: ***'Press N'***
      * Do you want to generate a new self-signed web GUI certificate?: ***'Press N'***
      * Restore web GUI access defaults?: ***'Press N'***
    * ***OPNsense.localdomain: OPNsense 23.1***
      * LAN (ue0)   -> v4: 192.168.101.1/24
      * WAN (em0)   -> v4/DHCP4: xxx.xxx.xxx.xxx

## Configure OPNsense via WEB-page

* Connect Workstation to Lan network
* Open Browser
  * Connect to 192.168.1.1
  * Byepass warning for ***'NET ERR_CERT_AUTHORITY_INVALID'***
    * Press ***'Advanged'***
    * Press ***'Continue to 192.168.1.1 (unsafe)'***
  * Login to OPNsense
    * Username: ***'root'***
    * Password:_***'opnsense'***
    * Press ***'Enter'***



### DHCP Configuration

***Services > DHCPv4 > Page***

|Interface|Range from|Range to|
|:---|:---|:---|
|[LAN]|192.168.101.128|192.168.1.254|
|[DMZ]|192.168.110.128|192.168.110.254|
|[USER]|192.168.120.128|192.168.120.254|
|[IPCAM]|192.168.130.128|192.168.130.254|

***“Services > DHCPv4 > Leases”***

|Interface|MAC address|IP address|Hostname
|:---|:---|:---|:---|
|[LAN]||192.168.101.2|hpe1820|
|[Office]||192.168.110.8|printer|
|[Office]||192.168.110.9|wdmycloud|
|[Office]||192.168.110.10|tvpc|

### Firewall Configuration

***Firewall > Aliases***

|Option|Value|
|:---|:---|
|Enabled|Checked|
|Name|PrivateNetworks|
|Type|Network(s)|
|Content|10.0.0.0/8, 172.16.0.0/12, 192.168.0.0/16|
|Description|All local networks|

***Firewall: Rules: [LAN]***

## HPE 1820 J9983A

#### [Set up LACP on the switch](https://gist.github.com/pvalkone/9568061)

-------------------------

1) Log into the switch management interface (by default at <http://192.168.2.10/>).
2) Navigate to Trunks > Trunk Configuration
3) Set up a new trunk by giving it a name, choosing "LACP Active" mode and the ports you'd like to aggregate.
4) Click "Apply".
