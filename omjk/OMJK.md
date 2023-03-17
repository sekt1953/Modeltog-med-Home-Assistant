# OMJK version af HA styring

## Schematic og PCB

### SkindeInterface

* Fritzing file: [SkindeInterface.fzz](./Fritzing/SkindeInterface.fzz)

|Schematic|
|:---:|
|![Schematic1](.//Images/Sk%C3%A6rmbillede%20fra%202023-03-15%2017-32-56.png)|

### ESP32 & PCF8574

* Fritzing file: [ESP32_PCF8574.fzz](./Fritzing/ESP32_PCF8574.fzz)

|Schematic|
|:---:|
|![Schematic2](./Images/Sk%C3%A6rmbillede%20fra%202023-03-16%2019-58-07.png)|

|Protype PCB|
|:---:|
|![](./Images/Sk%C3%A6rmbillede%20fra%202023-03-16%2019-57-49.png)|

## ESPHome ESP32 Input Controler

* Note:
  * PCF8574P
    * 8bit portudvidelse I2C (2 wire) interface DIL16
    * Adresserbar til hex:
    * 0x20 0x21 0x22 0x23 0x24  0x25 0x26 0x27
  * pcf8574AP
    * 8bit portudvidelse I2C (2 wire) interface DIL16
    * Adresserbar til hex: 
    * 0x38 0x39 0x3a 0x3b 0x3c 0x3d 0x3e 0x3f
  * IC PCF8575
    * 16 I/O porte, kan hver isæt anvendes som indgang eller udgang.
    * Adresserbar til hex:
    * 0x20 0x21 0x22 0x23 0x24  0x25 0x26 0x27

### Link til: [ESP32 input controler yaml code](./yaml/esp32_input.yaml)

<hr>

## LED Controler

* Fritzing file: [LED Controler](./Fritzing/LED_Controler.fzz)

|Schematic|
|:---:|
|![Schematic3](./Images/Sk%C3%A6rmbillede%20fra%202023-03-17%2012-51-40.png)|

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