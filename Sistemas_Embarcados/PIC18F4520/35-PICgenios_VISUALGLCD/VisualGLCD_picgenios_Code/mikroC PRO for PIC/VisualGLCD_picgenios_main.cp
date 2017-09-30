#line 1 "C:/Users/Microgenios/Desktop/AplicaçõesGLCD/VISUALGLCD/VisualGLCD_picgenios_Code/mikroC PRO for PIC/VisualGLCD_picgenios_main.c"
#line 1 "c:/users/microgenios/desktop/aplicaçõesglcd/visualglcd/visualglcd_picgenios_code/mikroc pro for pic/visualglcd_picgenios_objects.h"
#line 1 "c:/users/microgenios/desktop/aplicaçõesglcd/visualglcd/visualglcd_picgenios_code/mikroc pro for pic/__t6963c.h"
#line 165 "c:/users/microgenios/desktop/aplicaçõesglcd/visualglcd/visualglcd_picgenios_code/mikroc pro for pic/__t6963c.h"
void T6963C_init(unsigned int w, unsigned char h, unsigned char fntW);
void T6963C_writeData(unsigned char mydata);
void T6963C_writeCommand(unsigned char mydata);
void T6963C_setPtr(unsigned int addr, unsigned char t);
void T6963C_waitReady(void);
void T6963C_fill(unsigned char mydata, unsigned int start, unsigned int len);
void T6963C_dot(int x, int y, unsigned char color);
void T6963C_write_char(unsigned char c, unsigned char x, unsigned char y, unsigned char mode);
void T6963C_write_text(unsigned char *str, unsigned char x, unsigned char y, unsigned char mode);
void T6963C_line(int px0, int py0, int px1, int py1, unsigned char pcolor);
void T6963C_rectangle(int x0, int y0, int x1, int y1, unsigned char pcolor);
void T6963C_box(int x0, int y0, int x1, int y1, unsigned char pcolor);
void T6963C_circle(int x, int y, long r, unsigned char pcolor);
void T6963C_image(const char *pic);
void T6963C_sprite(unsigned char px, unsigned char py, const char *pic, unsigned char sx, unsigned char sy);
void T6963C_set_cursor(unsigned char x, unsigned char y);
void T6963C_PartialImage(unsigned int x_left, unsigned int y_top, unsigned int width,
 unsigned int height, code const unsigned short * image);
void T6963C_Rectangle_Round_Edges(unsigned int x_upper_left, unsigned int y_upper_left,
 unsigned int x_bottom_right, unsigned int y_bottom_right,
 unsigned int round_radius, unsigned short color);
void T6963C_Rectangle_Round_Edges_Fill(unsigned int x_upper_left, unsigned int y_upper_left,
 unsigned int x_bottom_right, unsigned int y_bottom_right,
 unsigned int round_radius, unsigned short color);
void T6963C_Circle_Fill(int x_center, int y_center, int radius, unsigned short color);
#line 194 "c:/users/microgenios/desktop/aplicaçõesglcd/visualglcd/visualglcd_picgenios_code/mikroc pro for pic/__t6963c.h"
extern sfr char T6963C_dataPort;
extern sfr char T6963C_cntlPort;

extern unsigned int T6963C_grWidth;
extern unsigned int T6963C_grHeight;
extern unsigned int T6963C_txtCols;

extern unsigned int T6963C_fontWidth;
extern unsigned int T6963C_grHomeAddr;
extern unsigned int T6963C_textHomeAddr;
extern unsigned int T6963C_grMemSize;
extern unsigned int T6963C_txtMemSize;

extern sfr sbit T6963C_cntlwr;
extern sfr sbit T6963C_cntlrd;
extern sfr sbit T6963C_cntlcd;
extern sfr sbit T6963C_cntlrst;

extern unsigned char T6963C_display;
#line 2 "c:/users/microgenios/desktop/aplicaçõesglcd/visualglcd/visualglcd_picgenios_code/mikroc pro for pic/visualglcd_picgenios_objects.h"
enum GlcdColor {_clClear, _clDraw, _clInvert};

typedef struct Screen TScreen;

typedef struct Button {
 TScreen *OwnerScreen;
 char Left;
 char Top;
 char Width;
 char Height;
 char Visible;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TButton;

typedef struct Button_Round {
 TScreen *OwnerScreen;
 char Left;
 char Top;
 char Width;
 char Height;
 char Round_Radius;
 char Visible;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TButton_Round;

typedef struct CaptionButton_Round {
 TScreen *OwnerScreen;
 char Left;
 char Top;
 char Width;
 char Height;
 char BorderWidth;
 char Round_Radius;
 char *Caption;
 const char *FontName;
 char FontWidth;
 char FontHeight;
 char FontOffset;
 char FontColor;
 char Visible;
 void (*OnUpPtr)();
 void (*OnDownPtr)();
 void (*OnClickPtr)();
 void (*OnPressPtr)();
} TCaptionButton_Round;

struct Screen {
 unsigned int ButtonsCount;
 TButton **Buttons;
 unsigned int Buttons_RoundCount;
 TButton_Round **Buttons_Round;
 unsigned int CaptionButtons_RoundCount;
 TCaptionButton_Round **CaptionButtons_Round;
};

extern TScreen Screen1;
extern TCaptionButton_Round RoundCaptionButton1;
extern TButton_Round RoundEdgedButton1;
extern TButton_Round RoundEdgedButton2;
extern TButton_Round RoundEdgedButton3;
extern TButton_Round RoundEdgedButton4;

extern TScreen Screen2;
extern TButton Button1;
extern TButton Button2;








extern char RoundCaptionButton1_Caption[];


void DrawScreen(TScreen *aScreen);
void DrawButton(TButton *Abutton);
void DrawRoundButton(TButton_Round *Around_button);
void DrawRoundCaptionButton(TCaptionButton_Round *Around_caption_button);
void Check_TP();
void Start_TP();
#line 8 "C:/Users/Microgenios/Desktop/AplicaçõesGLCD/VISUALGLCD/VisualGLCD_picgenios_Code/mikroC PRO for PIC/VisualGLCD_picgenios_main.c"
const code char handsOn_PaintEstrela[] = {
127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 252,
127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 252,
127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 252,
127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 252,
127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 252,
124, 0, 0, 0, 0, 0, 0, 7, 224, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 7, 224, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 7, 240, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 15, 240, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 15, 240, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 31, 248, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 31, 248, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 63, 252, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 63, 252, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 63, 252, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 127, 254, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 127, 254, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 255, 255, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 255, 255, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 0, 255, 255, 0, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 1, 255, 255, 128, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 1, 255, 255, 128, 0, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 0, 3, 255, 255, 192, 0, 0, 0, 0, 0, 124,
124, 0, 0, 3, 255, 255, 255, 255, 255, 255, 255, 255, 192, 0, 0, 124,
124, 0, 0, 7, 255, 255, 255, 255, 255, 255, 255, 255, 224, 0, 0, 124,
124, 0, 0, 15, 255, 255, 255, 255, 255, 255, 255, 255, 240, 0, 0, 124,
124, 0, 0, 15, 255, 255, 255, 255, 255, 255, 255, 255, 240, 0, 0, 124,
124, 0, 0, 7, 255, 255, 255, 255, 255, 255, 255, 255, 224, 0, 0, 124,
124, 0, 0, 3, 255, 255, 255, 255, 255, 255, 255, 255, 192, 0, 0, 124,
124, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 124,
124, 0, 0, 0, 63, 255, 255, 255, 255, 255, 255, 254, 0, 0, 0, 124,
124, 0, 0, 0, 31, 255, 255, 255, 255, 255, 255, 248, 0, 0, 0, 124,
124, 0, 0, 0, 7, 255, 255, 255, 255, 255, 255, 224, 0, 0, 0, 124,
124, 0, 0, 0, 1, 255, 255, 255, 255, 255, 255, 128, 0, 0, 0, 124,
124, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 63, 255, 255, 255, 255, 252, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 15, 255, 255, 255, 255, 240, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 7, 255, 255, 255, 255, 224, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 1, 255, 255, 255, 255, 128, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 1, 255, 255, 255, 255, 128, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 1, 255, 255, 255, 255, 128, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 1, 255, 255, 255, 255, 128, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 3, 255, 255, 255, 255, 192, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 3, 255, 255, 255, 255, 192, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 7, 255, 255, 255, 255, 224, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 7, 255, 255, 255, 255, 224, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 7, 255, 255, 255, 255, 224, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 15, 255, 255, 255, 255, 240, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 15, 255, 255, 255, 255, 240, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 15, 255, 254, 127, 255, 240, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 31, 255, 248, 31, 255, 248, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 31, 127, 224, 7, 254, 248, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 63, 255, 192, 3, 255, 252, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 63, 255, 0, 0, 255, 252, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 63, 252, 0, 0, 63, 252, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 127, 240, 0, 0, 15, 254, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 127, 192, 0, 0, 3, 254, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 127, 128, 0, 0, 0, 254, 0, 0, 0, 0, 124,
124, 0, 0, 0, 0, 126, 0, 0, 0, 0, 126, 0, 0, 0, 0, 124,
127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 252,
127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 252,
127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 252,
127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 252,
127, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 252
};


unsigned char ucRecepcao = 0;

void interrupt() {

 if( RCIF_bit == 1) {
 ucRecepcao = UART1_Read();
 UART1_Write(ucRecepcao);
 RCIF_bit = 0;
 }
}



void main() {
 unsigned char Texto[10];
 unsigned int Leitura_AN0;
 ADCON1 = 0B00001111;
 TRISD = 0;
 PORTD = 0;
 TRISB = 0;
 PORTB = 0;

 Start_TP();

 INTCON.GIEH = 1;
 INTCON.GIEL = 1;
 RCON.IPEN = 1;

 RCIF_bit = 0;
 RCIP_bit = 1;
 RCIE_bit = 1;
 UART1_Init(9600);

 while (1) {

 switch(ucRecepcao)
 {
 case 'A' : {
 DrawScreen(&Screen1);
 ucRecepcao = 0;
 do{
 Leitura_AN0 = ADC_Read(0);
 Leitura_AN0 = Leitura_AN0 * (128/1023.);
 WordToStr(Leitura_AN0, Texto);

 Texto[5] = '%';
 Texto[6] = 0;

 T6963C_write_text(Texto, 0, 7,  0b10000001  );
 }while(ucRecepcao == 0);
 break;
 }
 case 'B' : { DrawScreen(&Screen2); ucRecepcao = 0; break; }

 case 'C' : {
 T6963C_image(handsOn_PaintEstrela);
 ucRecepcao = 0;
 break;
 }
 }
 }

}
