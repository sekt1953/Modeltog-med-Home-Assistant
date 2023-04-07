# Modeltog med Home Assistant og ESPHome

![lovelace](./marklin/Images/Sk%C3%A6rmbillede%20fra%202023-03-29%2017-42-37.png)


## versioner for Marklin & OMJK

* Marklin version af styring 
  * [Lars's Marklin anlæg](./marklin/Marklin.md)
* [OMJK](https://www.facebook.com/omjk1949)
  * [OMJK version af Modelbane med Home Assistant](./omjk/OMJK.md)

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
    * [KF128 2.54mm PCB Mini Screw Terminal Blocks](https://www.aliexpress.com/item/1005004657032987.html?spm=a2g0o.store_pc_groupList.8148356.1.325b2c00DYsZjM&pdp_npi=2%40dis%21DKK%21DKK%2011.96%21DKK%2011.96%21%21%21%21%21%402101e9cf16805005147894914ea7c6%2112000030004878220%21sh)
    * [15EDG KF2EDG 2.54mm 2.54mm Pitch](https://www.aliexpress.com/item/1005004709162265.html?spm=a2g0o.productlist.main.51.29cb7e79CowySb&algo_pvid=4d1174eb-fd2e-4379-b9de-324859466603&algo_exp_id=4d1174eb-fd2e-4379-b9de-324859466603-25&pdp_ext_f=%7B%22sku_id%22%3A%2212000030194807351%22%7D&pdp_npi=3%40dis%21DKK%2122.54%2122.54%21%21%21%21%21%402122443916804688660288319d06e0%2112000030194807351%21sea%21DK%210&curPageLogUid=noc6Dld5wriM)
* CPU
  * [ESP32 DEV KIT DOIT Udviklingsboard](https://ebits.dk/products/esp32-dev-kit-doit-udviklingsboard?_pos=2&_sid=e219da91c&_ss=r "ebits.dk")
    * [Sådan løses CH340 USB til Serial Problem](https://unix.stackexchange.com/a/670637 "unix.stackexchange.com")
* IC's
  * [PCF8574P](https://softgenie.dk/ic/946-pcf8574.html "softgenie.dk")
  * [PCF8574AP ](https://softgenie.dk/ic/259-pcf8574ap.html "softgenie.dk")
  * [PCF8575](https://softgenie.dk/diverse/1534-i2c-16-portudvidelse-arduiniraspberry.html "softgenie.dk")
  * [PC817 / PC847](https://softgenie.dk/ic/302-pc817-opto-coubler.html "softgenie.dk")
  * [TLP620-4](https://el-supply.dk/tlp620-4-optokobler-55v-50ma-5kv-dil16/varenummer/0-386TLP620-4 "EL-Supply")
* Power mudule
  * [OE-SD28V Mini DC-DC Adjustable Step Down Power Supply Module](https://www.aliexpress.com/i/33056573446.html)
  * [ZkeeShop 10 Stücke Mini Step-Down](https://www.amazon.de/ZkeeShop-Stromversorgungsmodul-Spannungsabw%C3%A4rtswandler-Einstellbar-Spannungswandler/dp/B08CVF4BFW/ref=d_pd_sbs_sccl_2_6/257-9954418-9854261?pd_rd_w=w0GLa&content-id=amzn1.sym.e240add7-999b-4e0b-8c0e-340ec2846a97&pf_rd_p=e240add7-999b-4e0b-8c0e-340ec2846a97&pf_rd_r=WZTY9WCA03BZDF0V164Y&pd_rd_wg=Qe65w&pd_rd_r=245f3248-0d02-4e11-aa5f-ec7b31553a12&pd_rd_i=B08CVF4BFW&psc=1)
  * [DC-DC Step Down Buck Converter ](https://www.amazon.de/Converter-LAOMAO-Einstellbar-Spannungwandler-Netzteil-gr%C3%BCn/dp/B0B932CTQJ/ref=sr_1_8?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1ISR9FAXACQWV&keywords=Mini+Dc-Dc+Einstellbare&qid=1680778889&s=ce-de&sprefix=mini+dc-dc+einstellbare%2Celectronics%2C61&sr=1-8) 
    * [TPS54233 Datasheet](https://www.ti.com/lit/ds/slus859c/slus859c.pdf?ts=1680778134540&ref_url=https%253A%252F%252Fwww.google.dk%252F)
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

