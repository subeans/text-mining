/*
	유니코드 11,172자를 출력하는 프로그램 UTF-16 BE 출력 
*/
#include <stdio.h>

int main() {
	int i, j;
	FILE *fp;

	fp = fopen("output.txt", "wb");

	fprintf(fp, "%c%c", 0xFE, 0xFF);	// BOM 코드 -- Big Endian
	for (i=0xAC00, j=0; j < 11172; i++, j++) {
		//printf("%c%c: 0x%x\n", (i >> 8) & 0xFF, i & 0xFF, i);
		fprintf(fp, "%c%c", (i >> 8) & 0xFF, i & 0xFF);	// 한글 음절 -- 예) '가'
		fprintf(fp, "%c%c", 0x00, ':');
		fprintf(fp, "%c%c", 0x00, ' ');
		fprintf(fp, "%c%c", 0x00, '0');
		fprintf(fp, "%c%c", 0x00, 'x');
			// 여기에 한글 음절의 '유니코드16진수 코드'를 출력하려면 어떻게 해야할까요?
			// 간단하지 않은 이유 : 2바이트씩 맞춰줘야해서 복잡해진다. 
		fprintf(fp, "%c%c", 0x00, 0x0D);	// CR 문자 ( 줄바꿈)
		fprintf(fp, "%c%c", 0x00, 0x0A);	// LF 문자
	}
	fclose(fp);
	puts("File <output.txt> has been created!");
	
	return 0;
}
