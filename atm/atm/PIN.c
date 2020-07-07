/******************************************************/
/* 暗証番号の認証用プログラム                         */
/******************************************************/
#include "atm.h"
#include <stdio.h>
#include <Windows.h>

// 暗証番号の認証
// 戻り値：1=暗証番号を認証 / 0=取引終了
unsigned char checkPIN(USER* user)
{
	unsigned char flg = 0;
	char buf[CHARBUFF] = { 0 };
	unsigned long pin = 0;

	while (flg == 0) {
		// 画面表示
		system("cls");
		printf("****************************************\n");
		printf("*   暗証番号を4桁で入力してください    *\n");
		printf("*   Q:お取引終了                       *\n");
		printf("****************************************\n");

		fgets(buf, sizeof(buf), stdin);
		if (strncmp(buf, "Q", 1) == 0) {
			// 取引終了
			break;
		}
		else if ((strlen(buf) == 5) && (strncmp(buf, user->PIN, 4) == 0)) {
			// 入力した暗証番号が4桁かつユーザ情報と一致したとき
			flg = 1;
		}
		else {
			// 入力した暗証番号がユーザ情報と不一致のとき
			system("cls");
			printf("****************************************\n");
			printf("*   暗証番号が間違っています           *\n");
			printf("*   Enter:次へ                         *\n");
			printf("****************************************\n");
			// Enter入力待ち
			fgets(buf, sizeof(buf), stdin);
		}
	}
	return flg;
}
