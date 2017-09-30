
_putConstString:
;ENC28J60_HTTP.c,134 :: 		unsigned int    putConstString(const code char *s)
;ENC28J60_HTTP.c,136 :: 		unsigned int ctr = 0 ;
	CLRF        putConstString_ctr_L0+0 
	CLRF        putConstString_ctr_L0+1 
;ENC28J60_HTTP.c,138 :: 		while(*s)
L_putConstString0:
	MOVF        FARG_putConstString_s+0, 0 
	MOVWF       TBLPTRL 
	MOVF        FARG_putConstString_s+1, 0 
	MOVWF       TBLPTRH 
	MOVF        FARG_putConstString_s+2, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, R0
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_putConstString1
;ENC28J60_HTTP.c,140 :: 		Spi_Ethernet_putByte(*s++) ;
	MOVF        FARG_putConstString_s+0, 0 
	MOVWF       TBLPTRL 
	MOVF        FARG_putConstString_s+1, 0 
	MOVWF       TBLPTRH 
	MOVF        FARG_putConstString_s+2, 0 
	MOVWF       TBLPTRU 
	TBLRD*+
	MOVFF       TABLAT+0, FARG_SPI_Ethernet_putByte_v+0
	CALL        _SPI_Ethernet_putByte+0, 0
	MOVLW       1
	ADDWF       FARG_putConstString_s+0, 1 
	MOVLW       0
	ADDWFC      FARG_putConstString_s+1, 1 
	ADDWFC      FARG_putConstString_s+2, 1 
;ENC28J60_HTTP.c,141 :: 		ctr++ ;
	INFSNZ      putConstString_ctr_L0+0, 1 
	INCF        putConstString_ctr_L0+1, 1 
;ENC28J60_HTTP.c,142 :: 		}
	GOTO        L_putConstString0
L_putConstString1:
;ENC28J60_HTTP.c,143 :: 		return(ctr) ;
	MOVF        putConstString_ctr_L0+0, 0 
	MOVWF       R0 
	MOVF        putConstString_ctr_L0+1, 0 
	MOVWF       R1 
;ENC28J60_HTTP.c,144 :: 		}
	RETURN      0
; end of _putConstString

_putString:
;ENC28J60_HTTP.c,147 :: 		unsigned int    putString(char *s)
;ENC28J60_HTTP.c,149 :: 		unsigned int ctr = 0 ;
	CLRF        putString_ctr_L0+0 
	CLRF        putString_ctr_L0+1 
;ENC28J60_HTTP.c,151 :: 		while(*s)
L_putString2:
	MOVFF       FARG_putString_s+0, FSR0L
	MOVFF       FARG_putString_s+1, FSR0H
	MOVF        POSTINC0+0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_putString3
;ENC28J60_HTTP.c,153 :: 		Spi_Ethernet_putByte(*s++) ;
	MOVFF       FARG_putString_s+0, FSR0L
	MOVFF       FARG_putString_s+1, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_SPI_Ethernet_putByte_v+0 
	CALL        _SPI_Ethernet_putByte+0, 0
	INFSNZ      FARG_putString_s+0, 1 
	INCF        FARG_putString_s+1, 1 
;ENC28J60_HTTP.c,155 :: 		ctr++ ;
	INFSNZ      putString_ctr_L0+0, 1 
	INCF        putString_ctr_L0+1, 1 
;ENC28J60_HTTP.c,156 :: 		}
	GOTO        L_putString2
L_putString3:
;ENC28J60_HTTP.c,157 :: 		return(ctr) ;
	MOVF        putString_ctr_L0+0, 0 
	MOVWF       R0 
	MOVF        putString_ctr_L0+1, 0 
	MOVWF       R1 
;ENC28J60_HTTP.c,158 :: 		}
	RETURN      0
; end of _putString

_SPI_Ethernet_UserTCP:
;ENC28J60_HTTP.c,162 :: 		unsigned int    SPI_Ethernet_UserTCP(unsigned char *remoteHost, unsigned int remotePort, unsigned int localPort, unsigned int reqLength)
;ENC28J60_HTTP.c,168 :: 		if(localPort != 80)                         // I listen only to web request on port 80
	MOVLW       0
	XORWF       FARG_SPI_Ethernet_UserTCP_localPort+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP36
	MOVLW       80
	XORWF       FARG_SPI_Ethernet_UserTCP_localPort+0, 0 
L__SPI_Ethernet_UserTCP36:
	BTFSC       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP4
;ENC28J60_HTTP.c,170 :: 		return(0) ;
	CLRF        R0 
	CLRF        R1 
	RETURN      0
;ENC28J60_HTTP.c,171 :: 		}
L_SPI_Ethernet_UserTCP4:
;ENC28J60_HTTP.c,174 :: 		for(len = 0 ; len < 32 ; len++)
	CLRF        SPI_Ethernet_UserTCP_len_L0+0 
	CLRF        SPI_Ethernet_UserTCP_len_L0+1 
	CLRF        SPI_Ethernet_UserTCP_len_L0+2 
	CLRF        SPI_Ethernet_UserTCP_len_L0+3 
L_SPI_Ethernet_UserTCP5:
	MOVLW       0
	SUBWF       SPI_Ethernet_UserTCP_len_L0+3, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP37
	MOVLW       0
	SUBWF       SPI_Ethernet_UserTCP_len_L0+2, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP37
	MOVLW       0
	SUBWF       SPI_Ethernet_UserTCP_len_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP37
	MOVLW       32
	SUBWF       SPI_Ethernet_UserTCP_len_L0+0, 0 
L__SPI_Ethernet_UserTCP37:
	BTFSC       STATUS+0, 0 
	GOTO        L_SPI_Ethernet_UserTCP6
;ENC28J60_HTTP.c,176 :: 		getRequest[len] = SPI_Ethernet_getByte() ;
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
;ENC28J60_HTTP.c,174 :: 		for(len = 0 ; len < 32 ; len++)
	MOVLW       1
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,177 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP5
L_SPI_Ethernet_UserTCP6:
;ENC28J60_HTTP.c,178 :: 		getRequest[len] = 0 ;
	MOVLW       _getRequest+0
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 0 
	MOVWF       FSR1L 
	MOVLW       hi_addr(_getRequest+0)
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 0 
	MOVWF       FSR1H 
	CLRF        POSTINC1+0 
;ENC28J60_HTTP.c,179 :: 		len = 0;
	CLRF        SPI_Ethernet_UserTCP_len_L0+0 
	CLRF        SPI_Ethernet_UserTCP_len_L0+1 
	CLRF        SPI_Ethernet_UserTCP_len_L0+2 
	CLRF        SPI_Ethernet_UserTCP_len_L0+3 
;ENC28J60_HTTP.c,181 :: 		if(memcmp(getRequest, httpMethod, 5))       // only GET method is supported here
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
	GOTO        L_SPI_Ethernet_UserTCP8
;ENC28J60_HTTP.c,183 :: 		return(0) ;
	CLRF        R0 
	CLRF        R1 
	RETURN      0
;ENC28J60_HTTP.c,184 :: 		}
L_SPI_Ethernet_UserTCP8:
;ENC28J60_HTTP.c,186 :: 		httpCounter++ ;                             // one more request done
	MOVLW       1
	ADDWF       _httpCounter+0, 1 
	MOVLW       0
	ADDWFC      _httpCounter+1, 1 
	ADDWFC      _httpCounter+2, 1 
	ADDWFC      _httpCounter+3, 1 
;ENC28J60_HTTP.c,188 :: 		if(getRequest[5] == 's')                    // if request path name starts with s, store dynamic data in transmit buffer
	MOVF        _getRequest+5, 0 
	XORLW       115
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP9
;ENC28J60_HTTP.c,193 :: 		len = putConstString(httpHeader) ;              // HTTP header
	MOVLW       _httpHeader+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(_httpHeader+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(_httpHeader+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+0 
	MOVF        R1, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+1 
	MOVLW       0
	MOVWF       SPI_Ethernet_UserTCP_len_L0+2 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+3 
;ENC28J60_HTTP.c,194 :: 		len += putConstString(httpMimeTypeScript) ;     // with text MIME type
	MOVLW       _httpMimeTypeScript+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(_httpMimeTypeScript+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(_httpMimeTypeScript+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,197 :: 		WordToStr(ADC_Read(0), dyna) ;
	CLRF        FARG_ADC_Read_channel+0 
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
;ENC28J60_HTTP.c,198 :: 		len += putConstString("var AN0=") ;
	MOVLW       ?lstr_3_ENC28J60_HTTP+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(?lstr_3_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(?lstr_3_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,199 :: 		len += putString(dyna) ;
	MOVLW       _dyna+0
	MOVWF       FARG_putString_s+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_putString_s+1 
	CALL        _putString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,200 :: 		len += putConstString(";") ;
	MOVLW       ?lstr_4_ENC28J60_HTTP+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(?lstr_4_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(?lstr_4_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,203 :: 		WordToStr(ADC_Read(1), dyna) ;
	MOVLW       1
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
;ENC28J60_HTTP.c,204 :: 		len += putConstString("var AN1=") ;
	MOVLW       ?lstr_5_ENC28J60_HTTP+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(?lstr_5_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(?lstr_5_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,205 :: 		len += putString(dyna) ;
	MOVLW       _dyna+0
	MOVWF       FARG_putString_s+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_putString_s+1 
	CALL        _putString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,206 :: 		len += putConstString(";") ;
	MOVLW       ?lstr_6_ENC28J60_HTTP+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(?lstr_6_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(?lstr_6_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,209 :: 		len += putConstString("var PORTB=") ;
	MOVLW       ?lstr_7_ENC28J60_HTTP+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(?lstr_7_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(?lstr_7_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,210 :: 		WordToStr(PORTB, dyna) ;
	MOVF        PORTB+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVLW       0
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _dyna+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;ENC28J60_HTTP.c,211 :: 		len += putString(dyna) ;
	MOVLW       _dyna+0
	MOVWF       FARG_putString_s+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_putString_s+1 
	CALL        _putString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,212 :: 		len += putConstString(";") ;
	MOVLW       ?lstr_8_ENC28J60_HTTP+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(?lstr_8_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(?lstr_8_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,215 :: 		len += putConstString("var PORTD=") ;
	MOVLW       ?lstr_9_ENC28J60_HTTP+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(?lstr_9_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(?lstr_9_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,216 :: 		WordToStr(PORTD, dyna) ;
	MOVF        PORTD+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVLW       0
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _dyna+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;ENC28J60_HTTP.c,217 :: 		len += putString(dyna) ;
	MOVLW       _dyna+0
	MOVWF       FARG_putString_s+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_putString_s+1 
	CALL        _putString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,218 :: 		len += putConstString(";") ;
	MOVLW       ?lstr_10_ENC28J60_HTTP+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(?lstr_10_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(?lstr_10_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,221 :: 		WordToStr(httpCounter, dyna) ;
	MOVF        _httpCounter+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        _httpCounter+1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _dyna+0
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;ENC28J60_HTTP.c,222 :: 		len += putConstString("var REQ=") ;
	MOVLW       ?lstr_11_ENC28J60_HTTP+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(?lstr_11_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(?lstr_11_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,223 :: 		len += putString(dyna) ;
	MOVLW       _dyna+0
	MOVWF       FARG_putString_s+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_putString_s+1 
	CALL        _putString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,224 :: 		len += putConstString(";") ;
	MOVLW       ?lstr_12_ENC28J60_HTTP+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(?lstr_12_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(?lstr_12_ENC28J60_HTTP+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,225 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP10
L_SPI_Ethernet_UserTCP9:
;ENC28J60_HTTP.c,226 :: 		else if(getRequest[5] == 't')                           // if request path name starts with t, toggle PORTD (LED) bit number that comes after
	MOVF        _getRequest+5, 0 
	XORLW       116
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP11
;ENC28J60_HTTP.c,228 :: 		unsigned char   bitMask = 0 ;                   // for bit mask
;ENC28J60_HTTP.c,230 :: 		if(isdigit(getRequest[6]))                      // if 0 <= bit number <= 9, bits 8 & 9 does not exist but does not matter
	MOVF        _getRequest+6, 0 
	MOVWF       FARG_isdigit_character+0 
	CALL        _isdigit+0, 0
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP12
;ENC28J60_HTTP.c,232 :: 		bitMask = getRequest[6] - '0' ;         // convert ASCII to integer
	MOVLW       48
	SUBWF       _getRequest+6, 0 
	MOVWF       R0 
;ENC28J60_HTTP.c,233 :: 		bitMask = 1 << bitMask ;                // create bit mask
	MOVF        R0, 0 
	MOVWF       R1 
	MOVLW       1
	MOVWF       R0 
	MOVF        R1, 0 
L__SPI_Ethernet_UserTCP38:
	BZ          L__SPI_Ethernet_UserTCP39
	RLCF        R0, 1 
	BCF         R0, 0 
	ADDLW       255
	GOTO        L__SPI_Ethernet_UserTCP38
L__SPI_Ethernet_UserTCP39:
;ENC28J60_HTTP.c,234 :: 		PORTD ^= bitMask ;                      // toggle PORTD with xor operator
	MOVF        R0, 0 
	XORWF       PORTD+0, 1 
;ENC28J60_HTTP.c,235 :: 		}
L_SPI_Ethernet_UserTCP12:
;ENC28J60_HTTP.c,236 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP13
L_SPI_Ethernet_UserTCP11:
;ENC28J60_HTTP.c,237 :: 		else if((getRequest[5] == 'C')&&(getRequest[6] == '=') )                          // if request path name starts with t, toggle PORTD (LED) bit number that comes after
	MOVF        _getRequest+5, 0 
	XORLW       67
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP16
	MOVF        _getRequest+6, 0 
	XORLW       61
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP16
L__SPI_Ethernet_UserTCP35:
;ENC28J60_HTTP.c,239 :: 		Lcd_Out(1,1,"C:");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr13_ENC28J60_HTTP+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr13_ENC28J60_HTTP+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ENC28J60_HTTP.c,241 :: 		for(cont=7;cont<=32;cont++)
	MOVLW       7
	MOVWF       SPI_Ethernet_UserTCP_cont_L0+0 
	MOVLW       0
	MOVWF       SPI_Ethernet_UserTCP_cont_L0+1 
L_SPI_Ethernet_UserTCP17:
	MOVLW       0
	MOVWF       R0 
	MOVF        SPI_Ethernet_UserTCP_cont_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP40
	MOVF        SPI_Ethernet_UserTCP_cont_L0+0, 0 
	SUBLW       32
L__SPI_Ethernet_UserTCP40:
	BTFSS       STATUS+0, 0 
	GOTO        L_SPI_Ethernet_UserTCP18
;ENC28J60_HTTP.c,243 :: 		if (getRequest[cont]==';') break;
	MOVLW       _getRequest+0
	ADDWF       SPI_Ethernet_UserTCP_cont_L0+0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(_getRequest+0)
	ADDWFC      SPI_Ethernet_UserTCP_cont_L0+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	XORLW       59
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP20
	GOTO        L_SPI_Ethernet_UserTCP18
L_SPI_Ethernet_UserTCP20:
;ENC28J60_HTTP.c,244 :: 		Lcd_Chr_CP(getRequest[cont]);              // Escreve no display LCD
	MOVLW       _getRequest+0
	ADDWF       SPI_Ethernet_UserTCP_cont_L0+0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(_getRequest+0)
	ADDWFC      SPI_Ethernet_UserTCP_cont_L0+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;ENC28J60_HTTP.c,241 :: 		for(cont=7;cont<=32;cont++)
	INFSNZ      SPI_Ethernet_UserTCP_cont_L0+0, 1 
	INCF        SPI_Ethernet_UserTCP_cont_L0+1, 1 
;ENC28J60_HTTP.c,245 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP17
L_SPI_Ethernet_UserTCP18:
;ENC28J60_HTTP.c,246 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP21
L_SPI_Ethernet_UserTCP16:
;ENC28J60_HTTP.c,247 :: 		else if((getRequest[5] == 'L')&&(getRequest[6] == '=') )                          // if request path name starts with t, toggle PORTD (LED) bit number that comes after
	MOVF        _getRequest+5, 0 
	XORLW       76
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP24
	MOVF        _getRequest+6, 0 
	XORLW       61
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP24
L__SPI_Ethernet_UserTCP34:
;ENC28J60_HTTP.c,249 :: 		Lcd_Out(2,1,"L:");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr14_ENC28J60_HTTP+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr14_ENC28J60_HTTP+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ENC28J60_HTTP.c,251 :: 		for(cont=7;cont<=32;cont++)
	MOVLW       7
	MOVWF       SPI_Ethernet_UserTCP_cont_L0+0 
	MOVLW       0
	MOVWF       SPI_Ethernet_UserTCP_cont_L0+1 
L_SPI_Ethernet_UserTCP25:
	MOVLW       0
	MOVWF       R0 
	MOVF        SPI_Ethernet_UserTCP_cont_L0+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP41
	MOVF        SPI_Ethernet_UserTCP_cont_L0+0, 0 
	SUBLW       32
L__SPI_Ethernet_UserTCP41:
	BTFSS       STATUS+0, 0 
	GOTO        L_SPI_Ethernet_UserTCP26
;ENC28J60_HTTP.c,253 :: 		if (getRequest[cont]==';') break;
	MOVLW       _getRequest+0
	ADDWF       SPI_Ethernet_UserTCP_cont_L0+0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(_getRequest+0)
	ADDWFC      SPI_Ethernet_UserTCP_cont_L0+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	XORLW       59
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP28
	GOTO        L_SPI_Ethernet_UserTCP26
L_SPI_Ethernet_UserTCP28:
;ENC28J60_HTTP.c,254 :: 		Lcd_Chr_CP(getRequest[cont]);              // Escreve no display LCD
	MOVLW       _getRequest+0
	ADDWF       SPI_Ethernet_UserTCP_cont_L0+0, 0 
	MOVWF       FSR0L 
	MOVLW       hi_addr(_getRequest+0)
	ADDWFC      SPI_Ethernet_UserTCP_cont_L0+1, 0 
	MOVWF       FSR0H 
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_Lcd_Chr_CP_out_char+0 
	CALL        _Lcd_Chr_CP+0, 0
;ENC28J60_HTTP.c,251 :: 		for(cont=7;cont<=32;cont++)
	INFSNZ      SPI_Ethernet_UserTCP_cont_L0+0, 1 
	INCF        SPI_Ethernet_UserTCP_cont_L0+1, 1 
;ENC28J60_HTTP.c,255 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP25
L_SPI_Ethernet_UserTCP26:
;ENC28J60_HTTP.c,256 :: 		}
L_SPI_Ethernet_UserTCP24:
L_SPI_Ethernet_UserTCP21:
L_SPI_Ethernet_UserTCP13:
L_SPI_Ethernet_UserTCP10:
;ENC28J60_HTTP.c,257 :: 		if(len == 0)                                            // what do to by default
	MOVLW       0
	MOVWF       R0 
	XORWF       SPI_Ethernet_UserTCP_len_L0+3, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP42
	MOVF        R0, 0 
	XORWF       SPI_Ethernet_UserTCP_len_L0+2, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP42
	MOVF        R0, 0 
	XORWF       SPI_Ethernet_UserTCP_len_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP42
	MOVF        SPI_Ethernet_UserTCP_len_L0+0, 0 
	XORLW       0
L__SPI_Ethernet_UserTCP42:
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP29
;ENC28J60_HTTP.c,259 :: 		len =  putConstString(httpHeader) ;             // HTTP header
	MOVLW       _httpHeader+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(_httpHeader+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(_httpHeader+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+0 
	MOVF        R1, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+1 
	MOVLW       0
	MOVWF       SPI_Ethernet_UserTCP_len_L0+2 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+3 
;ENC28J60_HTTP.c,260 :: 		len += putConstString(httpMimeTypeHTML) ;       // with HTML MIME type
	MOVLW       _httpMimeTypeHTML+0
	MOVWF       FARG_putConstString_s+0 
	MOVLW       hi_addr(_httpMimeTypeHTML+0)
	MOVWF       FARG_putConstString_s+1 
	MOVLW       higher_addr(_httpMimeTypeHTML+0)
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,261 :: 		len += putConstString(indexPage) ;              // HTML page first part
	MOVF        _indexPage+0, 0 
	MOVWF       FARG_putConstString_s+0 
	MOVF        _indexPage+1, 0 
	MOVWF       FARG_putConstString_s+1 
	MOVF        _indexPage+2, 0 
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,262 :: 		len += putConstString(indexPage2) ;             // HTML page second part
	MOVF        _indexPage2+0, 0 
	MOVWF       FARG_putConstString_s+0 
	MOVF        _indexPage2+1, 0 
	MOVWF       FARG_putConstString_s+1 
	MOVF        _indexPage2+2, 0 
	MOVWF       FARG_putConstString_s+2 
	CALL        _putConstString+0, 0
	MOVF        R0, 0 
	ADDWF       SPI_Ethernet_UserTCP_len_L0+0, 1 
	MOVF        R1, 0 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+1, 1 
	MOVLW       0
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+2, 1 
	ADDWFC      SPI_Ethernet_UserTCP_len_L0+3, 1 
;ENC28J60_HTTP.c,263 :: 		}
L_SPI_Ethernet_UserTCP29:
;ENC28J60_HTTP.c,265 :: 		return(len) ;                                           // return to the library with the number of bytes to transmit
	MOVF        SPI_Ethernet_UserTCP_len_L0+0, 0 
	MOVWF       R0 
	MOVF        SPI_Ethernet_UserTCP_len_L0+1, 0 
	MOVWF       R1 
;ENC28J60_HTTP.c,266 :: 		}
	RETURN      0
; end of _SPI_Ethernet_UserTCP

_SPI_Ethernet_UserUDP:
;ENC28J60_HTTP.c,268 :: 		unsigned int    SPI_Ethernet_UserUDP(unsigned char *remoteHost, unsigned int remotePort, unsigned int destPort, unsigned int reqLength)
;ENC28J60_HTTP.c,273 :: 		ByteToStr(remoteHost[0], dyna) ;                // first IP address byte
	MOVFF       FARG_SPI_Ethernet_UserUDP_remoteHost+0, FSR0L
	MOVFF       FARG_SPI_Ethernet_UserUDP_remoteHost+1, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_ByteToStr_input+0 
	MOVLW       _dyna+0
	MOVWF       FARG_ByteToStr_output+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_ByteToStr_output+1 
	CALL        _ByteToStr+0, 0
;ENC28J60_HTTP.c,274 :: 		dyna[3] = '.' ;
	MOVLW       46
	MOVWF       _dyna+3 
;ENC28J60_HTTP.c,275 :: 		ByteToStr(remoteHost[1], dyna + 4) ;            // second
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
;ENC28J60_HTTP.c,276 :: 		dyna[7] = '.' ;
	MOVLW       46
	MOVWF       _dyna+7 
;ENC28J60_HTTP.c,277 :: 		ByteToStr(remoteHost[2], dyna + 8) ;            // third
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
;ENC28J60_HTTP.c,278 :: 		dyna[11] = '.' ;
	MOVLW       46
	MOVWF       _dyna+11 
;ENC28J60_HTTP.c,279 :: 		ByteToStr(remoteHost[3], dyna + 12) ;           // fourth
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
;ENC28J60_HTTP.c,281 :: 		dyna[15] = ':' ;                                // add separator
	MOVLW       58
	MOVWF       _dyna+15 
;ENC28J60_HTTP.c,284 :: 		WordToStr(remotePort, dyna + 16) ;
	MOVF        FARG_SPI_Ethernet_UserUDP_remotePort+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        FARG_SPI_Ethernet_UserUDP_remotePort+1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _dyna+16
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_dyna+16)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;ENC28J60_HTTP.c,285 :: 		dyna[21] = '[' ;
	MOVLW       91
	MOVWF       _dyna+21 
;ENC28J60_HTTP.c,286 :: 		WordToStr(destPort, dyna + 22) ;
	MOVF        FARG_SPI_Ethernet_UserUDP_destPort+0, 0 
	MOVWF       FARG_WordToStr_input+0 
	MOVF        FARG_SPI_Ethernet_UserUDP_destPort+1, 0 
	MOVWF       FARG_WordToStr_input+1 
	MOVLW       _dyna+22
	MOVWF       FARG_WordToStr_output+0 
	MOVLW       hi_addr(_dyna+22)
	MOVWF       FARG_WordToStr_output+1 
	CALL        _WordToStr+0, 0
;ENC28J60_HTTP.c,287 :: 		dyna[27] = ']' ;
	MOVLW       93
	MOVWF       _dyna+27 
;ENC28J60_HTTP.c,288 :: 		dyna[28] = 0 ;
	CLRF        _dyna+28 
;ENC28J60_HTTP.c,291 :: 		len = 28 + reqLength;
	MOVLW       28
	ADDWF       FARG_SPI_Ethernet_UserUDP_reqLength+0, 0 
	MOVWF       SPI_Ethernet_UserUDP_len_L0+0 
	MOVLW       0
	ADDWFC      FARG_SPI_Ethernet_UserUDP_reqLength+1, 0 
	MOVWF       SPI_Ethernet_UserUDP_len_L0+1 
;ENC28J60_HTTP.c,294 :: 		SPI_Ethernet_putBytes(dyna, 28) ;
	MOVLW       _dyna+0
	MOVWF       FARG_SPI_Ethernet_putBytes_ptr+0 
	MOVLW       hi_addr(_dyna+0)
	MOVWF       FARG_SPI_Ethernet_putBytes_ptr+1 
	MOVLW       28
	MOVWF       FARG_SPI_Ethernet_putBytes_n+0 
	MOVLW       0
	MOVWF       FARG_SPI_Ethernet_putBytes_n+1 
	CALL        _SPI_Ethernet_putBytes+0, 0
;ENC28J60_HTTP.c,297 :: 		while(reqLength--)
L_SPI_Ethernet_UserUDP30:
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
	GOTO        L_SPI_Ethernet_UserUDP31
;ENC28J60_HTTP.c,299 :: 		SPI_Ethernet_putByte(toupper(SPI_Ethernet_getByte())) ;
	CALL        _SPI_Ethernet_getByte+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_toupper_character+0 
	CALL        _toupper+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_SPI_Ethernet_putByte_v+0 
	CALL        _SPI_Ethernet_putByte+0, 0
;ENC28J60_HTTP.c,300 :: 		}
	GOTO        L_SPI_Ethernet_UserUDP30
L_SPI_Ethernet_UserUDP31:
;ENC28J60_HTTP.c,302 :: 		return(len) ;           // back to the library with the length of the UDP reply
	MOVF        SPI_Ethernet_UserUDP_len_L0+0, 0 
	MOVWF       R0 
	MOVF        SPI_Ethernet_UserUDP_len_L0+1, 0 
	MOVWF       R1 
;ENC28J60_HTTP.c,303 :: 		}
	RETURN      0
; end of _SPI_Ethernet_UserUDP

_main:
;ENC28J60_HTTP.c,308 :: 		void    main()
;ENC28J60_HTTP.c,310 :: 		ADCON1 = 0x0D ;         // ADC convertors will be used with AN0 and AN1
	MOVLW       13
	MOVWF       ADCON1+0 
;ENC28J60_HTTP.c,311 :: 		CMCON  = 0x07 ;         // turn off comparators
	MOVLW       7
	MOVWF       CMCON+0 
;ENC28J60_HTTP.c,313 :: 		PORTA = 0 ;
	CLRF        PORTA+0 
;ENC28J60_HTTP.c,314 :: 		TRISA = 0xff ;          // set PORTA as input for ADC
	MOVLW       255
	MOVWF       TRISA+0 
;ENC28J60_HTTP.c,316 :: 		PORTB = 0 ;
	CLRF        PORTB+0 
;ENC28J60_HTTP.c,317 :: 		TRISB = 0xff ;          // set PORTB as input for buttons
	MOVLW       255
	MOVWF       TRISB+0 
;ENC28J60_HTTP.c,319 :: 		PORTD = 0 ;
	CLRF        PORTD+0 
;ENC28J60_HTTP.c,320 :: 		TRISD = 0 ;             // set PORTD as output
	CLRF        TRISD+0 
;ENC28J60_HTTP.c,322 :: 		Lcd_Init();                               // Inicializa LCD.
	CALL        _Lcd_Init+0, 0
;ENC28J60_HTTP.c,324 :: 		Lcd_Cmd(_LCD_CLEAR);                      // Apaga display
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;ENC28J60_HTTP.c,325 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                 // Desliga cursor
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;ENC28J60_HTTP.c,334 :: 		SPI1_Init();
	CALL        _SPI1_Init+0, 0
;ENC28J60_HTTP.c,335 :: 		SPI_Rd_Ptr = SPI1_Read;
	MOVLW       _SPI1_Read+0
	MOVWF       _SPI_Rd_Ptr+0 
	MOVLW       hi_addr(_SPI1_Read+0)
	MOVWF       _SPI_Rd_Ptr+1 
	MOVLW       FARG_SPI1_Read_buffer+0
	MOVWF       _SPI_Rd_Ptr+2 
	MOVLW       hi_addr(FARG_SPI1_Read_buffer+0)
	MOVWF       _SPI_Rd_Ptr+3 
;ENC28J60_HTTP.c,336 :: 		SPI_Ethernet_Init(myMacAddr, myIpAddr, Spi_Ethernet_FULLDUPLEX) ;
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
;ENC28J60_HTTP.c,338 :: 		SPI_Ethernet_confNetwork(ipMask, gwIpAddr, dnsIpAddr) ;
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
;ENC28J60_HTTP.c,340 :: 		while(1)                            // do forever
L_main32:
;ENC28J60_HTTP.c,345 :: 		SPI_Ethernet_doPacket() ;   // process incoming Ethernet packets
	CALL        _SPI_Ethernet_doPacket+0, 0
;ENC28J60_HTTP.c,352 :: 		}
	GOTO        L_main32
;ENC28J60_HTTP.c,353 :: 		}
	GOTO        $+0
; end of _main
