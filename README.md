[![Build Firmware](https://github.com/mck1117/wideband/actions/workflows/build-firmware.yaml/badge.svg)](https://github.com/mck1117/wideband/actions/workflows/build-firmware.yaml) ![license](https://img.shields.io/github/license/mck1117/wideband)

# gerEFI Wideband Controller

[User Documentation](https://gerefi.com/s/wb)

## Building Firmware

The `firmware/boards` directory contains configuration for each board this firmware supports.

For the standalone board and the module built in to gerEFI Hellen boards, `f0_module` is the correct target.  Use the `build_wideband.sh` script to build and package the wideband firmware: both a bin including the bootloader, and a header file consumed by gerEFI that contains no bootloader, to be uploaded over CAN (via the aforementioned bootloader).
