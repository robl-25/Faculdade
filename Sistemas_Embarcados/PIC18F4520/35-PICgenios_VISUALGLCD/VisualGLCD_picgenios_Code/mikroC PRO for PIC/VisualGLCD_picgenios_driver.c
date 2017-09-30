#include "VisualGLCD_picgenios_objects.h"

// T6963C module connections
char T6963C_dataPort at PORTB;
sbit T6963C_ctrlwr at RD0_bit;
sbit T6963C_ctrlrd at RD1_bit;
sbit T6963C_ctrlcd at RD3_bit;
sbit T6963C_ctrlrst at RD4_bit;
sbit T6963C_ctrlwr_Direction at TRISD0_bit;
sbit T6963C_ctrlrd_Direction at TRISD1_bit;
sbit T6963C_ctrlcd_Direction at TRISD3_bit;
sbit T6963C_ctrlrst_Direction at TRISD4_bit;
sbit T6963C_ctrlce at ;
sbit T6963C_ctrlfs at ;
sbit T6963C_ctrlmd at ;
sbit T6963C_ctrlce_Direction at ;
sbit T6963C_ctrlfs_Direction at ;
sbit T6963C_ctrlmd_Direction at ;
// End T6963C module connections

// Touch Panel module connections
sbit DriveA at Todo;
sbit DriveB at Todo;
sbit DriveA_Direction at Todo;
sbit DriveB_Direction at Todo;
// End Touch Panel module connections

// Global variables
unsigned int Xcoord, Ycoord;
char PenDown;
void *PressedObject;
static void InitializeTouchPanel() {
  T6963C_ctrlce_Direction = 0;
  T6963C_ctrlce = 0;            // Enable T6963C
  T6963C_ctrlmd_Direction = 0;
  T6963C_ctrlmd = 0;            // Column number select
  T6963C_ctrlfs_Direction = 0;
  T6963C_ctrlfs = 0;            // Wide Font

  // Initialize T6963C
    T6963C_init(128, 128, 8);
  T6963C_graphics(1);
  T6963C_text(1);
  T6963C_cursor(0);

}

// Bitmaps

/////////////////////////
  TScreen *CurrentScreen;

  TScreen                Screen1;
  TCaptionButton_Round   RoundCaptionButton1;
  char RoundCaptionButton1_Caption[13] = "VISUAL GLCD ";

  TButton_Round          RoundEdgedButton1;
  TButton_Round          RoundEdgedButton2;
  TButton_Round          RoundEdgedButton3;
  TButton_Round          RoundEdgedButton4;
  TButton_Round          *Screen0_Buttons_Round[4];
  TCaptionButton_Round   *Screen0_CaptionButtons_Round[1];

  TScreen                Screen2;
  TButton                Button1;
  TButton                Button2;
  TButton                *Screen1_Buttons[2];



static void InitializeObjects() {
  Screen1.ButtonsCount              = 0;
  Screen1.Buttons_RoundCount        = 4;
  Screen1.Buttons_Round             = Screen0_Buttons_Round;
  Screen1.CaptionButtons_RoundCount = 1;
  Screen1.CaptionButtons_Round      = Screen0_CaptionButtons_Round;
  Screen0_CaptionButtons_Round[0]   = &RoundCaptionButton1;
  Screen0_Buttons_Round[0]          = &RoundEdgedButton1;
  Screen0_Buttons_Round[1]          = &RoundEdgedButton2;
  Screen0_Buttons_Round[2]          = &RoundEdgedButton3;
  Screen0_Buttons_Round[3]          = &RoundEdgedButton4;

  Screen2.ButtonsCount              = 2;
  Screen2.Buttons                   = Screen1_Buttons;
  Screen2.Buttons_RoundCount        = 0;
  Screen2.CaptionButtons_RoundCount = 0;
  Screen1_Buttons[0]                = &Button1;
  Screen1_Buttons[1]                = &Button2;


  RoundCaptionButton1.OwnerScreen  = &Screen1;
  RoundCaptionButton1.Left         = 11;
  RoundCaptionButton1.Top          = 3;
  RoundCaptionButton1.Width        = 106;
  RoundCaptionButton1.Height       = 18;
  RoundCaptionButton1.BorderWidth  = 3;
  RoundCaptionButton1.Round_Radius = 4;
  RoundCaptionButton1.Caption      = RoundCaptionButton1_Caption;
  RoundCaptionButton1.FontName    = 0;
  RoundCaptionButton1.FontWidth    = 7;
  RoundCaptionButton1.FontHeight   = 7;
  RoundCaptionButton1.FontOffset   = 32;
  RoundCaptionButton1.FontColor    = _clInvert;
  RoundCaptionButton1.Visible      = 1;
  RoundCaptionButton1.OnUpPtr     = 0;
  RoundCaptionButton1.OnDownPtr   = 0;
  RoundCaptionButton1.OnClickPtr  = 0;
  RoundCaptionButton1.OnPressPtr  = 0;

  RoundEdgedButton1.OwnerScreen  = &Screen1;
  RoundEdgedButton1.Left         = 12;
  RoundEdgedButton1.Top          = 35;
  RoundEdgedButton1.Width        = 20;
  RoundEdgedButton1.Height       = 12;
  RoundEdgedButton1.Round_Radius = 4;
  RoundEdgedButton1.Visible      = 1;
  RoundEdgedButton1.OnUpPtr     = 0;
  RoundEdgedButton1.OnDownPtr   = 0;
  RoundEdgedButton1.OnClickPtr  = 0;
  RoundEdgedButton1.OnPressPtr  = 0;

  RoundEdgedButton2.OwnerScreen  = &Screen1;
  RoundEdgedButton2.Left         = 40;
  RoundEdgedButton2.Top          = 35;
  RoundEdgedButton2.Width        = 20;
  RoundEdgedButton2.Height       = 12;
  RoundEdgedButton2.Round_Radius = 4;
  RoundEdgedButton2.Visible      = 1;
  RoundEdgedButton2.OnUpPtr     = 0;
  RoundEdgedButton2.OnDownPtr   = 0;
  RoundEdgedButton2.OnClickPtr  = 0;
  RoundEdgedButton2.OnPressPtr  = 0;

  RoundEdgedButton3.OwnerScreen  = &Screen1;
  RoundEdgedButton3.Left         = 69;
  RoundEdgedButton3.Top          = 35;
  RoundEdgedButton3.Width        = 20;
  RoundEdgedButton3.Height       = 12;
  RoundEdgedButton3.Round_Radius = 4;
  RoundEdgedButton3.Visible      = 1;
  RoundEdgedButton3.OnUpPtr     = 0;
  RoundEdgedButton3.OnDownPtr   = 0;
  RoundEdgedButton3.OnClickPtr  = 0;
  RoundEdgedButton3.OnPressPtr  = 0;

  RoundEdgedButton4.OwnerScreen  = &Screen1;
  RoundEdgedButton4.Left         = 97;
  RoundEdgedButton4.Top          = 35;
  RoundEdgedButton4.Width        = 20;
  RoundEdgedButton4.Height       = 12;
  RoundEdgedButton4.Round_Radius = 4;
  RoundEdgedButton4.Visible      = 1;
  RoundEdgedButton4.OnUpPtr     = 0;
  RoundEdgedButton4.OnDownPtr   = 0;
  RoundEdgedButton4.OnClickPtr  = 0;
  RoundEdgedButton4.OnPressPtr  = 0;

  Button1.OwnerScreen = &Screen2;
  Button1.Left        = 12;
  Button1.Top         = 12;
  Button1.Width       = 20;
  Button1.Height      = 12;
  Button1.Visible     = 1;
  Button1.OnUpPtr     = 0;
  Button1.OnDownPtr   = 0;
  Button1.OnClickPtr  = 0;
  Button1.OnPressPtr  = 0;

  Button2.OwnerScreen = &Screen2;
  Button2.Left        = 36;
  Button2.Top         = 12;
  Button2.Width       = 20;
  Button2.Height      = 12;
  Button2.Visible     = 1;
  Button2.OnUpPtr     = 0;
  Button2.OnDownPtr   = 0;
  Button2.OnClickPtr  = 0;
  Button2.OnPressPtr  = 0;
}



#define GetButton(index)              CurrentScreen->Buttons[index]
#define GetRoundButton(index)         CurrentScreen->Buttons_Round[index]
#define GetRoundCaptionButton(index)  CurrentScreen->CaptionButtons_Round[index]


void DrawButton(TButton *Abutton) {
  T6963C_box(Abutton->Left, Abutton->Top,
    Abutton->Left + Abutton->Width - 1,
    Abutton->Top + Abutton->Height - 1, T6963C_WHITE);
  if ((Abutton->Width >= 5) && (Abutton->Height >= 5))
    T6963C_rectangle(Abutton->Left + 1, Abutton->Top + 1,
      Abutton->Left + Abutton->Width - 2,
      Abutton->Top + Abutton->Height - 2, T6963C_BLACK);
}

static void DrawButtons() {
  int i;
  TButton *local_button;

  for ( i = 0 ; i < CurrentScreen->ButtonsCount ; i++ ) {
    local_button = GetButton(i);
    if (local_button->Visible == 1) {
      DrawButton(local_button);
    }
  }
}


void DrawRoundButton(TButton_Round *Around_button) {
  T6963C_Rectangle_Round_Edges_Fill(Around_button->Left, Around_button->Top,
    Around_button->Left + Around_button->Width - 1,
    Around_button->Top + Around_button->Height - 1, Around_button->Round_Radius, T6963C_WHITE);
  if ((Around_button->Width >= 5) && (Around_button->Height >= 5))
    T6963C_Rectangle_Round_Edges(Around_button->Left + 1, Around_button->Top + 1,
      Around_button->Left + Around_button->Width - 2,
      Around_button->Top + Around_button->Height - 2, Around_button->Round_Radius, T6963C_BLACK);
}

static void DrawRoundButtons() {
  int i;
  TButton_Round *local_round_button;

  for ( i = 0 ; i < CurrentScreen->Buttons_RoundCount ; i++ ) {
    local_round_button = GetRoundButton(i);
    if (local_round_button->Visible == 1) {
      DrawRoundButton(local_round_button);
    }
  }
}


void DrawRoundCaptionButton(TCaptionButton_Round *Around_caption_button) {
  T6963C_Rectangle_Round_Edges_Fill(Around_caption_button->Left, Around_caption_button->Top,
    Around_caption_button->Left + Around_caption_button->Width - 1,
    Around_caption_button->Top + Around_caption_button->Height - 1,  Around_caption_button->Round_Radius, T6963C_WHITE);
  if ((Around_caption_button->Width >= 5) && (Around_caption_button->Height >= 5))
    T6963C_Rectangle_Round_Edges(Around_caption_button->Left + 1, Around_caption_button->Top + 1,
      Around_caption_button->Left + Around_caption_button->Width - 2,
      Around_caption_button->Top + Around_caption_button->Height - 2, Around_caption_button->Round_Radius, T6963C_BLACK);
  T6963C_write_text(Around_caption_button->Caption,
    (Around_caption_button->Left + Around_caption_button->BorderWidth + 2) / 8,
    (Around_caption_button->Top + Around_caption_button->BorderWidth + 2) / 8, T6963C_ROM_MODE_XOR);
}

static void DrawRoundCaptionButtons() {
  int i;
  TCaptionButton_Round *local_round_caption_button;

  for ( i = 0 ; i < CurrentScreen->CaptionButtons_RoundCount ; i++ ) {
    local_round_caption_button = GetRoundCaptionButton(i);
    if (local_round_caption_button->Visible == 1) {
      DrawRoundCaptionButton(local_round_caption_button);
    }
  }
}

void DrawScreen(TScreen *aScreen) {
  T6963C_grFill(0);
  T6963C_txtFill(0);

  CurrentScreen = aScreen;

  DrawButtons();

  DrawRoundButtons();

  DrawRoundCaptionButtons();

}



void Start_TP() {
  InitializeTouchPanel();

  InitializeObjects();
  DrawScreen(&Screen1);
}
