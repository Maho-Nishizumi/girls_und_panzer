//list2_sub01.cpp
// 2019/07/08 16:06

#include "list2.h"

#include <iostream>
using namespace std;

// index で示す位置に色を挿入
bool InsertColor(int index, int color)
{
    SColor* pNew = new SColor;  // 動的に要素を確保する
    if(pNew == NULL)
        return false;
    pNew->color = color;

    SColor* pOld;  // 要素を挿入する位置
    int     i;

    // index の位置に来るか、最後に来るかしたら、そこへ挿入します
    // 分かりづらければ０～２個の要素で考えてみて下さい
    for(i = 0, pOld = &g_ColFirst; i < index && pOld->pNext != NULL; i++)
    {
        pOld = pOld->pNext;
    }

    // 挿入
    pNew->pNext = pOld->pNext;
    pOld->pNext = pNew;

    return true;
}

// リストを解放
void Release(void)
{
    SColor* pDel = g_ColFirst.pNext;

    while(pDel != NULL)
    {
        // delete したあとに pDel->pNext を取得してはいけません
        SColor* pNext = pDel->pNext;
        delete pDel;
        pDel = pNext;
    }
    g_ColFirst.pNext = NULL;
}

// 入力と挿入
bool Input(void)
{
    int index;
    int color;

    cout << "記号？（０１２３４５６→○×△□●▲■）> " << flush;
//  cout << "記号？（０１２３４５６→○×△□●▲■）> " << endl;
/*「flush」＝改行はせず、バッファーをフラッシュする
  「endl」＝改行した上で、バッファーをフラッシュする
*/
    cin >> color;
    if(color < COL_FIRST || COL_LAST < color)
        return false;

    cout << "何番目に挿入する？ > " << flush;
//  cout << "何番目に挿入する？ > " << endl;
    cin >> index;
    if(index < 0)
        return false;

    // 色を挿入
    if(!InsertColor(index, color))
        return false;
    return true;
}

// リストの内容を表示
void DispColors(void)
{
    SColor* pColor = g_ColFirst.pNext;

    while(pColor != NULL)
    {
        cout << "記号：" << g_asColor[pColor->color]
             << " , アドレス：" << pColor << endl;
        pColor = pColor->pNext;
    }
}

