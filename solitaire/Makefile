#############################################################################
# Makefile for building: solitaire
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  solitaire.pro
# Template: app
# Command: /home/chris/Qt5.5.1/5.5/gcc_64/bin/qmake -o Makefile solitaire.pro
#############################################################################
export LD_LIBRARY_PATH:=/usr/local/share/Qt-5.5.1/5.5/gcc_64/lib:${LD_LIBRARY_PATH}
export QT_PLUGIN_PATH:=/usr/local/share/Qt-5.5.1/5.5/gcc_64/plugins:${QT_PLUGIN_PATH}

MAKEFILE      = Makefile

all: gui cli
gui:
	cd src/gui && qmake -makefile && make
cli:
	cd src/cli && qmake -makefile && make
	
doxygen:
	doxygen conf/doxygen.conf

pack: clean
	zip -r xrykal00-xpolak33.zip ./

clean: clean-gui clean-cli
	rm -f hra2017
	rm -f hra2017-cli
	rm -fr src/target/
	rm -f xrykal00-xpolak33.zip
	cd doc && rm -rf *

clean-gui:
	cd src/gui && qmake -makefile && make clean && rm Makefile

clean-cli:
	cd src/cli && qmake -makefile && make clean && rm Makefile

run: run-gui run-cli

run-gui:
	./hra2017 &

run-cli:
	./hra2017-cli
