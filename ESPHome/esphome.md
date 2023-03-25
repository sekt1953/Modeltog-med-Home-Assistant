# ESPHome

## ESP32 Demokode for futtog_00

koden futtog_00.yaml består af følgende afsnit

* substitutions:
* [esphome:](https://esphome.io/components/esphome.html?highlight=esphome) 
* [esp32:](https://esphome.io/components/esp32.html?highlight=framework#esp32-platform) 
  * **board:** her defineres esp32 board type 
  * **framework:** 
    * **type:** her defineres framework type **Arduino** eller **ESP-IDF**
* [logger:](https://esphome.io/components/logger.html?highlight=logger) enable logning
* [uart:](https://esphome.io/components/uart.html?highlight=uart) her defineres comport for lyd mondulet DFPlayer mini
* [dfplayer:](https://esphome.io/components/dfplayer.html?highlight=dfplayer)
* [api:](https://esphome.io/components/api.html?highlight=api)
  * encryption: 
    * key: sætter encryptions key for api-call
  * service: her defineres api service for dfplayer mini
* [ota:](https://esphome.io/components/ota.html?highlight=ota)
  * password: 
* [wifi](https://esphome.io/components/wifi.html?highlight=wifi)  
  * ssid:
  * password:
  * ap: access point mode
    * ssid:
    * password:
* [captive_portal:](https://esphome.io/components/captive_portal.html?
highlight=captive_portal)
* [text_sensor:](https://esphome.io/components/text_sensor/index.html?highlight=text_sensor)
  * [wifi_info:](https://esphome.io/components/text_sensor/wifi_info.html?highlight=wifi_info)
* [i2c:](https://esphome.io/components/i2c.html#i2c)
* [pcf8574:](https://esphome.io/components/pcf8574.html?highlight=pcf8574)
* [binary_sensor:](https://esphome.io/components/binary_sensor/index.html?highlight=binary_sensor)
  * [gpio:](https://esphome.io/components/binary_sensor/gpio.html?highlight=gpio)

### substitutions


```yaml

```