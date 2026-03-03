#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Set Pin PC0 (VQFN Physical Pin 10) as an OUTPUT
    // DIRSET stands for "Direction Set"
    // PIN0_bm is the "Bit Mask" built into the compiler for Pin 0
    PORTC.DIRSET = PIN0_bm;

    while (1) {
        // Toggle the LED state
        // OUTTGL stands for "Output Toggle"
        PORTC.OUTTGL = PIN0_bm;

        // Wait for 500 milliseconds (half a second)
        _delay_ms(500);
    }

    return 0;
}