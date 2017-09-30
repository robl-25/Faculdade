
_main:
;GLCD_T6963C.c,32 :: 		void main() {
;GLCD_T6963C.c,33 :: 		char txt1[] = " EINSTEIN WOULD HAVE LIKED mE";
	MOVLW       ?ICSmain_txt1_L0+0
	MOVWF       TBLPTRL 
	MOVLW       hi_addr(?ICSmain_txt1_L0+0)
	MOVWF       TBLPTRH 
	MOVLW       higher_addr(?ICSmain_txt1_L0+0)
	MOVWF       TBLPTRU 
	MOVLW       main_txt1_L0+0
	MOVWF       FSR1L 
	MOVLW       hi_addr(main_txt1_L0+0)
	MOVWF       FSR1H 
	MOVLW       30
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	CALL        ___CC2DW+0, 0
;GLCD_T6963C.c,34 :: 		char txt[] =  " GLCD LIBRARY DEMO, WELCOME !";
	MOVLW       ?ICSmain_txt_L0+0
	MOVWF       TBLPTRL 
	MOVLW       hi_addr(?ICSmain_txt_L0+0)
	MOVWF       TBLPTRH 
	MOVLW       higher_addr(?ICSmain_txt_L0+0)
	MOVWF       TBLPTRU 
	MOVLW       main_txt_L0+0
	MOVWF       FSR1L 
	MOVLW       hi_addr(main_txt_L0+0)
	MOVWF       FSR1H 
	MOVLW       30
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	CALL        ___CC2DW+0, 0
;GLCD_T6963C.c,41 :: 		TRISA0_bit = 1;               // Set RA0 as input
	BSF         TRISA0_bit+0, 0 
;GLCD_T6963C.c,42 :: 		TRISA1_bit = 1;               // Set RA1 as input
	BSF         TRISA1_bit+0, 1 
;GLCD_T6963C.c,43 :: 		TRISA2_bit = 1;               // Set RA2 as input
	BSF         TRISA2_bit+0, 2 
;GLCD_T6963C.c,44 :: 		TRISA3_bit = 1;               // Set RA3 as input
	BSF         TRISA3_bit+0, 3 
;GLCD_T6963C.c,45 :: 		TRISA4_bit = 1;               // Set RA4 as input
	BSF         TRISA4_bit+0, 4 
;GLCD_T6963C.c,47 :: 		T6963C_ctrlce_Direction = 0;
	BCF         TRISC3_bit+0, 3 
;GLCD_T6963C.c,48 :: 		T6963C_ctrlce = 0;            // Enable T6963C
	BCF         RC3_bit+0, 3 
;GLCD_T6963C.c,49 :: 		T6963C_ctrlfs_Direction = 0;
	BCF         TRISC6_bit+0, 6 
;GLCD_T6963C.c,50 :: 		T6963C_ctrlfs = 0;            // Font Select 8x8
	BCF         RC6_bit+0, 6 
;GLCD_T6963C.c,51 :: 		T6963C_ctrlmd_Direction = 0;
	BCF         TRISC5_bit+0, 5 
;GLCD_T6963C.c,52 :: 		T6963C_ctrlmd = 0;            // Column number select
	BCF         RC5_bit+0, 5 
;GLCD_T6963C.c,57 :: 		T6963C_init(240, 128, 8);
	MOVLW       240
	MOVWF       FARG_T6963C_init_width+0 
	MOVLW       0
	MOVWF       FARG_T6963C_init_width+1 
	MOVLW       128
	MOVWF       FARG_T6963C_init_height+0 
	MOVLW       8
	MOVWF       FARG_T6963C_init_fntW+0 
	CALL        _T6963C_init+0, 0
;GLCD_T6963C.c,62 :: 		T6963C_graphics(1);
	BSF         _T6963C_display+0, 3 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,63 :: 		T6963C_text(1);
	BSF         _T6963C_display+0, 2 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,65 :: 		panel = 0;
	CLRF        main_panel_L0+0 
;GLCD_T6963C.c,67 :: 		curs = 0;
	CLRF        main_curs_L0+0 
;GLCD_T6963C.c,68 :: 		cposx = cposy = 0;
	CLRF        main_cposy_L0+0 
	CLRF        main_cposy_L0+1 
	CLRF        main_cposx_L0+0 
	CLRF        main_cposx_L0+1 
;GLCD_T6963C.c,72 :: 		T6963C_write_text(txt, 0, 0, T6963C_ROM_MODE_XOR);
	MOVLW       main_txt_L0+0
	MOVWF       FARG_T6963C_write_text_str+0 
	MOVLW       hi_addr(main_txt_L0+0)
	MOVWF       FARG_T6963C_write_text_str+1 
	CLRF        FARG_T6963C_write_text_x+0 
	CLRF        FARG_T6963C_write_text_y+0 
	MOVLW       129
	MOVWF       FARG_T6963C_write_text_mode+0 
	CALL        _T6963C_write_text+0, 0
;GLCD_T6963C.c,73 :: 		T6963C_write_text(txt1, 0, 15, T6963C_ROM_MODE_XOR);
	MOVLW       main_txt1_L0+0
	MOVWF       FARG_T6963C_write_text_str+0 
	MOVLW       hi_addr(main_txt1_L0+0)
	MOVWF       FARG_T6963C_write_text_str+1 
	CLRF        FARG_T6963C_write_text_x+0 
	MOVLW       15
	MOVWF       FARG_T6963C_write_text_y+0 
	MOVLW       129
	MOVWF       FARG_T6963C_write_text_mode+0 
	CALL        _T6963C_write_text+0, 0
;GLCD_T6963C.c,78 :: 		T6963C_cursor_height(8);       // 8 pixel height
	MOVLW       167
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,79 :: 		T6963C_set_cursor(0, 0);       // Move cursor to top left
	CLRF        FARG_T6963C_set_cursor_x+0 
	CLRF        FARG_T6963C_set_cursor_y+0 
	CALL        _T6963C_set_cursor+0, 0
;GLCD_T6963C.c,80 :: 		T6963C_cursor(0);              // Cursor off
	BCF         _T6963C_display+0, 1 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,85 :: 		T6963C_rectangle(0, 0, 239, 127, T6963C_WHITE);
	CLRF        FARG_T6963C_rectangle_x0+0 
	CLRF        FARG_T6963C_rectangle_x0+1 
	CLRF        FARG_T6963C_rectangle_y0+0 
	CLRF        FARG_T6963C_rectangle_y0+1 
	MOVLW       239
	MOVWF       FARG_T6963C_rectangle_x1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_x1+1 
	MOVLW       127
	MOVWF       FARG_T6963C_rectangle_y1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_y1+1 
	MOVLW       8
	MOVWF       FARG_T6963C_rectangle_pcolor+0 
	CALL        _T6963C_rectangle+0, 0
;GLCD_T6963C.c,86 :: 		T6963C_rectangle(20, 20, 219, 107, T6963C_WHITE);
	MOVLW       20
	MOVWF       FARG_T6963C_rectangle_x0+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_x0+1 
	MOVLW       20
	MOVWF       FARG_T6963C_rectangle_y0+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_y0+1 
	MOVLW       219
	MOVWF       FARG_T6963C_rectangle_x1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_x1+1 
	MOVLW       107
	MOVWF       FARG_T6963C_rectangle_y1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_y1+1 
	MOVLW       8
	MOVWF       FARG_T6963C_rectangle_pcolor+0 
	CALL        _T6963C_rectangle+0, 0
;GLCD_T6963C.c,87 :: 		T6963C_rectangle(40, 40, 199, 87, T6963C_WHITE);
	MOVLW       40
	MOVWF       FARG_T6963C_rectangle_x0+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_x0+1 
	MOVLW       40
	MOVWF       FARG_T6963C_rectangle_y0+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_y0+1 
	MOVLW       199
	MOVWF       FARG_T6963C_rectangle_x1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_x1+1 
	MOVLW       87
	MOVWF       FARG_T6963C_rectangle_y1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_y1+1 
	MOVLW       8
	MOVWF       FARG_T6963C_rectangle_pcolor+0 
	CALL        _T6963C_rectangle+0, 0
;GLCD_T6963C.c,88 :: 		T6963C_rectangle(60, 60, 179, 67, T6963C_WHITE);
	MOVLW       60
	MOVWF       FARG_T6963C_rectangle_x0+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_x0+1 
	MOVLW       60
	MOVWF       FARG_T6963C_rectangle_y0+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_y0+1 
	MOVLW       179
	MOVWF       FARG_T6963C_rectangle_x1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_x1+1 
	MOVLW       67
	MOVWF       FARG_T6963C_rectangle_y1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_rectangle_y1+1 
	MOVLW       8
	MOVWF       FARG_T6963C_rectangle_pcolor+0 
	CALL        _T6963C_rectangle+0, 0
;GLCD_T6963C.c,93 :: 		T6963C_line(0, 0, 239, 127, T6963C_WHITE);
	CLRF        FARG_T6963C_line_x0+0 
	CLRF        FARG_T6963C_line_x0+1 
	CLRF        FARG_T6963C_line_y0+0 
	CLRF        FARG_T6963C_line_y0+1 
	MOVLW       239
	MOVWF       FARG_T6963C_line_x1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_line_x1+1 
	MOVLW       127
	MOVWF       FARG_T6963C_line_y1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_line_y1+1 
	MOVLW       8
	MOVWF       FARG_T6963C_line_pcolor+0 
	CALL        _T6963C_line+0, 0
;GLCD_T6963C.c,94 :: 		T6963C_line(0, 127, 239, 0, T6963C_WHITE);
	CLRF        FARG_T6963C_line_x0+0 
	CLRF        FARG_T6963C_line_x0+1 
	MOVLW       127
	MOVWF       FARG_T6963C_line_y0+0 
	MOVLW       0
	MOVWF       FARG_T6963C_line_y0+1 
	MOVLW       239
	MOVWF       FARG_T6963C_line_x1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_line_x1+1 
	CLRF        FARG_T6963C_line_y1+0 
	CLRF        FARG_T6963C_line_y1+1 
	MOVLW       8
	MOVWF       FARG_T6963C_line_pcolor+0 
	CALL        _T6963C_line+0, 0
;GLCD_T6963C.c,99 :: 		T6963C_box(0, 0, 239, 8, T6963C_WHITE);
	CLRF        FARG_T6963C_box_x0+0 
	CLRF        FARG_T6963C_box_x0+1 
	CLRF        FARG_T6963C_box_y0+0 
	CLRF        FARG_T6963C_box_y0+1 
	MOVLW       239
	MOVWF       FARG_T6963C_box_x1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_box_x1+1 
	MOVLW       8
	MOVWF       FARG_T6963C_box_y1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_box_y1+1 
	MOVLW       8
	MOVWF       FARG_T6963C_box_pcolor+0 
	CALL        _T6963C_box+0, 0
;GLCD_T6963C.c,100 :: 		T6963C_box(0, 119, 239, 127, T6963C_WHITE);
	CLRF        FARG_T6963C_box_x0+0 
	CLRF        FARG_T6963C_box_x0+1 
	MOVLW       119
	MOVWF       FARG_T6963C_box_y0+0 
	MOVLW       0
	MOVWF       FARG_T6963C_box_y0+1 
	MOVLW       239
	MOVWF       FARG_T6963C_box_x1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_box_x1+1 
	MOVLW       127
	MOVWF       FARG_T6963C_box_y1+0 
	MOVLW       0
	MOVWF       FARG_T6963C_box_y1+1 
	MOVLW       8
	MOVWF       FARG_T6963C_box_pcolor+0 
	CALL        _T6963C_box+0, 0
;GLCD_T6963C.c,105 :: 		T6963C_circle(120, 64, 10, T6963C_WHITE);
	MOVLW       120
	MOVWF       FARG_T6963C_circle_x+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_x+1 
	MOVLW       64
	MOVWF       FARG_T6963C_circle_y+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_y+1 
	MOVLW       10
	MOVWF       FARG_T6963C_circle_r+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_r+1 
	MOVWF       FARG_T6963C_circle_r+2 
	MOVWF       FARG_T6963C_circle_r+3 
	MOVLW       8
	MOVWF       FARG_T6963C_circle_pcolor+0 
	CALL        _T6963C_circle+0, 0
;GLCD_T6963C.c,106 :: 		T6963C_circle(120, 64, 30, T6963C_WHITE);
	MOVLW       120
	MOVWF       FARG_T6963C_circle_x+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_x+1 
	MOVLW       64
	MOVWF       FARG_T6963C_circle_y+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_y+1 
	MOVLW       30
	MOVWF       FARG_T6963C_circle_r+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_r+1 
	MOVWF       FARG_T6963C_circle_r+2 
	MOVWF       FARG_T6963C_circle_r+3 
	MOVLW       8
	MOVWF       FARG_T6963C_circle_pcolor+0 
	CALL        _T6963C_circle+0, 0
;GLCD_T6963C.c,107 :: 		T6963C_circle(120, 64, 50, T6963C_WHITE);
	MOVLW       120
	MOVWF       FARG_T6963C_circle_x+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_x+1 
	MOVLW       64
	MOVWF       FARG_T6963C_circle_y+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_y+1 
	MOVLW       50
	MOVWF       FARG_T6963C_circle_r+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_r+1 
	MOVWF       FARG_T6963C_circle_r+2 
	MOVWF       FARG_T6963C_circle_r+3 
	MOVLW       8
	MOVWF       FARG_T6963C_circle_pcolor+0 
	CALL        _T6963C_circle+0, 0
;GLCD_T6963C.c,108 :: 		T6963C_circle(120, 64, 70, T6963C_WHITE);
	MOVLW       120
	MOVWF       FARG_T6963C_circle_x+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_x+1 
	MOVLW       64
	MOVWF       FARG_T6963C_circle_y+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_y+1 
	MOVLW       70
	MOVWF       FARG_T6963C_circle_r+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_r+1 
	MOVWF       FARG_T6963C_circle_r+2 
	MOVWF       FARG_T6963C_circle_r+3 
	MOVLW       8
	MOVWF       FARG_T6963C_circle_pcolor+0 
	CALL        _T6963C_circle+0, 0
;GLCD_T6963C.c,109 :: 		T6963C_circle(120, 64, 90, T6963C_WHITE);
	MOVLW       120
	MOVWF       FARG_T6963C_circle_x+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_x+1 
	MOVLW       64
	MOVWF       FARG_T6963C_circle_y+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_y+1 
	MOVLW       90
	MOVWF       FARG_T6963C_circle_r+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_r+1 
	MOVWF       FARG_T6963C_circle_r+2 
	MOVWF       FARG_T6963C_circle_r+3 
	MOVLW       8
	MOVWF       FARG_T6963C_circle_pcolor+0 
	CALL        _T6963C_circle+0, 0
;GLCD_T6963C.c,110 :: 		T6963C_circle(120, 64, 110, T6963C_WHITE);
	MOVLW       120
	MOVWF       FARG_T6963C_circle_x+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_x+1 
	MOVLW       64
	MOVWF       FARG_T6963C_circle_y+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_y+1 
	MOVLW       110
	MOVWF       FARG_T6963C_circle_r+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_r+1 
	MOVWF       FARG_T6963C_circle_r+2 
	MOVWF       FARG_T6963C_circle_r+3 
	MOVLW       8
	MOVWF       FARG_T6963C_circle_pcolor+0 
	CALL        _T6963C_circle+0, 0
;GLCD_T6963C.c,111 :: 		T6963C_circle(120, 64, 130, T6963C_WHITE);
	MOVLW       120
	MOVWF       FARG_T6963C_circle_x+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_x+1 
	MOVLW       64
	MOVWF       FARG_T6963C_circle_y+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_y+1 
	MOVLW       130
	MOVWF       FARG_T6963C_circle_r+0 
	MOVLW       0
	MOVWF       FARG_T6963C_circle_r+1 
	MOVWF       FARG_T6963C_circle_r+2 
	MOVWF       FARG_T6963C_circle_r+3 
	MOVLW       8
	MOVWF       FARG_T6963C_circle_pcolor+0 
	CALL        _T6963C_circle+0, 0
;GLCD_T6963C.c,113 :: 		T6963C_sprite(76, 4, einstein, 88, 119);         // Draw a sprite
	MOVLW       76
	MOVWF       FARG_T6963C_sprite_px+0 
	MOVLW       4
	MOVWF       FARG_T6963C_sprite_py+0 
	MOVLW       _einstein+0
	MOVWF       FARG_T6963C_sprite_pic+0 
	MOVLW       hi_addr(_einstein+0)
	MOVWF       FARG_T6963C_sprite_pic+1 
	MOVLW       higher_addr(_einstein+0)
	MOVWF       FARG_T6963C_sprite_pic+2 
	MOVLW       88
	MOVWF       FARG_T6963C_sprite_sx+0 
	MOVLW       119
	MOVWF       FARG_T6963C_sprite_sy+0 
	CALL        _T6963C_sprite+0, 0
;GLCD_T6963C.c,115 :: 		T6963C_setGrPanel(1);                            // Select other graphic panel
	MOVF        _T6963C_txtMemSize+0, 0 
	ADDWF       _T6963C_grMemSize+0, 0 
	MOVWF       _T6963C_grHomeAddr+0 
	MOVF        _T6963C_txtMemSize+1, 0 
	ADDWFC      _T6963C_grMemSize+1, 0 
	MOVWF       _T6963C_grHomeAddr+1 
;GLCD_T6963C.c,119 :: 		for(;;) {                                        // Endless loop
L_main0:
;GLCD_T6963C.c,123 :: 		if(RA0_bit) {
	BTFSS       RA0_bit+0, 0 
	GOTO        L_main3
;GLCD_T6963C.c,124 :: 		T6963C_graphics(1);
	BSF         _T6963C_display+0, 3 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,125 :: 		T6963C_text(0);
	BCF         _T6963C_display+0, 2 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,126 :: 		Delay_ms(300);
	MOVLW       4
	MOVWF       R11, 0
	MOVLW       12
	MOVWF       R12, 0
	MOVLW       51
	MOVWF       R13, 0
L_main4:
	DECFSZ      R13, 1, 0
	BRA         L_main4
	DECFSZ      R12, 1, 0
	BRA         L_main4
	DECFSZ      R11, 1, 0
	BRA         L_main4
	NOP
	NOP
;GLCD_T6963C.c,127 :: 		}
	GOTO        L_main5
L_main3:
;GLCD_T6963C.c,132 :: 		else if(RA1_bit) {
	BTFSS       RA1_bit+0, 1 
	GOTO        L_main6
;GLCD_T6963C.c,133 :: 		panel++;
	INCF        main_panel_L0+0, 1 
;GLCD_T6963C.c,134 :: 		panel &= 1;
	MOVLW       1
	ANDWF       main_panel_L0+0, 0 
	MOVWF       R4 
	MOVF        R4, 0 
	MOVWF       main_panel_L0+0 
;GLCD_T6963C.c,135 :: 		T6963C_displayGrPanel(panel);
	MOVF        _T6963C_txtMemSize+0, 0 
	ADDWF       _T6963C_grMemSize+0, 0 
	MOVWF       R0 
	MOVF        _T6963C_txtMemSize+1, 0 
	ADDWFC      _T6963C_grMemSize+1, 0 
	MOVWF       R1 
	MOVLW       0
	MOVWF       R5 
	CALL        _Mul_16x16_U+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_T6963C_setPtr_p+0 
	MOVF        R1, 0 
	MOVWF       FARG_T6963C_setPtr_p+1 
	MOVLW       66
	MOVWF       FARG_T6963C_setPtr_c+0 
	CALL        _T6963C_setPtr+0, 0
;GLCD_T6963C.c,136 :: 		Delay_ms(300);
	MOVLW       4
	MOVWF       R11, 0
	MOVLW       12
	MOVWF       R12, 0
	MOVLW       51
	MOVWF       R13, 0
L_main7:
	DECFSZ      R13, 1, 0
	BRA         L_main7
	DECFSZ      R12, 1, 0
	BRA         L_main7
	DECFSZ      R11, 1, 0
	BRA         L_main7
	NOP
	NOP
;GLCD_T6963C.c,137 :: 		}
	GOTO        L_main8
L_main6:
;GLCD_T6963C.c,142 :: 		else if(RA2_bit) {
	BTFSS       RA2_bit+0, 2 
	GOTO        L_main9
;GLCD_T6963C.c,143 :: 		T6963C_graphics(0);
	BCF         _T6963C_display+0, 3 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,144 :: 		T6963C_text(1);
	BSF         _T6963C_display+0, 2 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,145 :: 		Delay_ms(300);
	MOVLW       4
	MOVWF       R11, 0
	MOVLW       12
	MOVWF       R12, 0
	MOVLW       51
	MOVWF       R13, 0
L_main10:
	DECFSZ      R13, 1, 0
	BRA         L_main10
	DECFSZ      R12, 1, 0
	BRA         L_main10
	DECFSZ      R11, 1, 0
	BRA         L_main10
	NOP
	NOP
;GLCD_T6963C.c,146 :: 		}
	GOTO        L_main11
L_main9:
;GLCD_T6963C.c,151 :: 		else if(RA3_bit) {
	BTFSS       RA3_bit+0, 3 
	GOTO        L_main12
;GLCD_T6963C.c,152 :: 		T6963C_graphics(1);
	BSF         _T6963C_display+0, 3 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,153 :: 		T6963C_text(1);
	BSF         _T6963C_display+0, 2 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,154 :: 		Delay_ms(300);
	MOVLW       4
	MOVWF       R11, 0
	MOVLW       12
	MOVWF       R12, 0
	MOVLW       51
	MOVWF       R13, 0
L_main13:
	DECFSZ      R13, 1, 0
	BRA         L_main13
	DECFSZ      R12, 1, 0
	BRA         L_main13
	DECFSZ      R11, 1, 0
	BRA         L_main13
	NOP
	NOP
;GLCD_T6963C.c,155 :: 		}
	GOTO        L_main14
L_main12:
;GLCD_T6963C.c,160 :: 		else if(RA4_bit) {
	BTFSS       RA4_bit+0, 4 
	GOTO        L_main15
;GLCD_T6963C.c,161 :: 		curs++;
	INCF        main_curs_L0+0, 1 
;GLCD_T6963C.c,162 :: 		if(curs == 3) curs = 0;
	MOVF        main_curs_L0+0, 0 
	XORLW       3
	BTFSS       STATUS+0, 2 
	GOTO        L_main16
	CLRF        main_curs_L0+0 
L_main16:
;GLCD_T6963C.c,163 :: 		switch(curs) {
	GOTO        L_main17
;GLCD_T6963C.c,164 :: 		case 0:
L_main19:
;GLCD_T6963C.c,166 :: 		T6963C_cursor(0);
	BCF         _T6963C_display+0, 1 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,167 :: 		break;
	GOTO        L_main18
;GLCD_T6963C.c,168 :: 		case 1:
L_main20:
;GLCD_T6963C.c,170 :: 		T6963C_cursor(1);
	BSF         _T6963C_display+0, 1 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,171 :: 		T6963C_cursor_blink(1);
	BSF         _T6963C_display+0, 0 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,172 :: 		break;
	GOTO        L_main18
;GLCD_T6963C.c,173 :: 		case 2:
L_main21:
;GLCD_T6963C.c,175 :: 		T6963C_cursor(1);
	BSF         _T6963C_display+0, 1 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,176 :: 		T6963C_cursor_blink(0);
	BCF         _T6963C_display+0, 0 
	MOVF        _T6963C_display+0, 0 
	MOVWF       FARG_T6963C_writeCommand_mydata+0 
	CALL        _T6963C_writeCommand+0, 0
;GLCD_T6963C.c,177 :: 		break;
	GOTO        L_main18
;GLCD_T6963C.c,178 :: 		}
L_main17:
	MOVF        main_curs_L0+0, 0 
	XORLW       0
	BTFSC       STATUS+0, 2 
	GOTO        L_main19
	MOVF        main_curs_L0+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_main20
	MOVF        main_curs_L0+0, 0 
	XORLW       2
	BTFSC       STATUS+0, 2 
	GOTO        L_main21
L_main18:
;GLCD_T6963C.c,179 :: 		Delay_ms(300);
	MOVLW       4
	MOVWF       R11, 0
	MOVLW       12
	MOVWF       R12, 0
	MOVLW       51
	MOVWF       R13, 0
L_main22:
	DECFSZ      R13, 1, 0
	BRA         L_main22
	DECFSZ      R12, 1, 0
	BRA         L_main22
	DECFSZ      R11, 1, 0
	BRA         L_main22
	NOP
	NOP
;GLCD_T6963C.c,180 :: 		}
L_main15:
L_main14:
L_main11:
L_main8:
L_main5:
;GLCD_T6963C.c,185 :: 		cposx++;
	INFSNZ      main_cposx_L0+0, 1 
	INCF        main_cposx_L0+1, 1 
;GLCD_T6963C.c,186 :: 		if(cposx == T6963C_txtCols) {
	MOVF        main_cposx_L0+1, 0 
	XORWF       _T6963C_txtCols+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main26
	MOVF        _T6963C_txtCols+0, 0 
	XORWF       main_cposx_L0+0, 0 
L__main26:
	BTFSS       STATUS+0, 2 
	GOTO        L_main23
;GLCD_T6963C.c,187 :: 		cposx = 0;
	CLRF        main_cposx_L0+0 
	CLRF        main_cposx_L0+1 
;GLCD_T6963C.c,188 :: 		cposy++;
	INFSNZ      main_cposy_L0+0, 1 
	INCF        main_cposy_L0+1, 1 
;GLCD_T6963C.c,189 :: 		if(cposy == T6963C_grHeight / T6963C_CHARACTER_HEIGHT) {
	MOVF        _T6963C_grHeight+0, 0 
	MOVWF       R1 
	MOVF        _T6963C_grHeight+1, 0 
	MOVWF       R2 
	RRCF        R2, 1 
	RRCF        R1, 1 
	BCF         R2, 7 
	RRCF        R2, 1 
	RRCF        R1, 1 
	BCF         R2, 7 
	RRCF        R2, 1 
	RRCF        R1, 1 
	BCF         R2, 7 
	MOVF        main_cposy_L0+1, 0 
	XORWF       R2, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__main27
	MOVF        R1, 0 
	XORWF       main_cposy_L0+0, 0 
L__main27:
	BTFSS       STATUS+0, 2 
	GOTO        L_main24
;GLCD_T6963C.c,190 :: 		cposy = 0;
	CLRF        main_cposy_L0+0 
	CLRF        main_cposy_L0+1 
;GLCD_T6963C.c,191 :: 		}
L_main24:
;GLCD_T6963C.c,192 :: 		}
L_main23:
;GLCD_T6963C.c,193 :: 		T6963C_set_cursor(cposx, cposy);
	MOVF        main_cposx_L0+0, 0 
	MOVWF       FARG_T6963C_set_cursor_x+0 
	MOVF        main_cposy_L0+0, 0 
	MOVWF       FARG_T6963C_set_cursor_y+0 
	CALL        _T6963C_set_cursor+0, 0
;GLCD_T6963C.c,195 :: 		Delay_ms(100);
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       4
	MOVWF       R12, 0
	MOVLW       186
	MOVWF       R13, 0
L_main25:
	DECFSZ      R13, 1, 0
	BRA         L_main25
	DECFSZ      R12, 1, 0
	BRA         L_main25
	DECFSZ      R11, 1, 0
	BRA         L_main25
	NOP
;GLCD_T6963C.c,196 :: 		}
	GOTO        L_main0
;GLCD_T6963C.c,197 :: 		}
	GOTO        $+0
; end of _main
