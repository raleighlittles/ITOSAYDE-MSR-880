/********************************************************************
�ļ��� : sdkFiles.h
��  �� : �ļ����������ӿں���
��  Ȩ :
��  �� : �޳�
�޸ļ�¼:
    ����              �޸���  �޸�����
    2013-12-30 16:19  �޳�  ����
********************************************************************/
#ifndef BASE_SDKFILES_H_
#define BASE_SDKFILES_H_

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef u8
typedef unsigned char u8;
#endif
#ifndef s8
typedef char s8;
#endif
#ifndef u16
typedef unsigned short u16;
#endif
#ifndef s16
typedef short s16;
#endif
#ifndef u32
typedef unsigned int u32;
#endif
#ifndef s32
typedef int s32;
#endif

#define AID_NAME            "AidRec.data"               //IC�������ļ�
#define CAPK_NAME           "CapkRec.data"              //IC����Կ�ļ�

#undef      TRUE
#undef      FALSE
#define     TRUE     1
#define     FALSE    0

#define   SDK_OK     0
#define   SDK_ESC    -1
#define   SDK_ERROR  -2
#define   SDK_PARAMERR -3
#define   SDK_TIMEOUT  -4
#define   SDK_USER_DEFINE -10


s32 FileRead(u8 *pszFile, u8 *phexOut, u32 uiStart, u32 *puiLen);
s32 FileWrite(u8 *pszFile, u8 *phexIn, u32 uiLen);
s32 FileAppend(u8 *pszFile, u8 *phexIn, u32 uiLen);
s32 FileInsert(u8 *pszFile, u8 *phexIn, u32 uiStart, u32 uiLen);
s32 FileDel(u8 *pszFile);
s32 FileGetSize(u8 *pszFile);
s32 FileCreateDir(const u8 *pucPathName);
s32 FileSaftWrite(u8 *pszFile, u8 *phexIn, u32 uiLen);

#ifdef __cplusplus
    }
#endif

#endif

