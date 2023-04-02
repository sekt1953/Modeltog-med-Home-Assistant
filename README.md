# Modeltog med Home Assistant og ESPHome

![lovelace](./marklin/Images/Sk%C3%A6rmbillede%20fra%202023-03-29%2017-42-37.png)

## PCB Layout

|Marklin|OMJK|
|:---:|:---:|
|![Marklin](./marklin/Images/Sk%C3%A6rmbillede%20fra%202023-03-27%2019-28-04.png)  |![OMJK](./omjk/Images/Sk%C3%A6rmbillede%20fra%202023-03-16%2019-57-49.png)|

* Marklin version af styring 
  * [Lars's Marklin anlæg](./marklin/Marklin.md)
* OMJK version af styring [OMJK hjemmeside](https://www.facebook.com/omjk1949)
  * [Sporbesat detector for OMJK's anlæg](./omjk/OMJK.md)

## ESPHome

Her findes demokode til ESP32 futtog_00
og beskrivelse af koden.

* [beskrivelse af yaml kode for Futtog-00](./ESPHome/esphome.md)
  * Kode beskrivelse:
    * Sporbesat detector 
    * Lydmoduel DFPlayer minni
  * [futtog-00.yaml](./ESPHome/yaml/futtog-00.yaml)

## Home Assistant

* Automations
  * Spor besat indikering
  * Baneoverskæring
* Lovelace

## Matrialer

* PCB
  * [Rademacher WR-Typ 922 Printplade](https://www.conradelektronik.dk/p/rademacher-wr-typ-922-printplade-til-eksperimenter-hardt-papir-l-x-b-160-mm-x-100-mm-35-m-rastermal-254-mm-indhold-521214 "conradelektronik.dk")
  * [Rademacher WR-Typ 941 Printplade](https://www.conradelektronik.dk/p/rademacher-wr-typ-941-europrintplade-epoxyd-l-x-b-160-mm-x-100-mm-35-m-rastermal-254-mm-indhold-1-stk-529568 "conradelektronik.dk")
  * [Rademacher WR-Typ 821 Hulprint 5.08 mm](https://www.conradelektronik.dk/p/rademacher-wr-typ-821-printplade-hardt-papir-l-x-b-160-mm-x-100-mm-35-m-rastermal-508-mm-indhold-1-stk-527232 "conradelektronik.dk")
* PCB Connector
  * DIN 41612 Connector
    * [Hankonnektor Samlet poltal 96 Antal rækker 3](https://www.conradelektronik.dk/p/tru-components-tc-a-cm96abcr-203-hankonnektor-samlet-poltal-96-antal-rkker-3-1-stk-1586479 "conradelektronik.dk")
    * [ERNI 224470 Multistikfatning Samlet poltal 96 Antal rækker](https://www.conradelektronik.dk/p/erni-224470-multistikfatning-samlet-poltal-96-antal-rkker-3-1-stk-1169120 "conradelektronik.dk")
  * Screw Terminal Blocks  
    * [KF128 2.54mm PCB Mini Screw Terminal Blocks](https://www.aliexpress.com/item/1005001677869988.html?spm=a2g0o.productlist.main.1.dbd222fdV7W0to&algo_pvid=aa72d057-3d1a-4c99-b944-2046c7ceadf4&algo_exp_id=aa72d057-3d1a-4c99-b944-2046c7ceadf4-0&pdp_ext_f=%7B%22sku_id%22%3A%2212000030016966538%22%7D&pdp_npi=3%40dis%21DKK%2123.02%2117.93%21%21%21%21%21%40212250c216804576244045200d0707%2112000030016966538%21sea%21DK%210&curPageLogUid=WK4w9B6z5Rnf) 
* CPU
  * [ESP32 DEV KIT DOIT Udviklingsboard](https://ebits.dk/products/esp32-dev-kit-doit-udviklingsboard?_pos=2&_sid=e219da91c&_ss=r "ebits.dk")
    * [Sådan løses CH340 USB til Serial Problem](https://unix.stackexchange.com/a/670637 "unix.stackexchange.com")
* IC's
  * [PCF8574P](https://softgenie.dk/ic/946-pcf8574.html "softgenie.dk")
  * [PCF8574AP ](https://softgenie.dk/ic/259-pcf8574ap.html "softgenie.dk")
  * [PCF8575](https://softgenie.dk/diverse/1534-i2c-16-portudvidelse-arduiniraspberry.html "softgenie.dk")
  * [PC817 / PC847](https://softgenie.dk/ic/302-pc817-opto-coubler.html "softgenie.dk")
  * [TLP620-4](https://el-supply.dk/tlp620-4-optokobler-55v-50ma-5kv-dil16/varenummer/0-386TLP620-4 "EL-Supply")
* Pin Header
  * [IC sokkel række - 40pin](https://softgenie.dk/ic-sokler/293-ic-sokel-raekke-40pin.html "softgenie.dk")
  * [40 pin stiftrække han 1 række](https://softgenie.dk/stik-connector/263-40-pin-stiftraekke-han-1-raekke.html "softgenie.dk")
  * [Stift hun 2.54mm 1 række](https://softgenie.dk/stik-connector/3112-stift-hun-254mm-1-raekke.html#/pins-40_pins "softgenie.dk")
  * [5556.05 5PL. PINRÆKKE M.FLIG LIGE MOD 2.54](https://el-supply.dk/5pl-pinraekke-mflig-lige-mod-254/varenummer/0-5556.05 "el-supply.dk")
  * [5557.05 LØS CRIMPHUS med LÅS 5PL MOD 2.54](https://el-supply.dk/loes-crimphus-med-laas-5pl-mod-254/varenummer/0-5557.05 "el-supply.dk")
* Kabler
  * [5594 LEDNING MED CRIMPTERMINAL 30cm](https://el-supply.dk/soeg/?s=5594 "el-supply.dk")
    * [5594.0 LEDNING MED CRIMPTERMINAL 30cm SORT](https://el-supply.dk/ledning-med-crimpterminal-30cm-sort/varenummer/0-5594.0 "el-supply.dk")
    * [5594.1 LEDNING MED CRIMPTERMINAL 30cm BRUN](https://el-supply.dk/ledning-med-crimpterminal-30cm-brun/varenummer/0-5594.1 "el-supply.dk")
    * [5594.2 LEDNING MED CRIMPTERMINAL 30cm RØD](https://el-supply.dk/ledning-med-crimpterminal-30cm-roed/varenummer/0-5594.2 "el-supply.dk")
    * [5594.3 LEDNING MED CRIMPTERMINAL 30cm ORANGE](https://el-supply.dk/ledning-med-crimpterminal-30cm-orange/varenummer/0-5594.3 "el-supply.dk")
    * [5594.4 LEDNING MED CRIMPTERMINAL 30cm GUL](https://el-supply.dk/ledning-med-crimpterminal-30cm-gul/varenummer/0-5594.4 "el-supply.dk")
    * [5594.5 LEDNING MED CRIMPTERMINAL 30cm GRØN](https://el-supply.dk/soeg/?s=5594 "el-supply.dk")
    * [5594.6 LEDNING MED CRIMPTERMINAL 30cm BLÅ](https://el-supply.dk/ledning-med-crimpterminal-30cm-blaa/varenummer/0-5594.6 "el-supply.dk")
    * [5594.7 LEDNING MED CRIMPTERMINAL 30cm VIOLET](https://el-supply.dk/ledning-med-crimpterminal-30cm-violet/varenummer/0-5594.7 "el-supply.dk")
    * [5594.8 LEDNING MED CRIMPTERMINAL 30cm GRÅ](https://el-supply.dk/ledning-med-crimpterminal-30cm-graa/varenummer/0-5594.8 "el-supply.dk")
    * [5594.9 LEDNING MED CRIMPTERMINAL 30cm HVID](https://el-supply.dk/ledning-med-crimpterminal-30cm-hvid/varenummer/0-5594.9 "el-supply.dk")
  * Dupont ledninger
    * [Hun-til-hun 20 cm lange](https://softgenie.dk/stik-connector/55-hun-til-hun-ledninger.html "softgenie.dk")
    * [Hun-til-hun 10 cm lange](https://softgenie.dk/stik-connector/844-hun-til-hun-dupont-ledninger-korte.html "softgenie.dk")
* LED
  * [Rektangulære lysdioder](https://el-supply.dk/v-213/rektangulaere-lysdioder "el-supply.dk")
  * [100 OHM KULMODSTAND](https://el-supply.dk/100-stk-100-ohm-kulmodstand/varenummer/64-041310 "el-supply.dk")

