# Welcome!

Welcome to HomeSpan - a robust and extremely easy-to-use Arduino library for creating your own [ESP32-based](https://www.espressif.com/en/products/modules/esp32) HomeKit devices entirely within the [Arduino IDE](http://www.arduino.cc).

HomeSpan provides a microcontroller-focused implementation of Apple's HomeKit Accessory Protocol Specification Release R2 (HAP-R2) designed specifically for the Espressif ESP32 microcontroller running within the Arduino IDE.  HomeSpan pairs directly to HomeKit via your home WiFi network without the need for any external bridges or components.  With HomeSpan you can use the full power of the ESP32's I/O functionality to create custom control software and/or hardware to automatically operate external devices from the Home App on your iPhone, iPad, or Mac, or with Siri.

The current "pre-release" of the second-generation of HomeSpan (2.0.0-rc.1) *requires version 3.0.2 or greater* of the [Arduino-ESP32 Board Manager](https://github.com/espressif/arduino-esp32) and will run on the original ESP32 as well as Espressif's S2, S3, C3, and C6 chips.  The final first-generation production release of HomeSpan (1.9.1) requires version 2 (any variation) of the [Arduino-ESP32 Board Manager](https://github.com/espressif/arduino-esp32) and will run on the original ESP32 as well as Espressif's S2, S3, C3 chips, but not on the C6 chip.

> [!NOTE]
> Apple's HomeKit architecture [requires the use of a Home Hub](https://support.apple.com/en-us/HT207057) (either a HomePod or Apple TV) for full and proper operation of any HomeKit device, including those based on HomeSpan.  Use of HomeSpan without a Home Hub is NOT supported.

### HomeSpan Highlights

* Provides a natural, intuitive, and **very** easy-to-use framework
* Utilizes a unique *Service-Centric* approach to creating HomeKit devices
* Takes full advantage of the widely-popular Arduino IDE
* 100% HAP-R2 compliance
* Dozens of integrated HomeKit Services
* Operates in either Accessory or Bridge mode
* Supports pairing with Setup Codes or QR Codes

### For the HomeSpan Developer

* Extensive use of the Arduino Serial Monitor
  * Real-time, easy-to-understand diagnostics
  * Complete transparency to every underlying HomeKit action, data request, and data response
  * Command-line interface with a variety of info, debugging, and configuration commands
* Built-in database validation to ensure your configuration meets all HAP requirements
* Dedicated classes that utilize the ESP32's 16-channel PWM peripheral for easy control of:
  * LED Brightness (including auto-fading)
  * Servo Motors
* Integrated Push Button and Toggle Switch functionality supporting single, double, and long presses of:
  * Physical pushbuttons that connect an ESP32 pin to either ground or VCC
  * Touch pads/sensors connected to an ESP32 pin (for ESP32 devices that support touch pads)
* Integrated access to the ESP32's on-chip Remote Control peripheral for easy generation of IR and RF signals
* Dedicated classes to control one- and two-wire addressable RGB LEDs and LED strips
* Dedicated classes to control stepper motors that can run smoothly in the background without interfering with HomeSpan
* Dedicated class that faciliates seamless point-to-point communication between ESP32 devices using ESP-NOW
* Integrated Web Log for user-defined log messages
* Extensively-commented Tutorial Sketches taking you from the very basics of HomeSpan through advanced HomeKit topics
* Additional examples and projects showcasing real-world implementations of HomeSpan
* A complete set of documentation explaining every aspect of the HomeSpan API

### For the HomeSpan End-User

* Embedded WiFi Access Point and Web Interface to allow end-users (non-developers) to:
  * Set up Homespan with their own home WiFi Credentials
  * Create their own HomeKit Pairing Setup Code
* Status LED and Control Button to allow end-users to:
  * Force-unpair the device from HomeKit
  * Perform a Factory Reset
  * Launch the WiFi Access Point
* A standalone, detailed End-User Guide

## ❗Latest Update - HomeSpan 2.0.0-rc.1 (9/27/2024)

* **This is an initial "pre-release" of the second-generation of HomeSpan designed for version 3 of the [Arduino-ESP32 Board Manager](https://github.com/espressif/arduino-esp32)**

  * version 3 of the Arduino-ESP32 Board Manager is based on Espressif's IDF5, which is not backwards compatible with version 2 of the Arduino-ESP32 Board Manager that was based on Espressif's IDF4
  * the primary focus of HomeSpan 2.0.0-rc.1 was to refactor HomeSpan 1.9.1 as needed to allow it to operate under version 3 of the Arduino-ESP32 board manager ---
    * while **preserving backwards compatibility for all HomeSpan sketches written under HomeSpan 1.9.1**
    * in spite of the many [breaking changes](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/migration-guides/release-5.x/5.0/index.html) that Espressif made between IDF4 and IDF5,
    * and numerous additional breaking changes between version 2 and 3 of the Arduino-ESP32 Board Manager
      
* **Support for the ESP32-C6**
  
  * version 3 of the Arduino-ESP32 Board Manager added support for Espressif's ESP32-C6 and ESP32-H2 chips
    * HomeSpan supports the use of the C6 chip since it contains a WiFi radio, as currently required by HomeSpan, in addition to a Thread radio
    * HomeSpan does *not* support the use of the H2 chip since it lacks a WiFi radio (contains only a Thread radio)
 
* **Expanded functionality for the HomeSpan Pixel and RFControl libraries**

  * as a result of Espressif deprecating the IDF4-version of the RMT library and replacing it with a completely new library in IDF5, the HomeSpan Pixel and RFControl libraries have been completely written and upgraded:
    * you can now instantiate both Pixel and RFControl objects in the same sketch (previously these classes were incompatible with eachother and could not be used in the same sketch)
    * the Pixel class also adds a variety of new functionality:
      * adds support for 5-color RGBWC (red, green, blue, warm-white, and cool-white) LEDs
      * adds new method `Pixel::Color::WC()` to support setting warm-white / cool-white color values
      * adds new methods `Pixel::Color::CCT()` and `Pixel::setTemperatures()` that automatically set the warm-white / cool-white colors of a Pixel device based on whatever correlated color temperature (CCT) the user specifies (e.g. 3000K)
      * adds new constructor `Pixel(int pin, const char *pixelType)` that provides the ability to both select the colors and specify their transmission order (*pixelType*) to match a very wide variety of Pixel devices (ranging from pure-white LEDs to 5-color RGBWC LEDs)
        * deprecates constructor `Pixel(int pin, pixelType_t pixelType)` that limited *pixelType* to a pre-defined set of values
      * adds new method `boolean Pixel::hasColor(char c)` to determine whether an existing Pixel object supports any particular color
        * deprecates `boolean Pixel::isRGBW()` only distinguished RGB from RGBW devices
      * upgraded the [PixelTester](../examples/Other%20Examples/PixelTester) sketch to interactively step users through selecting and testing the correct *pixelType* for their device
      * added new [Pixel-RGBWC](../examples/Other%20Examples/Pixel-RGBWC) example demonstrating how to implement an RGBWC Pixel light-strip with separate Home App controls for the RGB and WC LED
      * see the [Addressable RGB LEDs](Pixels.md) page for full details

* ❗**Size alert**
  * version 3 of the Arduino-ESP32 Board Manager has a much larger footprint that version 2
  * the same HomeSpan sketch compiled under 1.9.1 will be approximately 200K larger when compiled under HomeSpan 2.0.0-rc.1!
  * as a result HomeSpan sketches will no longer fit into a 1.2MB or 1.3MB partition (the ESP32 default) and must be compiled under a larger partition scheme (such as "Minimal SPIFFS" which provides for 1.9MB partitions)
  * this has implications for upgrading through OTA (see Release Notes for details)
      
See [Releases](https://github.com/HomeSpan/HomeSpan/releases) for details on all changes and bug fixes included in this update.

# HomeSpan Resources

HomeSpan includes the following documentation:

* [Getting Started with HomeSpan](docs/GettingStarted.md) - setting up the software and the hardware needed to develop HomeSpan devices
* [HomeSpan API Overview](docs/Overview.md) - an overview of the HomeSpan API, including a step-by-step guide to developing your first HomeSpan Sketch
* [HomeSpan Tutorials](docs/Tutorials.md) - a guide to HomeSpan's tutorial-sketches
* [HomeSpan Services and Characteristics](docs/ServiceList.md) - a list of all HAP Services and Characterstics supported by HomeSpan
* [HomeSpan Accessory Categories](docs/Categories.md) - a list of all HAP Accessory Categories defined by HomeSpan
* [HomeSpan Command-Line Interface (CLI)](docs/CLI.md) - configure a HomeSpan device's WiFi Credentials, modify its HomeKit Setup Code, monitor and update its status, and access detailed, real-time device diagnostics from the Arduino IDE Serial Monitor
* [HomeSpan User Guide](docs/UserGuide.md) - turnkey instructions on how to configure an already-programmed HomeSpan device's WiFi Credentials, modify its HomeKit Setup Code, and pair the device to HomeKit.  No computer needed!
* [HomeSpan API Reference](docs/Reference.md) - a complete guide to the HomeSpan Library API
* [HomeSpan QR Codes](docs/QRCodes.md) - create and use QR Codes for pairing HomeSpan devices
* [HomeSpan OTA](docs/OTA.md) - update your sketches Over-the-Air directly from the Arduino IDE without a serial connection
* [HomeSpan PWM](docs/PWM.md) - integrated control of standard LEDs and Servo Motors using the ESP32's on-chip PWM peripheral
* [HomeSpan RFControl](docs/RMT.md) - easy generation of RF and IR Remote Control signals using the ESP32's on-chip RMT peripheral
* [HomeSpan Pixels](docs/Pixels.md) - integrated control of addressable one- and two-wire RGB and RGBW LEDs and LED strips
* [HomeSpan Stepper Motor Control](docs/Stepper.md) - integrated control of stepper motors, including PWM microstepping
* [HomeSpan SpanPoint](docs/NOW.md) - facilitates point-to-point, bi-directional communication between ESP32 Devices using ESP-NOW
* [HomeSpan Television Services](docs/TVServices.md) - how to use HomeKit's undocumented Television Services and Characteristics
* [HomeSpan Message Logging](docs/Logging.md) - how to generate log messages for display on the Arduino Serial Monitor as well as optionally posted to an integrated Web Log page
* [HomeSpan TLV8 Characteristics](docs/TLV8.md) - classes and methods for creating TLV8 objects to use with TLV8-based Characteristics
* [HomeSpan Device Cloning](docs/Cloning.md) - seamlessly swap a broken device for a new one without needing to re-pair and lose HomeKit automations
* [HomeSpan Projects](https://github.com/topics/homespan) - real-world applications of the HomeSpan Library
* [HomeSpan FAQ](docs/FAQ.md) - answers to frequently-asked questions
* [Solutions to Common Problems](docs/Solutions.md) - resolutions to some common problems when using/compiling HomeSpan
* [HomeSpan Reference Sketches](https://github.com/HomeSpan/HomeSpanReferenceSketches) - a collection of self-contained Reference Sketches showcasing some of the more complex HomeKit Services, such as Thermostats and Irrigation Systems

Note that all documentation is version-controlled and tied to each branch.  The *master* branch generally points to the latest release.  The *dev* branch, when available, will contain code under active development.

# External Resources

In addition to HomeSpan resources, developers who are new to HomeKit programming may find useful Chapters 8 and 9 of Apple's HomeKit Accessory Protocol Specification, Non-Commercial Version, Release R2 (HAP-R2). This document is unfortunately no longer available from Apple (perhaps because it was last updated July, 2019, and is now somewhat out-of-date).  However, you may be able find copies of this document elsewhere on the web.  Note Apple has not replaced the HAP-R2 document with any other versions for non-commercial use, and Apple's open-source [HomeKit ADK](https://github.com/apple/HomeKitADK) only reflects the original HAP-R2 specs (rather than all the latest Services and Characteristics available in HomeKit for commercial devices).

---

### Feedback or Questions?

Please post bug reports or other problems with HomeSpan to the [Issues Board](https://github.com/HomeSpan/HomeSpan/issues).  Please post all other questions about HomeSpan (use, functionality, specs, examples, etc.) or any ideas or recommendations you may have for new functionality, or any general feedback about HomeSpan or HomeKit, to the [Discussion Board](https://github.com/HomeSpan/HomeSpan/discussions).  For more general questions or feedback not related to a specific HomeSpan issue or function, you can email me directly at [homespan@icloud.com](mailto:homespan@icloud.com).

### About the Author

HomeSpan was developed and continues to be maintained and supported by Gregg Berman.  It was originally conceived to solve the pesky problem of not being able to operate an RF-controlled kitchen vent hood with Siri.  I hope you find it useful as well as fun to use.

This is my second large-scale open-source project --- my first was the design of an open-source sytem for operating model railroads using nothing more than an Arduino Uno and Arduino Motor Shield to generate digital command and control (DCC) signals.  Though I have not been involved with the model railroading hobby for many years, videos showcasing my original system (dubbed DCC++), along with detailed tutorials of how it works, are still available on the [DCC++ YouTube Channel](https://www.youtube.com/@dcc2840/videos). 
