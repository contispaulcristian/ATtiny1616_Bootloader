# --- Microcontroller and Clock Speed ---
MCU = attiny1616
# Define your clock speed here (e.g., 3.33MHz default, or 20MHz)
F_CPU = 3333333UL 

# --- Toolchain Definitions ---
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)

# --- Project Name and Source Files ---
TARGET = bootloader
SRCS = main.c

# --- Build Rules ---
# Typing 'make' will run this default rule
all: $(TARGET).hex

# Compile the C code into an ELF file
$(TARGET).elf: $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET).elf $(SRCS)

# Convert the ELF file into a HEX file (which the chip needs)
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $(TARGET).elf $(TARGET).hex

# --- Flashing Rule ---
# Typing 'make flash' will upload the code via Atmel-ICE on UPDI
flash: $(TARGET).hex
	avrdude -c atmelice_updi -p $(MCU) -U flash:w:$(TARGET).hex:i

# --- Cleanup Rule ---
# Typing 'make clean' removes the compiled files
clean:
	rm -f *.elf *.hex