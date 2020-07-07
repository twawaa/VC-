/******************************************************/
/* 残高照会画面制御用プログラム                       */
/******************************************************/
#include "atm.h"
#include <stdio.h>
#include <Windows.h>

// 残高照会画面表示
unsigned char balanceInquiry(USER* user)
{
	unsigned char flg = 0;
	char buf[CHARBUFF] = { 0 };

	while (flg == 0) {
		// 画面表示
		system("cls");
		printf("****************************************\n");
		printf("*   残高照会画面                       *\n");
		printf("*   口座残高はこちらです               *\n");
		printf("*   %28llu 円    *\n", user->Money);
		printf("*   Q:お取引終了                       *\n");
		printf("*   Enter:メイン画面へ                 *\n");
		printf("****************************************\n");

		// 入力受付
		fgets(buf, sizeof(buf), stdin);
		if (strncmp(buf, "Q", 1) == 0) {
			// 取引終了
			break;
		}
		else {
			// メイン画面に戻る
			flg = 1;
		}
	}
	return flg;
}
