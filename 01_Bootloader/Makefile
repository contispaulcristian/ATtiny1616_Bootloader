# --- Microcontroller and Clock Speed ---
MCU = attiny1616
# Define your clock speed here (e.g., 3.33MHz default, or 20MHz)
F_CPU = 20000000UL

# --- Toolchain Definitions ---
CC = avr-gcc
OBJCOPY = avr-objcopy
# Variable for output directory
OUTPUT_DIR = prod

# --- Include Paths ---
INCLUDES = -I./include -I./src/hal -I./src/mcal_lite -I./src/secure

# --- Compiler Flags ---
CFLAGS = -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) $(INCLUDES)

# --- Project Name and Source Files ---
TARGET = $(OUTPUT_DIR)/bootloader
SRCS = src/main.c \
       src/fuses.c \
       src/mcal_lite/clk_drv.c \
       src/mcal_lite/i2c_drv.c \
       src/mcal_lite/port_drv.c \
       src/hal/nvm_driver.c \
       src/hal/st25dv64k_driver.c

# --- Build Rules ---
.PHONY: all clean flash directories

all: directories $(TARGET).hex
	@echo "-----------------------------------------------------"
	@echo "|   BUILD COMPLETE: $(TARGET).hex is ready.   |"
	@echo "-----------------------------------------------------"

# Create the prod directory if it doesn't exist
directories:
	@echo "Creating output directory: $(OUTPUT_DIR)..."
	@mkdir -p $(OUTPUT_DIR)

$(TARGET).elf: $(SRCS)
	@echo "Compiling C source files for $(MCU)..."
	@$(CC) $(CFLAGS) -o $(TARGET).elf $(SRCS)

$(TARGET).hex: $(TARGET).elf
	@echo "Extracting executable hex from elf..."
	@$(OBJCOPY) -O ihex -R .eeprom $(TARGET).elf $(TARGET).hex

flash: $(TARGET).hex
	@echo "Connecting to Atmel-ICE and flashing $(MCU)..."
	@avrdude -c atmelice_updi -p $(MCU) -U flash:w:$(TARGET).hex:i && \
	(echo "---------------------------------------------------------"; \
	 echo "|   SUCCESS: Firmware flashed to $(MCU) successfully.   |"; \
	 echo "---------------------------------------------------------") || \
	(echo "-------------------------------------------------------"; \
	 echo "|   ERROR: Flashing failed. Check your UPDI wiring!   |"; \
	 echo "-------------------------------------------------------"; \
	 exit 1)

clean:
	@echo "Cleaning up build artifacts in $(OUTPUT_DIR)..."
	@rm -rf $(OUTPUT_DIR)
	@echo "-----------------------"
	@echo "|   Clean complete.   |"
	@echo "-----------------------"