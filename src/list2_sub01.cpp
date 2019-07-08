//list2_sub01.cpp
// 2019/07/08 16:06

#include "list2.h"

#include <iostream>
using namespace std;

// index �Ŏ����ʒu�ɐF��}��
bool InsertColor(int index, int color)
{
    SColor* pNew = new SColor;  // ���I�ɗv�f���m�ۂ���
    if(pNew == NULL)
        return false;
    pNew->color = color;

    SColor* pOld;  // �v�f��}������ʒu
    int     i;

    // index �̈ʒu�ɗ��邩�A�Ō�ɗ��邩������A�����֑}�����܂�
    // ������Â炯��΂O�`�Q�̗v�f�ōl���Ă݂ĉ�����
    for(i = 0, pOld = &g_ColFirst; i < index && pOld->pNext != NULL; i++)
    {
        pOld = pOld->pNext;
    }

    // �}��
    pNew->pNext = pOld->pNext;
    pOld->pNext = pNew;

    return true;
}

// ���X�g�����
void Release(void)
{
    SColor* pDel = g_ColFirst.pNext;

    while(pDel != NULL)
    {
        // delete �������Ƃ� pDel->pNext ���擾���Ă͂����܂���
        SColor* pNext = pDel->pNext;
        delete pDel;
        pDel = pNext;
    }
    g_ColFirst.pNext = NULL;
}

// ���͂Ƒ}��
bool Input(void)
{
    int index;
    int color;

    cout << "�L���H�i�O�P�Q�R�S�T�U�����~�����������j> " << flush;
//  cout << "�L���H�i�O�P�Q�R�S�T�U�����~�����������j> " << endl;
/*�uflush�v�����s�͂����A�o�b�t�@�[���t���b�V������
  �uendl�v�����s������ŁA�o�b�t�@�[���t���b�V������
*/
    cin >> color;
    if(color < COL_FIRST || COL_LAST < color)
        return false;

    cout << "���Ԗڂɑ}������H > " << flush;
//  cout << "���Ԗڂɑ}������H > " << endl;
    cin >> index;
    if(index < 0)
        return false;

    // �F��}��
    if(!InsertColor(index, color))
        return false;
    return true;
}

// ���X�g�̓��e��\��
void DispColors(void)
{
    SColor* pColor = g_ColFirst.pNext;

    while(pColor != NULL)
    {
        cout << "�L���F" << g_asColor[pColor->color]
             << " , �A�h���X�F" << pColor << endl;
        pColor = pColor->pNext;
    }
}

