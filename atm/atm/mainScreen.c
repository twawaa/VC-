/******************************************************/
/* ATM�V�X�e�����C����ʐ���p�v���O����              */
/******************************************************/
#include "atm.h"
#include <stdio.h>
#include <Windows.h>

// ���C����ʕ\��
// �߂�l�F�Ȃ�
void maintitle()
{
	// ��ʕ\��
	system("cls");
	printf("****************************************\n");
	printf("*   ��������Ⴂ�܂� ������sATM�ł�   *\n");
	printf("*   ��������e�����I�щ�����           *\n");
	printf("*   1:�����o��                         *\n");
	printf("*   2:���a����                         *\n");
	printf("*   3:�c���Ɖ�                         *\n");
	printf("*   Q:������I��                       *\n");
	printf("****************************************\n");
}

// ���C�����
// �߂�l�F�Ȃ�
void mainScreen(FILE* fp, USER* user)
{
	char buf[CHARBUFF] = { 0 };
	int value = 0;

	while (1) {
		// ���C����ʕ\��
		maintitle();
		// ���͎�t
		fgets(buf, sizeof(buf), stdin);
		if (sscanf_s(buf, "%d", &value) > 0) {
			// ���l�̂Ƃ�
			if (value == 1) {
				// �����o����ʂ֑J��
				if (withdrawal(fp, user) == 0) {
					// ����I��
					break;
				}
			}
			else if (value == 2) {
				// ���a�����ʂ֑J��
				if (payment(fp, user) == 0) {
					// ����I��
					break;
				}
			}
			else if (value == 3) {
				// �c���Ɖ��ʂ֑J��
				if (balanceInquiry(user) == 0) {
					// ����I��
					break;
				}
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
}
