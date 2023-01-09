#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include "DemoFiles.h" 

/********************************************************************
��������: ���ļ�
�������: pszFile           �ļ���
          puiLen            ������ȡ�ĳ���
          uiStart           ��ʼ��ַ
�������: phexOut           ����������
          puiLen            ʵ�ʳ���
�� �� ֵ: SDK_OK            �ɹ�
          SDK_ESC           ʧ��
          SDK_PARAMERR      ��������
�޸���Ϣ: 2013-12-30  �޳�  ����
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

    fp = fopen((s8*)pszFile, "rb");//rb ֻ����һ���������ļ��������д���ݣ��ļ�������ڡ�
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
��������: д�ļ�,��0��ַ��ʼд
�������: pszFile           �ļ���
          phexIn            ��д�������
          uiLen             ��д������ݳ�
�������: ��
�� �� ֵ: SDK_OK            �ɹ�
          SDK_ESC           ʧ��
          SDK_PARAMERR      ��������
�޸���Ϣ: 2013-12-30    ����
********************************************************************/
s32 FileWrite(u8 *pszFile, u8 *phexIn, u32 uiLen)
{
    FILE *fp;
    s32 iRet;

    if((pszFile == NULL)||(phexIn == NULL))
    {
        return SDK_PARAMERR;
    }

    //w+ �򿪿ɶ�д�ļ������ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ��������������ļ���
    fp = fopen((s8*)pszFile, "wb+");//wb+ ��д�򿪻���һ���������ļ����������д��
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
��������: ׷���ļ�
�������: pszFile           �ļ���
          phexIn            ��д�������
          uiLen             ��д������ݳ�
�������: ��
�� �� ֵ: SDK_OK            �ɹ�
          SDK_ESC           ʧ��
          SDK_PARAMERR      ��������
�޸���Ϣ: 2013-12-30  �޳�  ����
********************************************************************/
s32 FileAppend(u8 *pszFile, u8 *phexIn, u32 uiLen)
{

    FILE *fp;
    s32 iRet;

    if((pszFile == NULL)||(phexIn == NULL))
    {
        return SDK_PARAMERR;
    }

    //a+ �Ը��ӷ�ʽ�򿪿ɶ�д���ļ������ļ������ڣ���Ὠ�����ļ�������ļ����ڣ�д������ݻᱻ�ӵ��ļ�β�󣬼��ļ�ԭ�ȵ����ݻᱻ������
    fp = fopen((s8*)pszFile, "ab+");//ab+ ��д��һ���������ļ�������������ļ�ĩ׷�����ݡ�
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
��������: �޸��ļ�
�������: pszFile           �ļ���
          phexIn            ���޸�����
          uiStart           �޸�λ��
          uiLen             ���޸����ݳ���
�������: ��
�� �� ֵ: SDK_OK            �ɹ�
          SDK_ESC           ʧ��
          SDK_PARAMERR      ��������
�޸���Ϣ: 2013-12-30  �޳�  ����
********************************************************************/
s32 FileInsert(u8 *pszFile, u8 *phexIn, u32 uiStart, u32 uiLen)
{

    FILE *fp;
    s32 iRet;

    if((pszFile == NULL)||(phexIn == NULL))
    {
        return SDK_PARAMERR;
    }

    fp = fopen((s8*)pszFile, "rb+");//��д��һ���������ļ���ֻ�����д���ݣ��ļ�������ڡ�
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
��������: ɾ���ļ�
�������: pszFile           �ļ���
�������: ��
�� �� ֵ: ��
�޸���Ϣ: 2013-12-30  �޳�  ����
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
		return SDK_ESC; //ɾ���ļ�ʧ��
	}
    return SDK_OK;
}

/********************************************************************
��������: ��ȡ�ļ���С
�������: pszFile           �ļ���
�������: u32               �ļ���С
�� �� ֵ: SDK_OK            �ɹ�
          SDK_ESC           ʧ��
          SDK_PARAMERR      ��������
�޸���Ϣ: 2013-12-30  �޳�  ����
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


