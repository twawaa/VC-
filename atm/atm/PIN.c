/******************************************************/
/* �Ïؔԍ��̔F�ؗp�v���O����                         */
/******************************************************/
#include "atm.h"
#include <stdio.h>
#include <Windows.h>

// �Ïؔԍ��̔F��
// �߂�l�F1=�Ïؔԍ���F�� / 0=����I��
unsigned char checkPIN(USER* user)
{
	unsigned char flg = 0;
	char buf[CHARBUFF] = { 0 };
	unsigned long pin = 0;

	while (flg == 0) {
		// ��ʕ\��
		system("cls");
		printf("****************************************\n");
		printf("*   �Ïؔԍ���4���œ��͂��Ă�������    *\n");
		printf("*   Q:������I��                       *\n");
		printf("****************************************\n");

		fgets(buf, sizeof(buf), stdin);
		if (strncmp(buf, "Q", 1) == 0) {
			// ����I��
			break;
		}
		else if ((strlen(buf) == 5) && (strncmp(buf, user->PIN, 4) == 0)) {
			// ���͂����Ïؔԍ���4�������[�U���ƈ�v�����Ƃ�
			flg = 1;
		}
		else {
			// ���͂����Ïؔԍ������[�U���ƕs��v�̂Ƃ�
			system("cls");
			printf("****************************************\n");
			printf("*   �Ïؔԍ����Ԉ���Ă��܂�           *\n");
			printf("*   Enter:����                         *\n");
			printf("****************************************\n");
			// Enter���͑҂�
			fgets(buf, sizeof(buf), stdin);
		}
	}
	return flg;
}
