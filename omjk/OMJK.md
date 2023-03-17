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

## LED Controler

* Fritzing file: [LED Controler](./Fritzing/LED_Controler.fzz)

|Schematic|
|:---:|
|![Schematic3](./Images/Sk%C3%A6rmbillede%20fra%202023-03-17%2012-51-40.png)|

## ESPHome

### code for ESP32

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

```yaml
substitutions:
  esphome_name: "track_001"
  addr_hub0: "pcf8574_hub0"
  addr_hub1: "pcf8574_hub1"
  addr_hub2: "pcf8574_hub2"
  addr_hub3: "pcf8574_hub3"
  addr_hub4: "pcf8574_hub4"
  addr_hub5: "pcf8574_hub5"
  i2c_sda: "21"
  i2c_scl: "22"
  i2c_scan: "true"
  i2c_id: "bus_a"

esphome:
  name: ${esphome_name}
  friendly_name: ${esphome_name}

esp32:
  board: esp32dev
  framework:
    type: arduino

# Enable logging
logger:

# Enable Home Assistant API
api:
  encryption:
    key: "yrHbKGxleerdoOctryNkCifXUUh8lSCgghYNISbhLHo="

ota:
  password: "f63e9344a092d132836ace8bb0a053c9"

wifi:
  ssid: !secret wifi_ssid
  password: !secret wifi_password

  # Enable fallback hotspot (captive portal) in case wifi connection fails
  ap:
    ssid: "${esphome_name} Fallback Hotspot"
    password: "mdZZqsXjd1nT"

captive_portal:

text_sensor:
  - platform: wifi_info
    ip_address:
      name: "${esphome_name}_IP Address"
    ssid:
      name: "${esphome_name}_Connected SSID"
    bssid:
      name: "${esphome_name}_Connected BSSID"
    mac_address:
      name: "${esphome_name}_Mac Wifi Address"

i2c:
  sda: ${i2c_sda}
  scl: ${i2c_scl}
  scan: ${i2c_scan}  
  id: ${i2c_id}

# pcf8574P
# 8bit portudvidelse I2C (2 wire) interface DIL16 Adresserbar til 
# hex:  0x20 0x21 0x22 0x23 0x24  0x25 0x26 0x27

# pcf8574AP
# 8bit portudvidelse I2C (2 wire) interface DIL16 Adresserbar til 
# hex: 0x38 0x39 0x3a 0x3b 0x3c 0x3d 0x3e 0x3f 

pcf8574:
  - id: ${addr_hub0}
    address: 0x21
    pcf8575: false
  - id: ${addr_hub1}
    address: 0x38
    pcf8575: false

# Individual input hub
binary_sensor:
  - platform: gpio
    name: "Track #00"
    pin:
      pcf8574: ${addr_hub0}
      number: 0
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #01"
    pin:
      pcf8574: ${addr_hub0}
      number: 1
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #02"
    pin:
      pcf8574: ${addr_hub0}
      number: 2
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #03"
    pin:
      pcf8574: ${addr_hub0}
      number: 3
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #04"
    pin:
      pcf8574: ${addr_hub0}
      number: 4
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #05"
    pin:
      pcf8574: ${addr_hub0}
      number: 5
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #06"
    pin:
      pcf8574: ${addr_hub0}
      number: 6
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #07"
    pin:
      pcf8574: ${addr_hub0}
      number: 7
      mode:
        input: true
      inverted: true

# Individual input hub1
# binary_sensor:
  - platform: gpio
    name: "Track #08"
    pin:
      pcf8574: ${addr_hub1}
      number: 0
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #09"
    pin:
      pcf8574: ${addr_hub1}
      number: 1
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #10"
    pin:
      pcf8574: ${addr_hub1}
      number: 2
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #11"
    pin:
      pcf8574: ${addr_hub1}
      number: 3
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #12"
    pin:
      pcf8574: ${addr_hub1}
      number: 4
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #13"
    pin:
      pcf8574: ${addr_hub1}
      number: 5
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #14"
    pin:
      pcf8574: ${addr_hub1}
      number: 6
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #15"
    pin:
      pcf8574: ${addr_hub1}
      number: 7
      mode:
        input: true
      inverted: true
```

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