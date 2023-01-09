#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include "DemoFiles.h" 

/********************************************************************
函数功能: 读文件
输入参数: pszFile           文件名
          puiLen            期望读取的长度
          uiStart           起始地址
输出参数: phexOut           读出的数据
          puiLen            实际长度
返 回 值: SDK_OK            成功
          SDK_ESC           失败
          SDK_PARAMERR      参数错误
修改信息: 2013-12-30  罗成  创建
********************************************************************/
s32 FileRead(u8 *pszFile, u8 *phexOut, u32 uiStart, u32 *puiLen)
{

    u32 uiLen=0;
    FILE *fp;
    s32 iRet;

    if((pszFile == NULL)||(phexOut == NULL)||(puiLen == NULL))
    {
        return SDK_PARAMERR;
    }

    fp = fopen((s8*)pszFile, "rb");//rb 只读打开一个二进制文件，允许读写数据，文件必须存在。
    if (fp == NULL)
    {
        return SDK_ESC;
    }


    iRet = fseek(fp, uiStart, SEEK_SET);
    if(iRet < 0)
    {
        fclose(fp);
        return SDK_ESC;
    }

    uiLen = *puiLen;
    iRet = fread(phexOut,1,uiLen,fp);
    fclose(fp);
    if(iRet < 0)
        return SDK_ESC;

    *puiLen = (u32)iRet;
    return SDK_OK;

}

/********************************************************************
函数功能: 写文件,从0地址开始写
输入参数: pszFile           文件名
          phexIn            待写入的数据
          uiLen             待写入的数据长
输出参数: 无
返 回 值: SDK_OK            成功
          SDK_ESC           失败
          SDK_PARAMERR      参数错误
修改信息: 2013-12-30    创建
********************************************************************/
s32 FileWrite(u8 *pszFile, u8 *phexIn, u32 uiLen)
{
    FILE *fp;
    s32 iRet;

    if((pszFile == NULL)||(phexIn == NULL))
    {
        return SDK_PARAMERR;
    }

    //w+ 打开可读写文件，若文件存在则文件长度清为零，即该文件内容会消失。若文件不存在则建立该文件。
    fp = fopen((s8*)pszFile, "wb+");//wb+ 读写打开或建立一个二进制文件，允许读和写。
    if (fp == NULL)
    {
        return SDK_ESC;
    }

    iRet = fwrite(phexIn,1,uiLen,fp);
    fclose(fp);
    if(iRet < 0)
    {
        return SDK_ESC;
    }

    return SDK_OK;

}

/********************************************************************
函数功能: 追加文件
输入参数: pszFile           文件名
          phexIn            待写入的数据
          uiLen             待写入的数据长
输出参数: 无
返 回 值: SDK_OK            成功
          SDK_ESC           失败
          SDK_PARAMERR      参数错误
修改信息: 2013-12-30  罗成  创建
********************************************************************/
s32 FileAppend(u8 *pszFile, u8 *phexIn, u32 uiLen)
{

    FILE *fp;
    s32 iRet;

    if((pszFile == NULL)||(phexIn == NULL))
    {
        return SDK_PARAMERR;
    }

    //a+ 以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。
    fp = fopen((s8*)pszFile, "ab+");//ab+ 读写打开一个二进制文件，允许读或在文件末追加数据。
    if (fp == NULL)
    {
        return SDK_ESC;
    }

    iRet = fwrite(phexIn,1,uiLen,fp);
    fclose(fp);
    if(iRet < 0)
    {
        return SDK_ESC;
    }

    return SDK_OK;

}

/********************************************************************
函数功能: 修改文件
输入参数: pszFile           文件名
          phexIn            待修改数据
          uiStart           修改位置
          uiLen             待修改数据长度
输出参数: 无
返 回 值: SDK_OK            成功
          SDK_ESC           失败
          SDK_PARAMERR      参数错误
修改信息: 2013-12-30  罗成  创建
********************************************************************/
s32 FileInsert(u8 *pszFile, u8 *phexIn, u32 uiStart, u32 uiLen)
{

    FILE *fp;
    s32 iRet;

    if((pszFile == NULL)||(phexIn == NULL))
    {
        return SDK_PARAMERR;
    }

    fp = fopen((s8*)pszFile, "rb+");//读写打开一个二进制文件，只允许读写数据，文件必须存在。
    if (fp == NULL)
    {
        return SDK_ESC;
    }


    iRet = fseek(fp, uiStart, SEEK_SET);
    if(iRet < 0)
    {
        fclose(fp);
        return SDK_ESC;
    }


    iRet = fwrite(phexIn,1,uiLen,fp);
    fclose(fp);
    if(iRet < 0)
    {
        return SDK_ESC;
    }

    return SDK_OK;

}

/********************************************************************
函数功能: 删除文件
输入参数: pszFile           文件名
输出参数: 无
返 回 值: 无
修改信息: 2013-12-30  罗成  创建
********************************************************************/
s32 FileDel(u8 *pszFile)
{
    s32 iRet;

    if(pszFile == NULL)
    {
        return SDK_PARAMERR;
    }

	iRet = remove((s8*)pszFile);
	if(iRet)
	{
		return SDK_ESC; //删除文件失败
	}
    return SDK_OK;
}

/********************************************************************
函数功能: 获取文件大小
输入参数: pszFile           文件名
输出参数: u32               文件大小
返 回 值: SDK_OK            成功
          SDK_ESC           失败
          SDK_PARAMERR      参数错误
修改信息: 2013-12-30  罗成  创建
********************************************************************/
s32 FileGetSize(u8 *pszFile)
{

    FILE *fp;
    s32 iRet;
    s32 size;

    if(pszFile == NULL)
    {
        return SDK_PARAMERR;
    }

    fp = fopen((s8*)pszFile, "rb");
    if (fp == NULL)
    {
        return SDK_ESC;
    }

    iRet = fseek(fp,0L,SEEK_END);
    if(iRet < 0)
    {
        fclose(fp);
        return SDK_ESC;
    }

    size = ftell(fp);
    fclose(fp);

    return size;

}


