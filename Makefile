#
# Copyright (c) 2014 Rafael Vega <rvega@elsoftwarehamuerto.org>
# 
# BSD Simplified License.
# For information on usage and redistribution, and for a DISCLAIMER OF ALL
# WARRANTIES, see the file, "LICENSE.txt," in this distribution.
# 
# See https://github.com/libpd/libpd for documentation
#

# detect platform, move libpd dylib to local folder on mac
UNAME = $(shell uname)
SOLIB_PREFIX = lib

ifeq ($(UNAME), Darwin)  # Mac
  SOLIB_EXT = dylib
  PLATFORM = mac
  CXXFLAGS = -D__MACOSX_CORE__ -DHAVE_UNISTD_H
  AUDIO_API = -framework Foundation -framework CoreAudio
else
  ifeq ($(OS), Windows_NT)  # Windows, use Mingw
    SOLIB_EXT = dll
    SOLIB_PREFIX = 
    PLATFORM = windows
    CXXFLAGS = -D__WINDOWS_DS__
    AUDIO_API = -lole32 -loleaut32 -ldsound -lwinmm
  else  # assume Linux
    SOLIB_EXT = so
    PLATFORM = linux
    CXXFLAGS = -D__UNIX_JACK__ -D__LINUX_ALSA__
    AUDIO_API = -ljack -lasound -pthread
  endif
endif

LIBPD_DIR = ./libpd
LIBPD = libs/libpd.$(SOLIB_EXT)

SRC_DIR = src
OBJ_DIR = obj
# SRC_FILES = src/PdObject.cpp src/RtAudio.cpp src/gatto.cpp src/maingame.cpp src/npc.cpp src/oggetto.cpp src/stanza.cpp 
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
TARGET = game

CXXFLAGS += -I$(LIBPD_DIR)/libpd_wrapper -I$(LIBPD_DIR)/libpd_wrapper/util \
            -I$(LIBPD_DIR)/pure-data/src -I$(LIBPD_DIR)/cpp \
            -I./src -std=c++11 -DLIBPD_USE_STD_MUTEX -O3 \
            -I ./include

.PHONY: clean clobber

$(TARGET): $(OBJS) $(LIBPD)
	g++ -o $(TARGET) $^ $(LIBPD) $(AUDIO_API)
ifeq ($(PLATFORM), mac)
# mkdir -p ./libs && cp $(LIBPD) ./libs
endif

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	g++ $(CXXFLAGS) -c $< -o $@

$(LIBPD):
	cd $(LIBPD_DIR) && make UTIL=true EXTRA=true

$(OBJ_DIR): 
	mkdir -p $(dir $(OBJS))

clean:
	rm -rf obj $(TARGET)

clobber: clean
	rm -f $(TARGET)
ifeq ($(PLATFORM), mac)
	rm -rf ./libs
endif
	cd $(LIBPD_DIR) && make clobber

run: $(TARGET)
	./$(TARGET)
