/******************************************************/
/* �c���Ɖ��ʐ���p�v���O����                       */
/******************************************************/
#include "atm.h"
#include <stdio.h>
#include <Windows.h>

// �c���Ɖ��ʕ\��
unsigned char balanceInquiry(USER* user)
{
	unsigned char flg = 0;
	char buf[CHARBUFF] = { 0 };

	while (flg == 0) {
		// ��ʕ\��
		system("cls");
		printf("****************************************\n");
		printf("*   �c���Ɖ���                       *\n");
		printf("*   �����c���͂�����ł�               *\n");
		printf("*   %28llu �~    *\n", user->Money);
		printf("*   Q:������I��                       *\n");
		printf("*   Enter:���C����ʂ�                 *\n");
		printf("****************************************\n");

		// ���͎�t
		fgets(buf, sizeof(buf), stdin);
		if (strncmp(buf, "Q", 1) == 0) {
			// ����I��
			break;
		}
		else {
			// ���C����ʂɖ߂�
			flg = 1;
		}
	}
	return flg;
}
