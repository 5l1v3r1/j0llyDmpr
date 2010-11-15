/**
 *   j0llyDmpr
 *   Copyright (C) 2010 Souchet Axel <0vercl0k@tuxfamily.org>
 *
 *   This file is part of j0llyDmpr.
 *
 *   J0llyDmpr is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   J0llyDmpr is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with J0llyDmpr. If not, see <http://www.gnu.org/licenses/>.
**/
#ifndef _DEBUG_H
#define _DEBUG_H

#include <stdio.h>
#include <windows.h>

extern FILE *fpDbgManager;

#define DbgMSG(...)                      \
{                                        \
    fprintf(fpDbgManager, __VA_ARGS__);  \
    fflush(fpDbgManager);                \
}

#define FILE_LOG "j0llyDmp3r.log"

#define ERRORMSG(...)                    \
{                                        \
    DbgMSG("[ERROR] ");                  \
    DbgMSG(__VA_ARGS__);                 \
    DbgMSG(" -> GetLastError() = %d.\n", GetLastError()); \
}

#define DEBUGMSG(...)             \
{                                 \
    DbgMSG("[DEBUG] ");           \
    DbgMSG(__VA_ARGS__);          \
    fprintf(fpDbgManager, "\n");  \
                                  \
}

#define CloseDbgManager()         \
    fclose(fpDbgManager)

#ifdef DEBUG
    #define TRACEMSG()                       \
    {                                        \
        DbgMSG("[TRACE] %s():%d.\n", __FUNCTION__, __LINE__); \
    }
#else
    #define TRACEMSG(...) /* void */
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* # Initialization of debug-manager */
UCHAR initDbgManager();

#ifdef __cplusplus
}
#endif

#endif
