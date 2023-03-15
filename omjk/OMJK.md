# OMJK version af HA styring

## Schematic og PCB

### SkindeInterface

|Schematic|PCB|
|:---:|:---:|
|![Schematic1](./omjk/Images/Sk%C3%A6rmbillede%20fra%202023-03-15%2017-32-56.png)||

### ESP32 & PCF8574

|Schematic|PCB|
|:---:|:---:|
|![Schematic2](./omjk/Images/Sk%C3%A6rmbillede%20fra%202023-03-15%2017-58-53.png)|![pcb2](./omjk/Images/Sk%C3%A6rmbillede%20fra%202023-03-15%2017-59-12.png)|

## ESPHome

### code for ESP32

```yaml
substitutions:
  esphome_name: "track_001"

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
    ssid: "Futtog-001 Fallback Hotspot"
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
  sda: 21
  scl: 22
  scan: true
  id: bus_a    

pcf8574:
  - id: 'pcf8574_hub'
    address: 0x21
    pcf8575: false
  - id: 'pcf8574_hub1'
    address: 0x38
    pcf8575: false

# Individual input hub
binary_sensor:
  - platform: gpio
    name: "Track #00"
    pin:
      pcf8574: pcf8574_hub
      number: 0
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #01"
    pin:
      pcf8574: pcf8574_hub
      number: 1
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #02"
    pin:
      pcf8574: pcf8574_hub
      number: 2
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #03"
    pin:
      pcf8574: pcf8574_hub
      number: 3
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #04"
    pin:
      pcf8574: pcf8574_hub
      number: 4
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #05"
    pin:
      pcf8574: pcf8574_hub
      number: 5
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #06"
    pin:
      pcf8574: pcf8574_hub
      number: 6
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #07"
    pin:
      pcf8574: pcf8574_hub
      number: 7
      mode:
        input: true
      inverted: true

# Individual input hub1
# binary_sensor:
  - platform: gpio
    name: "Track #08"
    pin:
      pcf8574: pcf8574_hub1
      number: 0
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #09"
    pin:
      pcf8574: pcf8574_hub1
      number: 1
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #10"
    pin:
      pcf8574: pcf8574_hub1
      number: 2
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #11"
    pin:
      pcf8574: pcf8574_hub1
      number: 3
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #12"
    pin:
      pcf8574: pcf8574_hub1
      number: 4
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #13"
    pin:
      pcf8574: pcf8574_hub1
      number: 5
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #14"
    pin:
      pcf8574: pcf8574_hub1
      number: 6
      mode:
        input: true
      inverted: true
  - platform: gpio
    name: "Track #15"
    pin:
      pcf8574: pcf8574_hub1
      number: 7
      mode:
        input: true
      inverted: true
```

## Home Assistant

### Lovelace

|Track||
|:---:|:---:|
|![Track1](./omjk/Images/Sk%C3%A6rmbillede%20fra%202023-03-15%2018-18-34.png)|![]()|

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