/*
 * File:   Util.hpp
 * Author: h3xacod3
 *
 * Created on 28 de Outubro de 2008, 23:46
 */

#ifndef _UTIL_HPP
#define	_UTIL_HPP

#ifdef WIN32
#include <windows.h>
#endif

#include <string>
/**
  Delay e outros
  **/
class Util
{
public:
    static void Delay(int ms)
    {
        #ifdef WIN32
        Sleep(ms);
        #else
        usleep(ms*1000);
        #endif
    }
    static std::string IntToStr(int num)
    {
        //implement
        return "";
    }
    static int StrToInt(const std::string & str)
    {
        return atoi(str.data());
    }
    /*static bool StrCmp(const std::string& str1, const std::string str2)
    {
        if(str1==str2)
            return true;
        return false;
    }*/
    static bool StrCmp(std::string str1, std::string str2)
    {
        if(str1==str2)
            return true;
        return false;
    }
};
/**
  QFOREACH
  **/
template <typename T>
class QForeachContainer {
public:
    inline QForeachContainer(const T& t) : c(t), brk(0), i(c.begin()), e(c.end()) { }
    const T c;
    int brk;
    typename T::const_iterator i, e;
};

#define qforeach(variable, container)                                \
for (QForeachContainer<__typeof__(container)> _container_(container); \
     !_container_.brk && _container_.i != _container_.e;              \
     __extension__  ({ ++_container_.brk; ++_container_.i; }))                       \
    for (variable = *_container_.i;; __extension__ ({--_container_.brk; break;}))

#endif	/* _UTIL_HPP */


