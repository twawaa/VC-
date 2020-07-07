/******************************************************/
/* ATM�V�X�e���p�w�b�_�t�@�C��                        */
/******************************************************/
#pragma once

#include <stdio.h>

#define CHARBUFF 124

//ini�t�@�C�����烆�[�U���\���̐錾
typedef struct user
{
	char PIN[CHARBUFF];//�Ïؔԍ�
	unsigned long long Money;	//�����c��
}USER;

//�֐���`
unsigned char checkPIN(USER* user);
unsigned char withdrawal(FILE* fp, USER* user);
unsigned char payment(FILE* fp, USER* user);
unsigned char balanceInquiry(USER* user);
void maintitle();
void mainScreen(FILE* fp, USER* user);
void getGurrentDirectory(char* currentDirectory);