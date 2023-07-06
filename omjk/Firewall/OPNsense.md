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

* [Welcome to OPNsense’s documentation!](https://docs.opnsense.org/)
  * [OPNsense Download](https://opnsense.org/download/)
  * [OPNsense VLANs](https://docs.opnsense.org/manual/other-interfaces.html)
* Tech Tutorials - David McKone
  * [How to Install OPNsense firewall](https://youtu.be/-v7MFDpjI9g?list=PLOUG593yAwIGHmd1Au6aTDOG91iGFCBA9)
* [How to make LAN & WAN interface assignments and IP address configuration on OPNsense CLI](https://youtu.be/CocyuQ-AyOY "Zenarmor")
* [Home Network Guy](https://www.youtube.com/playlist?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I)
  * [(Part 1: Overview)](https://youtu.be/54JWsGedXpo)
  * [(Part 2: OPNsense)](https://youtu.be/h2_cQxTkh3Q)
  * [Written guides](https://homenetworkguy.com/how-to/set-up-a-fully-functioning-home-network-using-opnsense/)
* [Gateway IT Tutorials](https://www.youtube.com/@GatewayITTutorials/search?query=OPNsense)
  * [OPNSense Firewall Rules Explained](https://youtu.be/kYFNa_zpeII)
* [Dev Odyssey](https://www.youtube.com/@DevOdyssey/search?query=opnsense)
  * [Let's make a Router Firewall // How to install OPNsense on a PC](https://youtu.be/pXSucWm7JhE)
  * [Make more networks with this feature - How to Create a VLAN // OPNsense Firewall](https://youtu.be/GxTA0b1gAsU)

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
    * Enter the LAN interface name: ***'re0'***
    * Press Enter to finished ***'[ENTER]'***
    * Press ***'y'*** to confirm the interface assignment
  * select Option 0 ***'Logout'***
    * Press ***'Enter'***

### Configure OPNsense via WEB-page

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
