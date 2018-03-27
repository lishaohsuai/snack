#include <iostream>
#include <fstream>
#include "json/json.h"
#include <string>
#include <curses.h>
#include "windows/windows.h"
#include "snack/snack.h"

bool readJson(Windows &windows)
{
    std::string filename;
    filename = "./config/config.json";
    std::ifstream in;
    in.open(filename.c_str());
    std::string errs;
    Json::Value jsonRoot;
    Json::CharReaderBuilder builder;
    if (!parseFromStream(builder, in, &jsonRoot, &errs)) //从ifs中读取数据到jsonRoot
    {
        std::cout << "Sorry,read json file failed.Error is " << errs << std::endl;
        return false;
    }
    Json::Value config;
    config = jsonRoot["config"];
    std::cout <<"windows_long : "<< config["windows_long"] << std::endl;
    std::cout <<"windows_width : "<<  config["windows_width"] << std::endl;
    int w_long = config["windows_long"].asInt();
    int w_width = config["windows_width"].asInt();
    windows.setConfig(w_long, w_width);
    return true;
}

void initial()
{
    initscr();
    cbreak();// 一切输入的字符将被一一读取
    nl();// 对应 /n
    noecho();// 不立即显示
    intrflush(stdscr,false);//没什么用
    keypad(stdscr,true);// 系统中定义的 方向按键
    refresh();
}

int main(int argc, char **argv)
{
    Windows windows;
    readJson(windows);
    initial();
    box(stdscr,'|','-');
    move(LINES/2, COLS/2);
    waddstr(stdscr, "Hello, world!");
    attron(A_REVERSE);
}
