#ifndef _MSRAPI_
#define _MSRAPI_


// ***注：该头文件包含众多版本设备，所以您的设备并不是支持所有接口



#define  uchar   unsigned char
typedef struct{
   	unsigned char Command[4]; 
   	unsigned short Lc;
   	unsigned char  DataIn[512];
   	unsigned short Le;
}APDU_SEND;

typedef struct{
	unsigned short LenOut; 
   	unsigned char  DataOut[512];
   	unsigned char  SWA;
   	unsigned char  SWB;
}APDU_RESP;

// 读写磁卡接口 


extern int _stdcall MSR_Init(void);
extern void _stdcall MSR_Exit(void);
extern int _stdcall MSR_DoCancel(void);
extern int _stdcall MSR_Read(void);
extern int _stdcall MSR_Write(unsigned char *TK1Dat, unsigned char *TK2Dat, unsigned char *TK3Dat);
extern int _stdcall MSR_Read_ASCII(void);
extern int _stdcall MSR_Write_ASCII(char *trace1, char *trace2, char *trace3);
extern int _stdcall MSR_Erase(unsigned char mode);
extern int _stdcall MSR_GetTrackData(unsigned char *TK1Dat, unsigned char *TK2Dat, unsigned char *TK3Dat);

extern int _stdcall MSR_Set_HiCo ();
extern int _stdcall MSR_Set_LoCo ();
extern int _stdcall MSR_Get_CoStatus(unsigned char *status);
extern int _stdcall Msr_ChangeAscii(unsigned char *TK1Dat, unsigned char *TK2Dat, unsigned char *TK3Dat);
extern int _stdcall MSR_Write_status(void);
extern int _stdcall MSR_Fast_Init(int portnum);
extern int _stdcall MSR_Get_HwInfo (char *info);
extern void _stdcall MSR_BeepOff (void);
extern void _stdcall MSR_BeepOn (void);
extern int _stdcall MSR_Erase_status(void);
extern int _stdcall MSR_ASC_Read(void);
extern int __stdcall auto_init(void);

extern int _stdcall MSR_Write_SPEC(char *trace1, char *trace2, char *trace3,char parity1,char parity2,char parity3,char tr1len,char tr2len,char tr3len,char SS1,char ES1,char SS2,char ES2,char SS3,char ES3);
extern int _stdcall MSR_SetBPI(unsigned char mode);
extern int _stdcall User_To_ASC(unsigned char *TK1Dat, unsigned char *TK2Dat, unsigned char *TK3Dat,unsigned char parity1,unsigned char parity2,unsigned char parity3,unsigned char tr1bit,unsigned char tr2bit,unsigned char tr3bit,unsigned char ES1,unsigned char ES2,unsigned char ES3);
extern int _stdcall MSR_AUTH(void);






// Memory卡 接口

extern int __stdcall chk_4442(int icdev);
extern unsigned char __stdcall  Init4442(void);
extern int __stdcall srd_4442(int icdev,int Offset,int length,unsigned char *ata_buffer);
extern int __stdcall swr_4442(int icdev,int Offset,int length,unsigned char *ata_buffer);
extern int __stdcall prd_4442(int icdev,int length,unsigned char *ata_buffer) ;
extern int __stdcall pwr_4442(int icdev,int Offset,int length,unsigned char *ata_buffer);
extern int __stdcall csc_4442(int icdev,int length,unsigned char *ata_buffer) ;
extern int __stdcall wsc_4442(int icdev,int length,unsigned char *ata_buffer);
extern int __stdcall rsc_4442(int icdev,int length,unsigned char *ata_buffer) ;
extern int __stdcall rsct_4442(int icdev,int *counter);
extern unsigned char _stdcall set3DESKey(unsigned char* oldKey,unsigned char* newKey);
extern unsigned char __stdcall  M1ReadSec(unsigned char cardtype,unsigned char *pwd,unsigned char keyAB,unsigned char sector,unsigned char *buf,unsigned char mode ,unsigned char *snr,unsigned char timeout);
extern unsigned char __stdcall  M1WriteSec(unsigned char cardtype,unsigned char *pwd,unsigned char keyAB,unsigned char sector,unsigned char *buf,unsigned char len,unsigned char mode ,unsigned char *snr,unsigned char timeout);
extern int __stdcall chk_4428(int icdev);
extern unsigned char __stdcall  Init4428(void);
extern int __stdcall csc_4428(int icdev,int length,unsigned char *ata_buffer) ;
extern int __stdcall rsc_4428(int icdev,int length,unsigned char *ata_buffer) ;
extern int __stdcall wsc_4428(int icdev,int length,unsigned char *ata_buffer);
extern int __stdcall srd_4428(int icdev,int Offset,int length,unsigned char *ata_buffer);
extern int __stdcall swr_4428(int icdev,int Offset,int length,unsigned char *ata_buffer);
extern int __stdcall rsct_4428(int icdev,int *counter);
extern int __stdcall pwr_4428(int icdev,int Offset,int length,unsigned char *ata_buffer);
extern int __stdcall rdwpb_4428(int icdev,int Offset,int length,unsigned char *ata_buffer);

extern int _stdcall setWorkMode(int mode);
extern unsigned char _stdcall Tdes(unsigned char* inputData,unsigned char* outputData,unsigned char* keyData,long mode,long counter);
extern unsigned char _stdcall getDeviceStatus(void);
extern unsigned char  __stdcall  MagRead_DES(unsigned char *Track1,unsigned char *Track2,unsigned char *Track3);

extern unsigned char __stdcall piccchangesinglekey(unsigned char ctrlword,
			unsigned char *serial,unsigned char area , unsigned char keyA1B0,
			unsigned char *piccoldkey,unsigned char *piccnewkey);
extern unsigned char __stdcall ULRequest(unsigned char type,unsigned char *temp,unsigned char *length);
extern unsigned char __stdcall ULSelect(unsigned char *SerialNo);
extern unsigned char __stdcall  ULWrite(unsigned char block,unsigned char *pck);
extern unsigned char _stdcall BRequest(unsigned char *data);
extern unsigned char _stdcall BAttrib(void);
extern unsigned char _stdcall Get_UID(void);
extern unsigned char _stdcall B_Pending(void);
extern unsigned char _stdcall InitAT(void);
extern unsigned char _stdcall AT24_Read(unsigned char *start,unsigned char *lens,char ctype,unsigned char *data);

extern unsigned char _stdcall AT24_Write(unsigned char *start,unsigned char *lens, char ctype,unsigned char *data);
extern unsigned char _stdcall B_Apdu(char slot,APDU_SEND *ApduSend,APDU_RESP *ApduRecv);
extern unsigned char _stdcall Motor_Lock(void);
extern unsigned char _stdcall Motor_Open(void);
extern unsigned char _stdcall Motor_Auto_Lock(void);
extern unsigned char _stdcall Motor_No_Auto_Lock(void);
extern unsigned char _stdcall Check_Lock_Status(unsigned char *result);
extern unsigned char _stdcall Felicard_Request(unsigned char *data);
extern unsigned char _stdcall Felicard_Apdu(int length,unsigned char *result);

//密码键盘 接口

extern unsigned char _stdcall DownLoadMainKey(int num,unsigned char* key);
extern unsigned char _stdcall DownLoadWorkKey(int Wnum,int Mnum,unsigned char* key);
extern unsigned char _stdcall EnterKeyInfo(int MainNum ,int NumMin,int NumMax) ;
extern unsigned char _stdcall WaitingKey(unsigned char* len,unsigned char* buff) ;
extern unsigned char _stdcall SendCardNum(int len,unsigned char* CardNum) ;
extern unsigned char _stdcall clearBuffer(void);
extern unsigned char _stdcall getBtns(unsigned char* data);

extern unsigned char _stdcall StopgetBtns(void);


// IC卡 磁卡 接口
extern unsigned char  __stdcall  IccInit(uchar slot,uchar *ATR);
extern void __stdcall   IccClose(uchar slot);
extern unsigned char __stdcall   IccIsoCommand(uchar slot, APDU_SEND *ApduSend,APDU_RESP *ApduRecv);
extern unsigned char __stdcall   IccDetect(uchar slot);
extern void __stdcall   MagOpen(void);
extern void __stdcall   MagClose(void);
extern void  __stdcall   MagReset(void);
extern unsigned char __stdcall   MagSwiped(void);
extern unsigned char  __stdcall  MagRead(unsigned char *Track1, unsigned char *Track2,unsigned char *Track3);
extern unsigned char __stdcall	InitDev(unsigned char comport,long  BaudRate);
extern void  __stdcall  IccAutoResp(unsigned char slot, unsigned char autoresp);
extern int _stdcall MSR_ICCardID(unsigned char slot,char *data);


// M1卡 接口
extern unsigned char __stdcall  M1Request(unsigned char type,unsigned char *rsp);
extern unsigned char __stdcall  M1Select(unsigned char *SerialNo);
extern unsigned char __stdcall  M1Authority(unsigned char type,unsigned char block ,unsigned char *pwd);
extern unsigned char __stdcall  M1ReadBlock(unsigned char block,unsigned char *pck);
extern unsigned char __stdcall  M1WriteBlock(unsigned char block,unsigned char *pck);
extern unsigned char __stdcall  M1Operate(unsigned char Type,unsigned char Block ,unsigned char *Value,unsigned char TranBlock);
extern unsigned char __stdcall  M500PiccHalt(void);
extern unsigned char __stdcall  Beep1(void);
extern unsigned char __stdcall  ReadSN(unsigned char *sn);
extern void __stdcall DelDev(void);

//身份证模块接口

extern unsigned char _stdcall GetEndDate(char *strTmp);
extern unsigned char _stdcall GetEndDate(char *strTmp);
extern unsigned char _stdcall GetDepartment(char *strTmp);
extern unsigned char _stdcall GetDepartment(char *strTmp);
extern unsigned char _stdcall GetPeopleAddress(char *strTmp);
extern unsigned char _stdcall GetPeopleBirthday(char *strTmp);
extern unsigned char _stdcall GetPeopleNation(char *strTmp);
extern unsigned char _stdcall GetPeopleSex(char *strTmp);
extern unsigned char _stdcall GetPeopleName(unsigned char *strTmp);
extern unsigned char _stdcall writeIDData(void);
extern unsigned char _stdcall writeIDOff(void);
extern unsigned char _stdcall writeIDReset(void);


#endif