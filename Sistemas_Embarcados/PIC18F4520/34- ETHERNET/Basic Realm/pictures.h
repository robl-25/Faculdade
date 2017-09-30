/*
 * file         : pictures.h
 * project      : basicRealm
 * author       : Bruno Gavand
 * compiler     : mikroC V6.2
 * date         : july 1rst 2007
 *
 * description  :
                two GIF images as hexadecimal dump
 *
 * target device :
 *              PIC18 family, should work also on PIC16 with reduced possibilities
 *
 * Licence :
 *      Feel free to use this source code at your own risks.
 *
 * history :
 *      created january 2007
 *
 * see more details on http://www.micro-examples.com/
 */

/*
 * 'stop' image GIF file
 */
#define        DUMP_STOP_GIF_SIZE        1127

const unsigned char dump_stop_GIF[DUMP_STOP_GIF_SIZE] = {
0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x19, 0x00, 0x19, 0x00, 0xf7, 0x00, 0x00, 0x00, 0x00, 0x00,
0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00,
0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0xff,
0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x66, 0x00, 0x00,
0x99, 0x00, 0x00, 0xcc, 0x00, 0x00, 0xff, 0x00, 0x33, 0x00, 0x00, 0x33, 0x33, 0x00, 0x33, 0x66,
0x00, 0x33, 0x99, 0x00, 0x33, 0xcc, 0x00, 0x33, 0xff, 0x00, 0x66, 0x00, 0x00, 0x66, 0x33, 0x00,
0x66, 0x66, 0x00, 0x66, 0x99, 0x00, 0x66, 0xcc, 0x00, 0x66, 0xff, 0x00, 0x99, 0x00, 0x00, 0x99,
0x33, 0x00, 0x99, 0x66, 0x00, 0x99, 0x99, 0x00, 0x99, 0xcc, 0x00, 0x99, 0xff, 0x00, 0xcc, 0x00,
0x00, 0xcc, 0x33, 0x00, 0xcc, 0x66, 0x00, 0xcc, 0x99, 0x00, 0xcc, 0xcc, 0x00, 0xcc, 0xff, 0x00,
0xff, 0x00, 0x00, 0xff, 0x33, 0x00, 0xff, 0x66, 0x00, 0xff, 0x99, 0x00, 0xff, 0xcc, 0x00, 0xff,
0xff, 0x33, 0x00, 0x00, 0x33, 0x00, 0x33, 0x33, 0x00, 0x66, 0x33, 0x00, 0x99, 0x33, 0x00, 0xcc,
0x33, 0x00, 0xff, 0x33, 0x33, 0x00, 0x33, 0x33, 0x33, 0x33, 0x33, 0x66, 0x33, 0x33, 0x99, 0x33,
0x33, 0xcc, 0x33, 0x33, 0xff, 0x33, 0x66, 0x00, 0x33, 0x66, 0x33, 0x33, 0x66, 0x66, 0x33, 0x66,
0x99, 0x33, 0x66, 0xcc, 0x33, 0x66, 0xff, 0x33, 0x99, 0x00, 0x33, 0x99, 0x33, 0x33, 0x99, 0x66,
0x33, 0x99, 0x99, 0x33, 0x99, 0xcc, 0x33, 0x99, 0xff, 0x33, 0xcc, 0x00, 0x33, 0xcc, 0x33, 0x33,
0xcc, 0x66, 0x33, 0xcc, 0x99, 0x33, 0xcc, 0xcc, 0x33, 0xcc, 0xff, 0x33, 0xff, 0x00, 0x33, 0xff,
0x33, 0x33, 0xff, 0x66, 0x33, 0xff, 0x99, 0x33, 0xff, 0xcc, 0x33, 0xff, 0xff, 0x66, 0x00, 0x00,
0x66, 0x00, 0x33, 0x66, 0x00, 0x66, 0x66, 0x00, 0x99, 0x66, 0x00, 0xcc, 0x66, 0x00, 0xff, 0x66,
0x33, 0x00, 0x66, 0x33, 0x33, 0x66, 0x33, 0x66, 0x66, 0x33, 0x99, 0x66, 0x33, 0xcc, 0x66, 0x33,
0xff, 0x66, 0x66, 0x00, 0x66, 0x66, 0x33, 0x66, 0x66, 0x66, 0x66, 0x66, 0x99, 0x66, 0x66, 0xcc,
0x66, 0x66, 0xff, 0x66, 0x99, 0x00, 0x66, 0x99, 0x33, 0x66, 0x99, 0x66, 0x66, 0x99, 0x99, 0x66,
0x99, 0xcc, 0x66, 0x99, 0xff, 0x66, 0xcc, 0x00, 0x66, 0xcc, 0x33, 0x66, 0xcc, 0x66, 0x66, 0xcc,
0x99, 0x66, 0xcc, 0xcc, 0x66, 0xcc, 0xff, 0x66, 0xff, 0x00, 0x66, 0xff, 0x33, 0x66, 0xff, 0x66,
0x66, 0xff, 0x99, 0x66, 0xff, 0xcc, 0x66, 0xff, 0xff, 0x99, 0x00, 0x00, 0x99, 0x00, 0x33, 0x99,
0x00, 0x66, 0x99, 0x00, 0x99, 0x99, 0x00, 0xcc, 0x99, 0x00, 0xff, 0x99, 0x33, 0x00, 0x99, 0x33,
0x33, 0x99, 0x33, 0x66, 0x99, 0x33, 0x99, 0x99, 0x33, 0xcc, 0x99, 0x33, 0xff, 0x99, 0x66, 0x00,
0x99, 0x66, 0x33, 0x99, 0x66, 0x66, 0x99, 0x66, 0x99, 0x99, 0x66, 0xcc, 0x99, 0x66, 0xff, 0x99,
0x99, 0x00, 0x99, 0x99, 0x33, 0x99, 0x99, 0x66, 0x99, 0x99, 0x99, 0x99, 0x99, 0xcc, 0x99, 0x99,
0xff, 0x99, 0xcc, 0x00, 0x99, 0xcc, 0x33, 0x99, 0xcc, 0x66, 0x99, 0xcc, 0x99, 0x99, 0xcc, 0xcc,
0x99, 0xcc, 0xff, 0x99, 0xff, 0x00, 0x99, 0xff, 0x33, 0x99, 0xff, 0x66, 0x99, 0xff, 0x99, 0x99,
0xff, 0xcc, 0x99, 0xff, 0xff, 0xcc, 0x00, 0x00, 0xcc, 0x00, 0x33, 0xcc, 0x00, 0x66, 0xcc, 0x00,
0x99, 0xcc, 0x00, 0xcc, 0xcc, 0x00, 0xff, 0xcc, 0x33, 0x00, 0xcc, 0x33, 0x33, 0xcc, 0x33, 0x66,
0xcc, 0x33, 0x99, 0xcc, 0x33, 0xcc, 0xcc, 0x33, 0xff, 0xcc, 0x66, 0x00, 0xcc, 0x66, 0x33, 0xcc,
0x66, 0x66, 0xcc, 0x66, 0x99, 0xcc, 0x66, 0xcc, 0xcc, 0x66, 0xff, 0xcc, 0x99, 0x00, 0xcc, 0x99,
0x33, 0xcc, 0x99, 0x66, 0xcc, 0x99, 0x99, 0xcc, 0x99, 0xcc, 0xcc, 0x99, 0xff, 0xcc, 0xcc, 0x00,
0xcc, 0xcc, 0x33, 0xcc, 0xcc, 0x66, 0xcc, 0xcc, 0x99, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xff, 0xcc,
0xff, 0x00, 0xcc, 0xff, 0x33, 0xcc, 0xff, 0x66, 0xcc, 0xff, 0x99, 0xcc, 0xff, 0xcc, 0xcc, 0xff,
0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0x33, 0xff, 0x00, 0x66, 0xff, 0x00, 0x99, 0xff, 0x00, 0xcc,
0xff, 0x00, 0xff, 0xff, 0x33, 0x00, 0xff, 0x33, 0x33, 0xff, 0x33, 0x66, 0xff, 0x33, 0x99, 0xff,
0x33, 0xcc, 0xff, 0x33, 0xff, 0xff, 0x66, 0x00, 0xff, 0x66, 0x33, 0xff, 0x66, 0x66, 0xff, 0x66,
0x99, 0xff, 0x66, 0xcc, 0xff, 0x66, 0xff, 0xff, 0x99, 0x00, 0xff, 0x99, 0x33, 0xff, 0x99, 0x66,
0xff, 0x99, 0x99, 0xff, 0x99, 0xcc, 0xff, 0x99, 0xff, 0xff, 0xcc, 0x00, 0xff, 0xcc, 0x33, 0xff,
0xcc, 0x66, 0xff, 0xcc, 0x99, 0xff, 0xcc, 0xcc, 0xff, 0xcc, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
0x33, 0xff, 0xff, 0x66, 0xff, 0xff, 0x99, 0xff, 0xff, 0xcc, 0xff, 0xff, 0xff, 0x21, 0xf9, 0x04,
0x01, 0x00, 0x00, 0x10, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x19, 0x00, 0x00, 0x08,
0xff, 0x00, 0xff, 0x09, 0x1c, 0x48, 0xb0, 0xa0, 0xc1, 0x83, 0x08, 0x13, 0x2a, 0x44, 0x48, 0xed,
0x5f, 0xc3, 0x85, 0x07, 0xa9, 0xa5, 0x9a, 0xe2, 0xa7, 0x0f, 0xaa, 0x3e, 0x7d, 0xfc, 0x40, 0x1c,
0x28, 0x71, 0x9a, 0x3f, 0x7f, 0xfd, 0xec, 0xf1, 0xb3, 0x27, 0xad, 0x4f, 0xaa, 0x85, 0x1d, 0xa7,
0x80, 0xf4, 0x77, 0x6f, 0xa4, 0xbd, 0x7a, 0xfc, 0xa6, 0xa4, 0x7a, 0x58, 0x90, 0x9a, 0x1f, 0x8a,
0x1e, 0xa7, 0x4c, 0x9b, 0xd6, 0x8f, 0xdf, 0xc8, 0x98, 0xfc, 0x96, 0x9d, 0x24, 0x48, 0x6d, 0xca,
0x14, 0x54, 0xd3, 0x28, 0x2a, 0x6d, 0x86, 0x4a, 0x9a, 0x34, 0x7b, 0xa1, 0x98, 0x45, 0xb3, 0x77,
0x8a, 0x26, 0xb5, 0x3e, 0xfd, 0xa6, 0xf4, 0xeb, 0xe7, 0x47, 0x5a, 0xd2, 0xa4, 0xd2, 0x50, 0xf5,
0x3b, 0x25, 0xf0, 0xa9, 0x3d, 0x8d, 0x02, 0xa7, 0x48, 0xcb, 0xba, 0x56, 0xab, 0x34, 0xa3, 0x61,
0x99, 0x39, 0x45, 0x41, 0xed, 0x94, 0xbd, 0x68, 0x55, 0x05, 0x76, 0xcd, 0xba, 0x75, 0x2f, 0x45,
0x54, 0x15, 0x9d, 0x4e, 0x61, 0x36, 0xed, 0x69, 0xde, 0x7f, 0x5a, 0x63, 0xb6, 0xe5, 0x97, 0x35,
0xe3, 0xb4, 0x89, 0xcc, 0x4e, 0x49, 0x9b, 0x3a, 0xf9, 0xa1, 0xdf, 0xbe, 0x6b, 0x2d, 0xf6, 0xf3,
0x87, 0xaa, 0xb3, 0x5c, 0x97, 0x87, 0xa7, 0x8c, 0x8c, 0x36, 0x75, 0xaa, 0x3d, 0x7b, 0x9b, 0xa7,
0xf5, 0x39, 0xc5, 0x6c, 0xd9, 0xe9, 0xbb, 0x87, 0xfd, 0xec, 0xe3, 0x07, 0xd3, 0x27, 0xea, 0xd4,
0x7e, 0x9a, 0x4a, 0xe3, 0xf7, 0x8f, 0x24, 0xbf, 0x3e, 0x03, 0xa7, 0x44, 0xab, 0x47, 0xdc, 0xe7,
0x56, 0x7f, 0xaa, 0xef, 0x84, 0xb2, 0x43, 0xcc, 0xde, 0xb2, 0xa9, 0x42, 0x07, 0xfa, 0x89, 0x46,
0xdb, 0xf8, 0xe6, 0xad, 0x7d, 0x22, 0x3f, 0x75, 0x59, 0xcf, 0x0f, 0x4d, 0x3f, 0xa7, 0x66, 0xc3,
0x44, 0xbc, 0xde, 0xaf, 0xb3, 0x9d, 0x50, 0xbb, 0x49, 0x76, 0x1f, 0x2a, 0xf0, 0xaa, 0x75, 0x90,
0x7d, 0x9b, 0xa2, 0xfa, 0x59, 0x4f, 0x14, 0xfb, 0x81, 0xa9, 0x4e, 0xf9, 0x84, 0x5f, 0x5e, 0x2d,
0xb3, 0xd3, 0x41, 0xf9, 0x71, 0x1f, 0x47, 0xa9, 0x58, 0x94, 0x51, 0x6e, 0x7f, 0x49, 0x23, 0x57,
0x46, 0x34, 0x45, 0x44, 0xcd, 0x83, 0x10, 0x4a, 0x44, 0x91, 0x77, 0x0d, 0x6e, 0x64, 0xe1, 0x85,
0x18, 0x66, 0x28, 0x50, 0x40, 0x00, 0x3b } ;

/*
 * 'good' image GIF file
 */
#define        DUMP_GOOD_GIF_SIZE        998

const unsigned char dump_good_GIF[DUMP_GOOD_GIF_SIZE] = {
0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x19, 0x00, 0x19, 0x00, 0xf7, 0x00, 0x00, 0x00, 0x00, 0x00,
0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00,
0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0xff,
0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x66, 0x00, 0x00,
0x99, 0x00, 0x00, 0xcc, 0x00, 0x00, 0xff, 0x00, 0x33, 0x00, 0x00, 0x33, 0x33, 0x00, 0x33, 0x66,
0x00, 0x33, 0x99, 0x00, 0x33, 0xcc, 0x00, 0x33, 0xff, 0x00, 0x66, 0x00, 0x00, 0x66, 0x33, 0x00,
0x66, 0x66, 0x00, 0x66, 0x99, 0x00, 0x66, 0xcc, 0x00, 0x66, 0xff, 0x00, 0x99, 0x00, 0x00, 0x99,
0x33, 0x00, 0x99, 0x66, 0x00, 0x99, 0x99, 0x00, 0x99, 0xcc, 0x00, 0x99, 0xff, 0x00, 0xcc, 0x00,
0x00, 0xcc, 0x33, 0x00, 0xcc, 0x66, 0x00, 0xcc, 0x99, 0x00, 0xcc, 0xcc, 0x00, 0xcc, 0xff, 0x00,
0xff, 0x00, 0x00, 0xff, 0x33, 0x00, 0xff, 0x66, 0x00, 0xff, 0x99, 0x00, 0xff, 0xcc, 0x00, 0xff,
0xff, 0x33, 0x00, 0x00, 0x33, 0x00, 0x33, 0x33, 0x00, 0x66, 0x33, 0x00, 0x99, 0x33, 0x00, 0xcc,
0x33, 0x00, 0xff, 0x33, 0x33, 0x00, 0x33, 0x33, 0x33, 0x33, 0x33, 0x66, 0x33, 0x33, 0x99, 0x33,
0x33, 0xcc, 0x33, 0x33, 0xff, 0x33, 0x66, 0x00, 0x33, 0x66, 0x33, 0x33, 0x66, 0x66, 0x33, 0x66,
0x99, 0x33, 0x66, 0xcc, 0x33, 0x66, 0xff, 0x33, 0x99, 0x00, 0x33, 0x99, 0x33, 0x33, 0x99, 0x66,
0x33, 0x99, 0x99, 0x33, 0x99, 0xcc, 0x33, 0x99, 0xff, 0x33, 0xcc, 0x00, 0x33, 0xcc, 0x33, 0x33,
0xcc, 0x66, 0x33, 0xcc, 0x99, 0x33, 0xcc, 0xcc, 0x33, 0xcc, 0xff, 0x33, 0xff, 0x00, 0x33, 0xff,
0x33, 0x33, 0xff, 0x66, 0x33, 0xff, 0x99, 0x33, 0xff, 0xcc, 0x33, 0xff, 0xff, 0x66, 0x00, 0x00,
0x66, 0x00, 0x33, 0x66, 0x00, 0x66, 0x66, 0x00, 0x99, 0x66, 0x00, 0xcc, 0x66, 0x00, 0xff, 0x66,
0x33, 0x00, 0x66, 0x33, 0x33, 0x66, 0x33, 0x66, 0x66, 0x33, 0x99, 0x66, 0x33, 0xcc, 0x66, 0x33,
0xff, 0x66, 0x66, 0x00, 0x66, 0x66, 0x33, 0x66, 0x66, 0x66, 0x66, 0x66, 0x99, 0x66, 0x66, 0xcc,
0x66, 0x66, 0xff, 0x66, 0x99, 0x00, 0x66, 0x99, 0x33, 0x66, 0x99, 0x66, 0x66, 0x99, 0x99, 0x66,
0x99, 0xcc, 0x66, 0x99, 0xff, 0x66, 0xcc, 0x00, 0x66, 0xcc, 0x33, 0x66, 0xcc, 0x66, 0x66, 0xcc,
0x99, 0x66, 0xcc, 0xcc, 0x66, 0xcc, 0xff, 0x66, 0xff, 0x00, 0x66, 0xff, 0x33, 0x66, 0xff, 0x66,
0x66, 0xff, 0x99, 0x66, 0xff, 0xcc, 0x66, 0xff, 0xff, 0x99, 0x00, 0x00, 0x99, 0x00, 0x33, 0x99,
0x00, 0x66, 0x99, 0x00, 0x99, 0x99, 0x00, 0xcc, 0x99, 0x00, 0xff, 0x99, 0x33, 0x00, 0x99, 0x33,
0x33, 0x99, 0x33, 0x66, 0x99, 0x33, 0x99, 0x99, 0x33, 0xcc, 0x99, 0x33, 0xff, 0x99, 0x66, 0x00,
0x99, 0x66, 0x33, 0x99, 0x66, 0x66, 0x99, 0x66, 0x99, 0x99, 0x66, 0xcc, 0x99, 0x66, 0xff, 0x99,
0x99, 0x00, 0x99, 0x99, 0x33, 0x99, 0x99, 0x66, 0x99, 0x99, 0x99, 0x99, 0x99, 0xcc, 0x99, 0x99,
0xff, 0x99, 0xcc, 0x00, 0x99, 0xcc, 0x33, 0x99, 0xcc, 0x66, 0x99, 0xcc, 0x99, 0x99, 0xcc, 0xcc,
0x99, 0xcc, 0xff, 0x99, 0xff, 0x00, 0x99, 0xff, 0x33, 0x99, 0xff, 0x66, 0x99, 0xff, 0x99, 0x99,
0xff, 0xcc, 0x99, 0xff, 0xff, 0xcc, 0x00, 0x00, 0xcc, 0x00, 0x33, 0xcc, 0x00, 0x66, 0xcc, 0x00,
0x99, 0xcc, 0x00, 0xcc, 0xcc, 0x00, 0xff, 0xcc, 0x33, 0x00, 0xcc, 0x33, 0x33, 0xcc, 0x33, 0x66,
0xcc, 0x33, 0x99, 0xcc, 0x33, 0xcc, 0xcc, 0x33, 0xff, 0xcc, 0x66, 0x00, 0xcc, 0x66, 0x33, 0xcc,
0x66, 0x66, 0xcc, 0x66, 0x99, 0xcc, 0x66, 0xcc, 0xcc, 0x66, 0xff, 0xcc, 0x99, 0x00, 0xcc, 0x99,
0x33, 0xcc, 0x99, 0x66, 0xcc, 0x99, 0x99, 0xcc, 0x99, 0xcc, 0xcc, 0x99, 0xff, 0xcc, 0xcc, 0x00,
0xcc, 0xcc, 0x33, 0xcc, 0xcc, 0x66, 0xcc, 0xcc, 0x99, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xff, 0xcc,
0xff, 0x00, 0xcc, 0xff, 0x33, 0xcc, 0xff, 0x66, 0xcc, 0xff, 0x99, 0xcc, 0xff, 0xcc, 0xcc, 0xff,
0xff, 0xff, 0x00, 0x00, 0xff, 0x00, 0x33, 0xff, 0x00, 0x66, 0xff, 0x00, 0x99, 0xff, 0x00, 0xcc,
0xff, 0x00, 0xff, 0xff, 0x33, 0x00, 0xff, 0x33, 0x33, 0xff, 0x33, 0x66, 0xff, 0x33, 0x99, 0xff,
0x33, 0xcc, 0xff, 0x33, 0xff, 0xff, 0x66, 0x00, 0xff, 0x66, 0x33, 0xff, 0x66, 0x66, 0xff, 0x66,
0x99, 0xff, 0x66, 0xcc, 0xff, 0x66, 0xff, 0xff, 0x99, 0x00, 0xff, 0x99, 0x33, 0xff, 0x99, 0x66,
0xff, 0x99, 0x99, 0xff, 0x99, 0xcc, 0xff, 0x99, 0xff, 0xff, 0xcc, 0x00, 0xff, 0xcc, 0x33, 0xff,
0xcc, 0x66, 0xff, 0xcc, 0x99, 0xff, 0xcc, 0xcc, 0xff, 0xcc, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff,
0x33, 0xff, 0xff, 0x66, 0xff, 0xff, 0x99, 0xff, 0xff, 0xcc, 0xff, 0xff, 0xff, 0x21, 0xf9, 0x04,
0x01, 0x00, 0x00, 0x10, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x19, 0x00, 0x00, 0x08,
0xc3, 0x00, 0xff, 0x09, 0x1c, 0x48, 0xb0, 0xa0, 0xc1, 0x83, 0x08, 0x13, 0x2a, 0x4c, 0x18, 0xea,
0x4e, 0xc3, 0x85, 0x09, 0xfb, 0x44, 0xdb, 0x57, 0xaf, 0xde, 0x1d, 0x88, 0x07, 0xfb, 0xec, 0xdb,
0x58, 0x2f, 0x14, 0x46, 0x83, 0xa1, 0xea, 0x51, 0xac, 0x67, 0xe7, 0x63, 0xc1, 0x3b, 0x1b, 0xf7,
0x5d, 0x34, 0x49, 0xb0, 0x8f, 0x48, 0x68, 0x7d, 0x16, 0x86, 0xea, 0xd3, 0x70, 0x66, 0x4d, 0x97,
0x1b, 0x63, 0x46, 0x0c, 0x15, 0x6d, 0xd9, 0xb2, 0x89, 0x22, 0xeb, 0x45, 0x03, 0x4a, 0x32, 0x21,
0x4a, 0x91, 0x29, 0x53, 0x22, 0x1d, 0xb9, 0xd2, 0x60, 0x1f, 0x65, 0x14, 0xa3, 0x06, 0x95, 0xba,
0x4f, 0x99, 0x4e, 0x83, 0x77, 0x7e, 0x46, 0x4d, 0xca, 0xb5, 0xde, 0x32, 0x8f, 0x07, 0x1d, 0x82,
0x0a, 0xc5, 0x73, 0xea, 0x54, 0x68, 0xd1, 0x9a, 0x16, 0x0c, 0xe5, 0xf3, 0x54, 0xb4, 0xa5, 0x49,
0x45, 0x46, 0x03, 0x6b, 0xd0, 0x4e, 0x45, 0xaa, 0x66, 0xf7, 0x41, 0x2b, 0x7a, 0x90, 0xed, 0x5d,
0xae, 0x71, 0xe7, 0x32, 0x04, 0xe5, 0xf3, 0x6e, 0x5e, 0x65, 0x16, 0x8d, 0xce, 0x3d, 0xb5, 0x74,
0xe9, 0x5b, 0xb5, 0x4e, 0xa1, 0xe6, 0x7d, 0xab, 0x2c, 0x9a, 0x55, 0x99, 0x6f, 0xcd, 0x0a, 0x15,
0x4a, 0x57, 0x61, 0x9f, 0xac, 0x95, 0x11, 0x2b, 0xab, 0xc9, 0xd2, 0xa1, 0xe9, 0x87, 0x2c, 0x53,
0xab, 0x3e, 0x18, 0x10, 0x00, 0x3b } ;
