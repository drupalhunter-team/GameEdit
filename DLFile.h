//
//  DL_File.h
//  SanGuo
//
//  Created by No.1 on 13-1-11.
//
//
#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
//1字节低位和高位交换
#define SWAP_WORD(x) ((x) = (((x) & 0x00FF) << 8) |(((x) & 0xFF00) >> 8))

//4字节低位和高位交换
#define SWAP_DWORD(x) ((x) = (((x) & 0x0000FFFF) << 24) |(((x) & 0x0000FF00) << 8) |(((x) & 0x00FF0000) >> 8)|(((x) & 0xFF000000) >> 24))

FILE* openFile( const char* pathName);
void closeFile( FILE* fp);

char readByte( FILE *fp);
char readBoolean( FILE *fp);
short readShort( FILE *fp);
int readInt( FILE *fp);
void skipBytes( FILE *fp, int len);
void readBytes( char *dst_buf, FILE *fp, int len);
char* readUTF( FILE *fp);
char* readUTFEx( FILE *fp, char* str);
void readUTFForStr( char str[], int str_len,FILE *fp);

void saveInt( int value, FILE *fp);
#endif
