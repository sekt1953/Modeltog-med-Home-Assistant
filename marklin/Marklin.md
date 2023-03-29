# Marklin modeltog med Home Assistant

## ESPHome interface for sporbesat detektor

|Schematic|Prototype|
|:---:|:---:|
|![](./Images/Sk%C3%A6rmbillede%20fra%202023-03-27%2019-27-50.png)|![](./Images/Sk%C3%A6rmbillede%20fra%202023-03-27%2019-28-04.png) |

* Files for download:
  * ESPHome
    * [Fritzing file](./Fritzing/Spor_Interface_Marklin.fzz)
      * [Schematic png](./Images/Sk%C3%A6rmbillede%20fra%202023-03-27%2019-27-50.png)
      * [Prototype png](./Images/Sk%C3%A6rmbillede%20fra%202023-03-27%2019-28-04.png)
    * [ESPHome Files](./yaml/ESPHome/)
      * [futtog-01.yaml](./yaml/ESPHome/futtog-01.yaml)
      * [secrets.yaml](./yaml/ESPHome/secrets.yaml)

---

## Home Assistant interface for sporbesat detektor

|Home Assistant|
|:---:|
|![](./Images/Sk%C3%A6rmbillede%20fra%202023-03-29%2017-42-37.png)|

* Files for download:
  * HomeAssistant
    * [Configurations Files](./yaml/HomeAssistant/Configuration/)
      * [Helper Files](./yaml/HomeAssistant/Helpers/)
      * [Automations Files](./yaml/HomeAssistant/Automations/)
    * [Lovelace](./yaml/HomeAssistant/lovelace/)
      * [Track.yaml](./yaml/HomeAssistant/lovelace/Track.yaml)
      * [Track occupied.yaml](./yaml/HomeAssistant/lovelace/Track%20occupied.yaml)
      * [Railway Crossing](./yaml/HomeAssistant/lovelace/Railway%20Crossing)
