#What is this
A simple project using the AMG8851 GRID-EYE sensor.  Basically it prints the thermopile array information to an 8x8 LED matrix.

#Licence
The software here is under the MIT licence

#Library Dependencies
Requires GRIDEYE library (included)
Requires [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library)
Requires [Adafruit_LED_Backpack](https://github.com/adafruit/Adafruit_LED_Backpack)

To install the library under linux, first modify instll_lib.sh so it points at wherever you keep your arduino libraries.  Then run:

`sh install_lib.sh`

If you tweak the libaries, you can run that again to re-install.  Arduino will need to be restarted the first time you run it.

Windows people, you will have to write your own script, or manually copy for now.