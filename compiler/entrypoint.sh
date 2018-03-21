#!/bin/bash

FOLDER=${KEYMAP_FOLDER:-/keymap}

if [ ! -f "$FOLDER/keymap.c" ]; then
  echo "No keymap.c found!"
  exit 1
fi

cd /firmware/keyboards/ergodox_ez

rm -rf keymaps/__custom                # (just in case...)
mkdir -p keymaps/__custom
cp $FOLDER/keymap.c keymaps/__custom

make KEYMAP=__custom

cp -f /firmware/.build/ergodox_ez___custom.hex $FOLDER/ergodox_ez.hex