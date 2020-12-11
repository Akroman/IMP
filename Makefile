BASE = ../../../
FCMAKE = C:/Program Files/FITkit/bin/fcmake.exe
FKFLASH = C:/Program Files/FITkit/bin/fkflash.exe
FKTERM = C:/Program Files/FITkit/bin/fkterm.exe
FKTEST = C:/Program Files/FITkit/bin/fktest.exe
PROJECT = project.xml
OUTPUTPREFIX = lcd_cz
DEPENDENCIES = ../../demo/display

all: dependencycheck build/lcd_cz_f1xx.hex build/lcd_cz_f2xx.hex

#MCU part
#=====================================================================
HEXFILE_F1XX = build/lcd_cz_f1xx.hex
HEXFILE_F2XX = build/lcd_cz_f2xx.hex

build/mcu/display_cz_f1xx.o: ../../../mcu/libs/lcd_cz/display_cz.c
	$(comp_tpl_f1xx)

build/mcu/display_cz_f2xx.o: ../../../mcu/libs/lcd_cz/display_cz.c
	$(comp_tpl_f2xx)

build/mcu/main_f1xx.o: mcu/main.c
	$(comp_tpl_f1xx)

build/mcu/main_f2xx.o: mcu/main.c
	$(comp_tpl_f2xx)

OBJFILES_F1XX = build/mcu/display_cz_f1xx.o build/mcu/main_f1xx.o
OBJFILES_F2XX = build/mcu/display_cz_f2xx.o build/mcu/main_f2xx.o

#FPGA part
#=====================================================================
BINFILE = ../../demo/display/build/lcd.bin

PKGS_LIST = ../../../mcu/libs/lcd_cz/package.xml

include $(BASE)/base/Makefile.inc
