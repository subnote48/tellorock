
#include "FontHelper.h"

FontHelper::FontHelper(HWND hwnd) : _hwnd(hwnd)
{
	_font = this;
}

FontHelper& FontHelper::Get()
{
	return *_font;
}

HWND FontHelper::GetMainHwnd() const
{
	return _hwnd;
}