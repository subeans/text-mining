// 유니코드 자음, 모음, 초/중/종성 코드 -- UTF-16 BE 출력
//	C> a.exe > output.txt
//		--> output.txt�� �޸��忡�� Ȯ��
#include <stdio.h>

int main() {
	int i; int ch;

	putchar(0xFE); putchar(0xFF);	// BOM code: UTF-16 BE 
	putchar(0xAC); putchar(0x00);	// '가'
	putchar(0xD7); putchar(0xA3);	// '힣'
//	putchar(0x00); putchar('\n');	// LF(줄바꿈 문자)

	ch = 0x3131;	// 자음: 0x3131
	for (i=0; i < 30; i++) {	// 초성 출력
		putchar((ch >> 8) & 0x00FF); putchar(ch & 0x00FF);
		ch ++;
	}

	ch = 0x314F;	// 모음: 0x314F
	for (i=0; i < 21; i++) {	// 초성 출력 
		putchar((ch >> 8) & 0xFF); putchar(ch & 0xFF);
		ch ++;
	}

	ch = 0x11A8;	// 초성: 0x1100, 중성 : 0x1161, 종성: 0x11A8
	for (i=0; i < 27; i++) {	// 종성 출력
		putchar((ch >> 8) & 0xFF); putchar(ch & 0xFF);
		ch ++;
	}

	// <참고> 초성 출력이 안되는 것들이 있음 
	ch = 0x1100;	// 초성: 0x1100, 중성 :0x1161, 종성: 0x11A8
	for (i=0; i < 19; i++) {	// 초성출력
		putchar((ch >> 8) & 0xFF); putchar(ch & 0xFF);
		//putchar(0x00); putchar(0x0a);	// LF(줄바꿈 문자)
		ch ++;
	}

	return 0;
}
