/******************************************************/
/* ���a�����ʐ���p�v���O����                       */
/******************************************************/
#include "atm.h"
#include <stdio.h>
#include <Windows.h>

// ���a�����ʕ\��
// �߂�l�F1=�a���ꊮ�� / 0=����I��
unsigned char payment(FILE* fp, USER* user)
{
	unsigned char flg = 0;
	char buf[CHARBUFF] = { 0 };
	unsigned long long value = 0;

	// �Ïؔԍ��̓���
	if (checkPIN(user) == 0) {
		// ����I��
		return 0;
	}

	while (flg == 0) {
		// ��ʕ\��
		system("cls");
		printf("****************************************\n");
		printf("*   ���a������                       *\n");
		printf("*   ���a������z����͂��ĉ�����       *\n");
		printf("*   Q:������I��                       *\n");
		printf("****************************************\n");

		// ���͎�t
		fgets(buf, sizeof(buf), stdin);
		if (sscanf_s(buf, "%llu", &value) > 0) {
			// ���������Z
			user->Money += value;
			// ������e���t�@�C���o��
			fprintf_s(fp, "payment : %llu money=%llu\n", value, user->Money);
			// ��ʕ\��
			system("cls");
			printf("****************************************\n");
			printf("*   ���a���ꂪ�������܂���             *\n");
			printf("*   Enter:����                         *\n");
			printf("****************************************\n");
			flg = 1;
			// Enter���͑҂�
			fgets(buf, sizeof(buf), stdin);
		}
		else {
			// ������̂Ƃ�
			if (strncmp(buf, "Q", 1) == 0) {
				// ����I��
				break;
			}
		}
	}
	return flg;
}
