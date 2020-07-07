/******************************************************/
/* ATMシステムメイン画面制御用プログラム              */
/******************************************************/
#include "atm.h"
#include <stdio.h>
#include <Windows.h>

// メイン画面表示
// 戻り値：なし
void maintitle()
{
	// 画面表示
	system("cls");
	printf("****************************************\n");
	printf("*   いらっしゃいませ ○○銀行ATMです   *\n");
	printf("*   お取引内容をお選び下さい           *\n");
	printf("*   1:お引出し                         *\n");
	printf("*   2:お預入れ                         *\n");
	printf("*   3:残高照会                         *\n");
	printf("*   Q:お取引終了                       *\n");
	printf("****************************************\n");
}

// メイン画面
// 戻り値：なし
void mainScreen(FILE* fp, USER* user)
{
	char buf[CHARBUFF] = { 0 };
	int value = 0;

	while (1) {
		// メイン画面表示
		maintitle();
		// 入力受付
		fgets(buf, sizeof(buf), stdin);
		if (sscanf_s(buf, "%d", &value) > 0) {
			// 数値のとき
			if (value == 1) {
				// お引出し画面へ遷移
				if (withdrawal(fp, user) == 0) {
					// 取引終了
					break;
				}
			}
			else if (value == 2) {
				// お預入れ画面へ遷移
				if (payment(fp, user) == 0) {
					// 取引終了
					break;
				}
			}
			else if (value == 3) {
				// 残高照会画面へ遷移
				if (balanceInquiry(user) == 0) {
					// 取引終了
					break;
				}
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
}
