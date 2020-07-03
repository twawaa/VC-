/******************************************************/
/* ATMシステムメインプログラム(入力と出力)            */
/******************************************************/

#include "atm.h"
#include <stdio.h>

/* カレントディレクトリ取得*/
// 戻り値：なし
void getGurrentDirectory(char* currentDirectory)
{
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}



/*メインプログラム*/
int main()
{   
    //ファイルポインタ
    FILE* fp;
    errno_t error;

    //ユーザ情報
    USER user;
    //口座残高保存用
    char buf[CHARBUFF] = {0};

    error = fopen_s(&fp, "Results.txt", "w");
    if (error != 0) {
        //ファイルオープンエラー
        fprintf_s(stderr, "failed to open");
        return -1;
    }

	//カレントディレクトリ
	char currentDirectory[CHARBUFF];
	getGurrentDirectory(currentDirectory);

	// iniファイルから読み込み
	
	
	// 暗証番号の読み込み
	
	// 口座残高の読み込み
	
	// 口座残高をiniファイルに書き込み
	

	// 口座残高をresult.txtに書き込み
	
	// ファイルクローズ
	fclose(fp);
	return 0;



}