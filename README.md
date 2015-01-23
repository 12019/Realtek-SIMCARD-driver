# Realtek-SIMCARD-driver
Realtek SIMCARD driver written in C 

![alt text](http://i30.twenga.com/phones/sim-card-reader/power-star-lect-sim-tp_4456589808252741641vb.jpg "image")

PowerStar sim card reader

# How to use ?
Download source code and then use

    $ make 
    
you can use the python script so as to load the .ko module , to do it , juste execute the python script using 

    $ ./simcard.py
    
you've got those cmd

* load 	       ( load module )
* show 	       ( show dmesg output )
* info 	       ( module info )
* quit 	       ( quit )

the sim binary is a program that allows you to read data from the <b>/dev/sdb</b> , <b>/dev/sdd</b> or <b>/dec/sc0</b> , source code are available on the simcard.c file

your <b>Realtek Semiconductor Drive</b> must be plugged

output of <b>lsusb -v</b> for the Realtek Semiconductor Drive is available on the <b>raw.txt</b> file

