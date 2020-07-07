/******************************************************/
/* ATM�V�X�e�����C���v���O����                        */
/******************************************************/
#include "atm.h"
#include <stdio.h>
#include <Windows.h>

// �J�����g�f�B���N�g���擾
// �߂�l�F�Ȃ�
void getGurrentDirectory(char* currentDirectory)
{
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

// ���C���v���O����
int main(void)
{
	// �t�@�C���|�C���^
	FILE* fp;
	errno_t error;
	// ���[�U���
	USER user;
	// �����c���ۑ��p
	char buf[CHARBUFF] = { 0 };

	error = fopen_s(&fp, "Results.txt", "w");
	if (error != 0) {
		// �t�@�C���I�[�v���G���[
		fprintf_s(stderr, "failed to open");
		return -1;
	}

	// �J�����g�f�B���N�g��
	char currentDirectory[CHARBUFF];
	getGurrentDirectory(currentDirectory);

	// ini�t�@�C������ǂݍ���
	char section[CHARBUFF];
	sprintf_s(section, CHARBUFF, "user");
	char keyWord[CHARBUFF];
	sprintf_s(keyWord, CHARBUFF, "PIN");
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, CHARBUFF, "%s\\setting.ini", currentDirectory);
	// �Ïؔԍ��̓ǂݍ���
	if (GetPrivateProfileString(section, keyWord, "none", user.PIN, CHARBUFF, settingFile) == 0) {
		// �ǂݍ��݃G���[
		fprintf_s(stderr, "failed to read PIN");
		return -1;
	}
	// �����c���̓ǂݍ���
	sprintf_s(keyWord, CHARBUFF, "Money");
	if (GetPrivateProfileString(section, keyWord, "none", buf, CHARBUFF, settingFile) == 0) {
		// �ǂݍ��݃G���[
		fprintf_s(stderr, "failed to read Money");
		return -1;
	}
	user.Money = strtoull(buf, NULL, 10);

	// ���C����ʂ̕\��
	mainScreen(fp, &user);

	// �����c����ini�t�@�C���ɏ�������
	sprintf_s(buf, CHARBUFF, "%llu", user.Money);
	sprintf_s(keyWord, CHARBUFF, "Money");
	WritePrivateProfileString(section, keyWord, buf, settingFile);

	// �����c����result.txt�ɏ�������
	fprintf_s(fp, "end of transaction : money=%llu\n", user.Money);
	// �t�@�C���N���[�Y
	fclose(fp);
	return 0;
}
