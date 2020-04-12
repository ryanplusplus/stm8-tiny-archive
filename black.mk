TARGET := tiny
BUILD_DIR := ./build/black

DEVICE := stm8s105k4
DEVICE_TYPE := STM8S105
STLINK := stlinkv2
OPENOCD_CFG := openocd/stm8s105.cfg
TOOLCHAIN_VERSION := 4.0.0

MAIN := src/app/black/main.c

SRC_FILES := \

SRC_DIRS := \
  src/app/black \

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
