// list2.h
// 2019/07/08 16:06

#include <iostream>
using namespace std;

#define numof(array)  (sizeof (array) / sizeof *(array))

// �F��ێ����郊�X�g�̗v�f
struct SColor
{
	int     color;  // �F
	SColor* pNext;  // ���̗v�f�ւ̃|�C���^
};

#ifdef MAIN

// �F��\0��������
//static const char g_asColor[][3] = {
char g_asColor[][3] = {
	"��", "�~", "��", "��", "��", "��", "��",
};

// �F�̏���A�����l
//const int COL_FIRST = 0;
//const int COL_LAST  = numof(g_asColor) - 1;
int COL_FIRST = 0;
int COL_LAST  = numof(g_asColor) - 1;

// �ŏ��̗v�f�̃A�h���X��ێ�������ʂȗv�f
//static SColor g_ColFirst = { 0, NULL };
SColor g_ColFirst = { 0, NULL };

extern bool InsertColor();
extern void Release();
extern bool Input();
extern void DispColors();
extern void for_gdb_debug();

#else
extern char g_asColor[][3];
extern int COL_FIRST;
extern int COL_LAST;
extern SColor g_ColFirst;

#endif


