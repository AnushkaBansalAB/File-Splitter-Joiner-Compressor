#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Compress(unsigned char *szOut, const char *szMessage) {
	unsigned long long nBuffer = 0; 
	char nBitsInBuffer = 0;
	while (*szMessage != 0) {
       		nBuffer |= (unsigned long long)(*szMessage++ & 0x7F) << nBitsInBuffer;
		nBitsInBuffer += 7;
		if (nBitsInBuffer == 7 * 8) { 
			while (nBitsInBuffer > 0) {
				*szOut++ = nBuffer & 0xFF;
				nBuffer >>= 8;
				nBitsInBuffer -= 8; }
			nBitsInBuffer = 0;
			nBuffer = 0;  } }
	while (nBitsInBuffer > 0) {
		*szOut++ = nBuffer & 0xFF;
		nBuffer >>= 8;
		nBitsInBuffer -= 8;
	}
}


int main() {

    int  i=0;
    char szMessage[100];  
    FILE *file;  
    file = fopen("file.txt", "r"); 
    while(fgets(szMessage, sizeof szMessage, file)!=NULL) {      
      continue; 
    }
    fclose(file);
    static const unsigned nCompressedSize = sizeof(szMessage) * 7 / 8; 
    unsigned char pCompressedBytes[nCompressedSize];
    char szUncompressed[sizeof(szMessage)];
    printf("\n------------------------File Compression Project------------------------");
    printf("\n");
      Compress(pCompressedBytes, szMessage);
    printf("----------------File Compression-----------------------------------");
for (int nByte = 0; nByte < nCompressedSize; ++nByte) {
    	printf("%02X ", pCompressedBytes[nByte]);
    }
printf("\n");
	printf("File has been compressed to compressed.out file!");
	
	FILE *f = fopen("compressed.out", "wb");
	fwrite(pCompressedBytes, sizeof(char), sizeof(pCompressedBytes), f);
	fclose(f);
	
	
		
	return 0;
}
