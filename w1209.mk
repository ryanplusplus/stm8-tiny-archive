TARGET = tiny
BUILD_DIR = ./build/w1209

DEVICE := stm8s003f3
DEVICE_TYPE := STM8S003
STLINK := stlinkv2
OPENOCD_CFG := openocd/stm8s103.cfg

MAIN := src/app/w1209/main.c

SRC_FILES := \

SRC_DIRS := \
  src/app/w1209 \

LIB_FILES := \

LIB_DIRS := \
  lib/tiny/src \
  src/peripheral \

INC_DIRS := \
  lib/stm8/inc \

include makefile-worker.mk
