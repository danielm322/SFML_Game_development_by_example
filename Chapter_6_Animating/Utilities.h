//
// Created by daniel on 31/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_UTILITIES_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_UTILITIES_H

#define RUNNING_LINUX
#include <iostream>
#include <string>
#include <algorithm>
namespace Utils{
    #ifdef RUNNING_WINDOWS
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
    #include <Shlwapi.h>
    inline std::string GetWorkingDirectory(){
        HMODULE hModule = GetModuleHandle(nullptr);
        if(hModule){
            char path[256];
            GetModuleFileName(hModule,path,sizeof(path));
            PathRemoveFileSpec(path);
            strcat_s(path,"\\"); // new
            return std::string(path); // new
        }
        return "";
    }
    #elif defined RUNNING_LINUX
    #include <unistd.h>
    inline std::string GetWorkingDirectory(){
        char cwd[1024];
        if(getcwd(cwd, sizeof(cwd)) != nullptr)
        {
            return std::string(cwd) + std::string("/");
        }
    return "";
    }
    #endif
}

#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_UTILITIES_H
