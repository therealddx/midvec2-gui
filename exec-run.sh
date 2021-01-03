#!/bin/bash
# 
# exec-run.sh
# workaround script to kick off midvec2-gui while linking in the midvec2
# library.
# 

export LD_LIBRARY_PATH="$PWD"/build-midvec2-lib-Desktop-Debug
cd build-midvec2-gui-Desktop-Debug
./midvec2-gui
cd ../

