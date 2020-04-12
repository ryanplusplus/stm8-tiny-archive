TARGET := tiny
BUILD_DIR := ./build/blue-zumo

DEVICE := stm8s103f3
DEVICE_TYPE := STM8S103
STLINK := stlinkv2
OPENOCD_CFG := openocd/stm8s103.cfg
TOOLCHAIN_VERSION := 4.0.0

MAIN := src/app/blue-zumo/main.c

SRC_FILES := \

SRC_DIRS := \
  src/app/blue-zumo \
  src/app/common \

LIB_FILES := \

LIB_DIRS := \
  lib/tiny/src \
  src/device \
  src/peripheral \

INC_DIRS := \
  lib/stm8/inc \
  lib/tiny/include \

include makefile-worker.mk
