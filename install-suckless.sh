#!/bin/bash
set -eu

cd dwm && make && sudo make install && make clean && cd ..
cd st && make && sudo make install && make clean && cd ..
cd dmenu && make && sudo make install && make clean && cd ..
cd xnotify && make && sudo make install && make clean && cd ..
cd nnn && make && sudo make install && make clean && cd ..
cd dwmblocks && make && sudo make install && make clean && cd ..
cd slock && make && sudo make install && make clean && cd ..

