# OPNsense Interface

* Sources and inspiration
  * [Set Up a Fully Functioning Home Network Using OPNsense](https://homenetworkguy.com/how-to/set-up-a-fully-functioning-home-network-using-opnsense/ "Home Network Guy")
  * [Videos](https://www.youtube.com/playlist?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy")
    * [Set up a Full Network using OPNsense (Part 1: Overview)](https://youtu.be/54JWsGedXpo?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy")
    * [Set up a Full Network using OPNsense (Part 2: OPNsense)](https://youtu.be/h2_cQxTkh3Q?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy")
    * [Set up a Full Network using OPNsense (Part 3: Switch)](https://youtu.be/4HP-YAJX56E?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy")
    * [Set up a Full Network using OPNsense (Part 4: Wireless Access Point)](https://youtu.be/xiugRYzO3lQ?list=PLZeTcCOrKlnDlyZCIxhFZukAnA0NNWL_I "Home Network Guy"))

## Interfaces > Settings

|Option|Value|
|:---|:---|
|Hardware CRC|Check “Disable hardware checksum offload” (if not already checked)|
|Hardware TSO|Check “Disable hardware TCP segmentation offload” (if not already checked)|
|Hardware LRO|Check “Disable hardware large receive offload” (if not already checked)|
|VLAN Hardware Filtering|Choose the “Disable VLAN Hardware Filtering” option|

### Interfaces > Other Types: VLAN

For the purposes of this guide, the following VLANs will be created along with some of the reasons why We may want such a VLAN on your network:

|VLAN Tag|VLAN Description|Purpose|
|:---|:---|:---|
|10|Office|For PCs, laptops, Printer|
|20|Train|For HA, Tracksensor, Leddriver|
|30|IPCAM|Isolated network for IP cameras (for local access only)|

#### Interfaces > Other Types > VLAN

Create the VLANs by navigating to the “Interfaces > Other Types > VLAN” page. To minimize the length of this guide, repeat the following configuration below for each VLAN in the table above:

|Option|VLAN10|VLAN20|VLAN30|
|:---|:---|:---|:---|
|Device||||
|Parent|re1 (ac:15:a2:60:df:06)|re1 (ac:15:a2:60:df:06)|re1 (ac:15:a2:60:df:06)|
|VLAN tag|10|20|30|
|VLAN priority|Best Effort (0, default)|Best Effort (0, default)|Best Effort (0, default)|
|Description|Office|Train|IPCam|

Press: ***[Save]***
Press: ***[Apply]***

#### Interfaces > Assignments

After the VLANs are created, you will be able to assign them to interfaces. You can think of an “interface” as not only the address of the physical port itself but also an entirely separate network. That concept may seem confusing to new users, but creating a new interface assignment is how you create separate physical or logical networks in OPNsense (and other router platforms). When creating an interface you can specify the size of the network, which limits the total number of devices that can be connected to each network. The interface acts as the gateway for each network where traffic may enter or exit.

On the “Interfaces > Assignments” page, you can create a new interface by clicking on the “+” button in the “New interface” section of the page. The dropdown box only shows unassigned physical/logical interfaces. Once you assign the interface, it will no longer be included in the dropdown.

The WAN and LAN interfaces should already be assigned from the OPNsense installation so I will only mention setting up the VLAN interface assignments.

Select each VLAN listed in the table below in the “Network port” dropdown box and add the appropriate “Description”. The “Description” is displayed on the “Interfaces” section in the left side menu so it is important to use a short name to indicate the purpose of each network. Otherwise, they will show up as “OPT1”, “OPT2”, etc., which will be very confusing when you have multiple networks to manage.

|Interface (ID )|Network port|
|:---|:---|
|WAN (wan)|em0 (2c:41:38:8d:26:f9)|
|LAN (lan)|re0 (ac:15:a2:02:e4:a9)|
|Office (opt1)|vlan01 Office (Parent: re1, Tag: 10)|
|Train (opt2)|vlan02 Train (Parent: re1, Tag: 20)|
|IPCAM (opt3)|vlan03 IPCAM (Parent: re1, Tag: 30)|

Click the “Save” button when you are finished.

***Interfaces > [Page]***

Each interface has its own page under the “Interfaces” menu on the left side of the OPNsense user interface. They will appear as [WAN], [LAN], etc. Go to the appropriate interface pages below to modify the configuration described below.

|Option|WAN|LAN|Office|Train|IPCam|
|:---|:---|:---|:---|:---|:---|
|Enable|**Enable Interface**|**Enable Interface**|**Enable Interface**|**Enable Interface**|**Enable Interface**|
|Lock|**Check**|**Check**|**Check**|**Check**|**Check**|
|Description|**WAN**|**LAN**|**Office**|**Train**|**IPCam**|
|Block private networks|**Unchecked**|**Unchecked**|**Unchecked**|**Unchecked**|**Unchecked**|
|Block bogon networks|**Unchecked**|**Unchecked**|**Unchecked**|**Unchecked**|**Unchecked**|
|IPv4 Configuration Type|**DHCP**|**Static IPv4**|**Static IPv4**|**Static IPv4**|**Static IPv4**|
|IPv6 Configuration Type||**None**|**None**|**None**|**None**|
|Static IPv4 configuration||
|IPv4 address||**192.168.101.1/24**|**192.168.110.1/24**|**192.168.120.1/24**|**192.168.130.1/24**|
