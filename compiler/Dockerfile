FROM debian:jessie

MAINTAINER Potiguar Faga <potz@potz.me>

# Installs requirements for compiling the firmware
RUN apt-get update && \
    apt-get install -y git-core && \ 
    apt-get install -y gcc-avr binutils-avr avr-libc make && \
    apt-get install -y dfu-programmer dfu-util && \
    rm -rf /var/lib/apt/lists/*

RUN git clone -q https://github.com/qmk/qmk_firmware /firmware

# Map this volume to some folder where a keymap.c can be found.
# The resulting firmware.hex will also be put in this folder when finished.
VOLUME /keymap

COPY entrypoint.sh /

CMD [ "/entrypoint.sh" ]