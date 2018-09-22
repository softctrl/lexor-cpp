#
#
# Author:
#  Carlos Timoshenko
#  carlostimoshenkorodrigueslopes@gmail.com
#
#  https://github.com/softctrl
#
# This project is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 3 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
#
TEMPLATE = lib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    state.cpp \
    token.cpp \
    reader.cpp \
    machine.cpp \
    tail.cpp \
    type.cpp \
    symbols.cpp \
    state_exception.cpp \
    random_file_reader.cpp \
    lexor_exception.cpp \
    base_state.cpp \
    final_state.cpp \
    non_final_state.cpp \
    sc_string_utils.cpp

HEADERS += \
    state.h \
    token.h \
    reader.h \
    machine.h \
    tail.h \
    type.h \
    symbols.h \
    state_exception.h \
    random_file_reader.h \
    lexor_exception.h \
    base_state.h \
    final_state.h \
    non_final_state.h \
    sc_string_utils.h
