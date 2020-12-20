# Toolchain.
export CC = g++
# Toolchain configuration.
export CFLAGS += --std=c++11 -Wall -Wextra -O3
# Executable file.
export EXEC = rng

all:
	$(CC) $(CFLAGS) $(EXEC).cpp -o $(EXEC).elf

clean:
	rm -f $(EXEC).elf
