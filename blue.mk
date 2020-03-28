TARGET = tiny
BUILD_DIR = ./build/blue

DEVICE := stm8s103f3
DEVICE_TYPE := STM8S103
STLINK := stlinkv2
OPENOCD_CFG := openocd/stm8s103.cfg

MAIN := src/app/blue/main.c

SRC_FILES := \

SRC_DIRS := \
  src/app/blue \

LIB_FILES := \
  src/peripheral/clock.c \
  src/peripheral/pb5_heartbeat.c \
  src/peripheral/tim4_system_tick.c \
  src/peripheral/watchdog.c \

LIB_DIRS := \
  lib/tiny/src \
  src/app/common \
  src/device \

INC_DIRS := \
  lib/stm8/inc \
  src/peripheral \

include makefile-worker.mk
