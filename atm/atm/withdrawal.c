/******************************************************/
/* �����o����ʐ���p�v���O����                       */
/******************************************************/
#include "atm.h"
#include <stdio.h>
#include <Windows.h>

// �����o�����
// �߂�l�F1=���o������ / 0=����I��
unsigned char withdrawal(FILE* fp, USER* user)
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
		printf("*   �����o�����                       *\n");
		printf("*   �����o�����z����͂��ĉ�����       *\n");
		printf("*   Q:������I��                       *\n");
		printf("****************************************\n");

		// ���͎�t
		fgets(buf, sizeof(buf), stdin);
		if (sscanf_s(buf, "%llu", &value) > 0) {
			// ���l�̂Ƃ�
			if (user->Money < value) {
				// �c���s���̂Ƃ�
				// ��ʕ\��
				system("cls");
				printf("****************************************\n");
				printf("*   �c���s���ł�                       *\n");
				printf("*   Enter:����                         *\n");
				printf("****************************************\n");
				// Enter���͑҂�
				fgets(buf, sizeof(buf), stdin);
			}
			else {
				// �c���ȏ�̂Ƃ��������Ƃ�
				user->Money -= value;
				// ������e���t�@�C���o��
				fprintf_s(fp, "withdrawal : %llu money=%llu\n", value, user->Money);
				// ��ʕ\��
				system("cls");
				printf("****************************************\n");
				printf("*   ���������󂯎�艺����             *\n");
				printf("*   Enter:����                         *\n");
				printf("****************************************\n");
				flg = 1;
				// Enter���͑҂�
				fgets(buf, sizeof(buf), stdin);
			}
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
