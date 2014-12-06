/* 
 * File:   keyboard.h
 * Author: Brian Rieder <brieder@purdue.edu>
 *
 * Created on December 6, 2014, 12:13 PM
 * 
 * ============================================================================
 * 
 * This library was made to be compatible with the CodeWarrior compiler.
 */

 #define KEYBOARD_A 0x1C
 #define KEYBOARD_A_backwards 0xC1
 #define KEYBOARD_B 0x32
 #define KEYBOARD_C 0x21
 #define KEYBOARD_D 0x23
 #define KEYBOARD_E 0x24
 #define KEYBOARD_F 0x2B
 #define KEYBOARD_G 0x34
 #define KEYBOARD_H 0x33
 #define KEYBOARD_I 0x43
 #define KEYBOARD_J 0x3B
 #define KEYBOARD_K 0x42
 #define KEYBOARD_L 0x4B
 #define KEYBOARD_M 0x3A
 #define KEYBOARD_N 0x31
 #define KEYBOARD_O 0x44
 #define KEYBOARD_P 0x4D
 #define KEYBOARD_Q 0x15
 #define KEYBOARD_R 0x2D
 #define KEYBOARD_S 0x1B
 #define KEYBOARD_T 0x2C
 #define KEYBOARD_U 0x3C
 #define KEYBOARD_V 0x2A
 #define KEYBOARD_W 0x1D
 #define KEYBOARD_X 0x22
 #define KEYBOARD_Y 0x35
 #define KEYBOARD_Z 0x1A
 #define KEYBOARD_ENTER 0x5A

 /**
 * Interrupt service routine triggered by the keyboard through the IRQ
 * pin on the microcontroller.
 * 
 * Instead of returning a character, this function uses 'keyboard_char_to_buff' to
 * write to the global character buffer 'keyboard_char_buff'.
 *
 */
 interrupt 6 void IRQ_ISR(void);

 /**
 * Writes a character to buffer after removing parity, start, and stop
 * bits.
 * 
 * Instead of returning a character, this function writes to the global
 * character buffer 'keyboard_char_buff'.
 *
 */
 void keyboard_char_to_buff(void);

/**
 * Uses PS/2 Scan Code Set 2 to change keyboard input to actual characters.
 * 
 * Returns the character of the pressed key.
 *
 */
 unsigned char translate_keyboard_character(unsigned char buff_char);

/**
 * General purpose debugging function that writes a character in binary
 * to the SCI serial port.
 *
 */
 void outbin(char x);

 /**
 * General purpose debugging function that writes an integer in binary
 * to the SCI serial port.
 *
 */
 void outbin_int(int x);