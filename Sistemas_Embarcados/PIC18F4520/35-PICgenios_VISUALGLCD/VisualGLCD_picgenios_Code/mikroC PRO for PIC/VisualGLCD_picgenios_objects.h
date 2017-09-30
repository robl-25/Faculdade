#include "__T6963C.h"
enum GlcdColor {_clClear, _clDraw, _clInvert};

typedef struct Screen TScreen;

typedef struct  Button {
  TScreen       *OwnerScreen;
  char          Left;
  char          Top;
  char          Width;
  char          Height;
  char          Visible;
  void          (*OnUpPtr)();
  void          (*OnDownPtr)();
  void          (*OnClickPtr)();
  void          (*OnPressPtr)();
} TButton;

typedef struct  Button_Round {
  TScreen       *OwnerScreen;
  char          Left;
  char          Top;
  char          Width;
  char          Height;
  char          Round_Radius;
  char          Visible;
  void          (*OnUpPtr)();
  void          (*OnDownPtr)();
  void          (*OnClickPtr)();
  void          (*OnPressPtr)();
} TButton_Round;

typedef struct  CaptionButton_Round {
  TScreen       *OwnerScreen;
  char          Left;
  char          Top;
  char          Width;
  char          Height;
  char          BorderWidth;
  char          Round_Radius;
  char          *Caption;
  const char    *FontName;
  char          FontWidth;
  char          FontHeight;
  char          FontOffset;
  char          FontColor;
  char          Visible;
  void          (*OnUpPtr)();
  void          (*OnDownPtr)();
  void          (*OnClickPtr)();
  void          (*OnPressPtr)();
} TCaptionButton_Round;

struct Screen {
  unsigned int           ButtonsCount;
  TButton                **Buttons;
  unsigned int           Buttons_RoundCount;
  TButton_Round          **Buttons_Round;
  unsigned int           CaptionButtons_RoundCount;
  TCaptionButton_Round   **CaptionButtons_Round;
};

extern   TScreen                Screen1;
extern   TCaptionButton_Round   RoundCaptionButton1;
extern   TButton_Round          RoundEdgedButton1;
extern   TButton_Round          RoundEdgedButton2;
extern   TButton_Round          RoundEdgedButton3;
extern   TButton_Round          RoundEdgedButton4;

extern   TScreen                Screen2;
extern   TButton                Button1;
extern   TButton                Button2;


/////////////////////////
// Events Code Declarations
/////////////////////////

/////////////////////////////////
// Caption variables Declarations
extern char RoundCaptionButton1_Caption[];
/////////////////////////////////

void DrawScreen(TScreen *aScreen);
void DrawButton(TButton *Abutton);
void DrawRoundButton(TButton_Round *Around_button);
void DrawRoundCaptionButton(TCaptionButton_Round *Around_caption_button);
void Check_TP();
void Start_TP();
