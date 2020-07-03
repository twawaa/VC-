/******************************************************/
/* ATMシステム用ヘッダファイル                        */
/******************************************************/

#pragma once

#define CHARBUFF124

//ユーザ情報構造体宣言
typwdefstruct user
{
	char PIN[CHARBUFF];	//暗証番号
	unsigned long long Money;	//口座残高
}USER

//関数定義