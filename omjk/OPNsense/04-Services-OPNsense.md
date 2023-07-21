# OPNsense Services

## Services > DHCPv4 > [Pages]

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

|Interface|IP address|MAC address|Hostname|Description|Start|End|Status|Lease type
|:---|:---|:---|:---|:---|:---|:---|:---|:---|
|LAN|192.168.101.2|54:80:28:59:7d:a0 *Hewlett Packard Enterprise*|||2023/07/21 11:36:10 UTC|2023/07/21 13:36:10 UTC||static|
|LAN|192.168.101.8|50:7b:9d:4e:5d:09 *LCFC(HeFei) Electronics Technology co., ltd*|T450-01|SEKT's PC||||static|
|Office|192.168.110.128|68:f7:28:51:27:b3 *LCFC(HeFei) Electronics Technology co., ltd*|T450-02||2023/07/21 11:36:14 UTC|2023/07/21 13:36:14 UTC||active|
|Train|192.168.120.128|f0:de:f1:d2:67:b1 *Wistron Infocomm (Zhongshan) Corporation*|E525-005||2023/07/21 11:36:07 UTC|2023/07/21 13:36:07 UTC||active|
