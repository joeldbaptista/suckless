#!/bin/sh
set -e
make && sudo make install && make clean
