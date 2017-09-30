
_SPI_Ethernet_UserTCP:

;microEthernet.c,201 :: 		unsigned int    SPI_Ethernet_UserTCP(unsigned char *remoteHost, unsigned int remotePort, unsigned int localPort, unsigned int reqLength, char *canClose)
;microEthernet.c,210 :: 		if(localPort != 80)                         // I listen only to web request on port 80
	MOVLW       0
	XORWF       FARG_SPI_Ethernet_UserTCP_localPort+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP14
	MOVLW       80
	XORWF       FARG_SPI_Ethernet_UserTCP_localPort+0, 0 
L__SPI_Ethernet_UserTCP14:
	BTFSC       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP0
;microEthernet.c,212 :: 		return(0) ;
	CLRF        R0 
	CLRF        R1 
	RETURN      0
;microEthernet.c,213 :: 		}
L_SPI_Ethernet_UserTCP0:
;microEthernet.c,216 :: 		for(len = 0 ; len < 10 ; len++)
	CLRF        SPI_Ethernet_UserTCP_len_L0+0 
	CLRF        SPI_Ethernet_UserTCP_len_L0+1 
L_SPI_Ethernet_UserTCP1:
	MOVLW       0
	SUBWF       SPI_Ethernet_UserTCP_len_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP15
	MOVLW       10
	SUBWF       SPI_Ethernet_UserTCP_len_L0+0, 0 
L__SPI_Ethernet_UserTCP15:
	BTFSC       STATUS+0, 0 
	GOTO        L_SPI_Ethernet_UserTCP2
;microEthernet.c,218 :: 		getRequest[len] = SPI_Ethernet_getByte() ;
	MOVLW       _getRequest+0
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 0 
	MOVWF       FLOC__SPI_Ethernet_UserTCP+0 
	MOVLW       hi_addr(_getRequest+0)
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 0 
	MOVWF       FLOC__SPI_Ethernet_UserTCP+1 
	CALL        _SPI_Ethernet_getByte+0, 0
	MOVFF       FLOC__SPI_Ethernet_UserTCP+0, FSR1L
	MOVFF       FLOC__SPI_Ethernet_UserTCP+1, FSR1H
	MOVF        R0, 0 
	MOVWF       POSTINC1+0 
;microEthernet.c,216 :: 		for(len = 0 ; len < 10 ; len++)
	INFSNZ      SPI_Ethernet_UserTCP_len_L0+0, 1 
	INCF        SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,219 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP1
L_SPI_Ethernet_UserTCP2:
;microEthernet.c,220 :: 		getRequest[len] = 0 ;
	MOVLW       _getRequest+0
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 0 
	MOVWF       FSR1L 
	MOVLW       hi_addr(_getRequest+0)
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 0 
	MOVWF       FSR1H 
	CLRF        POSTINC1+0 
;microEthernet.c,221 :: 		len = 0;
	CLRF        SPI_Ethernet_UserTCP_len_L0+0 
	CLRF        SPI_Ethernet_UserTCP_len_L0+1 
;microEthernet.c,223 :: 		if(memcmp(getRequest, httpMethod, 5))       // only GET method is supported here
	MOVLW       _getRequest+0
	MOVWF       FARG_memcmp_s1+0 
	MOVLW       hi_addr(_getRequest+0)
	MOVWF       FARG_memcmp_s1+1 
	MOVLW       _httpMethod+0
	MOVWF       FARG_memcmp_s2+0 
	MOVLW       hi_addr(_httpMethod+0)
	MOVWF       FARG_memcmp_s2+1 
	MOVLW       5
	MOVWF       FARG_memcmp_n+0 
	MOVLW       0
	MOVWF       FARG_memcmp_n+1 
	CALL        _memcmp+0, 0
	MOVF        R0, 0 
	IORWF       R1, 0 
	BTFSC       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP4
;microEthernet.c,225 :: 		return(0) ;
	CLRF        R0 
	CLRF        R1 
	RETURN      0
;microEthernet.c,226 :: 		}
L_SPI_Ethernet_UserTCP4:
;microEthernet.c,228 :: 		httpCounter++ ;                             // one more request done
	MOVLW       1
	ADDWF       _httpCounter+0, 1 
	MOVLW       0
	ADDWFC      _httpCounter+1, 1 
	ADDWFC      _httpCounter+2, 1 
	ADDWFC      _httpCounter+3, 1 
;microEthernet.c,230 :: 		if(getRequest[5] == 's')                    // if request path name starts with s, store dynamic data in transmit buffer
	MOVF        _getRequest+5, 0 
	XORLW       115
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP5
;microEthernet.c,235 :: 		len = putConstString(httpHeader) ;              // HTTP header
	MOVLW       _httpHeader+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(_httpHeader+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(_httpHeader+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+0 
	MOVF        R1, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+1 
;microEthernet.c,236 :: 		len += putConstString(httpMimeTypeScript) ;     // with text MIME type
	MOVLW       _httpMimeTypeScript+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(_httpMimeTypeScript+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(_httpMimeTypeScript+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,239 :: 		WordToStr(ADC_Read(2), dyna) ;
	MOVLW       2
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _dyna+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;microEthernet.c,240 :: 		len += putConstString("var AN2=") ;
	MOVLW       ?lstr_3_microEthernet+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(?lstr_3_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(?lstr_3_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,241 :: 		len += putString(dyna) ;
	MOVLW       _dyna+0
	MOVWF       FARG_SPI_Ethernet_putString_ptr+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_SPI_Ethernet_putString_ptr+1 
	CALL        _SPI_Ethernet_putString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,242 :: 		len += putConstString(";") ;
	MOVLW       ?lstr_4_microEthernet+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(?lstr_4_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(?lstr_4_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,245 :: 		WordToStr(ADC_Read(3), dyna) ;
	MOVLW       3
	MOVWF       FARG_ADC_Read_channel+0 
	CALL        _ADC_Read+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        R1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _dyna+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;microEthernet.c,246 :: 		len += putConstString("var AN3=") ;
	MOVLW       ?lstr_5_microEthernet+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(?lstr_5_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(?lstr_5_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,247 :: 		len += putString(dyna) ;
	MOVLW       _dyna+0
	MOVWF       FARG_SPI_Ethernet_putString_ptr+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_SPI_Ethernet_putString_ptr+1 
	CALL        _SPI_Ethernet_putString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,248 :: 		len += putConstString(";") ;
	MOVLW       ?lstr_6_microEthernet+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(?lstr_6_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(?lstr_6_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,251 :: 		len += putConstString("var PORTB=") ;
	MOVLW       ?lstr_7_microEthernet+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(?lstr_7_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(?lstr_7_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,252 :: 		WordToStr(PORTB, dyna) ;
	MOVF        PORTB+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVLW       0
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _dyna+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;microEthernet.c,253 :: 		len += putString(dyna) ;
	MOVLW       _dyna+0
	MOVWF       FARG_SPI_Ethernet_putString_ptr+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_SPI_Ethernet_putString_ptr+1 
	CALL        _SPI_Ethernet_putString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,254 :: 		len += putConstString(";") ;
	MOVLW       ?lstr_8_microEthernet+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(?lstr_8_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(?lstr_8_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,257 :: 		len += putConstString("var PORTD=") ;
	MOVLW       ?lstr_9_microEthernet+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(?lstr_9_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(?lstr_9_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,258 :: 		WordToStr(PORTD, dyna) ;
	MOVF        PORTD+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVLW       0
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _dyna+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;microEthernet.c,259 :: 		len += putString(dyna) ;
	MOVLW       _dyna+0
	MOVWF       FARG_SPI_Ethernet_putString_ptr+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_SPI_Ethernet_putString_ptr+1 
	CALL        _SPI_Ethernet_putString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,260 :: 		len += putConstString(";") ;
	MOVLW       ?lstr_10_microEthernet+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(?lstr_10_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(?lstr_10_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,263 :: 		WordToStr(httpCounter, dyna) ;
	MOVF        _httpCounter+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        _httpCounter+1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _dyna+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;microEthernet.c,264 :: 		len += putConstString("var REQ=") ;
	MOVLW       ?lstr_11_microEthernet+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(?lstr_11_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(?lstr_11_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,265 :: 		len += putString(dyna) ;
	MOVLW       _dyna+0
	MOVWF       FARG_SPI_Ethernet_putString_ptr+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_SPI_Ethernet_putString_ptr+1 
	CALL        _SPI_Ethernet_putString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,266 :: 		len += putConstString(";") ;
	MOVLW       ?lstr_12_microEthernet+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(?lstr_12_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(?lstr_12_microEthernet+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,267 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP6
L_SPI_Ethernet_UserTCP5:
;microEthernet.c,268 :: 		else if(getRequest[5] == 't')                           // if request path name starts with t, toggle PORTD (LED) bit number that comes after
	MOVF        _getRequest+5, 0 
	XORLW       116
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP7
;microEthernet.c,270 :: 		unsigned char   bitMask = 0 ;                   // for bit mask
;microEthernet.c,272 :: 		if(isdigit(getRequest[6]))                      // if 0 <= bit number <= 9, bits 8 & 9 does not exist but does not matter
	MOVF        _getRequest+6, 0 
	MOVWF       FARG_isdigit_character+0 
	CALL        _isdigit+0, 0
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP8
;microEthernet.c,274 :: 		bitMask = getRequest[6] - '0' ;         // convert ASCII to integer
	MOVLW       48
	SUBWF       _getRequest+6, 0 
	MOVWF       R0 
;microEthernet.c,275 :: 		bitMask = 1 << bitMask ;                // create bit mask
	MOVF        R0, 0 
	MOVWF       R1 
	MOVLW       1
	MOVWF       R0 
	MOVF        R1, 0 
L__SPI_Ethernet_UserTCP16:
	BZ          L__SPI_Ethernet_UserTCP17
	RLCF        R0, 1 
	BCF         R0, 0 
	ADDLW       255
	GOTO        L__SPI_Ethernet_UserTCP16
L__SPI_Ethernet_UserTCP17:
;microEthernet.c,276 :: 		PORTD ^= bitMask ;                      // toggle PORTD with xor operator
	MOVF        R0, 0 
	XORWF       PORTD+0, 1 
;microEthernet.c,277 :: 		}
L_SPI_Ethernet_UserTCP8:
;microEthernet.c,278 :: 		}
L_SPI_Ethernet_UserTCP7:
L_SPI_Ethernet_UserTCP6:
;microEthernet.c,280 :: 		if(len == 0)                                            // what do to by default
	MOVLW       0
	XORWF       SPI_Ethernet_UserTCP_len_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP18
	MOVLW       0
	XORWF       SPI_Ethernet_UserTCP_len_L0+0, 0 
L__SPI_Ethernet_UserTCP18:
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP9
;microEthernet.c,282 :: 		len =  putConstString(httpHeader) ;             // HTTP header
	MOVLW       _httpHeader+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(_httpHeader+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(_httpHeader+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+0 
	MOVF        R1, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+1 
;microEthernet.c,283 :: 		len += putConstString(httpMimeTypeHTML) ;       // with HTML MIME type
	MOVLW       _httpMimeTypeHTML+0
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVLW       hi_addr(_httpMimeTypeHTML+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVLW       higher_addr(_httpMimeTypeHTML+0)
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,284 :: 		len += putConstString(indexPage) ;              // HTML page first part
	MOVF        _indexPage+0, 0 
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVF        _indexPage+1, 0 
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVF        _indexPage+2, 0 
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,285 :: 		len += putConstString(indexPage2) ;             // HTML page second part
	MOVF        _indexPage2+0, 0 
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+0 
	MOVF        _indexPage2+1, 0 
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+1 
	MOVF        _indexPage2+2, 0 
	MOVWF       FARG_SPI_Ethernet_putConstString_ptr+2 
	CALL        _SPI_Ethernet_putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
;microEthernet.c,286 :: 		}
L_SPI_Ethernet_UserTCP9:
;microEthernet.c,288 :: 		return(len) ;                                           // return to the library with the number of bytes to transmit
	MOVF        SPI_Ethernet_UserTCP_len_L0+0, 0 
	MOVWF       R0 
	MOVF        SPI_Ethernet_UserTCP_len_L0+1, 0 
	MOVWF       R1 
;microEthernet.c,289 :: 		}
	RETURN      0
; end of _SPI_Ethernet_UserTCP

_SPI_Ethernet_UserUDP:

;microEthernet.c,301 :: 		unsigned int    SPI_Ethernet_UserUDP(unsigned char *remoteHost, unsigned int remotePort, unsigned int destPort, unsigned int reqLength)
;microEthernet.c,306 :: 		ByteToStr(remoteHost[0], dyna) ;                // first IP address byte
	MOVFF       FARG_SPI_Ethernet_UserUDP_remoteHost+0, FSR0L
	MOVFF       FARG_SPI_Ethernet_UserUDP_remoteHost+1, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_ByteToStr_input+0 
	MOVLW       _dyna+0
	MOVWF       FARG_ByteToStr_output+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_ByteToStr_output+1 
	CALL        _ByteToStr+0, 0
;microEthernet.c,307 :: 		dyna[3] = '.' ;
	MOVLW       46
	MOVWF       _dyna+3 
;microEthernet.c,308 :: 		ByteToStr(remoteHost[1], dyna + 4) ;            // second
	MOVLW       1
	ADDWF       FARG_SPI_Ethernet_UserUDP_remoteHost+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_SPI_Ethernet_UserUDP_remoteHost+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_ByteToStr_input+0 
	MOVLW       _dyna+4
	MOVWF       FARG_ByteToStr_output+0 
	MOVLW       hi_addr(_dyna+4)
	MOVWF       FARG_ByteToStr_output+1 
	CALL        _ByteToStr+0, 0
;microEthernet.c,309 :: 		dyna[7] = '.' ;
	MOVLW       46
	MOVWF       _dyna+7 
;microEthernet.c,310 :: 		ByteToStr(remoteHost[2], dyna + 8) ;            // third
	MOVLW       2
	ADDWF       FARG_SPI_Ethernet_UserUDP_remoteHost+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_SPI_Ethernet_UserUDP_remoteHost+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_ByteToStr_input+0 
	MOVLW       _dyna+8
	MOVWF       FARG_ByteToStr_output+0 
	MOVLW       hi_addr(_dyna+8)
	MOVWF       FARG_ByteToStr_output+1 
	CALL        _ByteToStr+0, 0
;microEthernet.c,311 :: 		dyna[11] = '.' ;
	MOVLW       46
	MOVWF       _dyna+11 
;microEthernet.c,312 :: 		ByteToStr(remoteHost[3], dyna + 12) ;           // fourth
	MOVLW       3
	ADDWF       FARG_SPI_Ethernet_UserUDP_remoteHost+0, 0 
	MOVWF       FSR0L 
	MOVLW       0
	ADDWFC      FARG_SPI_Ethernet_UserUDP_remoteHost+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_ByteToStr_input+0 
	MOVLW       _dyna+12
	MOVWF       FARG_ByteToStr_output+0 
	MOVLW       hi_addr(_dyna+12)
	MOVWF       FARG_ByteToStr_output+1 
	CALL        _ByteToStr+0, 0
;microEthernet.c,314 :: 		dyna[15] = ':' ;                                // add separator
	MOVLW       58
	MOVWF       _dyna+15 
;microEthernet.c,317 :: 		WordToStr(remotePort, dyna + 16) ;
	MOVF        FARG_SPI_Ethernet_UserUDP_remotePort+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        FARG_SPI_Ethernet_UserUDP_remotePort+1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _dyna+16
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_dyna+16)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;microEthernet.c,318 :: 		dyna[21] = '[' ;
	MOVLW       91
	MOVWF       _dyna+21 
;microEthernet.c,319 :: 		WordToStr(destPort, dyna + 22) ;
	MOVF        FARG_SPI_Ethernet_UserUDP_destPort+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        FARG_SPI_Ethernet_UserUDP_destPort+1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _dyna+22
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_dyna+22)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;microEthernet.c,320 :: 		dyna[27] = ']' ;
	MOVLW       93
	MOVWF       _dyna+27 
;microEthernet.c,321 :: 		dyna[28] = 0 ;
	CLRF        _dyna+28 
;microEthernet.c,324 :: 		len = 28 + reqLength;
	MOVLW       28
	ADDWF       FARG_SPI_Ethernet_UserUDP_reqLength+0, 0 
	MOVWF       SPI_Ethernet_UserUDP_len_L0+0 
	MOVLW       0
	ADDWFC      FARG_SPI_Ethernet_UserUDP_reqLength+1, 0 
	MOVWF       SPI_Ethernet_UserUDP_len_L0+1 
;microEthernet.c,327 :: 		SPI_Ethernet_putBytes(dyna, 28) ;
	MOVLW       _dyna+0
	MOVWF       FARG_SPI_Ethernet_putBytes_ptr+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_SPI_Ethernet_putBytes_ptr+1 
	MOVLW       28
	MOVWF       FARG_SPI_Ethernet_putBytes_n+0 
	MOVLW       0
	MOVWF       FARG_SPI_Ethernet_putBytes_n+1 
	CALL        _SPI_Ethernet_putBytes+0, 0
;microEthernet.c,330 :: 		while(reqLength--)
L_SPI_Ethernet_UserUDP10:
	MOVF        FARG_SPI_Ethernet_UserUDP_reqLength+0, 0 
	MOVWF       R0 
	MOVF        FARG_SPI_Ethernet_UserUDP_reqLength+1, 0 
	MOVWF       R1 
	MOVLW       1
	SUBWF       FARG_SPI_Ethernet_UserUDP_reqLength+0, 1 
	MOVLW       0
	SUBWFB      FARG_SPI_Ethernet_UserUDP_reqLength+1, 1 
	MOVF        R0, 0 
	IORWF       R1, 0 
	BTFSC       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserUDP11
;microEthernet.c,332 :: 		SPI_Ethernet_putByte(toupper(SPI_Ethernet_getByte())) ;
	CALL        _SPI_Ethernet_getByte+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_toupper_character+0 
	CALL        _toupper+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_SPI_Ethernet_putByte_v+0 
	CALL        _SPI_Ethernet_putByte+0, 0
;microEthernet.c,333 :: 		}
	GOTO        L_SPI_Ethernet_UserUDP10
L_SPI_Ethernet_UserUDP11:
;microEthernet.c,335 :: 		return(len) ;           // back to the library with the length of the UDP reply
	MOVF        SPI_Ethernet_UserUDP_len_L0+0, 0 
	MOVWF       R0 
	MOVF        SPI_Ethernet_UserUDP_len_L0+1, 0 
	MOVWF       R1 
;microEthernet.c,336 :: 		}
	RETURN      0
; end of _SPI_Ethernet_UserUDP

_main:

;microEthernet.c,341 :: 		void    main()
;microEthernet.c,343 :: 		ADCON1 = 15 ;         // ADC convertors will be used with AN2 and AN3
	MOVLW       15
	MOVWF       ADCON1+0 
;microEthernet.c,344 :: 		CMCON  = 0x07 ;         // turn off comparators
	MOVLW       7
	MOVWF       CMCON+0 
;microEthernet.c,346 :: 		PORTA = 0 ;
	CLRF        PORTA+0 
;microEthernet.c,347 :: 		TRISA = 0xff ;          // set PORTA as input for ADC
	MOVLW       255
	MOVWF       TRISA+0 
;microEthernet.c,349 :: 		PORTB = 0 ;
	CLRF        PORTB+0 
;microEthernet.c,350 :: 		TRISB = 0xff ;          // set PORTB as input for buttons
	MOVLW       255
	MOVWF       TRISB+0 
;microEthernet.c,352 :: 		PORTD = 0 ;
	CLRF        PORTD+0 
;microEthernet.c,353 :: 		TRISD = 0 ;             // set PORTD as output
	CLRF        TRISD+0 
;microEthernet.c,362 :: 		SPI1_Init();
	CALL        _SPI1_Init+0, 0
;microEthernet.c,363 :: 		SPI_Rd_Ptr = SPI1_Read;
	MOVLW       _SPI1_Read+0
	MOVWF       _SPI_Rd_Ptr+0 
	MOVLW       hi_addr(_SPI1_Read+0)
	MOVWF       _SPI_Rd_Ptr+1 
	MOVLW       FARG_SPI1_Read_buffer+0
	MOVWF       _SPI_Rd_Ptr+2 
	MOVLW       hi_addr(FARG_SPI1_Read_buffer+0)
	MOVWF       _SPI_Rd_Ptr+3 
;microEthernet.c,364 :: 		SPI_Ethernet_Init(myMacAddr, myIpAddr, Spi_Ethernet_FULLDUPLEX) ;
	MOVLW       _myMacAddr+0
	MOVWF       FARG_SPI_Ethernet_Init_mac+0 
	MOVLW       hi_addr(_myMacAddr+0)
	MOVWF       FARG_SPI_Ethernet_Init_mac+1 
	MOVLW       _myIpAddr+0
	MOVWF       FARG_SPI_Ethernet_Init_ip+0 
	MOVLW       hi_addr(_myIpAddr+0)
	MOVWF       FARG_SPI_Ethernet_Init_ip+1 
	MOVLW       1
	MOVWF       FARG_SPI_Ethernet_Init_fullDuplex+0 
	CALL        _SPI_Ethernet_Init+0, 0
;microEthernet.c,367 :: 		SPI_Ethernet_confNetwork(ipMask, gwIpAddr, dnsIpAddr) ;
	MOVLW       _ipMask+0
	MOVWF       FARG_SPI_Ethernet_confNetwork_ipMask+0 
	MOVLW       hi_addr(_ipMask+0)
	MOVWF       FARG_SPI_Ethernet_confNetwork_ipMask+1 
	MOVLW       _gwIpAddr+0
	MOVWF       FARG_SPI_Ethernet_confNetwork_gwIpAddr+0 
	MOVLW       hi_addr(_gwIpAddr+0)
	MOVWF       FARG_SPI_Ethernet_confNetwork_gwIpAddr+1 
	MOVLW       _dnsIpAddr+0
	MOVWF       FARG_SPI_Ethernet_confNetwork_dnsIpAddr+0 
	MOVLW       hi_addr(_dnsIpAddr+0)
	MOVWF       FARG_SPI_Ethernet_confNetwork_dnsIpAddr+1 
	CALL        _SPI_Ethernet_confNetwork+0, 0
;microEthernet.c,369 :: 		while(1)                            // do forever
L_main12:
;microEthernet.c,374 :: 		SPI_Ethernet_doPacket() ;   // process incoming Ethernet packets
	CALL        _SPI_Ethernet_doPacket+0, 0
;microEthernet.c,381 :: 		}
	GOTO        L_main12
;microEthernet.c,382 :: 		}
	GOTO        $+0
; end of _main
