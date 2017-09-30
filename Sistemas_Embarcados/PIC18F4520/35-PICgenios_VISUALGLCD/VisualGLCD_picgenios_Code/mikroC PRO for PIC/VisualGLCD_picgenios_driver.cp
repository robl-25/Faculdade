#line 1 "C:/Users/Microgenios/Desktop/AplicaçõesGLCD/VISUALGLCD/VisualGLCD_picgenios_Code/mikroC PRO for PIC/VisualGLCD_picgenios_driver.c"
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
#line 4 "C:/Users/Microgenios/Desktop/AplicaçõesGLCD/VISUALGLCD/VisualGLCD_picgenios_Code/mikroC PRO for PIC/VisualGLCD_picgenios_driver.c"
char T6963C_dataPort at PORTB;
sbit T6963C_ctrlwr at RD0_bit;
sbit T6963C_ctrlrd at RD1_bit;
sbit T6963C_ctrlcd at RD3_bit;
sbit T6963C_ctrlrst at RD4_bit;
sbit T6963C_ctrlwr_Direction at TRISD0_bit;
sbit T6963C_ctrlrd_Direction at TRISD1_bit;
sbit T6963C_ctrlcd_Direction at TRISD3_bit;
sbit T6963C_ctrlrst_Direction at TRISD4_bit;


unsigned int Xcoord, Ycoord;
char PenDown;
void *PressedObject;
static void InitializeTouchPanel() {



 T6963C_init(128, 64, 8);
  T6963C_display. F3  = 1; T6963C_writeCommand(T6963C_display) ;
  T6963C_display. F2  = 1; T6963C_writeCommand(T6963C_display) ;
  T6963C_display. F1  = 0; T6963C_writeCommand(T6963C_display) ;

}




 TScreen *CurrentScreen;

 TScreen Screen1;
 TCaptionButton_Round RoundCaptionButton1;
 char RoundCaptionButton1_Caption[13] = "VISUAL GLCD ";

 TButton_Round RoundEdgedButton1;
 TButton_Round RoundEdgedButton2;
 TButton_Round RoundEdgedButton3;
 TButton_Round RoundEdgedButton4;
 TButton_Round *Screen0_Buttons_Round[4];
 TCaptionButton_Round *Screen0_CaptionButtons_Round[1];

 TScreen Screen2;
 TButton Button1;
 TButton Button2;
 TButton *Screen1_Buttons[2];



static void InitializeObjects() {
 Screen1.ButtonsCount = 0;
 Screen1.Buttons_RoundCount = 4;
 Screen1.Buttons_Round = Screen0_Buttons_Round;
 Screen1.CaptionButtons_RoundCount = 1;
 Screen1.CaptionButtons_Round = Screen0_CaptionButtons_Round;
 Screen0_CaptionButtons_Round[0] = &RoundCaptionButton1;
 Screen0_Buttons_Round[0] = &RoundEdgedButton1;
 Screen0_Buttons_Round[1] = &RoundEdgedButton2;
 Screen0_Buttons_Round[2] = &RoundEdgedButton3;
 Screen0_Buttons_Round[3] = &RoundEdgedButton4;

 Screen2.ButtonsCount = 2;
 Screen2.Buttons = Screen1_Buttons;
 Screen2.Buttons_RoundCount = 0;
 Screen2.CaptionButtons_RoundCount = 0;
 Screen1_Buttons[0] = &Button1;
 Screen1_Buttons[1] = &Button2;


 RoundCaptionButton1.OwnerScreen = &Screen1;
 RoundCaptionButton1.Left = 11;
 RoundCaptionButton1.Top = 3;
 RoundCaptionButton1.Width = 106;
 RoundCaptionButton1.Height = 18;
 RoundCaptionButton1.BorderWidth = 3;
 RoundCaptionButton1.Round_Radius = 4;
 RoundCaptionButton1.Caption = RoundCaptionButton1_Caption;
 RoundCaptionButton1.FontName = 0;
 RoundCaptionButton1.FontWidth = 7;
 RoundCaptionButton1.FontHeight = 7;
 RoundCaptionButton1.FontOffset = 32;
 RoundCaptionButton1.FontColor = _clInvert;
 RoundCaptionButton1.Visible = 1;
 RoundCaptionButton1.OnUpPtr = 0;
 RoundCaptionButton1.OnDownPtr = 0;
 RoundCaptionButton1.OnClickPtr = 0;
 RoundCaptionButton1.OnPressPtr = 0;

 RoundEdgedButton1.OwnerScreen = &Screen1;
 RoundEdgedButton1.Left = 12;
 RoundEdgedButton1.Top = 35;
 RoundEdgedButton1.Width = 20;
 RoundEdgedButton1.Height = 12;
 RoundEdgedButton1.Round_Radius = 4;
 RoundEdgedButton1.Visible = 1;
 RoundEdgedButton1.OnUpPtr = 0;
 RoundEdgedButton1.OnDownPtr = 0;
 RoundEdgedButton1.OnClickPtr = 0;
 RoundEdgedButton1.OnPressPtr = 0;

 RoundEdgedButton2.OwnerScreen = &Screen1;
 RoundEdgedButton2.Left = 40;
 RoundEdgedButton2.Top = 35;
 RoundEdgedButton2.Width = 20;
 RoundEdgedButton2.Height = 12;
 RoundEdgedButton2.Round_Radius = 4;
 RoundEdgedButton2.Visible = 1;
 RoundEdgedButton2.OnUpPtr = 0;
 RoundEdgedButton2.OnDownPtr = 0;
 RoundEdgedButton2.OnClickPtr = 0;
 RoundEdgedButton2.OnPressPtr = 0;

 RoundEdgedButton3.OwnerScreen = &Screen1;
 RoundEdgedButton3.Left = 69;
 RoundEdgedButton3.Top = 35;
 RoundEdgedButton3.Width = 20;
 RoundEdgedButton3.Height = 12;
 RoundEdgedButton3.Round_Radius = 4;
 RoundEdgedButton3.Visible = 1;
 RoundEdgedButton3.OnUpPtr = 0;
 RoundEdgedButton3.OnDownPtr = 0;
 RoundEdgedButton3.OnClickPtr = 0;
 RoundEdgedButton3.OnPressPtr = 0;

 RoundEdgedButton4.OwnerScreen = &Screen1;
 RoundEdgedButton4.Left = 97;
 RoundEdgedButton4.Top = 35;
 RoundEdgedButton4.Width = 20;
 RoundEdgedButton4.Height = 12;
 RoundEdgedButton4.Round_Radius = 4;
 RoundEdgedButton4.Visible = 1;
 RoundEdgedButton4.OnUpPtr = 0;
 RoundEdgedButton4.OnDownPtr = 0;
 RoundEdgedButton4.OnClickPtr = 0;
 RoundEdgedButton4.OnPressPtr = 0;

 Button1.OwnerScreen = &Screen2;
 Button1.Left = 12;
 Button1.Top = 12;
 Button1.Width = 20;
 Button1.Height = 12;
 Button1.Visible = 1;
 Button1.OnUpPtr = 0;
 Button1.OnDownPtr = 0;
 Button1.OnClickPtr = 0;
 Button1.OnPressPtr = 0;

 Button2.OwnerScreen = &Screen2;
 Button2.Left = 36;
 Button2.Top = 12;
 Button2.Width = 20;
 Button2.Height = 12;
 Button2.Visible = 1;
 Button2.OnUpPtr = 0;
 Button2.OnDownPtr = 0;
 Button2.OnClickPtr = 0;
 Button2.OnPressPtr = 0;
}








void DrawButton(TButton *Abutton) {
 T6963C_box(Abutton->Left, Abutton->Top,
 Abutton->Left + Abutton->Width - 1,
 Abutton->Top + Abutton->Height - 1,  0b1000 );
 if ((Abutton->Width >= 5) && (Abutton->Height >= 5))
 T6963C_rectangle(Abutton->Left + 1, Abutton->Top + 1,
 Abutton->Left + Abutton->Width - 2,
 Abutton->Top + Abutton->Height - 2,  0 );
}

static void DrawButtons() {
 int i;
 TButton *local_button;

 for ( i = 0 ; i < CurrentScreen->ButtonsCount ; i++ ) {
 local_button =  CurrentScreen->Buttons[i] ;
 if (local_button->Visible == 1) {
 DrawButton(local_button);
 }
 }
}


void DrawRoundButton(TButton_Round *Around_button) {
 T6963C_Rectangle_Round_Edges_Fill(Around_button->Left, Around_button->Top,
 Around_button->Left + Around_button->Width - 1,
 Around_button->Top + Around_button->Height - 1, Around_button->Round_Radius,  0b1000 );
 if ((Around_button->Width >= 5) && (Around_button->Height >= 5))
 T6963C_Rectangle_Round_Edges(Around_button->Left + 1, Around_button->Top + 1,
 Around_button->Left + Around_button->Width - 2,
 Around_button->Top + Around_button->Height - 2, Around_button->Round_Radius,  0 );
}

static void DrawRoundButtons() {
 int i;
 TButton_Round *local_round_button;

 for ( i = 0 ; i < CurrentScreen->Buttons_RoundCount ; i++ ) {
 local_round_button =  CurrentScreen->Buttons_Round[i] ;
 if (local_round_button->Visible == 1) {
 DrawRoundButton(local_round_button);
 }
 }
}


void DrawRoundCaptionButton(TCaptionButton_Round *Around_caption_button) {
 T6963C_Rectangle_Round_Edges_Fill(Around_caption_button->Left, Around_caption_button->Top,
 Around_caption_button->Left + Around_caption_button->Width - 1,
 Around_caption_button->Top + Around_caption_button->Height - 1, Around_caption_button->Round_Radius,  0b1000 );
 if ((Around_caption_button->Width >= 5) && (Around_caption_button->Height >= 5))
 T6963C_Rectangle_Round_Edges(Around_caption_button->Left + 1, Around_caption_button->Top + 1,
 Around_caption_button->Left + Around_caption_button->Width - 2,
 Around_caption_button->Top + Around_caption_button->Height - 2, Around_caption_button->Round_Radius,  0 );
 T6963C_write_text(Around_caption_button->Caption,
 (Around_caption_button->Left + Around_caption_button->BorderWidth + 2) / 8,
 (Around_caption_button->Top + Around_caption_button->BorderWidth + 2) / 8,  0b10000001 );
}

static void DrawRoundCaptionButtons() {
 int i;
 TCaptionButton_Round *local_round_caption_button;

 for ( i = 0 ; i < CurrentScreen->CaptionButtons_RoundCount ; i++ ) {
 local_round_caption_button =  CurrentScreen->CaptionButtons_Round[i] ;
 if (local_round_caption_button->Visible == 1) {
 DrawRoundCaptionButton(local_round_caption_button);
 }
 }
}

void DrawScreen(TScreen *aScreen) {
  T6963C_fill(0, 0, T6963C_grMemSize) ;
  T6963C_fill(0, T6963C_grMemsize, T6963C_txtMemSize) ;

 CurrentScreen = aScreen;

 DrawButtons();

 DrawRoundButtons();

 DrawRoundCaptionButtons();

}



void Start_TP() {
 InitializeTouchPanel();

 InitializeObjects();
 DrawScreen(&Screen2);
}
