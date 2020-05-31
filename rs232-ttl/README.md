# RS232-TTL

This project enables setting up the ESP32 with a hardware serial (using pins 16 and 17) to interact with an RS232-TTL converter.
This main use of this project was in a scenario with interfacing with old school peripheral devices.
All the RS232 signals require converting to a TTL UART signal, this in turn requires stepping down to 3.3V to work with the ESP32 board.

For this project, the following devices are require:
- ESP32 board (https://www.jaycar.com.au/esp32-main-board-with-wifi-and-bluetooth-communication/p/XC3800)
- Sparkfun Level Logic Converter (https://www.robotgear.com.au/Product.aspx/Details/500-SparkFun-Logic-Level-Converter-Bi-Directional-3-3V-5V?gclid=CjwKCAjwq832BRA5EiwACvCWseCU3rAQwyUC8C_IBEbgElZI_llL2laoofJWH5u4SkKVXZs7t_eldBoC-boQAvD_BwE)
- MAX3232 RS232 to TTL UART Module (https://www.jaycar.com.au/rs-232-to-ttl-uart-converter-module/p/XC3724)

The wiring is shown below:

![Image of layout](https://raw.githubusercontent.com/gazzenger/esp32-projects/rs232-ttl/hardware-serial_bb.png)