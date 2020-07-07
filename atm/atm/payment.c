/******************************************************/
/* お預入れ画面制御用プログラム                       */
/******************************************************/
#include "atm.h"
#include <stdio.h>
#include <Windows.h>

// お預入れ画面表示
// 戻り値：1=預入れ完了 / 0=取引終了
unsigned char payment(FILE* fp, USER* user)
{
	unsigned char flg = 0;
	char buf[CHARBUFF] = { 0 };
	unsigned long long value = 0;

	// 暗証番号の入力
	if (checkPIN(user) == 0) {
		// 取引終了
		return 0;
	}

	while (flg == 0) {
		// 画面表示
		system("cls");
		printf("****************************************\n");
		printf("*   お預入れ画面                       *\n");
		printf("*   お預入れ金額を入力して下さい       *\n");
		printf("*   Q:お取引終了                       *\n");
		printf("****************************************\n");

		// 入力受付
		fgets(buf, sizeof(buf), stdin);
		if (sscanf_s(buf, "%llu", &value) > 0) {
			// 入金分加算
			user->Money += value;
			// 取引内容をファイル出力
			fprintf_s(fp, "payment : %llu money=%llu\n", value, user->Money);
			// 画面表示
			system("cls");
			printf("****************************************\n");
			printf("*   お預入れが完了しました             *\n");
			printf("*   Enter:次へ                         *\n");
			printf("****************************************\n");
			flg = 1;
			// Enter入力待ち
			fgets(buf, sizeof(buf), stdin);
		}
		else {
			// 文字列のとき
			if (strncmp(buf, "Q", 1) == 0) {
				// 取引終了
				break;
			}
		}
	}
	return flg;
}
