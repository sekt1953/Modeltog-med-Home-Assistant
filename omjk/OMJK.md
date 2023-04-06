# OMJK version af HA styring

## Schematic og PCB

### PCB-CPU & Power

|Schematic|
|:---:|
|![Schematic1](./Fritzing/PCB-CPU/PCB-CPU_and_Power_schem.png)|

|PCB|
|:---:|
|![pcb](./Fritzing/PCB-CPU/PCB-CPU_and_Power_bb.png)|

### Files

* Fritzing
  * [Fritzing CPU-File](./Fritzing/PCB-CPU/PCB-CPU_and_Power.fzz)
* ESPHome yaml]
  * [CPU with TrackSensor]()

### Matrialer

* IC 
  * [ESP32 DEV KIT DOIT Udviklingsboard](https://ebits.dk/products/esp32-dev-kit-doit-udviklingsboard?_pos=2&_sid=e219da91c&_ss=r "ebits.dk")
  * [I2C Expander - TCA9548A](https://arduinotech.dk/shop/8-channel-i2c-muti-channel-expansion-development-board/ "Arduino Tech.dk")
  * [Step Down 4.5-24 DC-DC 3A 0.8-17V Module Adjustable](https://ardustore.dk/produkt/step-down-4-5-24-dc-dc-3a-0-8-17v-module-adjustable "ardustore.dk")
* Connector
  * Pin Header Male
    * 1 stk. [Pin Header Male Single Row 1×40](https://ardustore.dk/produkt/pin-header-male-single-row-1x40 "ardustore.dk")
  * Dupont Jumper Wire Male
    * 1 stk. [10stk. Dupont Jumper Wire 1p 10cm Hun-Hun](https://arduinotech.dk/shop/dupont-jumper-wire-1p-10cm/  "Arduino Tech.dk")
    * Dupont Connector Housing
    * 7 stk. [2 pol Dupont Connector Housing](https://arduinotech.dk/shop/dupont-stik-1p-10p-diy/)
    * 1 stk. [4 pol Dupont Connector Housing](https://arduinotech.dk/shop/dupont-stik-1p-10p-diy/)
    * 2 stk. [6 pol Dupont Connector Housing](https://arduinotech.dk/shop/dupont-stik-1p-10p-diy/)
  * PINRÆKKE M.FLIG VINKEL MOD 2.54 5556
    * 1 stk. [2PL. PINRÆKKE M.FLIG VINKEL MOD 2.54 (vnr: 5556.02A)](https://el-supply.dk/2pl-pinraekke-mflig-vinkel-mod-254/varenummer/0-5556.02A "el-supply.dk")
    * 6 stk. [4PL. PINRÆKKE M.FLIG VINKEL MOD 2.54 (vnr: 5556.04A)](https://el-supply.dk/4pl-pinraekke-mflig-vinkel-mod-254/varenummer/0-5556.04A "el-supply.dk")
  * LØS CRIMPHUS med LÅS
    * 1 stk. [LØS CRIMPHUS med LÅS 2PL MOD 2.54 (vnr: 5557.02)](https://el-supply.dk/loes-crimphus-med-laas-2pl-mod-254/varenummer/0-5557.02 "el-supply.dk")
    * 6 stk. [LØS CRIMPHUS med LÅS 6PL MOD 2.54 (vnr: 5557.06)](https://el-supply.dk/loes-crimphus-med-laas-6pl-mod-254/varenummer/0-5557.06 "el-supply.dk")
  * LEDNING MED CRIMPTERMINAL 5594
    * 7 stk. [LEDNING MED CRIMPTERMINAL 30cm SORT (vnr: 5594.0)](https://el-supply.dk/ledning-med-crimpterminal-30cm-sort/varenummer/0-5594.0 "el-supply.dk")
    * 6 stk. [LEDNING MED CRIMPTERMINAL 30cm RØD (vnr: 5594.2)](https://el-supply.dk/ledning-med-crimpterminal-30cm-roed/varenummer/0-5594.2 "el-supply.dk")
    * 1 stk. [LEDNING MED CRIMPTERMINAL 30cm GUL (vnr: 5594.4)](https://el-supply.dk/ledning-med-crimpterminal-30cm-gul/varenummer/0-5594.4 "el-supply.dk")
* PCB
  * [Rademacher WR-Typ 941 Printplade](https://www.conradelektronik.dk/p/rademacher-wr-typ-941-europrintplade-epoxyd-l-x-b-160-mm-x-100-mm-35-m-rastermal-254-mm-indhold-1-stk-529568 "conradelektronik.dk")


### PCB-TrackSensor

|Schematic|
|:---:|
|![Schematic1](./Fritzing/PCB-TrackSensor/PCB-TrackSensor_schem.png)|

|PCB|
|:---:|
|![pcb](./Fritzing/PCB-TrackSensor/PCB-TrackSensor_bb.png)|

* [Fritzing TrackSensor-File](./Fritzing/PCB-TrackSensor/PCB-TrackSensor.fzz)

### PCB-PCB-LedDriver

|Schematic|
|:---:|
|![Schematic1](./Fritzing/PCB-LedDriver/PCB-LedDriver_schem.png)|

|PCB|
|:---:|
|![pcb](./Fritzing/PCB-LedDriver/PCB-LedDriver_bb.png)|

* [Fritzing LedDriver-File](./Fritzing/PCB-LedDriver/PCB-LedDriver.fzz)

### SkindeInterface

* Fritzing file: [SkindeInterface.fzz](./Fritzing/Sporbes%C3%A6ttelse_Ny.fzz)

|Schematic|
|:---:|
|![Schematic1](./Images/Sk%C3%A6rmbillede%20fra%202023-03-27%2019-43-19.png)|

<hr>

## Home Assistant

### Lovelace

|Track||
|:---:|:---:|
|![Track1](./Images/Sk%C3%A6rmbillede%20fra%202023-03-17%2014-30-21.png)|![]()|

### Lovelace yaml

Track 001.000-007:

```yaml
type: entities
entities:
  - entity: sensor.futtog_001_futtog_001_ip_address
  - entity: binary_sensor.futtog_001_track_000
  - entity: binary_sensor.futtog_001_track_001
  - entity: binary_sensor.futtog_001_track_002
  - entity: binary_sensor.futtog_001_track_003
  - entity: binary_sensor.futtog_001_track_004
  - entity: binary_sensor.futtog_001_track_005
  - entity: binary_sensor.futtog_001_track_006
  - entity: binary_sensor.futtog_001_track_007
title: Track 001.000-007
state_color: true

```

Track 001.100-107:

```yaml
type: entities
entities:
  - entity: sensor.futtog_001_futtog_001_ip_address
  - entity: binary_sensor.futtog_001_track_100
  - entity: binary_sensor.futtog_001_track_101
  - entity: binary_sensor.futtog_001_track_102
  - entity: binary_sensor.futtog_001_track_103
  - entity: binary_sensor.futtog_001_track_104
  - entity: binary_sensor.futtog_001_track_105
  - entity: binary_sensor.futtog_001_track_106
  - entity: binary_sensor.futtog_001_track_107
title: Track 001.100-107
state_color: true

```