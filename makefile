#
# Copyright(C) 2016-2017 Pedro H. Penna <pedrohenriquepenna@gmail.com>
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.
#

# Directories.
export BINDIR = $(CURDIR)/bin
export INCDIR = $(CURDIR)/include
export SRCDIR = $(CURDIR)/src

# Toolchain.
export CC = g++

# Toolchain configuration.
export CFLAGS += -I $(INCDIR) -I $(CURDIR)/contrib/enhanced-libgomp/src/libgomp/build -I $(CURDIR)/..//MOGSLib/include
export CFLAGS += --std=c++14 -static -fopenmp
export CFLAGS += -Wall -Wextra
export CFLAGS += -O3

# Libraries.
export LIBS = -L $(CURDIR)/contrib/enhanced-libgomp/src/libgomp/build/.libs -lgomp -lm

# Executable file.
export EXEC = benchmark

# Builds everything.
all:
	mkdir -p $(BINDIR)
	$(CC) $(SRCDIR)/benchmark/*.cpp $(CFLAGS)  -o $(BINDIR)/$(EXEC).elf $(LIBS)

# Cleans compilation files.
clean:
	rm -f $(BINDIR)/$(EXEC).elf
