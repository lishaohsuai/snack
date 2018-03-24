#ifndef __WINDOWS_H__
#define __WINDOWS_H__

#include <string>
#include <iostream>
class Windows
{
public:
    Windows();
    ~Windows();
    bool setConfig(int & , int & );
    Windows(int, int);
private:
    int windows_long;
    int windows_width;
};

#endif
