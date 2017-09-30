
VisualGLCD_picgenios_driver_InitializeTouchPanel:

;VisualGLCD_picgenios_driver.c,18 :: 		static void InitializeTouchPanel() {
;VisualGLCD_picgenios_driver.c,22 :: 		T6963C_init(128, 64, 8);
	MOVLW       128
	MOVWF       FARG_T6963C_init_width+0 
	MOVLW       0
	MOVWF       FARG_T6963C_init_width+1 
	MOVLW       64
	MOVWF       FARG_T6963C_init_height+0 
	MOVLW       8
	MOVWF       FARG_T6963C_init_fntW+0 
	CALL        _T6963C_init+0, 0
;VisualGLCD_picgenios_driver.c,23 :: 		T6963C_graphics(1);
	BSF         _T6963C_display+0, 3 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;VisualGLCD_picgenios_driver.c,24 :: 		T6963C_text(1);
	BSF         _T6963C_display+0, 2 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;VisualGLCD_picgenios_driver.c,25 :: 		T6963C_cursor(0);
	BCF         _T6963C_display+0, 1 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;VisualGLCD_picgenios_driver.c,27 :: 		}
	RETURN      0
; end of VisualGLCD_picgenios_driver_InitializeTouchPanel

VisualGLCD_picgenios_driver_InitializeObjects:

;VisualGLCD_picgenios_driver.c,52 :: 		static void InitializeObjects() {
;VisualGLCD_picgenios_driver.c,53 :: 		Screen1.ButtonsCount              = 0;
	CLRF        _Screen1+0 
	CLRF        _Screen1+1 
;VisualGLCD_picgenios_driver.c,54 :: 		Screen1.Buttons_RoundCount        = 4;
	MOVLW       4
	MOVWF       _Screen1+4 
	MOVLW       0
	MOVWF       _Screen1+5 
;VisualGLCD_picgenios_driver.c,55 :: 		Screen1.Buttons_Round             = Screen0_Buttons_Round;
	MOVLW       _Screen0_Buttons_Round+0
	MOVWF       _Screen1+6 
	MOVLW       hi_addr(_Screen0_Buttons_Round+0)
	MOVWF       _Screen1+7 
;VisualGLCD_picgenios_driver.c,56 :: 		Screen1.CaptionButtons_RoundCount = 1;
	MOVLW       1
	MOVWF       _Screen1+8 
	MOVLW       0
	MOVWF       _Screen1+9 
;VisualGLCD_picgenios_driver.c,57 :: 		Screen1.CaptionButtons_Round      = Screen0_CaptionButtons_Round;
	MOVLW       _Screen0_CaptionButtons_Round+0
	MOVWF       _Screen1+10 
	MOVLW       hi_addr(_Screen0_CaptionButtons_Round+0)
	MOVWF       _Screen1+11 
;VisualGLCD_picgenios_driver.c,58 :: 		Screen0_CaptionButtons_Round[0]   = &RoundCaptionButton1;
	MOVLW       _RoundCaptionButton1+0
	MOVWF       _Screen0_CaptionButtons_Round+0 
	MOVLW       hi_addr(_RoundCaptionButton1+0)
	MOVWF       _Screen0_CaptionButtons_Round+1 
;VisualGLCD_picgenios_driver.c,59 :: 		Screen0_Buttons_Round[0]          = &RoundEdgedButton1;
	MOVLW       _RoundEdgedButton1+0
	MOVWF       _Screen0_Buttons_Round+0 
	MOVLW       hi_addr(_RoundEdgedButton1+0)
	MOVWF       _Screen0_Buttons_Round+1 
;VisualGLCD_picgenios_driver.c,60 :: 		Screen0_Buttons_Round[1]          = &RoundEdgedButton2;
	MOVLW       _RoundEdgedButton2+0
	MOVWF       _Screen0_Buttons_Round+2 
	MOVLW       hi_addr(_RoundEdgedButton2+0)
	MOVWF       _Screen0_Buttons_Round+3 
;VisualGLCD_picgenios_driver.c,61 :: 		Screen0_Buttons_Round[2]          = &RoundEdgedButton3;
	MOVLW       _RoundEdgedButton3+0
	MOVWF       _Screen0_Buttons_Round+4 
	MOVLW       hi_addr(_RoundEdgedButton3+0)
	MOVWF       _Screen0_Buttons_Round+5 
;VisualGLCD_picgenios_driver.c,62 :: 		Screen0_Buttons_Round[3]          = &RoundEdgedButton4;
	MOVLW       _RoundEdgedButton4+0
	MOVWF       _Screen0_Buttons_Round+6 
	MOVLW       hi_addr(_RoundEdgedButton4+0)
	MOVWF       _Screen0_Buttons_Round+7 
;VisualGLCD_picgenios_driver.c,64 :: 		Screen2.ButtonsCount              = 2;
	MOVLW       2
	MOVWF       _Screen2+0 
	MOVLW       0
	MOVWF       _Screen2+1 
;VisualGLCD_picgenios_driver.c,65 :: 		Screen2.Buttons                   = Screen1_Buttons;
	MOVLW       _Screen1_Buttons+0
	MOVWF       _Screen2+2 
	MOVLW       hi_addr(_Screen1_Buttons+0)
	MOVWF       _Screen2+3 
;VisualGLCD_picgenios_driver.c,66 :: 		Screen2.Buttons_RoundCount        = 0;
	CLRF        _Screen2+4 
	CLRF        _Screen2+5 
;VisualGLCD_picgenios_driver.c,67 :: 		Screen2.CaptionButtons_RoundCount = 0;
	CLRF        _Screen2+8 
	CLRF        _Screen2+9 
;VisualGLCD_picgenios_driver.c,68 :: 		Screen1_Buttons[0]                = &Button1;
	MOVLW       _Button1+0
	MOVWF       _Screen1_Buttons+0 
	MOVLW       hi_addr(_Button1+0)
	MOVWF       _Screen1_Buttons+1 
;VisualGLCD_picgenios_driver.c,69 :: 		Screen1_Buttons[1]                = &Button2;
	MOVLW       _Button2+0
	MOVWF       _Screen1_Buttons+2 
	MOVLW       hi_addr(_Button2+0)
	MOVWF       _Screen1_Buttons+3 
;VisualGLCD_picgenios_driver.c,72 :: 		RoundCaptionButton1.OwnerScreen  = &Screen1;
	MOVLW       _Screen1+0
	MOVWF       _RoundCaptionButton1+0 
	MOVLW       hi_addr(_Screen1+0)
	MOVWF       _RoundCaptionButton1+1 
;VisualGLCD_picgenios_driver.c,73 :: 		RoundCaptionButton1.Left         = 11;
	MOVLW       11
	MOVWF       _RoundCaptionButton1+2 
;VisualGLCD_picgenios_driver.c,74 :: 		RoundCaptionButton1.Top          = 3;
	MOVLW       3
	MOVWF       _RoundCaptionButton1+3 
;VisualGLCD_picgenios_driver.c,75 :: 		RoundCaptionButton1.Width        = 106;
	MOVLW       106
	MOVWF       _RoundCaptionButton1+4 
;VisualGLCD_picgenios_driver.c,76 :: 		RoundCaptionButton1.Height       = 18;
	MOVLW       18
	MOVWF       _RoundCaptionButton1+5 
;VisualGLCD_picgenios_driver.c,77 :: 		RoundCaptionButton1.BorderWidth  = 3;
	MOVLW       3
	MOVWF       _RoundCaptionButton1+6 
;VisualGLCD_picgenios_driver.c,78 :: 		RoundCaptionButton1.Round_Radius = 4;
	MOVLW       4
	MOVWF       _RoundCaptionButton1+7 
;VisualGLCD_picgenios_driver.c,79 :: 		RoundCaptionButton1.Caption      = RoundCaptionButton1_Caption;
	MOVLW       _RoundCaptionButton1_Caption+0
	MOVWF       _RoundCaptionButton1+8 
	MOVLW       hi_addr(_RoundCaptionButton1_Caption+0)
	MOVWF       _RoundCaptionButton1+9 
;VisualGLCD_picgenios_driver.c,80 :: 		RoundCaptionButton1.FontName    = 0;
	CLRF        _RoundCaptionButton1+10 
	CLRF        _RoundCaptionButton1+11 
	CLRF        _RoundCaptionButton1+12 
;VisualGLCD_picgenios_driver.c,81 :: 		RoundCaptionButton1.FontWidth    = 7;
	MOVLW       7
	MOVWF       _RoundCaptionButton1+13 
;VisualGLCD_picgenios_driver.c,82 :: 		RoundCaptionButton1.FontHeight   = 7;
	MOVLW       7
	MOVWF       _RoundCaptionButton1+14 
;VisualGLCD_picgenios_driver.c,83 :: 		RoundCaptionButton1.FontOffset   = 32;
	MOVLW       32
	MOVWF       _RoundCaptionButton1+15 
;VisualGLCD_picgenios_driver.c,84 :: 		RoundCaptionButton1.FontColor    = _clInvert;
	MOVLW       2
	MOVWF       _RoundCaptionButton1+16 
;VisualGLCD_picgenios_driver.c,85 :: 		RoundCaptionButton1.Visible      = 1;
	MOVLW       1
	MOVWF       _RoundCaptionButton1+17 
;VisualGLCD_picgenios_driver.c,86 :: 		RoundCaptionButton1.OnUpPtr     = 0;
	CLRF        _RoundCaptionButton1+18 
	CLRF        _RoundCaptionButton1+19 
	CLRF        _RoundCaptionButton1+20 
	CLRF        _RoundCaptionButton1+21 
;VisualGLCD_picgenios_driver.c,87 :: 		RoundCaptionButton1.OnDownPtr   = 0;
	CLRF        _RoundCaptionButton1+22 
	CLRF        _RoundCaptionButton1+23 
	CLRF        _RoundCaptionButton1+24 
	CLRF        _RoundCaptionButton1+25 
;VisualGLCD_picgenios_driver.c,88 :: 		RoundCaptionButton1.OnClickPtr  = 0;
	CLRF        _RoundCaptionButton1+26 
	CLRF        _RoundCaptionButton1+27 
	CLRF        _RoundCaptionButton1+28 
	CLRF        _RoundCaptionButton1+29 
;VisualGLCD_picgenios_driver.c,89 :: 		RoundCaptionButton1.OnPressPtr  = 0;
	CLRF        _RoundCaptionButton1+30 
	CLRF        _RoundCaptionButton1+31 
	CLRF        _RoundCaptionButton1+32 
	CLRF        _RoundCaptionButton1+33 
;VisualGLCD_picgenios_driver.c,91 :: 		RoundEdgedButton1.OwnerScreen  = &Screen1;
	MOVLW       _Screen1+0
	MOVWF       _RoundEdgedButton1+0 
	MOVLW       hi_addr(_Screen1+0)
	MOVWF       _RoundEdgedButton1+1 
;VisualGLCD_picgenios_driver.c,92 :: 		RoundEdgedButton1.Left         = 12;
	MOVLW       12
	MOVWF       _RoundEdgedButton1+2 
;VisualGLCD_picgenios_driver.c,93 :: 		RoundEdgedButton1.Top          = 35;
	MOVLW       35
	MOVWF       _RoundEdgedButton1+3 
;VisualGLCD_picgenios_driver.c,94 :: 		RoundEdgedButton1.Width        = 20;
	MOVLW       20
	MOVWF       _RoundEdgedButton1+4 
;VisualGLCD_picgenios_driver.c,95 :: 		RoundEdgedButton1.Height       = 12;
	MOVLW       12
	MOVWF       _RoundEdgedButton1+5 
;VisualGLCD_picgenios_driver.c,96 :: 		RoundEdgedButton1.Round_Radius = 4;
	MOVLW       4
	MOVWF       _RoundEdgedButton1+6 
;VisualGLCD_picgenios_driver.c,97 :: 		RoundEdgedButton1.Visible      = 1;
	MOVLW       1
	MOVWF       _RoundEdgedButton1+7 
;VisualGLCD_picgenios_driver.c,98 :: 		RoundEdgedButton1.OnUpPtr     = 0;
	CLRF        _RoundEdgedButton1+8 
	CLRF        _RoundEdgedButton1+9 
	CLRF        _RoundEdgedButton1+10 
	CLRF        _RoundEdgedButton1+11 
;VisualGLCD_picgenios_driver.c,99 :: 		RoundEdgedButton1.OnDownPtr   = 0;
	CLRF        _RoundEdgedButton1+12 
	CLRF        _RoundEdgedButton1+13 
	CLRF        _RoundEdgedButton1+14 
	CLRF        _RoundEdgedButton1+15 
;VisualGLCD_picgenios_driver.c,100 :: 		RoundEdgedButton1.OnClickPtr  = 0;
	CLRF        _RoundEdgedButton1+16 
	CLRF        _RoundEdgedButton1+17 
	CLRF        _RoundEdgedButton1+18 
	CLRF        _RoundEdgedButton1+19 
;VisualGLCD_picgenios_driver.c,101 :: 		RoundEdgedButton1.OnPressPtr  = 0;
	CLRF        _RoundEdgedButton1+20 
	CLRF        _RoundEdgedButton1+21 
	CLRF        _RoundEdgedButton1+22 
	CLRF        _RoundEdgedButton1+23 
;VisualGLCD_picgenios_driver.c,103 :: 		RoundEdgedButton2.OwnerScreen  = &Screen1;
	MOVLW       _Screen1+0
	MOVWF       _RoundEdgedButton2+0 
	MOVLW       hi_addr(_Screen1+0)
	MOVWF       _RoundEdgedButton2+1 
;VisualGLCD_picgenios_driver.c,104 :: 		RoundEdgedButton2.Left         = 40;
	MOVLW       40
	MOVWF       _RoundEdgedButton2+2 
;VisualGLCD_picgenios_driver.c,105 :: 		RoundEdgedButton2.Top          = 35;
	MOVLW       35
	MOVWF       _RoundEdgedButton2+3 
;VisualGLCD_picgenios_driver.c,106 :: 		RoundEdgedButton2.Width        = 20;
	MOVLW       20
	MOVWF       _RoundEdgedButton2+4 
;VisualGLCD_picgenios_driver.c,107 :: 		RoundEdgedButton2.Height       = 12;
	MOVLW       12
	MOVWF       _RoundEdgedButton2+5 
;VisualGLCD_picgenios_driver.c,108 :: 		RoundEdgedButton2.Round_Radius = 4;
	MOVLW       4
	MOVWF       _RoundEdgedButton2+6 
;VisualGLCD_picgenios_driver.c,109 :: 		RoundEdgedButton2.Visible      = 1;
	MOVLW       1
	MOVWF       _RoundEdgedButton2+7 
;VisualGLCD_picgenios_driver.c,110 :: 		RoundEdgedButton2.OnUpPtr     = 0;
	CLRF        _RoundEdgedButton2+8 
	CLRF        _RoundEdgedButton2+9 
	CLRF        _RoundEdgedButton2+10 
	CLRF        _RoundEdgedButton2+11 
;VisualGLCD_picgenios_driver.c,111 :: 		RoundEdgedButton2.OnDownPtr   = 0;
	CLRF        _RoundEdgedButton2+12 
	CLRF        _RoundEdgedButton2+13 
	CLRF        _RoundEdgedButton2+14 
	CLRF        _RoundEdgedButton2+15 
;VisualGLCD_picgenios_driver.c,112 :: 		RoundEdgedButton2.OnClickPtr  = 0;
	CLRF        _RoundEdgedButton2+16 
	CLRF        _RoundEdgedButton2+17 
	CLRF        _RoundEdgedButton2+18 
	CLRF        _RoundEdgedButton2+19 
;VisualGLCD_picgenios_driver.c,113 :: 		RoundEdgedButton2.OnPressPtr  = 0;
	CLRF        _RoundEdgedButton2+20 
	CLRF        _RoundEdgedButton2+21 
	CLRF        _RoundEdgedButton2+22 
	CLRF        _RoundEdgedButton2+23 
;VisualGLCD_picgenios_driver.c,115 :: 		RoundEdgedButton3.OwnerScreen  = &Screen1;
	MOVLW       _Screen1+0
	MOVWF       _RoundEdgedButton3+0 
	MOVLW       hi_addr(_Screen1+0)
	MOVWF       _RoundEdgedButton3+1 
;VisualGLCD_picgenios_driver.c,116 :: 		RoundEdgedButton3.Left         = 69;
	MOVLW       69
	MOVWF       _RoundEdgedButton3+2 
;VisualGLCD_picgenios_driver.c,117 :: 		RoundEdgedButton3.Top          = 35;
	MOVLW       35
	MOVWF       _RoundEdgedButton3+3 
;VisualGLCD_picgenios_driver.c,118 :: 		RoundEdgedButton3.Width        = 20;
	MOVLW       20
	MOVWF       _RoundEdgedButton3+4 
;VisualGLCD_picgenios_driver.c,119 :: 		RoundEdgedButton3.Height       = 12;
	MOVLW       12
	MOVWF       _RoundEdgedButton3+5 
;VisualGLCD_picgenios_driver.c,120 :: 		RoundEdgedButton3.Round_Radius = 4;
	MOVLW       4
	MOVWF       _RoundEdgedButton3+6 
;VisualGLCD_picgenios_driver.c,121 :: 		RoundEdgedButton3.Visible      = 1;
	MOVLW       1
	MOVWF       _RoundEdgedButton3+7 
;VisualGLCD_picgenios_driver.c,122 :: 		RoundEdgedButton3.OnUpPtr     = 0;
	CLRF        _RoundEdgedButton3+8 
	CLRF        _RoundEdgedButton3+9 
	CLRF        _RoundEdgedButton3+10 
	CLRF        _RoundEdgedButton3+11 
;VisualGLCD_picgenios_driver.c,123 :: 		RoundEdgedButton3.OnDownPtr   = 0;
	CLRF        _RoundEdgedButton3+12 
	CLRF        _RoundEdgedButton3+13 
	CLRF        _RoundEdgedButton3+14 
	CLRF        _RoundEdgedButton3+15 
;VisualGLCD_picgenios_driver.c,124 :: 		RoundEdgedButton3.OnClickPtr  = 0;
	CLRF        _RoundEdgedButton3+16 
	CLRF        _RoundEdgedButton3+17 
	CLRF        _RoundEdgedButton3+18 
	CLRF        _RoundEdgedButton3+19 
;VisualGLCD_picgenios_driver.c,125 :: 		RoundEdgedButton3.OnPressPtr  = 0;
	CLRF        _RoundEdgedButton3+20 
	CLRF        _RoundEdgedButton3+21 
	CLRF        _RoundEdgedButton3+22 
	CLRF        _RoundEdgedButton3+23 
;VisualGLCD_picgenios_driver.c,127 :: 		RoundEdgedButton4.OwnerScreen  = &Screen1;
	MOVLW       _Screen1+0
	MOVWF       _RoundEdgedButton4+0 
	MOVLW       hi_addr(_Screen1+0)
	MOVWF       _RoundEdgedButton4+1 
;VisualGLCD_picgenios_driver.c,128 :: 		RoundEdgedButton4.Left         = 97;
	MOVLW       97
	MOVWF       _RoundEdgedButton4+2 
;VisualGLCD_picgenios_driver.c,129 :: 		RoundEdgedButton4.Top          = 35;
	MOVLW       35
	MOVWF       _RoundEdgedButton4+3 
;VisualGLCD_picgenios_driver.c,130 :: 		RoundEdgedButton4.Width        = 20;
	MOVLW       20
	MOVWF       _RoundEdgedButton4+4 
;VisualGLCD_picgenios_driver.c,131 :: 		RoundEdgedButton4.Height       = 12;
	MOVLW       12
	MOVWF       _RoundEdgedButton4+5 
;VisualGLCD_picgenios_driver.c,132 :: 		RoundEdgedButton4.Round_Radius = 4;
	MOVLW       4
	MOVWF       _RoundEdgedButton4+6 
;VisualGLCD_picgenios_driver.c,133 :: 		RoundEdgedButton4.Visible      = 1;
	MOVLW       1
	MOVWF       _RoundEdgedButton4+7 
;VisualGLCD_picgenios_driver.c,134 :: 		RoundEdgedButton4.OnUpPtr     = 0;
	CLRF        _RoundEdgedButton4+8 
	CLRF        _RoundEdgedButton4+9 
	CLRF        _RoundEdgedButton4+10 
	CLRF        _RoundEdgedButton4+11 
;VisualGLCD_picgenios_driver.c,135 :: 		RoundEdgedButton4.OnDownPtr   = 0;
	CLRF        _RoundEdgedButton4+12 
	CLRF        _RoundEdgedButton4+13 
	CLRF        _RoundEdgedButton4+14 
	CLRF        _RoundEdgedButton4+15 
;VisualGLCD_picgenios_driver.c,136 :: 		RoundEdgedButton4.OnClickPtr  = 0;
	CLRF        _RoundEdgedButton4+16 
	CLRF        _RoundEdgedButton4+17 
	CLRF        _RoundEdgedButton4+18 
	CLRF        _RoundEdgedButton4+19 
;VisualGLCD_picgenios_driver.c,137 :: 		RoundEdgedButton4.OnPressPtr  = 0;
	CLRF        _RoundEdgedButton4+20 
	CLRF        _RoundEdgedButton4+21 
	CLRF        _RoundEdgedButton4+22 
	CLRF        _RoundEdgedButton4+23 
;VisualGLCD_picgenios_driver.c,139 :: 		Button1.OwnerScreen = &Screen2;
	MOVLW       _Screen2+0
	MOVWF       _Button1+0 
	MOVLW       hi_addr(_Screen2+0)
	MOVWF       _Button1+1 
;VisualGLCD_picgenios_driver.c,140 :: 		Button1.Left        = 12;
	MOVLW       12
	MOVWF       _Button1+2 
;VisualGLCD_picgenios_driver.c,141 :: 		Button1.Top         = 12;
	MOVLW       12
	MOVWF       _Button1+3 
;VisualGLCD_picgenios_driver.c,142 :: 		Button1.Width       = 20;
	MOVLW       20
	MOVWF       _Button1+4 
;VisualGLCD_picgenios_driver.c,143 :: 		Button1.Height      = 12;
	MOVLW       12
	MOVWF       _Button1+5 
;VisualGLCD_picgenios_driver.c,144 :: 		Button1.Visible     = 1;
	MOVLW       1
	MOVWF       _Button1+6 
;VisualGLCD_picgenios_driver.c,145 :: 		Button1.OnUpPtr     = 0;
	CLRF        _Button1+7 
	CLRF        _Button1+8 
	CLRF        _Button1+9 
	CLRF        _Button1+10 
;VisualGLCD_picgenios_driver.c,146 :: 		Button1.OnDownPtr   = 0;
	CLRF        _Button1+11 
	CLRF        _Button1+12 
	CLRF        _Button1+13 
	CLRF        _Button1+14 
;VisualGLCD_picgenios_driver.c,147 :: 		Button1.OnClickPtr  = 0;
	CLRF        _Button1+15 
	CLRF        _Button1+16 
	CLRF        _Button1+17 
	CLRF        _Button1+18 
;VisualGLCD_picgenios_driver.c,148 :: 		Button1.OnPressPtr  = 0;
	CLRF        _Button1+19 
	CLRF        _Button1+20 
	CLRF        _Button1+21 
	CLRF        _Button1+22 
;VisualGLCD_picgenios_driver.c,150 :: 		Button2.OwnerScreen = &Screen2;
	MOVLW       _Screen2+0
	MOVWF       _Button2+0 
	MOVLW       hi_addr(_Screen2+0)
	MOVWF       _Button2+1 
;VisualGLCD_picgenios_driver.c,151 :: 		Button2.Left        = 36;
	MOVLW       36
	MOVWF       _Button2+2 
;VisualGLCD_picgenios_driver.c,152 :: 		Button2.Top         = 12;
	MOVLW       12
	MOVWF       _Button2+3 
;VisualGLCD_picgenios_driver.c,153 :: 		Button2.Width       = 20;
	MOVLW       20
	MOVWF       _Button2+4 
;VisualGLCD_picgenios_driver.c,154 :: 		Button2.Height      = 12;
	MOVLW       12
	MOVWF       _Button2+5 
;VisualGLCD_picgenios_driver.c,155 :: 		Button2.Visible     = 1;
	MOVLW       1
	MOVWF       _Button2+6 
;VisualGLCD_picgenios_driver.c,156 :: 		Button2.OnUpPtr     = 0;
	CLRF        _Button2+7 
	CLRF        _Button2+8 
	CLRF        _Button2+9 
	CLRF        _Button2+10 
;VisualGLCD_picgenios_driver.c,157 :: 		Button2.OnDownPtr   = 0;
	CLRF        _Button2+11 
	CLRF        _Button2+12 
	CLRF        _Button2+13 
	CLRF        _Button2+14 
;VisualGLCD_picgenios_driver.c,158 :: 		Button2.OnClickPtr  = 0;
	CLRF        _Button2+15 
	CLRF        _Button2+16 
	CLRF        _Button2+17 
	CLRF        _Button2+18 
;VisualGLCD_picgenios_driver.c,159 :: 		Button2.OnPressPtr  = 0;
	CLRF        _Button2+19 
	CLRF        _Button2+20 
	CLRF        _Button2+21 
	CLRF        _Button2+22 
;VisualGLCD_picgenios_driver.c,160 :: 		}
	RETURN      0
; end of VisualGLCD_picgenios_driver_InitializeObjects

_DrawButton:

;VisualGLCD_picgenios_driver.c,169 :: 		void DrawButton(TButton *Abutton) {
;VisualGLCD_picgenios_driver.c,170 :: 		T6963C_box(Abutton->Left, Abutton->Top,
	MOVLW       2
	ADDWF       FARG_DrawButton_Abutton+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawButton_Abutton+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R1 
	MOVF        R1, 0 
	MOVWF       FARG_T6963C_box_x0+0 
	MOVLW       0
	MOVWF       FARG_T6963C_box_x0+1 
	MOVLW       3
	ADDWF       FARG_DrawButton_Abutton+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawButton_Abutton+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       FARG_T6963C_box_y0+0 
	MOVLW       0
	MOVWF       FARG_T6963C_box_y0+1 
;VisualGLCD_picgenios_driver.c,171 :: 		Abutton->Left + Abutton->Width - 1,
	MOVLW       4
	ADDWF       FARG_DrawButton_Abutton+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawButton_Abutton+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       R1, 0 
	MOVWF       FARG_T6963C_box_x1+0 
	CLRF        FARG_T6963C_box_x1+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_box_x1+1, 1 
	MOVLW       1
	SUBWF       FARG_T6963C_box_x1+0, 1 
	MOVLW       0
	SUBWFB      FARG_T6963C_box_x1+1, 1 
;VisualGLCD_picgenios_driver.c,172 :: 		Abutton->Top + Abutton->Height - 1, T6963C_WHITE);
	MOVLW       5
	ADDWF       FARG_DrawButton_Abutton+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawButton_Abutton+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       R0, 0 
	MOVWF       FARG_T6963C_box_y1+0 
	CLRF        FARG_T6963C_box_y1+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_box_y1+1, 1 
	MOVLW       1
	SUBWF       FARG_T6963C_box_y1+0, 1 
	MOVLW       0
	SUBWFB      FARG_T6963C_box_y1+1, 1 
	MOVLW       8
	MOVWF       FARG_T6963C_box_pcolor+0 
	CALL        _T6963C_box+0, 0
;VisualGLCD_picgenios_driver.c,173 :: 		if ((Abutton->Width >= 5) && (Abutton->Height >= 5))
	MOVLW       4
	ADDWF       FARG_DrawButton_Abutton+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawButton_Abutton+1, 0 
	MOVWF       FSR0H 
	MOVLW       5
	SUBWF       POSTINC0+0, 0 
	BTFSS       STATUS+0, 0 
	GOTO        L_DrawButton2
	MOVLW       5
	ADDWF       FARG_DrawButton_Abutton+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawButton_Abutton+1, 0 
	MOVWF       FSR0H 
	MOVLW       5
	SUBWF       POSTINC0+0, 0 
	BTFSS       STATUS+0, 0 
	GOTO        L_DrawButton2
L__DrawButton21:
;VisualGLCD_picgenios_driver.c,174 :: 		T6963C_rectangle(Abutton->Left + 1, Abutton->Top + 1,
	MOVLW       2
	ADDWF       FARG_DrawButton_Abutton+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawButton_Abutton+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R1 
	MOVF        R1, 0 
	ADDLW       1
	MOVWF       FARG_T6963C_rectangle_x0+0 
	CLRF        FARG_T6963C_rectangle_x0+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_rectangle_x0+1, 1 
	MOVLW       3
	ADDWF       FARG_DrawButton_Abutton+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawButton_Abutton+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	ADDLW       1
	MOVWF       FARG_T6963C_rectangle_y0+0 
	CLRF        FARG_T6963C_rectangle_y0+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_rectangle_y0+1, 1 
;VisualGLCD_picgenios_driver.c,175 :: 		Abutton->Left + Abutton->Width - 2,
	MOVLW       4
	ADDWF       FARG_DrawButton_Abutton+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawButton_Abutton+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       R1, 0 
	MOVWF       FARG_T6963C_rectangle_x1+0 
	CLRF        FARG_T6963C_rectangle_x1+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_rectangle_x1+1, 1 
	MOVLW       2
	SUBWF       FARG_T6963C_rectangle_x1+0, 1 
	MOVLW       0
	SUBWFB      FARG_T6963C_rectangle_x1+1, 1 
;VisualGLCD_picgenios_driver.c,176 :: 		Abutton->Top + Abutton->Height - 2, T6963C_BLACK);
	MOVLW       5
	ADDWF       FARG_DrawButton_Abutton+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawButton_Abutton+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       R0, 0 
	MOVWF       FARG_T6963C_rectangle_y1+0 
	CLRF        FARG_T6963C_rectangle_y1+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_rectangle_y1+1, 1 
	MOVLW       2
	SUBWF       FARG_T6963C_rectangle_y1+0, 1 
	MOVLW       0
	SUBWFB      FARG_T6963C_rectangle_y1+1, 1 
	CLRF        FARG_T6963C_rectangle_pcolor+0 
	CALL        _T6963C_rectangle+0, 0
L_DrawButton2:
;VisualGLCD_picgenios_driver.c,177 :: 		}
	RETURN      0
; end of _DrawButton

VisualGLCD_picgenios_driver_DrawButtons:

;VisualGLCD_picgenios_driver.c,179 :: 		static void DrawButtons() {
;VisualGLCD_picgenios_driver.c,183 :: 		for ( i = 0 ; i < CurrentScreen->ButtonsCount ; i++ ) {
	CLRF        VisualGLCD_picgenios_driver_DrawButtons_i_L0+0 
	CLRF        VisualGLCD_picgenios_driver_DrawButtons_i_L0+1 
L_VisualGLCD_picgenios_driver_DrawButtons3:
	MOVFF       _CurrentScreen+0, FSR0L
	MOVFF       _CurrentScreen+1, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       R1 
	MOVF        POSTINC0+0, 0 
	MOVWF       R2 
	MOVF        R2, 0 
	SUBWF       VisualGLCD_picgenios_driver_DrawButtons_i_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_VisualGLCD_picgenios_driver_DrawButtons24
	MOVF        R1, 0 
	SUBWF       VisualGLCD_picgenios_driver_DrawButtons_i_L0+0, 0 
L_VisualGLCD_picgenios_driver_DrawButtons24:
	BTFSC       STATUS+0, 0 
	GOTO        L_VisualGLCD_picgenios_driver_DrawButtons4
;VisualGLCD_picgenios_driver.c,184 :: 		local_button = GetButton(i);
	MOVLW       2
	ADDWF       _CurrentScreen+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      _CurrentScreen+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R3 
	MOVF        POSTINC0+0, 0 
	MOVWF       R4 
	MOVF        VisualGLCD_picgenios_driver_DrawButtons_i_L0+0, 0 
	MOVWF       R0 
	MOVF        VisualGLCD_picgenios_driver_DrawButtons_i_L0+1, 0 
	MOVWF       R1 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R1, 1 
	MOVF        R0, 0 
	ADDWF       R3, 0 
	MOVWF       FSR0L 
	MOVF        R1, 0 
	ADDWFC      R4, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        POSTINC0+0, 0 
	MOVWF       R1 
	MOVF        R0, 0 
	MOVWF       VisualGLCD_picgenios_driver_DrawButtons_local_button_L0+0 
	MOVF        R1, 0 
	MOVWF       VisualGLCD_picgenios_driver_DrawButtons_local_button_L0+1 
;VisualGLCD_picgenios_driver.c,185 :: 		if (local_button->Visible == 1) {
	MOVLW       6
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_VisualGLCD_picgenios_driver_DrawButtons6
;VisualGLCD_picgenios_driver.c,186 :: 		DrawButton(local_button);
	MOVF        VisualGLCD_picgenios_driver_DrawButtons_local_button_L0+0, 0 
	MOVWF       FARG_DrawButton_Abutton+0 
	MOVF        VisualGLCD_picgenios_driver_DrawButtons_local_button_L0+1, 0 
	MOVWF       FARG_DrawButton_Abutton+1 
	CALL        _DrawButton+0, 0
;VisualGLCD_picgenios_driver.c,187 :: 		}
L_VisualGLCD_picgenios_driver_DrawButtons6:
;VisualGLCD_picgenios_driver.c,183 :: 		for ( i = 0 ; i < CurrentScreen->ButtonsCount ; i++ ) {
	INFSNZ      VisualGLCD_picgenios_driver_DrawButtons_i_L0+0, 1 
	INCF        VisualGLCD_picgenios_driver_DrawButtons_i_L0+1, 1 
;VisualGLCD_picgenios_driver.c,188 :: 		}
	GOTO        L_VisualGLCD_picgenios_driver_DrawButtons3
L_VisualGLCD_picgenios_driver_DrawButtons4:
;VisualGLCD_picgenios_driver.c,189 :: 		}
	RETURN      0
; end of VisualGLCD_picgenios_driver_DrawButtons

_DrawRoundButton:

;VisualGLCD_picgenios_driver.c,192 :: 		void DrawRoundButton(TButton_Round *Around_button) {
;VisualGLCD_picgenios_driver.c,193 :: 		T6963C_Rectangle_Round_Edges_Fill(Around_button->Left, Around_button->Top,
	MOVLW       2
	ADDWF       FARG_DrawRoundButton_Around_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundButton_Around_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R1 
	MOVF        R1, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_x_upper_left+0 
	MOVLW       0
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_x_upper_left+1 
	MOVLW       3
	ADDWF       FARG_DrawRoundButton_Around_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundButton_Around_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_y_upper_left+0 
	MOVLW       0
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_y_upper_left+1 
;VisualGLCD_picgenios_driver.c,194 :: 		Around_button->Left + Around_button->Width - 1,
	MOVLW       4
	ADDWF       FARG_DrawRoundButton_Around_button+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundButton_Around_button+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       R1, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_x_bottom_right+0 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_Fill_x_bottom_right+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_Rectangle_Round_Edges_Fill_x_bottom_right+1, 1 
	MOVLW       1
	SUBWF       FARG_T6963C_Rectangle_Round_Edges_Fill_x_bottom_right+0, 1 
	MOVLW       0
	SUBWFB      FARG_T6963C_Rectangle_Round_Edges_Fill_x_bottom_right+1, 1 
;VisualGLCD_picgenios_driver.c,195 :: 		Around_button->Top + Around_button->Height - 1, Around_button->Round_Radius, T6963C_WHITE);
	MOVLW       5
	ADDWF       FARG_DrawRoundButton_Around_button+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundButton_Around_button+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       R0, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_y_bottom_right+0 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_Fill_y_bottom_right+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_Rectangle_Round_Edges_Fill_y_bottom_right+1, 1 
	MOVLW       1
	SUBWF       FARG_T6963C_Rectangle_Round_Edges_Fill_y_bottom_right+0, 1 
	MOVLW       0
	SUBWFB      FARG_T6963C_Rectangle_Round_Edges_Fill_y_bottom_right+1, 1 
	MOVLW       6
	ADDWF       FARG_DrawRoundButton_Around_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundButton_Around_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_round_radius+0 
	MOVLW       0
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_round_radius+1 
	MOVLW       0
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_round_radius+1 
	MOVLW       8
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_color+0 
	CALL        _T6963C_Rectangle_Round_Edges_Fill+0, 0
;VisualGLCD_picgenios_driver.c,196 :: 		if ((Around_button->Width >= 5) && (Around_button->Height >= 5))
	MOVLW       4
	ADDWF       FARG_DrawRoundButton_Around_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundButton_Around_button+1, 0 
	MOVWF       FSR0H 
	MOVLW       5
	SUBWF       POSTINC0+0, 0 
	BTFSS       STATUS+0, 0 
	GOTO        L_DrawRoundButton9
	MOVLW       5
	ADDWF       FARG_DrawRoundButton_Around_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundButton_Around_button+1, 0 
	MOVWF       FSR0H 
	MOVLW       5
	SUBWF       POSTINC0+0, 0 
	BTFSS       STATUS+0, 0 
	GOTO        L_DrawRoundButton9
L__DrawRoundButton22:
;VisualGLCD_picgenios_driver.c,197 :: 		T6963C_Rectangle_Round_Edges(Around_button->Left + 1, Around_button->Top + 1,
	MOVLW       2
	ADDWF       FARG_DrawRoundButton_Around_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundButton_Around_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R1 
	MOVF        R1, 0 
	ADDLW       1
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_x_upper_left+0 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_x_upper_left+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_Rectangle_Round_Edges_x_upper_left+1, 1 
	MOVLW       3
	ADDWF       FARG_DrawRoundButton_Around_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundButton_Around_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	ADDLW       1
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_y_upper_left+0 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_y_upper_left+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_Rectangle_Round_Edges_y_upper_left+1, 1 
;VisualGLCD_picgenios_driver.c,198 :: 		Around_button->Left + Around_button->Width - 2,
	MOVLW       4
	ADDWF       FARG_DrawRoundButton_Around_button+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundButton_Around_button+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       R1, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_x_bottom_right+0 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_x_bottom_right+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_Rectangle_Round_Edges_x_bottom_right+1, 1 
	MOVLW       2
	SUBWF       FARG_T6963C_Rectangle_Round_Edges_x_bottom_right+0, 1 
	MOVLW       0
	SUBWFB      FARG_T6963C_Rectangle_Round_Edges_x_bottom_right+1, 1 
;VisualGLCD_picgenios_driver.c,199 :: 		Around_button->Top + Around_button->Height - 2, Around_button->Round_Radius, T6963C_BLACK);
	MOVLW       5
	ADDWF       FARG_DrawRoundButton_Around_button+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundButton_Around_button+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       R0, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_y_bottom_right+0 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_y_bottom_right+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_Rectangle_Round_Edges_y_bottom_right+1, 1 
	MOVLW       2
	SUBWF       FARG_T6963C_Rectangle_Round_Edges_y_bottom_right+0, 1 
	MOVLW       0
	SUBWFB      FARG_T6963C_Rectangle_Round_Edges_y_bottom_right+1, 1 
	MOVLW       6
	ADDWF       FARG_DrawRoundButton_Around_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundButton_Around_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_round_radius+0 
	MOVLW       0
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_round_radius+1 
	MOVLW       0
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_round_radius+1 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_color+0 
	CALL        _T6963C_Rectangle_Round_Edges+0, 0
L_DrawRoundButton9:
;VisualGLCD_picgenios_driver.c,200 :: 		}
	RETURN      0
; end of _DrawRoundButton

VisualGLCD_picgenios_driver_DrawRoundButtons:

;VisualGLCD_picgenios_driver.c,202 :: 		static void DrawRoundButtons() {
;VisualGLCD_picgenios_driver.c,206 :: 		for ( i = 0 ; i < CurrentScreen->Buttons_RoundCount ; i++ ) {
	CLRF        VisualGLCD_picgenios_driver_DrawRoundButtons_i_L0+0 
	CLRF        VisualGLCD_picgenios_driver_DrawRoundButtons_i_L0+1 
L_VisualGLCD_picgenios_driver_DrawRoundButtons10:
	MOVLW       4
	ADDWF       _CurrentScreen+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      _CurrentScreen+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	MOVWF       R1 
	MOVF        POSTINC2+0, 0 
	MOVWF       R2 
	MOVF        R2, 0 
	SUBWF       VisualGLCD_picgenios_driver_DrawRoundButtons_i_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_VisualGLCD_picgenios_driver_DrawRoundButtons25
	MOVF        R1, 0 
	SUBWF       VisualGLCD_picgenios_driver_DrawRoundButtons_i_L0+0, 0 
L_VisualGLCD_picgenios_driver_DrawRoundButtons25:
	BTFSC       STATUS+0, 0 
	GOTO        L_VisualGLCD_picgenios_driver_DrawRoundButtons11
;VisualGLCD_picgenios_driver.c,207 :: 		local_round_button = GetRoundButton(i);
	MOVLW       6
	ADDWF       _CurrentScreen+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      _CurrentScreen+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R3 
	MOVF        POSTINC0+0, 0 
	MOVWF       R4 
	MOVF        VisualGLCD_picgenios_driver_DrawRoundButtons_i_L0+0, 0 
	MOVWF       R0 
	MOVF        VisualGLCD_picgenios_driver_DrawRoundButtons_i_L0+1, 0 
	MOVWF       R1 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R1, 1 
	MOVF        R0, 0 
	ADDWF       R3, 0 
	MOVWF       FSR0L 
	MOVF        R1, 0 
	ADDWFC      R4, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        POSTINC0+0, 0 
	MOVWF       R1 
	MOVF        R0, 0 
	MOVWF       VisualGLCD_picgenios_driver_DrawRoundButtons_local_round_button_L0+0 
	MOVF        R1, 0 
	MOVWF       VisualGLCD_picgenios_driver_DrawRoundButtons_local_round_button_L0+1 
;VisualGLCD_picgenios_driver.c,208 :: 		if (local_round_button->Visible == 1) {
	MOVLW       7
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_VisualGLCD_picgenios_driver_DrawRoundButtons13
;VisualGLCD_picgenios_driver.c,209 :: 		DrawRoundButton(local_round_button);
	MOVF        VisualGLCD_picgenios_driver_DrawRoundButtons_local_round_button_L0+0, 0 
	MOVWF       FARG_DrawRoundButton_Around_button+0 
	MOVF        VisualGLCD_picgenios_driver_DrawRoundButtons_local_round_button_L0+1, 0 
	MOVWF       FARG_DrawRoundButton_Around_button+1 
	CALL        _DrawRoundButton+0, 0
;VisualGLCD_picgenios_driver.c,210 :: 		}
L_VisualGLCD_picgenios_driver_DrawRoundButtons13:
;VisualGLCD_picgenios_driver.c,206 :: 		for ( i = 0 ; i < CurrentScreen->Buttons_RoundCount ; i++ ) {
	INFSNZ      VisualGLCD_picgenios_driver_DrawRoundButtons_i_L0+0, 1 
	INCF        VisualGLCD_picgenios_driver_DrawRoundButtons_i_L0+1, 1 
;VisualGLCD_picgenios_driver.c,211 :: 		}
	GOTO        L_VisualGLCD_picgenios_driver_DrawRoundButtons10
L_VisualGLCD_picgenios_driver_DrawRoundButtons11:
;VisualGLCD_picgenios_driver.c,212 :: 		}
	RETURN      0
; end of VisualGLCD_picgenios_driver_DrawRoundButtons

_DrawRoundCaptionButton:

;VisualGLCD_picgenios_driver.c,215 :: 		void DrawRoundCaptionButton(TCaptionButton_Round *Around_caption_button) {
;VisualGLCD_picgenios_driver.c,216 :: 		T6963C_Rectangle_Round_Edges_Fill(Around_caption_button->Left, Around_caption_button->Top,
	MOVLW       2
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R1 
	MOVF        R1, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_x_upper_left+0 
	MOVLW       0
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_x_upper_left+1 
	MOVLW       3
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_y_upper_left+0 
	MOVLW       0
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_y_upper_left+1 
;VisualGLCD_picgenios_driver.c,217 :: 		Around_caption_button->Left + Around_caption_button->Width - 1,
	MOVLW       4
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       R1, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_x_bottom_right+0 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_Fill_x_bottom_right+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_Rectangle_Round_Edges_Fill_x_bottom_right+1, 1 
	MOVLW       1
	SUBWF       FARG_T6963C_Rectangle_Round_Edges_Fill_x_bottom_right+0, 1 
	MOVLW       0
	SUBWFB      FARG_T6963C_Rectangle_Round_Edges_Fill_x_bottom_right+1, 1 
;VisualGLCD_picgenios_driver.c,218 :: 		Around_caption_button->Top + Around_caption_button->Height - 1,  Around_caption_button->Round_Radius, T6963C_WHITE);
	MOVLW       5
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       R0, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_y_bottom_right+0 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_Fill_y_bottom_right+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_Rectangle_Round_Edges_Fill_y_bottom_right+1, 1 
	MOVLW       1
	SUBWF       FARG_T6963C_Rectangle_Round_Edges_Fill_y_bottom_right+0, 1 
	MOVLW       0
	SUBWFB      FARG_T6963C_Rectangle_Round_Edges_Fill_y_bottom_right+1, 1 
	MOVLW       7
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_round_radius+0 
	MOVLW       0
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_round_radius+1 
	MOVLW       0
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_round_radius+1 
	MOVLW       8
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_Fill_color+0 
	CALL        _T6963C_Rectangle_Round_Edges_Fill+0, 0
;VisualGLCD_picgenios_driver.c,219 :: 		if ((Around_caption_button->Width >= 5) && (Around_caption_button->Height >= 5))
	MOVLW       4
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR0H 
	MOVLW       5
	SUBWF       POSTINC0+0, 0 
	BTFSS       STATUS+0, 0 
	GOTO        L_DrawRoundCaptionButton16
	MOVLW       5
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR0H 
	MOVLW       5
	SUBWF       POSTINC0+0, 0 
	BTFSS       STATUS+0, 0 
	GOTO        L_DrawRoundCaptionButton16
L__DrawRoundCaptionButton23:
;VisualGLCD_picgenios_driver.c,220 :: 		T6963C_Rectangle_Round_Edges(Around_caption_button->Left + 1, Around_caption_button->Top + 1,
	MOVLW       2
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R1 
	MOVF        R1, 0 
	ADDLW       1
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_x_upper_left+0 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_x_upper_left+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_Rectangle_Round_Edges_x_upper_left+1, 1 
	MOVLW       3
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	ADDLW       1
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_y_upper_left+0 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_y_upper_left+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_Rectangle_Round_Edges_y_upper_left+1, 1 
;VisualGLCD_picgenios_driver.c,221 :: 		Around_caption_button->Left + Around_caption_button->Width - 2,
	MOVLW       4
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       R1, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_x_bottom_right+0 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_x_bottom_right+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_Rectangle_Round_Edges_x_bottom_right+1, 1 
	MOVLW       2
	SUBWF       FARG_T6963C_Rectangle_Round_Edges_x_bottom_right+0, 1 
	MOVLW       0
	SUBWFB      FARG_T6963C_Rectangle_Round_Edges_x_bottom_right+1, 1 
;VisualGLCD_picgenios_driver.c,222 :: 		Around_caption_button->Top + Around_caption_button->Height - 2, Around_caption_button->Round_Radius, T6963C_BLACK);
	MOVLW       5
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	ADDWF       R0, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_y_bottom_right+0 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_y_bottom_right+1 
	MOVLW       0
	ADDWFC      FARG_T6963C_Rectangle_Round_Edges_y_bottom_right+1, 1 
	MOVLW       2
	SUBWF       FARG_T6963C_Rectangle_Round_Edges_y_bottom_right+0, 1 
	MOVLW       0
	SUBWFB      FARG_T6963C_Rectangle_Round_Edges_y_bottom_right+1, 1 
	MOVLW       7
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_round_radius+0 
	MOVLW       0
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_round_radius+1 
	MOVLW       0
	MOVWF       FARG_T6963C_Rectangle_Round_Edges_round_radius+1 
	CLRF        FARG_T6963C_Rectangle_Round_Edges_color+0 
	CALL        _T6963C_Rectangle_Round_Edges+0, 0
L_DrawRoundCaptionButton16:
;VisualGLCD_picgenios_driver.c,223 :: 		T6963C_write_text(Around_caption_button->Caption,
	MOVLW       8
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_T6963C_write_text_str+0 
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_T6963C_write_text_str+1 
;VisualGLCD_picgenios_driver.c,224 :: 		(Around_caption_button->Left + Around_caption_button->BorderWidth + 2) / 8,
	MOVLW       2
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR0H 
	MOVLW       6
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	MOVWF       R5 
	MOVF        R5, 0 
	ADDWF       POSTINC0+0, 0 
	MOVWF       R0 
	CLRF        R1 
	MOVLW       0
	ADDWFC      R1, 1 
	MOVLW       2
	ADDWF       R0, 0 
	MOVWF       R3 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       R4 
	MOVLW       3
	MOVWF       R2 
	MOVF        R3, 0 
	MOVWF       R0 
	MOVF        R4, 0 
	MOVWF       R1 
	MOVF        R2, 0 
L__DrawRoundCaptionButton26:
	BZ          L__DrawRoundCaptionButton27
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	BTFSC       R1, 6 
	BSF         R1, 7 
	ADDLW       255
	GOTO        L__DrawRoundCaptionButton26
L__DrawRoundCaptionButton27:
	MOVF        R0, 0 
	MOVWF       FARG_T6963C_write_text_x+0 
;VisualGLCD_picgenios_driver.c,225 :: 		(Around_caption_button->Top + Around_caption_button->BorderWidth + 2) / 8, T6963C_ROM_MODE_XOR);
	MOVLW       3
	ADDWF       FARG_DrawRoundCaptionButton_Around_caption_button+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_DrawRoundCaptionButton_Around_caption_button+1, 0 
	MOVWF       FSR0H 
	MOVF        R5, 0 
	ADDWF       POSTINC0+0, 0 
	MOVWF       R0 
	CLRF        R1 
	MOVLW       0
	ADDWFC      R1, 1 
	MOVLW       2
	ADDWF       R0, 0 
	MOVWF       R3 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       R4 
	MOVLW       3
	MOVWF       R2 
	MOVF        R3, 0 
	MOVWF       R0 
	MOVF        R4, 0 
	MOVWF       R1 
	MOVF        R2, 0 
L__DrawRoundCaptionButton28:
	BZ          L__DrawRoundCaptionButton29
	RRCF        R1, 1 
	RRCF        R0, 1 
	BCF         R1, 7 
	BTFSC       R1, 6 
	BSF         R1, 7 
	ADDLW       255
	GOTO        L__DrawRoundCaptionButton28
L__DrawRoundCaptionButton29:
	MOVF        R0, 0 
	MOVWF       FARG_T6963C_write_text_y+0 
	MOVLW       129
	MOVWF       FARG_T6963C_write_text_mode+0 
	CALL        _T6963C_write_text+0, 0
;VisualGLCD_picgenios_driver.c,226 :: 		}
	RETURN      0
; end of _DrawRoundCaptionButton

VisualGLCD_picgenios_driver_DrawRoundCaptionButtons:

;VisualGLCD_picgenios_driver.c,228 :: 		static void DrawRoundCaptionButtons() {
;VisualGLCD_picgenios_driver.c,232 :: 		for ( i = 0 ; i < CurrentScreen->CaptionButtons_RoundCount ; i++ ) {
	CLRF        VisualGLCD_picgenios_driver_DrawRoundCaptionButtons_i_L0+0 
	CLRF        VisualGLCD_picgenios_driver_DrawRoundCaptionButtons_i_L0+1 
L_VisualGLCD_picgenios_driver_DrawRoundCaptionButtons17:
	MOVLW       8
	ADDWF       _CurrentScreen+0, 0 
	MOVWF       FSR2L 
	MOVLW       0
	ADDWFC      _CurrentScreen+1, 0 
	MOVWF       FSR2H 
	MOVF        POSTINC2+0, 0 
	MOVWF       R1 
	MOVF        POSTINC2+0, 0 
	MOVWF       R2 
	MOVF        R2, 0 
	SUBWF       VisualGLCD_picgenios_driver_DrawRoundCaptionButtons_i_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L_VisualGLCD_picgenios_driver_DrawRoundCaptionButtons30
	MOVF        R1, 0 
	SUBWF       VisualGLCD_picgenios_driver_DrawRoundCaptionButtons_i_L0+0, 0 
L_VisualGLCD_picgenios_driver_DrawRoundCaptionButtons30:
	BTFSC       STATUS+0, 0 
	GOTO        L_VisualGLCD_picgenios_driver_DrawRoundCaptionButtons18
;VisualGLCD_picgenios_driver.c,233 :: 		local_round_caption_button = GetRoundCaptionButton(i);
	MOVLW       10
	ADDWF       _CurrentScreen+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      _CurrentScreen+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R3 
	MOVF        POSTINC0+0, 0 
	MOVWF       R4 
	MOVF        VisualGLCD_picgenios_driver_DrawRoundCaptionButtons_i_L0+0, 0 
	MOVWF       R0 
	MOVF        VisualGLCD_picgenios_driver_DrawRoundCaptionButtons_i_L0+1, 0 
	MOVWF       R1 
	RLCF        R0, 1 
	BCF         R0, 0 
	RLCF        R1, 1 
	MOVF        R0, 0 
	ADDWF       R3, 0 
	MOVWF       FSR0L 
	MOVF        R1, 0 
	ADDWFC      R4, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       R0 
	MOVF        POSTINC0+0, 0 
	MOVWF       R1 
	MOVF        R0, 0 
	MOVWF       VisualGLCD_picgenios_driver_DrawRoundCaptionButtons_local_round_caption_button_L0+0 
	MOVF        R1, 0 
	MOVWF       VisualGLCD_picgenios_driver_DrawRoundCaptionButtons_local_round_caption_button_L0+1 
;VisualGLCD_picgenios_driver.c,234 :: 		if (local_round_caption_button->Visible == 1) {
	MOVLW       17
	ADDWF       R0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      R1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_VisualGLCD_picgenios_driver_DrawRoundCaptionButtons20
;VisualGLCD_picgenios_driver.c,235 :: 		DrawRoundCaptionButton(local_round_caption_button);
	MOVF        VisualGLCD_picgenios_driver_DrawRoundCaptionButtons_local_round_caption_button_L0+0, 0 
	MOVWF       FARG_DrawRoundCaptionButton_Around_caption_button+0 
	MOVF        VisualGLCD_picgenios_driver_DrawRoundCaptionButtons_local_round_caption_button_L0+1, 0 
	MOVWF       FARG_DrawRoundCaptionButton_Around_caption_button+1 
	CALL        _DrawRoundCaptionButton+0, 0
;VisualGLCD_picgenios_driver.c,236 :: 		}
L_VisualGLCD_picgenios_driver_DrawRoundCaptionButtons20:
;VisualGLCD_picgenios_driver.c,232 :: 		for ( i = 0 ; i < CurrentScreen->CaptionButtons_RoundCount ; i++ ) {
	INFSNZ      VisualGLCD_picgenios_driver_DrawRoundCaptionButtons_i_L0+0, 1 
	INCF        VisualGLCD_picgenios_driver_DrawRoundCaptionButtons_i_L0+1, 1 
;VisualGLCD_picgenios_driver.c,237 :: 		}
	GOTO        L_VisualGLCD_picgenios_driver_DrawRoundCaptionButtons17
L_VisualGLCD_picgenios_driver_DrawRoundCaptionButtons18:
;VisualGLCD_picgenios_driver.c,238 :: 		}
	RETURN      0
; end of VisualGLCD_picgenios_driver_DrawRoundCaptionButtons

_DrawScreen:

;VisualGLCD_picgenios_driver.c,240 :: 		void DrawScreen(TScreen *aScreen) {
;VisualGLCD_picgenios_driver.c,241 :: 		T6963C_grFill(0);
	CLRF        FARG_T6963C_fill_v+0 
	CLRF        FARG_T6963C_fill_start+0 
	CLRF        FARG_T6963C_fill_start+1 
	MOVF        _T6963C_grMemSize+0, 0 
	MOVWF       FARG_T6963C_fill_len+0 
	MOVF        _T6963C_grMemSize+1, 0 
	MOVWF       FARG_T6963C_fill_len+1 
	CALL        _T6963C_fill+0, 0
;VisualGLCD_picgenios_driver.c,242 :: 		T6963C_txtFill(0);
	CLRF        FARG_T6963C_fill_v+0 
	MOVF        _T6963C_grMemSize+0, 0 
	MOVWF       FARG_T6963C_fill_start+0 
	MOVF        _T6963C_grMemSize+1, 0 
	MOVWF       FARG_T6963C_fill_start+1 
	MOVF        _T6963C_txtMemSize+0, 0 
	MOVWF       FARG_T6963C_fill_len+0 
	MOVF        _T6963C_txtMemSize+1, 0 
	MOVWF       FARG_T6963C_fill_len+1 
	CALL        _T6963C_fill+0, 0
;VisualGLCD_picgenios_driver.c,244 :: 		CurrentScreen = aScreen;
	MOVF        FARG_DrawScreen_aScreen+0, 0 
	MOVWF       _CurrentScreen+0 
	MOVF        FARG_DrawScreen_aScreen+1, 0 
	MOVWF       _CurrentScreen+1 
;VisualGLCD_picgenios_driver.c,246 :: 		DrawButtons();
	CALL        VisualGLCD_picgenios_driver_DrawButtons+0, 0
;VisualGLCD_picgenios_driver.c,248 :: 		DrawRoundButtons();
	CALL        VisualGLCD_picgenios_driver_DrawRoundButtons+0, 0
;VisualGLCD_picgenios_driver.c,250 :: 		DrawRoundCaptionButtons();
	CALL        VisualGLCD_picgenios_driver_DrawRoundCaptionButtons+0, 0
;VisualGLCD_picgenios_driver.c,252 :: 		}
	RETURN      0
; end of _DrawScreen

_Start_TP:

;VisualGLCD_picgenios_driver.c,256 :: 		void Start_TP() {
;VisualGLCD_picgenios_driver.c,257 :: 		InitializeTouchPanel();
	CALL        VisualGLCD_picgenios_driver_InitializeTouchPanel+0, 0
;VisualGLCD_picgenios_driver.c,259 :: 		InitializeObjects();
	CALL        VisualGLCD_picgenios_driver_InitializeObjects+0, 0
;VisualGLCD_picgenios_driver.c,260 :: 		DrawScreen(&Screen2);
	MOVLW       _Screen2+0
	MOVWF       FARG_DrawScreen_aScreen+0 
	MOVLW       hi_addr(_Screen2+0)
	MOVWF       FARG_DrawScreen_aScreen+1 
	CALL        _DrawScreen+0, 0
;VisualGLCD_picgenios_driver.c,261 :: 		}
	RETURN      0
; end of _Start_TP

VisualGLCD_picgenios_driver____ag:

	RETURN      0
; end of VisualGLCD_picgenios_driver____ag
