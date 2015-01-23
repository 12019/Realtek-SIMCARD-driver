#!/usr/bin/python
#for simcard module 

import os

action = -1

def load():
	os.system("sudo insmod sc_drive.ko")

def show():
	os.system("dmesg")
def info():
	os.system("modinfo sc_drive.ko")
def help():
	print "load 	/* load module */"
	print "show 	/* show dmesg output */"
	print "info 	/* module info */"
	print "quit 	/* quit */"

	return 


while(action != "quit"):
	action = raw_input("[+] => ")
	if action == "load":
		load()
	if action == "show":
		show()
	if action == "load":
		info()
	if action == "help":
		help()