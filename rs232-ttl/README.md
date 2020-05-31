# RS232 TTL UART Converter for ESP32

## Description
This project enables setting up the ESP32 with a hardware serial (using pins 16 and 17) to interact with an RS232-TTL converter.
This main use of this project was in a scenario with interfacing with old school peripheral devices.
All the RS232 signals require converting to a TTL UART signal, this in turn requires stepping down to 3.3V to work with the ESP32 board.

## Requirements

For this project, the following devices are require:
- ESP32 board (https://www.jaycar.com.au/esp32-main-board-with-wifi-and-bluetooth-communication/p/XC3800)

This board requires powering from the USB port


- Sparkfun Level Logic Converter (https://www.robotgear.com.au/Product.aspx/Details/500-SparkFun-Logic-Level-Converter-Bi-Directional-3-3V-5V?gclid=CjwKCAjwq832BRA5EiwACvCWseCU3rAQwyUC8C_IBEbgElZI_llL2laoofJWH5u4SkKVXZs7t_eldBoC-boQAvD_BwE)

This board need powering from both the HV and the LV side.
The HV side is the 5V side, and the LV side is the 3.3V side.
Earth can be shared between the two sides.

- MAX3232 RS232 to TTL UART Module (https://www.jaycar.com.au/rs-232-to-ttl-uart-converter-module/p/XC3724)

According to the specs on the Jaycar website, this module can only be powered off 5V.
Powering this device off 3.3V cause noise to be interpretted in the TX data.

## Wiring

The wiring is shown below:

![Image of layout](https://raw.githubusercontent.com/gazzenger/esp32-projects/master/rs232-ttl/hardware-serial_bb.png)

!important
**To be able to connect a peripheral to this RS232 port, it'll be required that the Rx and Tx on the RS232 pins are swapped.
The existing plug on these MAX3232s are design so the device can be connected to a computer, i.e. this device is a peripheral.


## Linux Usage
For interfacing RS232 devices with linux, use a USB-RS232 device

Once connected, outputs can be verified by using the command
```bash
$ echo /dev/ttyUSB1
```

To send a message, use the following 
```bash
echo -ne "asdf" > /dev/ttyUSB1
```

To set the properties of the connection, use the following commands,
i.e. baud rate as 19200kbps, 7 bits, even parity (with the minus), and 1 stop bit
```bash
$ stty -F /dev/ttyUSB1 speed 19200 cs7 -parodd -cstopb
```
