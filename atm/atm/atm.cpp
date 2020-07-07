/******************************************************/
/* ATMシステムメインプログラム(入力と出力)            */
/******************************************************/

#include "atm.h"
#include <stdio.h>
#include <Windows.h>

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
	char section[CHARBUFF];
	sprintf_s(section, CHARBUFF, "user");
	char keyWord[CHARBUFF];
	sprintf_s(keyWord, CHARBUFF, "PIN");
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, CHARBUFF, "%setting.ini", currentDirectory);

	//暗証番号の読み込み
	if (GetPrivateProfilrString(section, keyWord, "none", user.PIN, CHARBUFF, settingFile) == 0) {
		//読み込みエラー
		fprintf_s(stderr, "fileld to read PIN");
		return -1;
	}
	// 口座残高の読み込み
	sprintf_s(keyWord, CHARBUFF, "Money");
	if (GetPrivateProfilesString(section, keyWord, "none", buf, CHARBUFF, settingFile) == 0) {
		//読み込みエラー
		fprintf_s(stderr, "fileld to read Money")
		return -1;
	}
	user.Money = strtoull(buf, NULL, 10);

	//メイン画面の表示
	mainScreen(fp, &user);

	// 口座残高をiniファイルに書き込み
	sprintf_s(buf, ChARBUFF, "%llu".user.Money);
	sprintf_s(keyWorf, CHARBUFF, "Money");
	WritePrivateProfileString(section, keyWord, buf, settingFile);

	// 口座残高をresult.txtに書き込み
	sprint_s(fp, "end of transaction : money=%llu\n", user.Money);
	// ファイルクローズ
	fclose(fp);
	return 0;



}