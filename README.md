# Magnetic Switch Sensor (Reed Switch)

Sense if windows are open or closed.

Sensors in use: https://www.amazon.de/gp/product/B07Z4NCWDD/ref=ppx_yo_dt_b_asin_title_o00_s01?ie=UTF8&psc=1

Microcontroller: Node MCU, Esp8266-12 WiFi module

Tutorial: https://www.smarthome-tricks.de/esp8266/reedkontakt-schalter-abfragen/

# Functionality:

The sensor is used to detect if a window is open by using a magnet switch. It sends its initial state (open/closed), and sends a message whenever the window state changes. All messages are sent as retained messages.

It uses the CleanAIRDevice library to connect to wifi and mqtt via external configuration. (See: https://github.com/CleanAIR-Building/CleanAIRDevice)

It sends json messages in the following shape:
```
{
    "sensor": <sensor-name>,
    "window_state": <window-state-string>
}
```