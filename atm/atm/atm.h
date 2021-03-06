/******************************************************/
/* ATMシステム用ヘッダファイル                        */
/******************************************************/
#pragma once

#include <stdio.h>

// 文字列長
#define CHARBUFF 124

// iniファイルから読み込んだユーザ情報の構造体宣言
typedef struct user
{
	char PIN[CHARBUFF];			// 暗証番号
	unsigned long long Money;	// 口座残高
} USER;

// 関数定義
unsigned char checkPIN(USER* user);
unsigned char withdrawal(FILE* fp, USER* user);
unsigned char payment(FILE* fp, USER* user);
unsigned char balanceInquiry(USER* user);
void maintitle();
void mainScreen(FILE* fp, USER* user);
void getGurrentDirectory(char* currentDirectory);
