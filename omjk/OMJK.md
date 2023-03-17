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
|![Track1](./Images/Sk%C3%A6rmbillede%20fra%202023-03-15%2018-18-34.png)|![]()|

### Lovelace yaml

Track 00-07:

```yaml
type: entities
entities:
  - entity: sensor.futtog_001_esphome_name_ip_address
    name: IP Address
    secondary_info: none
  - entity: binary_sensor.futtog_001_track_00
    name: 'Track #00'
  - entity: binary_sensor.futtog_001_track_01
    name: 'Track #01'
  - entity: binary_sensor.futtog_001_track_02
    name: 'Track #02'
  - entity: binary_sensor.futtog_001_track_03
    name: 'Track #03'
  - entity: binary_sensor.futtog_001_track_04
    name: 'Track #04'
  - entity: binary_sensor.futtog_001_track_05
    name: 'Track #05'
  - entity: binary_sensor.futtog_001_track_06
    name: 'Track #06'
  - entity: binary_sensor.futtog_001_track_07
    name: 'Track #07'
title: Track 00-07
state_color: true

```

Track 08-15:

```yaml
type: entities
entities:
  - entity: sensor.futtog_001_esphome_name_ip_address
    name: IP Address
  - entity: binary_sensor.futtog_001_track_08
    name: 'Track #08'
  - entity: binary_sensor.futtog_001_track_09
    name: 'Track #09'
  - entity: binary_sensor.futtog_001_track_10
    name: 'Track #10'
  - entity: binary_sensor.futtog_001_track_11
    name: 'Track #11'
  - entity: binary_sensor.futtog_001_track_12
    name: 'Track #12'
  - entity: binary_sensor.futtog_001_track_13
    name: 'Track #13'
  - entity: binary_sensor.futtog_001_track_14
    name: 'Track #14'
  - entity: binary_sensor.futtog_001_track_15
    name: 'Track #15'
title: Track 08-15
state_color: true

```