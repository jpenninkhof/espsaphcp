# espsaphcp

This is a simple library for ESP8266(EX) chips to push sensor data to the SAP HANA Cloud Platform IoT services

## Features

 * Easy to use.
 * Supports multiple requests in parallel.
 * Tested with Espressif SDK v1.1.1

## Building
If you don't have a toolchain yet, install one with <https://github.com/pfalcon/esp-open-sdk> then get Espressif's SDK.

### The submodule way
If your project looks like esphttpd from Sprite_tm:
```bash
git clone http://git.spritesserver.nl/esphttpd.git/
cd esphttpd
git submodule add https://github.com/jpenninkhof/espsaphcp.git lib/espsaphcp
git submodule add https://github.com/jpenninkhof/esphttpclient.git lib/esphttpclient
git submodule update --init
```

Now append `lib/espsaphcp` and `lib/esphttpclient` to the following `Makefile` line and you should be ready:
```
MODULES = driver user lib/espsaphcp lib/esphttpclient
```
As the SAP HANA Cloud platform uses SSL, don't forget to add `ssl` to `LIBS` in the `Makefile`
```
LIBS = c gcc hal pp phy net80211 lwip wpa main ssl
```

### The dirty way
Alternatively you could create a simple project:
```bash
git clone https://github.com/esp8266/source-code-examples.git
cd source-code-examples/basic_example
# Set your Wifi credentials in user_config.h
# I could not test this because of the UART baud rate (74880)
```

Then download this library and move the files to `user/`:
```bash
git clone https://github.com/jpenninkhof/espsaphcp.git
mv espsaphcp/*.* user/
git clone https://github.com/jpenninkhof/esphttpclient.git
mv esphttpclient/*.* user/
```

## Usage
Include `saphcp.h` from `user_main.c` then call one of these functions:
```