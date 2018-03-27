
#include "windows.h"

Windows::Windows(int w_long, int w_width):
    windows_long(w_long),
    windows_width(w_width)
{}

Windows::~Windows()
{}

Windows::Windows()
{}

bool Windows::setConfig(int & w_long, int & w_width)
{
    windows_width = w_width;
    windows_long = w_long;
}
