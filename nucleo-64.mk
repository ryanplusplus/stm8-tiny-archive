TARGET := tiny
BUILD_DIR := ./build/nucleo-64

DEVICE := stm8s208rb
DEVICE_TYPE := STM8S208
STLINK := stlinkv21
OPENOCD_CFG := openocd/stm8s208.cfg
TOOLCHAIN_VERSION := 4.0.0

MAIN := src/app/nucleo-64/main.c

SRC_FILES := \

SRC_DIRS := \
  src/app/nucleo-64 \

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
