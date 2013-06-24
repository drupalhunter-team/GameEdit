#include "DLFile.h"

FILE* openFile( const char* pathName)
{
    return fopen(pathName, "rb+");
}
void closeFile( FILE* fp)
{
    fclose(fp);
}
char readByte( FILE *fp)
{
	char num;
	fread( &num, sizeof(char), 1, fp);
	return num;
}

char readBoolean( FILE *fp)
{
    char num;
    fread( &num, sizeof(char), 1, fp);
	return num;
}
short readShort( FILE *fp)
{
	short num;
	fread( &num, sizeof(short), 1, fp);
	SWAP_WORD(num);
	return num;
}
int readInt( FILE *fp)
{
	int num = 0;
	fread( &num, sizeof(int), 1, fp);
	SWAP_DWORD(num);
	return num;
}
void saveInt( int value, FILE *fp)
{
    SWAP_DWORD(value);
    fwrite( &value, sizeof(int), 1, fp);
}
void skipBytes( FILE *fp, int len)
{
	fseek( fp, len, SEEK_CUR);
}

void readBytes( char *dst_buf, FILE *fp, int len)
{
	fread( dst_buf, len, 1, fp);
}

char* readUTF( FILE *fp)
{
	short len = 0;
	fread( &len, sizeof(short), 1, fp);
	SWAP_WORD(len);
	char* str_buf = (char*)malloc(len+1);
    memset(str_buf, 0, len+1);
	fread( str_buf, len, 1, fp);
	return str_buf;
}

char* readUTFEx( FILE *fp, char* str)
{
    short len = 0;
    fread( &len, sizeof(short), 1, fp);
    SWAP_WORD(len);
    int str_size = len+strlen(str)+1;
    char* str_buf = (char*)malloc(str_size);
    memset(str_buf, 0, str_size);
    fread( str_buf, len, 1, fp);
    strcat( str_buf, str);
    return str_buf;
}
void readUTFForStr( char str[], int str_len,FILE *fp)
{
    short len = 0;
    memset( str, 0, str_len);
    fread( &len, sizeof(short), 1, fp);
    SWAP_WORD(len);

    fread( str, len, 1, fp);
}

