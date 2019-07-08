// list2.h
// 2019/07/08 16:06

#include <iostream>
using namespace std;

#define numof(array)  (sizeof (array) / sizeof *(array))

// 色を保持するリストの要素
struct SColor
{
	int     color;  // 色
	SColor* pNext;  // 次の要素へのポインタ
};

#ifdef MAIN

// 色を表0す文字列
//static const char g_asColor[][3] = {
char g_asColor[][3] = {
	"○", "×", "△", "□", "●", "▲", "■",
};

// 色の上限、下限値
//const int COL_FIRST = 0;
//const int COL_LAST  = numof(g_asColor) - 1;
int COL_FIRST = 0;
int COL_LAST  = numof(g_asColor) - 1;

// 最初の要素のアドレスを保持する特別な要素
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


