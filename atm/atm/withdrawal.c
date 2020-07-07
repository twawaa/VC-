/******************************************************/
/* お引出し画面制御用プログラム                       */
/******************************************************/
#include "atm.h"
#include <stdio.h>
#include <Windows.h>

// お引出し画面
// 戻り値：1=引出し完了 / 0=取引終了
unsigned char withdrawal(FILE* fp, USER* user)
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
		printf("*   お引出し画面                       *\n");
		printf("*   お引出し金額を入力して下さい       *\n");
		printf("*   Q:お取引終了                       *\n");
		printf("****************************************\n");

		// 入力受付
		fgets(buf, sizeof(buf), stdin);
		if (sscanf_s(buf, "%llu", &value) > 0) {
			// 数値のとき
			if (user->Money < value) {
				// 残高不足のとき
				// 画面表示
				system("cls");
				printf("****************************************\n");
				printf("*   残高不足です                       *\n");
				printf("*   Enter:次へ                         *\n");
				printf("****************************************\n");
				// Enter入力待ち
				fgets(buf, sizeof(buf), stdin);
			}
			else {
				// 残高以上のとき引き落とす
				user->Money -= value;
				// 取引内容をファイル出力
				fprintf_s(fp, "withdrawal : %llu money=%llu\n", value, user->Money);
				// 画面表示
				system("cls");
				printf("****************************************\n");
				printf("*   お金をお受け取り下さい             *\n");
				printf("*   Enter:次へ                         *\n");
				printf("****************************************\n");
				flg = 1;
				// Enter入力待ち
				fgets(buf, sizeof(buf), stdin);
			}
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
