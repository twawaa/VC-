/******************************************************/
/* ATMシステム用ヘッダファイル                        */
/******************************************************/
#pragma once

#include <stdio.h>

#define CHARBUFF 124

//iniファイルからユーザ情報構造体宣言
typedef struct user
{
	char PIN[CHARBUFF];//暗証番号
	unsigned long long Money;	//口座残高
}USER

//関数定義