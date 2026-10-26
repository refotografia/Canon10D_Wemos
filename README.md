# Canon Intervalometer (Wemos D1 mini)

A simple intervalometer for Canon cameras using a Wemos D1 mini (ESP8266), two PC817C optocouplers and a DIP switch to select the interval.

## Wiring

| D1 mini pin | Function |
|---|---|
| GPIO5 (D1) | Optocoupler for focus/meter, via 330–470 Ω resistor |
| GPIO4 (D2) | Optocoupler for shutter, via 330–470 Ω resistor |
| GPIO14 (D5) | DIP switch 2 |
| GPIO12 (D6) | DIP switch 3 |
| GPIO13 (D7) | DIP switch 4 |
| GND | Common side of the DIP switch, optocoupler cathodes |

DIP switch 1 (GPIO16) is not used.

Each PC817C output: collector to the remote's focus or shutter wire, emitter to the remote's ground wire.

## Intervals

| Switch ON | Interval |
|---|---|
| 2 | 2 s |
| 3 | 7 s |
| 4 | 20 s |
| none | 45 s |

If more than one switch is on, the lowest-numbered one wins.

The switches are read only at boot: change the switch, then press RESET.

## Build

Rename file as desired, add to a folder of same name. Then open in the Arduino IDE with the ESP8266 board package installed, select "LOLIN(WEMOS) D1 R2 & mini" and upload.
