# Verify the OS
ifeq ($(OS),Windows_NT)
    OS_NAME := windows
else
    OS_NAME := linux
endif

# Folder from command line
F ?= .

# C program
ifeq ($(OS_NAME), windows)
	COMMAND := $(MAKE) --file=.\Make\Windows\Makefile.win
else
	COMMAND := $(MAKE) --file=./Make/Linux/Makefile.linux
endif

all:
	$(COMMAND) STRUCTURE=$(F)

clean:
	$(COMMAND) clean STRUCTURE=$(F)

run:
	$(COMMAND) run STRUCTURE=$(F)