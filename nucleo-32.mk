TARGET = tiny
BUILD_DIR = ./build/nucleo-32

DEVICE := stm8s207k8
DEVICE_TYPE := STM8S207
STLINK := stlinkv21
OPENOCD_CFG := openocd/stm8s207.cfg

MAIN := src/app/nucleo-32/main.c

SRC_FILES := \

SRC_DIRS := \
  src/app/nucleo-32 \

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
