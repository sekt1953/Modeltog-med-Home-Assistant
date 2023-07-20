# OPNsense Interface

## Interfaces > Settings

|Option|Value|
|:---|:---|
|Hardware CRC|Check “Disable hardware checksum offload” (if not already checked)|
|Hardware TSO|Check “Disable hardware TCP segmentation offload” (if not already checked)|
|Hardware LRO|Check “Disable hardware large receive offload” (if not already checked)|
|VLAN Hardware Filtering|Choose the “Disable VLAN Hardware Filtering” option|

### Interfaces VLAN

|VLAN Tag|VLAN Description|Purpose|
|:---|:---|:---|
|10|Office|For PCs, laptops, Printer|
|20|Train|For HA, Tracksensor, Leddriver|
|30|IPCAM|Isolated network for IP cameras (for local access only)|

#### Interfaces > Other Types > VLAN

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

|Interface (ID )|Network port|
|:---|:---|
|WAN (wan)|em0 (2c:41:38:8d:26:f9)|
|LAN (lan)|ue0 (00:e0:4c:68:63:7b)|
|Office (opt1)|vlan01 Office (Parent: re1, Tag: 10)|
|Train (opt2)|vlan02 Train (Parent: re1, Tag: 20)|
|IPCAM (opt3)|vlan03 IPCAM (Parent: re1, Tag: 30)|

Click the “Save” button when you are finished.

***Interfaces > [Page]***

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
