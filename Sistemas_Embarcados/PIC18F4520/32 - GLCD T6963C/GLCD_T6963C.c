#include        "__T6963C.h"

// T6963C module connections
char T6963C_dataPort at PORTD;                   // DATA port

sbit T6963C_ctrlwr  at RC2_bit;                  // WR write signal
sbit T6963C_ctrlrd  at RC1_bit;                  // RD read signal
sbit T6963C_ctrlcd  at RC0_bit;                  // CD command/data signal
sbit T6963C_ctrlrst at RC4_bit;                  // RST reset signal
sbit T6963C_ctrlwr_Direction  at TRISC2_bit;     // WR write signal
sbit T6963C_ctrlrd_Direction  at TRISC1_bit;     // RD read signal
sbit T6963C_ctrlcd_Direction  at TRISC0_bit;     // CD command/data signal
sbit T6963C_ctrlrst_Direction at TRISC4_bit;     // RST reset signal

// Signals not used by library, they are set in main function
sbit T6963C_ctrlce at RC3_bit;                   // CE signal
sbit T6963C_ctrlfs at RC6_bit;                   // FS signal
sbit T6963C_ctrlmd at RC5_bit;                   // MD signal
sbit T6963C_ctrlce_Direction  at TRISC3_bit;     // CE signal direction
sbit T6963C_ctrlfs_Direction  at TRISC6_bit;     // FS signal direction
sbit T6963C_ctrlmd_Direction  at TRISC5_bit;     // MD signal direction

// End T6963C module connections

/*
 * bitmap pictures stored in ROM
 */
const code char mikroe_bmp[];
const code char einstein[];


void main() {
  char txt1[] = " EINSTEIN WOULD HAVE LIKED mE";
  char txt[] =  " GLCD LIBRARY DEMO, WELCOME !";

  unsigned char  panel;         // Current panel
  unsigned int   i;             // General purpose register
  unsigned char  curs;          // Cursor visibility
  unsigned int   cposx, cposy;  // Cursor x-y position

  TRISA0_bit = 1;               // Set RA0 as input
  TRISA1_bit = 1;               // Set RA1 as input
  TRISA2_bit = 1;               // Set RA2 as input
  TRISA3_bit = 1;               // Set RA3 as input
  TRISA4_bit = 1;               // Set RA4 as input

  T6963C_ctrlce_Direction = 0;
  T6963C_ctrlce = 0;            // Enable T6963C
  T6963C_ctrlfs_Direction = 0;
  T6963C_ctrlfs = 0;            // Font Select 8x8
  T6963C_ctrlmd_Direction = 0;
  T6963C_ctrlmd = 0;            // Column number select



  // Initialize T6369C
  T6963C_init(240, 128, 8);

  /*
   * Enable both graphics and text display at the same time
   */
  T6963C_graphics(1);
  T6963C_text(1);

  panel = 0;
  i = 0;
  curs = 0;
  cposx = cposy = 0;
  /*
   * Text messages
   */
  T6963C_write_text(txt, 0, 0, T6963C_ROM_MODE_XOR);
  T6963C_write_text(txt1, 0, 15, T6963C_ROM_MODE_XOR);

  /*
   * Cursor
   */
  T6963C_cursor_height(8);       // 8 pixel height
  T6963C_set_cursor(0, 0);       // Move cursor to top left
  T6963C_cursor(0);              // Cursor off

  /*
   * Draw rectangles
   */
  T6963C_rectangle(0, 0, 239, 127, T6963C_WHITE);
  T6963C_rectangle(20, 20, 219, 107, T6963C_WHITE);
  T6963C_rectangle(40, 40, 199, 87, T6963C_WHITE);
  T6963C_rectangle(60, 60, 179, 67, T6963C_WHITE);

  /*
   * Draw a cross
   */
  T6963C_line(0, 0, 239, 127, T6963C_WHITE);
  T6963C_line(0, 127, 239, 0, T6963C_WHITE);

  /*
   * Draw solid boxes
   */
  T6963C_box(0, 0, 239, 8, T6963C_WHITE);
  T6963C_box(0, 119, 239, 127, T6963C_WHITE);

  /*
   * Draw circles
   */
  T6963C_circle(120, 64, 10, T6963C_WHITE);
  T6963C_circle(120, 64, 30, T6963C_WHITE);
  T6963C_circle(120, 64, 50, T6963C_WHITE);
  T6963C_circle(120, 64, 70, T6963C_WHITE);
  T6963C_circle(120, 64, 90, T6963C_WHITE);
  T6963C_circle(120, 64, 110, T6963C_WHITE);
  T6963C_circle(120, 64, 130, T6963C_WHITE);

  T6963C_sprite(76, 4, einstein, 88, 119);         // Draw a sprite

  T6963C_setGrPanel(1);                            // Select other graphic panel

  //T6963C_image(mikroE_240x64_bmp);

  for(;;) {                                        // Endless loop
    /*
     * If RA0 is pressed, display only graphic panel
     */
    if(RA0_bit) {
      T6963C_graphics(1);
      T6963C_text(0);
      Delay_ms(300);
      }

    /*
     * If RA1 is pressed, toggle the display between graphic panel 0 and graphic panel 1
     */
    else if(RA1_bit) {
      panel++;
      panel &= 1;
      T6963C_displayGrPanel(panel);
      Delay_ms(300);
      }

    /*
     * If RA2 is pressed, display only text panel
     */
    else if(RA2_bit) {
      T6963C_graphics(0);
      T6963C_text(1);
      Delay_ms(300);
      }

    /*
     * If RA3 is pressed, display text and graphic panels
     */
    else if(RA3_bit) {
      T6963C_graphics(1);
      T6963C_text(1);
      Delay_ms(300);
      }

    /*
     * If RA4 is pressed, change cursor
     */
    else if(RA4_bit) {
      curs++;
      if(curs == 3) curs = 0;
      switch(curs) {
        case 0:
          // no cursor
          T6963C_cursor(0);
          break;
        case 1:
          // blinking cursor
          T6963C_cursor(1);
          T6963C_cursor_blink(1);
          break;
        case 2:
          // non blinking cursor
          T6963C_cursor(1);
          T6963C_cursor_blink(0);
          break;
        }
      Delay_ms(300);
      }

    /*
     * Move cursor, even if not visible
     */
    cposx++;
    if(cposx == T6963C_txtCols) {
      cposx = 0;
      cposy++;
      if(cposy == T6963C_grHeight / T6963C_CHARACTER_HEIGHT) {
        cposy = 0;
        }
      }
    T6963C_set_cursor(cposx, cposy);

    Delay_ms(100);
    }
}
