TARGET = tiny
BUILD_DIR = ./build/blue-207

DEVICE := stm8s207rb
DEVICE_TYPE := STM8S207
STLINK := stlinkv2
OPENOCD_CFG := openocd/stm8s207.cfg

MAIN := src/app/blue-207/main.c

SRC_FILES := \

SRC_DIRS := \
  src/app/blue-207 \

LIB_FILES := \

LIB_DIRS := \
  lib/tiny/src \
  src/app/common \
  src/device \
  src/peripheral \

INC_DIRS := \
  lib/stm8/inc \
  lib/tiny/include \

include makefile-worker.mk
