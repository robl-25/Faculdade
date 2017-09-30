
_SPI_Ethernet_UserUDP:

;Basic_Realm.c,147 :: 		unsigned int    SPI_Ethernet_UserUDP(unsigned char *remoteHost, unsigned int remotePort, unsigned int destPort, unsigned int reqLength)
;Basic_Realm.c,149 :: 		return(0) ;
	CLRF        R0 
	CLRF        R1 
;Basic_Realm.c,150 :: 		}
	RETURN      0
; end of _SPI_Ethernet_UserUDP

_SPI_Ethernet_UserTCP:

;Basic_Realm.c,155 :: 		unsigned int    SPI_Ethernet_UserTCP(unsigned char *remoteHost, unsigned int remotePort, unsigned int localPort, unsigned int reqLength, char *canClose)
;Basic_Realm.c,157 :: 		unsigned int    len = 0 ;       // my reply length
	CLRF        SPI_Ethernet_UserTCP_len_L0+0 
	CLRF        SPI_Ethernet_UserTCP_len_L0+1 
;Basic_Realm.c,169 :: 		if(localPort != 80)
	MOVLW       0
	XORWF       FARG_SPI_Ethernet_UserTCP_localPort+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP17
	MOVLW       80
	XORWF       FARG_SPI_Ethernet_UserTCP_localPort+0, 0 
L__SPI_Ethernet_UserTCP17:
	BTFSC       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP0
;Basic_Realm.c,171 :: 		return(0) ;             // no reply to other ports
	CLRF        R0 
	CLRF        R1 
	RETURN      0
;Basic_Realm.c,172 :: 		}
L_SPI_Ethernet_UserTCP0:
;Basic_Realm.c,177 :: 		if(HTTP_getRequest(http_request, &reqLength, HTTP_REQUEST_SIZE) == 0)
	MOVLW       _http_request+0
	MOVWF       FARG_HTTP_getRequest_ptr+0 
	MOVLW       hi_addr(_http_request+0)
	MOVWF       FARG_HTTP_getRequest_ptr+1 
	MOVLW       FARG_SPI_Ethernet_UserTCP_reqLength+0
	MOVWF       FARG_HTTP_getRequest_len+0 
	MOVLW       hi_addr(FARG_SPI_Ethernet_UserTCP_reqLength+0)
	MOVWF       FARG_HTTP_getRequest_len+1 
	MOVLW       50
	MOVWF       FARG_HTTP_getRequest_max+0 
	MOVLW       0
	MOVWF       FARG_HTTP_getRequest_max+1 
	CALL        _HTTP_getRequest+0, 0
	MOVF        R0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP1
;Basic_Realm.c,179 :: 		return(0) ;             // no reply if not found
	CLRF        R0 
	CLRF        R1 
	RETURN      0
;Basic_Realm.c,180 :: 		}
L_SPI_Ethernet_UserTCP1:
;Basic_Realm.c,185 :: 		admin = HTTP_basicRealm(reqLength, PRIVATE_LOGINPASSWD) ;
	MOVF        FARG_SPI_Ethernet_UserTCP_reqLength+0, 0 
	MOVWF       FARG_HTTP_basicRealm_l+0 
	MOVF        FARG_SPI_Ethernet_UserTCP_reqLength+1, 0 
	MOVWF       FARG_HTTP_basicRealm_l+1 
	MOVLW       ?lstr1_Basic_Realm+0
	MOVWF       FARG_HTTP_basicRealm_passwd+0 
	MOVLW       hi_addr(?lstr1_Basic_Realm+0)
	MOVWF       FARG_HTTP_basicRealm_passwd+1 
	CALL        _HTTP_basicRealm+0, 0
	MOVF        R0, 0 
	MOVWF       SPI_Ethernet_UserTCP_admin_L0+0 
;Basic_Realm.c,190 :: 		if(memcmp(http_request, path_private, sizeof(path_private) - 1) == 0)   // is path under private section ?
	MOVLW       _http_request+0
	MOVWF       FARG_memcmp_s1+0 
	MOVLW       hi_addr(_http_request+0)
	MOVWF       FARG_memcmp_s1+1 
	MOVLW       _path_private+0
	MOVWF       FARG_memcmp_s2+0 
	MOVLW       hi_addr(_path_private+0)
	MOVWF       FARG_memcmp_s2+1 
	MOVLW       8
	MOVWF       FARG_memcmp_n+0 
	MOVLW       0
	MOVWF       FARG_memcmp_n+1 
	CALL        _memcmp+0, 0
	MOVLW       0
	XORWF       R1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP18
	MOVLW       0
	XORWF       R0, 0 
L__SPI_Ethernet_UserTCP18:
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP2
;Basic_Realm.c,193 :: 		ptr = http_request + sizeof(path_private) - 1;
	MOVLW       1
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVF        R0, 0 
	SUBLW       _http_request+9
	MOVWF       SPI_Ethernet_UserTCP_ptr_L0+0 
	MOVF        R1, 0 
	MOVWF       SPI_Ethernet_UserTCP_ptr_L0+1 
	MOVLW       hi_addr(_http_request+9)
	SUBFWB      SPI_Ethernet_UserTCP_ptr_L0+1, 1 
;Basic_Realm.c,196 :: 		if(admin == 0)
	MOVF        SPI_Ethernet_UserTCP_admin_L0+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP3
;Basic_Realm.c,199 :: 		len = HTTP_accessDenied(ZONE_NAME, MSG_DENIED) ;
	MOVLW       ?lstr_2_Basic_Realm+0
	MOVWF       FARG_HTTP_accessDenied_zn+0 
	MOVLW       hi_addr(?lstr_2_Basic_Realm+0)
	MOVWF       FARG_HTTP_accessDenied_zn+1 
	MOVLW       higher_addr(?lstr_2_Basic_Realm+0)
	MOVWF       FARG_HTTP_accessDenied_zn+2 
	MOVLW       ?lstr_3_Basic_Realm+0
	MOVWF       FARG_HTTP_accessDenied_m+0 
	MOVLW       hi_addr(?lstr_3_Basic_Realm+0)
	MOVWF       FARG_HTTP_accessDenied_m+1 
	MOVLW       higher_addr(?lstr_3_Basic_Realm+0)
	MOVWF       FARG_HTTP_accessDenied_m+2 
	CALL        _HTTP_accessDenied+0, 0
	MOVF        R0, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+0 
	MOVF        R1, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+1 
;Basic_Realm.c,200 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP4
L_SPI_Ethernet_UserTCP3:
;Basic_Realm.c,204 :: 		if(memcmp(ptr, path_redirect, sizeof(path_redirect) - 1) == 0)
	MOVF        SPI_Ethernet_UserTCP_ptr_L0+0, 0 
	MOVWF       FARG_memcmp_s1+0 
	MOVF        SPI_Ethernet_UserTCP_ptr_L0+1, 0 
	MOVWF       FARG_memcmp_s1+1 
	MOVLW       _path_redirect+0
	MOVWF       FARG_memcmp_s2+0 
	MOVLW       hi_addr(_path_redirect+0)
	MOVWF       FARG_memcmp_s2+1 
	MOVLW       9
	MOVWF       FARG_memcmp_n+0 
	MOVLW       0
	MOVWF       FARG_memcmp_n+1 
	CALL        _memcmp+0, 0
	MOVLW       0
	XORWF       R1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP19
	MOVLW       0
	XORWF       R0, 0 
L__SPI_Ethernet_UserTCP19:
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP5
;Basic_Realm.c,207 :: 		len = HTTP_redirect(redirURL) ;
	MOVLW       _redirURL+0
	MOVWF       FARG_HTTP_redirect_url+0 
	MOVLW       hi_addr(_redirURL+0)
	MOVWF       FARG_HTTP_redirect_url+1 
	CALL        _HTTP_redirect+0, 0
	MOVF        R0, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+0 
	MOVF        R1, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+1 
;Basic_Realm.c,208 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP6
L_SPI_Ethernet_UserTCP5:
;Basic_Realm.c,212 :: 		len = HTTP_html(privateHTML) ;
	MOVLW       _privateHTML+0
	MOVWF       FARG_HTTP_html_html+0 
	MOVLW       hi_addr(_privateHTML+0)
	MOVWF       FARG_HTTP_html_html+1 
	MOVLW       higher_addr(_privateHTML+0)
	MOVWF       FARG_HTTP_html_html+2 
	CALL        _HTTP_html+0, 0
	MOVF        R0, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+0 
	MOVF        R1, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+1 
;Basic_Realm.c,213 :: 		}
L_SPI_Ethernet_UserTCP6:
;Basic_Realm.c,214 :: 		}
L_SPI_Ethernet_UserTCP4:
;Basic_Realm.c,215 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP7
L_SPI_Ethernet_UserTCP2:
;Basic_Realm.c,216 :: 		else if(memcmp(http_request, path_stop, strlen(path_stop)) == 0)        // is 'stop' image requested ?
	MOVLW       _path_stop+0
	MOVWF       FARG_strlen_s+0 
	MOVLW       hi_addr(_path_stop+0)
	MOVWF       FARG_strlen_s+1 
	CALL        _strlen+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_memcmp_n+0 
	MOVF        R1, 0 
	MOVWF       FARG_memcmp_n+1 
	MOVLW       _http_request+0
	MOVWF       FARG_memcmp_s1+0 
	MOVLW       hi_addr(_http_request+0)
	MOVWF       FARG_memcmp_s1+1 
	MOVLW       _path_stop+0
	MOVWF       FARG_memcmp_s2+0 
	MOVLW       hi_addr(_path_stop+0)
	MOVWF       FARG_memcmp_s2+1 
	CALL        _memcmp+0, 0
	MOVLW       0
	XORWF       R1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP20
	MOVLW       0
	XORWF       R0, 0 
L__SPI_Ethernet_UserTCP20:
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP8
;Basic_Realm.c,219 :: 		len = HTTP_imageGIF(dump_stop_GIF, DUMP_STOP_GIF_SIZE) ;
	MOVLW       _dump_stop_GIF+0
	MOVWF       FARG_HTTP_imageGIF_img+0 
	MOVLW       hi_addr(_dump_stop_GIF+0)
	MOVWF       FARG_HTTP_imageGIF_img+1 
	MOVLW       higher_addr(_dump_stop_GIF+0)
	MOVWF       FARG_HTTP_imageGIF_img+2 
	MOVLW       103
	MOVWF       FARG_HTTP_imageGIF_l+0 
	MOVLW       4
	MOVWF       FARG_HTTP_imageGIF_l+1 
	CALL        _HTTP_imageGIF+0, 0
	MOVF        R0, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+0 
	MOVF        R1, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+1 
;Basic_Realm.c,220 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP9
L_SPI_Ethernet_UserTCP8:
;Basic_Realm.c,221 :: 		else if(memcmp(http_request, path_good, strlen(path_good)) == 0)        // is 'good' image requested ?
	MOVLW       _path_good+0
	MOVWF       FARG_strlen_s+0 
	MOVLW       hi_addr(_path_good+0)
	MOVWF       FARG_strlen_s+1 
	CALL        _strlen+0, 0
	MOVF        R0, 0 
	MOVWF       FARG_memcmp_n+0 
	MOVF        R1, 0 
	MOVWF       FARG_memcmp_n+1 
	MOVLW       _http_request+0
	MOVWF       FARG_memcmp_s1+0 
	MOVLW       hi_addr(_http_request+0)
	MOVWF       FARG_memcmp_s1+1 
	MOVLW       _path_good+0
	MOVWF       FARG_memcmp_s2+0 
	MOVLW       hi_addr(_path_good+0)
	MOVWF       FARG_memcmp_s2+1 
	CALL        _memcmp+0, 0
	MOVLW       0
	XORWF       R1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP21
	MOVLW       0
	XORWF       R0, 0 
L__SPI_Ethernet_UserTCP21:
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP10
;Basic_Realm.c,224 :: 		len = HTTP_imageGIF(dump_good_GIF, DUMP_GOOD_GIF_SIZE) ;
	MOVLW       _dump_good_GIF+0
	MOVWF       FARG_HTTP_imageGIF_img+0 
	MOVLW       hi_addr(_dump_good_GIF+0)
	MOVWF       FARG_HTTP_imageGIF_img+1 
	MOVLW       higher_addr(_dump_good_GIF+0)
	MOVWF       FARG_HTTP_imageGIF_img+2 
	MOVLW       230
	MOVWF       FARG_HTTP_imageGIF_l+0 
	MOVLW       3
	MOVWF       FARG_HTTP_imageGIF_l+1 
	CALL        _HTTP_imageGIF+0, 0
	MOVF        R0, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+0 
	MOVF        R1, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+1 
;Basic_Realm.c,225 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP11
L_SPI_Ethernet_UserTCP10:
;Basic_Realm.c,226 :: 		else if(memcmp(http_request, "/", 1) == 0)                              // is home page requested ?
	MOVLW       _http_request+0
	MOVWF       FARG_memcmp_s1+0 
	MOVLW       hi_addr(_http_request+0)
	MOVWF       FARG_memcmp_s1+1 
	MOVLW       ?lstr4_Basic_Realm+0
	MOVWF       FARG_memcmp_s2+0 
	MOVLW       hi_addr(?lstr4_Basic_Realm+0)
	MOVWF       FARG_memcmp_s2+1 
	MOVLW       1
	MOVWF       FARG_memcmp_n+0 
	MOVLW       0
	MOVWF       FARG_memcmp_n+1 
	CALL        _memcmp+0, 0
	MOVLW       0
	XORWF       R1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__SPI_Ethernet_UserTCP22
	MOVLW       0
	XORWF       R0, 0 
L__SPI_Ethernet_UserTCP22:
	BTFSS       STATUS+0, 2 
	GOTO        L_SPI_Ethernet_UserTCP12
;Basic_Realm.c,229 :: 		len = HTTP_html(publicHTML) ;
	MOVLW       _publicHTML+0
	MOVWF       FARG_HTTP_html_html+0 
	MOVLW       hi_addr(_publicHTML+0)
	MOVWF       FARG_HTTP_html_html+1 
	MOVLW       higher_addr(_publicHTML+0)
	MOVWF       FARG_HTTP_html_html+2 
	CALL        _HTTP_html+0, 0
	MOVF        R0, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+0 
	MOVF        R1, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+1 
;Basic_Realm.c,230 :: 		}
	GOTO        L_SPI_Ethernet_UserTCP13
L_SPI_Ethernet_UserTCP12:
;Basic_Realm.c,234 :: 		len = HTTP_error() ;
	CALL        _HTTP_error+0, 0
	MOVF        R0, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+0 
	MOVF        R1, 0 
	MOVWF       SPI_Ethernet_UserTCP_len_L0+1 
;Basic_Realm.c,235 :: 		}
L_SPI_Ethernet_UserTCP13:
L_SPI_Ethernet_UserTCP11:
L_SPI_Ethernet_UserTCP9:
L_SPI_Ethernet_UserTCP7:
;Basic_Realm.c,237 :: 		return(len) ;   // return reply buffer length to library
	MOVF        SPI_Ethernet_UserTCP_len_L0+0, 0 
	MOVWF       R0 
	MOVF        SPI_Ethernet_UserTCP_len_L0+1, 0 
	MOVWF       R1 
;Basic_Realm.c,238 :: 		}
	RETURN      0
; end of _SPI_Ethernet_UserTCP

_main:

;Basic_Realm.c,243 :: 		void    main()
;Basic_Realm.c,245 :: 		ADCON1 |= 0x0F;                  // Configure AN pins as digital
	MOVLW       15
	IORWF       ADCON1+0, 1 
;Basic_Realm.c,246 :: 		CMCON  |= 7;                     // Turn off comparators
	MOVLW       7
	IORWF       CMCON+0, 1 
;Basic_Realm.c,248 :: 		SPI1_Init() ;    // init SPI communication with ethernet board
	CALL        _SPI1_Init+0, 0
;Basic_Realm.c,249 :: 		SPI_Rd_Ptr = SPI1_Read;
	MOVLW       _SPI1_Read+0
	MOVWF       _SPI_Rd_Ptr+0 
	MOVLW       hi_addr(_SPI1_Read+0)
	MOVWF       _SPI_Rd_Ptr+1 
	MOVLW       FARG_SPI1_Read_buffer+0
	MOVWF       _SPI_Rd_Ptr+2 
	MOVLW       hi_addr(FARG_SPI1_Read_buffer+0)
	MOVWF       _SPI_Rd_Ptr+3 
;Basic_Realm.c,250 :: 		SPI_Ethernet_Init(myMacAddr, myIpAddr, 1) ; // init ethernet board
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
;Basic_Realm.c,253 :: 		SPI_Ethernet_confNetwork(ipMask, gwIpAddr, dnsIpAddr) ;
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
;Basic_Realm.c,255 :: 		for(;;)         // forever
L_main14:
;Basic_Realm.c,260 :: 		SPI_Ethernet_doPacket() ;   // process incoming Ethernet packets and do services
	CALL        _SPI_Ethernet_doPacket+0, 0
;Basic_Realm.c,261 :: 		}
	GOTO        L_main14
;Basic_Realm.c,262 :: 		}
	GOTO        $+0
; end of _main
