# MultiWatchy - Multiple watch faces for SQFMI's Open Source E-Paper Watch

![Watchy](https://watchy.sqfmi.com/img/watchy_render.png)

**Buy Watchy from [The Pi Hut](https://thepihut.com/collections/sqfmi), [Crowd Supply](https://www.crowdsupply.com/sqfmi/watchy), and [Mouser](https://www.mouser.com/ProductDetail/SQFMI/SQFMI-WATCHY-10?qs=DRkmTr78QARN9VSJRzqRxw%3D%3D)!**

[**Watchy Case & Accessories**](https://shop.sqfmi.com)

Visit [**https://watchy.sqfmi.com**](https://watchy.sqfmi.com) for documentation, hardware design files, and more!

## Differences from standard Watchy library

In the standard Watchy library, you subclass the `Watchy` class, and implement your `drawWatchFace()` function there. In MultiWatchy, you instead subclass the `WatchFace` class; other than that, you still implement `drawWatchFace()` and draw your watch face in that function.

The main difference is that instead of working directly with the settings, display and state variables within the Watchy class, your watch face instead gets a pointer to the underlying watch hardware, which has all of those variables inside. You can access the watch hardware via the `watch` ivar, which is available anywhere in your watch face class. It has all of the same attributes you'd normally expect from Watchy.

It ends up being fairly simple once you see it: whereas before you might have written code like this:

```cpp
void MyWatchy::drawWatchFace() {
    weatherData currentWeather = getWeatherData();
    int8_t temperature = currentWeather.temperature;
    display.setFont(&DSEG7_Classic_Regular_39);
    display.setCursor(90, 90);
    display.println(temperature);
}
```

with MultiWatchy, you'd write this (note the addition of `watch->`):

```cpp
void MyWatchFace::drawWatchFace() {
    weatherData currentWeather = watch->getWeatherData();
    int8_t temperature = currentWeather.temperature;
    watch->display.setFont(&DSEG7_Classic_Regular_39);
    watch->display.setCursor(90, 90);
    watch->display.println(temperature);
}
```

Once you've included the watch faces you want in your Arduino project, you'll declare a `MultiWatchy` object (instead of a `Watchy`), and then add the watch faces to MultiWatchy **before** calling `watchy.init()`:

```cpp
MultiWatchy watchy(settings);

void setup() {
  watchy.addWatchFace(new WatchFace());
  watchy.addWatchFace(new SunriseWatchFace());
  watchy.addWatchFace(new TideChartWatchFace());
  watchy.addWatchFace(new MoonPhaseWatchFace());

  watchy.init();
}
```

The core `Watchy` class has been renamed `MultiWatchy` in this library, so it can coexist with the normal Watchy library in your Arduino libraries folder without causing conflicts. It's not in the Arduino package manager, though; to install it, follow the steps below.

## Setup
1. In the Arduino IDE Boards Manager, [install support for the ESP32](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).
    * Arduino > Preferences > Additional Board Manager URLs
    * ```https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json```
2. Download this repository, rename the folder `MultiWatchy` if needed, and copy it to the `libraries` folder in your Arduino directory. 
3. Check out the examples under ```Examples``` -> ```MultiWatchy```
4. Compile & Upload with these board settings:
    * Board: "Watchy"
    * Partition Scheme: "Huge App"
    * Board Revision: Choose your Watchy version (if your Up button doesn't work, try **Watchy 2.0**)
    * All Other Settings: leave to default

You may also have to install the [CP2104 USB to Serial drivers](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers) if the port is not automatically detected.

### Have Fun! :)


### Got Questions?

Join our [Discord](https://discord.gg/ZXDegGV8E7)


