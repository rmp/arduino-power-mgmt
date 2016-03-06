# arduino-power-mgmt #

Trivial power management using Arduino Seeedstudio relay shield

Author: rmp@psyphi.net

Blog post:
https://psyphi.net/blog/2016/03/remote-power-management-using-arduino/

## Background ##

Originally this project was to provide a trivial alternative to
out-of-band (OOB) management like Dell iDRAC or Intel AMT. The code
implements a basic serial (9600 baud) command interpreter to switch
all relays on or off, or cycle power.

## Requirements ##

    * SeeedStudio Relay Shield v3.0 (may work with others)
    * Arduino Duemilanove (may work with others)

## Possible Extensions ##

    * Extend the command structure to switch individual- or sets of relays
    * Make use of Ethernet, Wifi or BLE connectivity.

# Licensing #

See LICENSE
