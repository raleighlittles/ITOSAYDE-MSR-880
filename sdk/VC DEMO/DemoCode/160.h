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

typedef struct _thailandid_obj_{
	unsigned char	CID[20];  //0D
	unsigned char	NameSex[256];     //0XD1 # Fullname Thai + Eng + BirthDate + Sex
	unsigned char 	Address[128];    //0x64
	unsigned char 	IssueExpire[20];   //0x12  issue/expire
}ThailandIDObj;
extern unsigned char _stdcall GetThailandIDInfo(unsigned char slot,ThailandIDObj *pThailandIDInfo);

//system
extern unsigned char __stdcall	InitDev(unsigned char comport,long  BaudRate);
extern void __stdcall DelDev(void);
extern unsigned char __stdcall  ReadSN(unsigned char *sn);
extern int _stdcall setWorkMode(int mode);
extern unsigned char _stdcall set3DESKey(unsigned char* oldKey,unsigned char* newKey);
extern unsigned char __stdcall  Beep1(void);
extern unsigned char _stdcall getDeviceStatus(void);
extern unsigned char __stdcall	GetSDKVersion(char *OutVer);

//algorithm
extern void __stdcall   one_two(unsigned char *in,int lc,unsigned char *out);
extern void __stdcall   two_one(unsigned char *in,int in_len,unsigned char *out);
extern unsigned char _stdcall Tdes(unsigned char* inputData,unsigned char* outputData,unsigned char* keyData,long mode,long counter);
extern unsigned char _stdcall CalcDesECB(unsigned char* inputData,int inputDatalen,unsigned char* outputData,unsigned char* keyData,unsigned char keyDatalen,unsigned char mode);

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
extern int _stdcall MSR_Write_SPEC(char *trace1, char *trace2, char *trace3,char parity1,char parity2,char parity3,char tr1len,char tr2len,char tr3len,char SS1,char ES1,char SS2,char ES2,char SS3,char ES3);
extern int _stdcall MSR_SetBPI(unsigned char mode);
extern int _stdcall User_To_ASC(unsigned char *TK1Dat, unsigned char *TK2Dat, unsigned char *TK3Dat,unsigned char parity1,unsigned char parity2,unsigned char parity3,unsigned char tr1bit,unsigned char tr2bit,unsigned char tr3bit,unsigned char ES1,unsigned char ES2,unsigned char ES3);
extern int _stdcall MSR_AUTH(void);



//IC Memory卡 接口
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

extern unsigned char _stdcall InitAT(void);
extern unsigned char _stdcall AT24_Read(unsigned char *start,unsigned char *lens,char ctype,unsigned char *data);
extern unsigned char _stdcall AT24_Write(unsigned char *start,unsigned char *lens, char ctype,unsigned char *data);


//NFC TYPEB
extern unsigned char _stdcall BRequest(unsigned char *data);
extern unsigned char _stdcall BAttrib(void);
extern unsigned char _stdcall Get_UID(void);
extern unsigned char _stdcall B_Pending(void);
extern unsigned char _stdcall B_Apdu(char slot,APDU_SEND *ApduSend,APDU_RESP *ApduRecv);
extern unsigned char __stdcall  B_Apdu2(uchar slot, uchar *Send ,int sendLen, uchar *Recv,int &rcvLen);

//Motor
extern unsigned char _stdcall Motor_Lock(void);
extern unsigned char _stdcall Motor_Open(void);
extern unsigned char _stdcall Motor_Auto_Lock(void);
extern unsigned char _stdcall Motor_No_Auto_Lock(void);
extern unsigned char _stdcall Check_Lock_Status(unsigned char *result);

//Felicard
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
extern unsigned char _stdcall SetParam(unsigned char eType ,unsigned char eValue);
extern unsigned char _stdcall ActiveWorkingKey(unsigned char dwMkSN,unsigned char dwWkSN);
extern unsigned char _stdcall StartPinInput(unsigned char byLen ) ;
extern unsigned char _stdcall StartPlainInput() ;
extern unsigned char _stdcall BeepRun();
extern unsigned char _stdcall GetPinBlock(unsigned char * block);
extern unsigned char _stdcall EncryptData(unsigned char len,unsigned char* srcInfo, unsigned char *destInfo) ;
extern unsigned char _stdcall MacEncrypt(unsigned char len,unsigned char* srcInfo, unsigned char *destInfo) ;


// IC CPU  接口
extern unsigned char  __stdcall  IccInit(uchar slot,uchar *ATR);
extern void __stdcall   IccClose(uchar slot);
extern unsigned char __stdcall   IccIsoCommand(uchar slot, APDU_SEND *ApduSend,APDU_RESP *ApduRecv);
extern unsigned char __stdcall   IccDetect(uchar slot);
extern void  __stdcall  IccAutoResp(unsigned char slot, unsigned char autoresp);
extern unsigned char __stdcall   IccIsoCommand2(unsigned char slot, unsigned char *Send ,int sendLen, unsigned char *Recv,int &rcvLen);

//磁卡
extern void __stdcall   MagOpen(void);
extern void __stdcall   MagClose(void);
extern void __stdcall   MagReset(void);
extern unsigned char __stdcall  MagSwiped(void);
extern unsigned char __stdcall  MagRead(unsigned char *Track1, unsigned char *Track2,unsigned char *Track3);
extern unsigned char __stdcall  MagRead_DES(unsigned char *Track1,unsigned char *Track2,unsigned char *Track3);


// M1卡 接口
extern unsigned char __stdcall  M1Request(unsigned char type,unsigned char *rsp);
extern unsigned char __stdcall  M1Select(unsigned char *SerialNo);
extern unsigned char __stdcall  M1Authority(unsigned char type,unsigned char block ,unsigned char *pwd);
extern unsigned char __stdcall  M1ReadBlock(unsigned char block,unsigned char *pck);
extern unsigned char __stdcall  M1WriteBlock(unsigned char block,unsigned char *pck);
extern unsigned char __stdcall  M1Operate(unsigned char Type,unsigned char Block ,unsigned char *Value,unsigned char TranBlock);
extern unsigned char __stdcall  M500PiccHalt(void);
extern unsigned char __stdcall  M1ReadSec(unsigned char cardtype,unsigned char *pwd,unsigned char keyAB,unsigned char sector,unsigned char *buf,unsigned char mode ,unsigned char *snr,unsigned char timeout);
extern unsigned char __stdcall  M1WriteSec(unsigned char cardtype,unsigned char *pwd,unsigned char keyAB,unsigned char sector,unsigned char *buf,unsigned char len,unsigned char mode ,unsigned char *snr,unsigned char timeout);
extern unsigned char __stdcall piccchangesinglekey(unsigned char ctrlword,unsigned char *serial,unsigned char area , unsigned char keyA1B0,unsigned char *piccoldkey,unsigned char *piccnewkey);

//ultralight 
extern unsigned char __stdcall ULRequest(unsigned char type,unsigned char *temp,unsigned char *length);
extern unsigned char __stdcall ULSelect(unsigned char *SerialNo);
extern unsigned char __stdcall ULWrite(unsigned char block,unsigned char *pck);
extern unsigned char __stdcall M1ReadBlock(unsigned char block,unsigned char *pck);

//desfire
extern  unsigned char _stdcall  DFRequest(unsigned char* buffer);
extern  unsigned char _stdcall DFReset(unsigned char* buffer);
extern  unsigned char _stdcall DFHalt(void) ;

extern  unsigned char _stdcall DFAuthenKey(int index,unsigned char* Key);
extern unsigned char _stdcall DFUpdateKey(int index,unsigned char* newPass,unsigned char* oldPass);
extern unsigned char _stdcall DFGetKeySetting(unsigned char* result);
extern unsigned char _stdcall DFChangeKeySetting(unsigned char keysetting);
extern unsigned char _stdcall DFGetKeyVersion(int keyNum,unsigned char *OutVer);

extern unsigned char _stdcall DFSelectAID(unsigned char* aid);
extern unsigned char _stdcall DFCreateAID(unsigned char* aid,unsigned char setting,unsigned char keynum);
extern unsigned char _stdcall DFDeleteApp(unsigned char* aid);
extern unsigned char _stdcall DFGetApplicationIDs(unsigned char *aidnum,unsigned char* aids);
extern unsigned char _stdcall DFFormatCard(void);
extern unsigned char _stdcall DFGetInfo(unsigned char* result);

extern unsigned char _stdcall DFGetFileIDs(unsigned char *filenum,unsigned char*fileIDs);
extern unsigned char _stdcall DFGetFileSetting(int index,unsigned char* filesetting,unsigned char *Outlen);
extern unsigned char _stdcall DFChangeFileSetting(int index,unsigned char* setting);
extern unsigned char _stdcall DFCreateSTDFile(int index,unsigned char* settings,unsigned char* filesize);
extern unsigned char _stdcall DFCreateBackupDataFile(int index,unsigned char* settings,unsigned char* filesize);
extern unsigned char _stdcall DFCreateValueFile(int index,unsigned char* settings,unsigned char* lowsb,unsigned char* highsb,unsigned char* initsb,unsigned char limiten);
extern unsigned char _stdcall DFCreateLinearRecordFile(int index,unsigned char* settings,unsigned char* filesize,unsigned char* number);
extern unsigned char _stdcall DFCreateCyclicRecordFile(int index, unsigned char* settings,unsigned char* filesize,unsigned char* number);
extern unsigned char _stdcall DFDeleteFile(int index);

extern unsigned char _stdcall DFWriteDataFile(int index,unsigned char* address,unsigned char* length,unsigned char*data);
extern unsigned char _stdcall DFPlusValueFile(int index,unsigned char* value);
extern unsigned char _stdcall DFMinusValueFile(int index,unsigned char* value);
extern unsigned char _stdcall DFGetValueFile(int index,unsigned char* OutValue);
extern unsigned char _stdcall DFReadDataFile(int index,unsigned char* offset,unsigned char* len,unsigned char* OutData,unsigned int *DataLen);
extern unsigned char _stdcall DFWriteRecord(int index,unsigned char* offset,unsigned char* len,unsigned char* data);
extern unsigned char _stdcall DFReadRecord(int index,unsigned char* offset,unsigned char* recordnum,unsigned char* OutData,unsigned int *DataLen);
extern unsigned char _stdcall DFClearRecordFile(int index);
extern unsigned char _stdcall DFCommitTransion(void);
extern unsigned char _stdcall DFAbortTransion(void);

//PinPad
#define KEYTYPE_PINEK           (0x20)	/*PIN加密密钥/工作密钥，只用于PIN加密*/
#define KEYTYPE_DATAEK          (0x21)	/*数据加密密钥/工作密钥，只用于数据加密、MAC运算等*/
#define KEYTYPE_DATADK          (0x22)	/*数据解密密钥/工作密钥，只用于数据解密*/

extern int _stdcall PinPadSetCom(unsigned char ComId);
extern int _stdcall PinPadGetCom(unsigned char *ComId);
extern int _stdcall PinPadInit(void);
extern int _stdcall PinPadGetInfo(unsigned char *OutVer,unsigned char *OutSN);
extern int _stdcall PinPadGetPin(unsigned char *Title, unsigned char Mode, unsigned char *PAN, unsigned char *PinData, unsigned char MinPINLen, unsigned char MaxPINLen, unsigned short TimeOut, unsigned short KeyIndex);
extern int _stdcall PinpadLoadMasterKey(unsigned int mkeyID, unsigned char keyType, unsigned char *keybuf, unsigned char keylen);
extern int _stdcall PinpadLoadWorkKey(unsigned int wkeyID, unsigned int mkeyID, unsigned char keyType, unsigned char *keybuf, unsigned char keylen,unsigned char *kcv,unsigned char kcvlen);
extern int _stdcall PinPadCalcDES(unsigned char CalcMode, unsigned char *OutData, unsigned char *InData,unsigned int InDataLen, unsigned int KeyIndex, unsigned char CbcMode,unsigned char *InvData);
extern int _stdcall PinPadGetMac(unsigned char CalMode, unsigned char *pMac, unsigned char *Data,unsigned int DataLen, unsigned int KeyIndex);

//身份证模块接口
extern unsigned char _stdcall GetStartDate(char *strTmp);
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
extern unsigned char _stdcall GetPeopleIDCode(char *strTmp);


//PED
extern unsigned char _stdcall PED_GetVersion(unsigned char *Version);
extern unsigned char _stdcall PED_GetPinBlock(unsigned char *Data);
unsigned char _stdcall PED_StartPinInput(unsigned char KeyId,unsigned char PinLen,
										 unsigned char Mode, unsigned char TimeOut1,
										 unsigned char CardnoLen,unsigned char *Cardno);
extern unsigned char _stdcall PED_LoadTLKplaim(unsigned char KeyType,unsigned char *TLK_TRK,unsigned char mode,unsigned char *AuKey);
extern unsigned char _stdcall PED_LoadTMKpim(unsigned char SrcKeyType,unsigned char SrcKeyIdx,unsigned char DstKeyIdx,unsigned char datalen,unsigned char *data);
extern unsigned char _stdcall PED_GetKeyBody(unsigned char *key, unsigned char SrcKeyType, unsigned char SrcKeyIdx,  unsigned char DstKeyIdx,unsigned char DstKeyType, unsigned char *RFU,unsigned char DstKeyLen,  unsigned char *DstKey ,   
									  unsigned char KcvMode,    unsigned char *Kcv,
									  unsigned char *InitKSN,	unsigned char *RecvData);
extern unsigned char _stdcall PED_ErasureKeys();
extern unsigned char _stdcall PED_GetMAC(unsigned char KeyIdx,unsigned char Mode, unsigned char *DataInLen,unsigned char *DataIn,unsigned char *MAC);
extern unsigned char _stdcall PED_DataEncrypt(unsigned char Mode,unsigned char KeyIdx,unsigned char *DataInLen,unsigned char *DataIn,unsigned char *DataOut);
extern unsigned char _stdcall PED_GetKeyCode(unsigned char *KeyCode);
extern unsigned char _stdcall PED_CloseKeyboard();
extern unsigned char _stdcall PED_StartPlainInput(unsigned char timeout);
extern unsigned char __stdcall PED_InitDev(unsigned char comport,long  BaudRate);


//print
extern void _stdcall MyPrinter(unsigned char *data, unsigned char len);
extern void _stdcall Print_RESET();//初始化  清楚缓存区 恢复默认值 清楚标志位
extern void _stdcall Print_LF();//打印并且换行
extern void _stdcall Print_SP_R(unsigned char n);//设置字符右边间距为n个字符	默认是0
extern void _stdcall Print_SP_LINE(unsigned char n);//设置行距 为n, 默认值为4 ，(28 x 0.125mm)，不包括字符高度
extern void _stdcall Print_ALIGN(unsigned char n);//设置对齐方式 n=0左对齐 1居中 2 右对齐
extern void _stdcall Print_FONT(unsigned char n);//n=0 normal font   n=1 big font
extern void _stdcall Print_BMP(unsigned char* data,long len);//我测试用的接口 客户不需要使用
extern int _stdcall Print_IMG(const char *data);


//wifi
extern unsigned char _stdcall OpenWifi();
extern unsigned char _stdcall CloseWifi();
extern unsigned char _stdcall SetWifiName(unsigned char len,unsigned char *data);
extern unsigned char _stdcall SetPhoneStatue(unsigned char *phoneNum,unsigned char statue, unsigned char *onlineTime);
extern unsigned char _stdcall TimeOutMessage(unsigned char *phoneNum);
extern unsigned char _stdcall QueryFlow(unsigned char *data);
extern unsigned char _stdcall QueryTotalFlow(unsigned char *data);
extern unsigned char _stdcall RecDevData(unsigned char *data);

//bluetooth
extern void _stdcall BlueSendData(int len,unsigned char *data);
extern unsigned char _stdcall BlueRecvData(unsigned int *datalen,unsigned char *data);
extern unsigned char _stdcall BlueRename(unsigned char *data);
extern unsigned char _stdcall BlueModifyKey(unsigned char *data);
extern void _stdcall BlueClose();
extern void _stdcall BlueOpen();
extern unsigned char _stdcall BlueGetConnectName(unsigned int *datalen,unsigned char *data);
extern unsigned char _stdcall BlueGetSignal(unsigned char *data);
extern unsigned char _stdcall BlueGetKey(unsigned char *data);


//download tool
extern unsigned char _stdcall GetDevInfo(unsigned char *data);
extern unsigned char _stdcall TurnBoot();
extern unsigned char _stdcall DeviceShakeHand();
extern unsigned char _stdcall DownLoadType(unsigned char *data);
extern unsigned char _stdcall FileLength(unsigned char *length);
extern  unsigned char _stdcall DownLoadFile(int len,unsigned char*data);
extern unsigned char _stdcall RunApp();


//国密2 3 4
extern unsigned char _stdcall GMB_Reset();
extern unsigned char _stdcall GMB_Erase();
extern unsigned char _stdcall GMB_GetKeyPair(unsigned char Num,unsigned char *data);
extern unsigned char _stdcall GMB_InputKeyPair(unsigned char Num,unsigned char *data);
extern unsigned char _stdcall GMB_EncryptSM2(unsigned char Len,unsigned char *Srsdata,unsigned char *Desdata);
extern unsigned char _stdcall GMB_DecryptSM2(unsigned char Len,unsigned char *Srsdata);
extern unsigned char _stdcall GMB_EncryptSM3(unsigned char SrsdataLen,unsigned char *Srsdata,unsigned char *Desdata);
extern unsigned char _stdcall GMB_DownLoadKeySM4(unsigned char Num,unsigned char keylen,unsigned char *key);
extern unsigned char _stdcall GMB_EncryptSM4(unsigned char len,unsigned char *data,unsigned char* desdata);
extern unsigned char _stdcall GMB_DecryptSM4(unsigned char len,unsigned char *data,unsigned char* desdata);



//金融社保卡
extern unsigned char _stdcall GetSocialCard(unsigned char slot,unsigned char *name,unsigned char *cardnum);
extern int _stdcall MSR_ICCardID(unsigned char slot,char *data);
extern int _stdcall PBOC_ICPAN(unsigned char slot,char *data);

//判断IC卡槽 插卡与拔卡 瞬间 接口。   插卡返回1  拔卡返回2
extern uchar _stdcall COMRecv(uchar *data );

//extern unsigned char extern "C" _declspec(dllimport)  GetDevTypeInfo(unsigned char* data);
extern unsigned char _stdcall phone_double();
extern unsigned char _stdcall phone_Rename(unsigned char *data);
extern unsigned char _stdcall phone_DownLoadSN(unsigned char *data, int len);
extern unsigned char _stdcall phone_DownLoadTDK(unsigned char *data);
extern unsigned char _stdcall phone_readSN(unsigned char *data);
extern unsigned char _stdcall phone_ReadSN(unsigned char *data);
extern unsigned char _stdcall phone_powerdown(int time);//ms

extern unsigned char _stdcall Factory_Test_Recv(uchar* data);
extern unsigned char _stdcall Factory_Test_IC_Ramdon(uchar *data);
extern unsigned char _stdcall Factory_Test_IC_CardOut();

#ifndef u8
#define u8 unsigned char
#endif
#ifndef u16
#define u16 unsigned short
#endif
#ifndef u32
#define u32 unsigned int
#endif

//终端参数_做交易之前(最好在main()函数)设置一次(不存储)
typedef struct
{
	u8 ucIFD[8+1];                  //9F1E 设备序列号,ASC以0x00结束
	u8 ucTerminalCountry[2];        //9F1A 国家代码
	u8 ucTermType;				    //9F35 终端类型
	u8 ucTermCapa[3];               //9F33 终端性能
	u8 ucAddTermCapa[5];            //9F40 终端附加性能

	u8 ucMerchantNameLocation[40+1];//9F4E 商户名，ASC码以0x00结束
	u8 ucMerchantCode[2];           //9F15 商户分类号BCD
	u8 ucMerchantID[15+1];          //9F16 商户号,应用以0x00结束
	u8 ucAcquirerID[6];        		//9F01 收单行BCD
	u8 ucTermID[8+1];               //9F1C 终端标识(终端号),ASC以0x00结束

	u8 ucTranRefCurrExp;		    //9F3D 参考货币指数
	u8 ucTranRefCurr[2];			//9F3C 参考货币代码
	u8 ucTranCurrExp;			    //5F36 交易货币指数
	u8 ucTranCurrCode[2];			//5F2A 交易货币代码

    u8 ucCapture;                   //     数据采集 = 0联机数据采集 =1批数据采集
	u8 ucTermSMSupportIndicator;	//     终端是否支持SM算法 =0不支持 =1支持
    u8 ucPaypassImplementationOptions;      //PayPass执行选项 =0 EMV，=1 Data Exchange

	u8 ucTermFLmtFlg;    			//	   非接读卡器是否支持终端最低限额检查9F1B (qPBOC一般为1) =0不检查，=1检查
	u8 ucRFTxnLmtFlg;				//	   非接读卡器是否支持交易限额检查DF20(qPBOC一般为1) =0不检查，=1检查
	u8 ucRFFLmtFlg;					//	   非接读卡器是否支持脱机最低限额检查DF19(qPBOC一般为1) =0不检查，=1检查
	u8 ucRFCVMLmtFlg;   			//	   非接读卡器是否支持CVM执行限额检查DF21(qPBOC一般为1) =0不检查，=1检查

	u8 ucRFStatusCheckFlg;    		// 	   非接读卡器是否支持状态检查(qPBOC一般为0) =1若授权金额为1,则9F66要求联机密文
	u8 ucRFZeroAmtNoAllowed;       	//	   非接交易0金额检查(qPBOC一般为0) =0不检查，=1检查若授权金额为0,则9F66要求联机密文

	u8 ucUseFangba;                 //     非接启用闪卡功能 =0不启用 =1启用

	u8 ucPrintfDebugInfo;           //     打印串口调试信息 =0不打印 =1打印
	u8 ucHostType;				    //	   =0标准,=1BCTC测试后台
    u8 ucEmvTest;                   //     =0unionPay, =1EMV, =2PBOC, =3qPBOC, =4qUICS,=5PayWare,=6PayPass
    u8 ucUseCallBackApdu;           //     使用回调函数发送发送接收APDU =0不启用 =1启用
}T_EMV_TERM_PARAM;

//交易参数_做交易前(调用应用选择函数)设置(不存储)
typedef struct
{
	u8 ucTransKernalType; 			// 	   内核类型, =0接触式或非接触式EMV/PBOC, =1非接统一入口
	u8 ucIsForceOnline;             //     是否强制联机,用于EMV/PBOC中 =1 强制联机(如余额查询需要)
	u8 ucIsSimpleFlow;              //     用于EMV/PBOC中 =0完整流程 =1 简易流程(只走到read record)
    u8 ucOption;                    //     交易可选项(见交易可选项宏定义,按位使用)
	u8 ucEcTerminalSupportIndicator;//9F7A 电子现金终端支持指示器,用于EMV/PBOC中 =0EMV =1电子现金
    u8 ucReaderTTQ[4];      		//9F66 终端交易性能，用于qPBOC中

    u8 ucTransNo[4];      			//9F41 交易流水号 BCD，用于消费交易，余额查询不用设置
	u8 ucTransDate[3];  		    //9A   交易日期 BCD YYMMDD
	u8 ucTransTime[3];  			//9F21 交易时间 BCD HHMMS
    u8 ucAmountAuth[6];     		//9F02 授权金额(交易金额) BCD ,ucAmountAuth[0]=0x01表示金额为空
    u8 ucAmountOther[6];    		//9F03 其他金额(返现金额) BCD ,ucAmountOther[0]=0x01表示金额为空
	u8 ucTransType;                 //9C   交易类型 一般为0x00 ,返现请设置0x09

}T_EMV_TRANS_PARAM;
typedef struct
{
	u8 ucAID[16];		        	//9F06 应用ID
	u8 ucAIDLen;                  	//     应用aid长度
	u8 ucSelectIndicator;     		//DF01 应用选择指示符（ASI）(=0部分匹配,=1完全匹配)
	u8 ucTargetPercentage;     		//DF17 随机百分比
	u8 ucMaxTargetPercentage;  		//DF16 随机最大百分比
	u8 ucTermFloor[4];        		//9F1B 终端最低限额HEX

    u32 uiThresholdValue;			//DF15 随机选择阀值
    u8 ucOnLinePINFlag;            	//DF18 终端联机PIN支持能力(=0不支持,=1支持)
	
	u8 ucTACDefault[5];        		//DF11 缺省
	u8 ucTACDenial[5];         		//DF13 拒绝
	u8 ucTACOnline[5];         		//DF12 联机
	u8 ucDdolLen;       			//     DDOL长度
	u8 ucDdol[252];            		//DF14 缺省DDOL
	u8 ucTdolLen;       			//     TDOL长度
	u8 ucTdol[252];            		//97   缺省TDOL
	u8 ucTermAVM[2];           		//9F09 应用版本号
	u8 ucRFTxnLmt[6];   			//DF20 非接触读写器交易限额bcd,>=此值交易终止
	u8 ucRFFLmt[6];     			//DF19 非接触读写器脱机最低限额bcd,>此值联机 DF8123
	u8 ucRFCVMLmt[6];       		//DF21 非接读写器持卡人验证方法CVM所需限制bcd,>=此值执行CVM
	u8 ucECTranLmt[6];        		//9F7B 电子现金终端交易限额bcd,<走电子现金

    //银联EMV测试后台增加---------------------------------
	u8 ucMerchantNameLocation[40+1];//9F4E 商户名，ASC码以0x00结束
	u8 ucMerchantCode[2];           //9F15 商户分类号BCD
	u8 ucMerchantID[15+1];          //9F16 商户号,应用以0x00结束
	u8 ucAcquirerID[6];        		//9F01 收单行BCD
	u8 ucTermID[8+1];               //9F1C 终端标识(终端号),ASC以0x00结束
	u8 ucTranRefCurrExp;		    //9F3D 交易参考货币指数
	u8 ucTranRefCurr[2];			//9F3C 参考货币代码
	u8 ucTranCurrExp;			    //5F36 交易货币指数
	u8 ucTranCurrCode[2];			//5F2A 交易货币代码
    //----------------------------------------------------

	//PAYPASS---------------------------------
	u8 ucUdolLen;       			//UDOL长度
	u8 ucUdol[240];            		//9F69     缺省UDOL
	u8 MagStripeInd;       			//     Mag Stripe指示器
	u8 MagStripeVer[2];             //9F6D    Mag Stripe版本
    u8 TermCapNoCVMReq[3];          //NoCVM 终端性能
	u8 TermCapCVMReq[3];            //CVM 终端性能
	u8 ucPayPassAddTermCapa[5];     //9F40 终端附加性能
	u8 ucPayPassTermType;		   //9F35 终端类型
	u8 PaypassRFU[32];             //预留
	 //----------------------------------------------------
	u16 unCrc;						//	   crc
}T_EMV_APP_LIST;
typedef struct
{
	u8 ucRID[5];               		//9F06 与认证中心公钥索引一起标识认证中心的公钥
	u8 ucIndex;                		//9F22 认证中心公钥索引
	u8 ucHashIndicator;        		//DF06 认证中心公钥哈什算法标识
	u8 ucCAPKIndicator;        		//DF07 认证中心公钥算法标识
	u8 ucModulusLen;
	u8 ucModulus[248];         		//DF02 认证中心公钥模   变长，最大为248
	u8 ucExponentLen;
	u8 ucExponent[3];         		//DF04 认证中心公钥指数  0x10001或0x03
	u8 ucExpDate[3];           		//DF05 认证中心公钥有效期(bcd yyyymmdd)
	u8 ucCheckSum[20];         		//DF03 认证中心公钥校验值sha1
	u16 unCrc;						//	   crc
}T_EMV_TERM_CAPK;
#ifndef s32
#define s32 int
#endif
#ifndef s8
#define s8 char
#endif
typedef struct
{   
    s32 (*EmvCbDebugPritLogFun)(u8 *phexIn, u32 uiLen);//
	
    //EMV专用回调函数
    s32 (*EmvCbSelAppFun)(u8 ucIsFirstSelect,s8 *pcAppLabelList[], s32 iAppNum);//显示应用标签列表，要求持卡人选择 >= 1选择应用列表的序号(从1开始) <0(EMV_USER_CANCEL,EMV_TIME_OUT等)
    s32 (*EmvCbShowHintFun)(s8 *pcStr,s32 iClearFlag,s32 iDisplayTime);//显示字符串ucStr;显示iDisplayTime秒（可按任意键）返回,iDisplayTime=0不等待直接返回，iDisplayTime=-1有按键才返回
    s32 (*EmvCbInputPINFun)(u8 ucPINType,u8 *pucOutPINBlock);//输入PIN, ucPINType(参见宏定义);pucICChallenge 从IC卡得到的随机数,用于脱机密文PIN;tPublicKey IC卡加密PIN公钥，用于脱机密文PIN;pucOutPINBlock:得到的PINBLOCK
    s32 (*EmvCbCertVerifyFun)(void);//持卡人证件验证 =0成功 <0(EMV_USER_CANCEL,EMV_TIME_OUT等)
    s32 (*EmvCbGetSumLogByPANFun)(u8 *pucPAN,u32 uiPANLen,u32 *puiOutAmount);//得到一张卡片的交易累计金额，用于判断终端最低限额9f1b
    s32 (*EmvCbOnlineProcFun)(void);//联机发送接收，解析响应的55域数据,RspCode为39域应答码,>0为应用层错误码
    s32 (*EmvCbReferProcFun)(void); //发卡行返回授权响应码(39域为01或02)显示参考(批准或拒绝)
    s32 (*EmvCbAdviceProcFun)(void);//GAC之后, 请求通知

	s32 (*EmvCbReSwipeCardFun)(void);// 出现闪卡,重新挥卡
	s32 (*EmvCbLoadRevocListFun)(u8 *pucRID,u8 ucCAPKIndex,u8 *pucCertSerial);//根据RID和公钥索引得到公钥回收列表，=0找到
	s32 (*EmvCbSearchExceptionListFun)(u8 *pucPAN,u32 uiPANLen,u8 ucPANSeq);//查找黑名单，用于异常文件检查 =0找到
}T_EMVCORE_CALLBACK;
extern int _stdcall EmvCoreCbInit(void);
extern int _stdcall EmvClearAIDList(void);
extern int _stdcall EmvClearCAPKList(void);
extern int _stdcall EmvAddAIDList(T_EMV_APP_LIST *pEmvAppList);
extern int _stdcall EmvADDCAPKList(T_EMV_TERM_CAPK *pEmvTermCapk);
extern int _stdcall EmvCoreTrans(u8 Slot,u8 *pAmountAuth,u8 *pucTransResult);
extern int _stdcall EmvCoreGetTagData(u32 uiTag,u8 *pucDataOut,u32 *puiDataOutLen);
extern int _stdcall EmvCoreSetTagData(u32 uiTag,u8 *pucDataIn,u32 uiDataInLen);
extern int _stdcall EmvCoreSetCallBackFun(T_EMVCORE_CALLBACK *ptEmvCallback);
extern T_EMV_TERM_PARAM *EmvCoreGetTermParam(void);//得到终端参数指针
extern T_EMV_TRANS_PARAM *EmvCoreGetTransParam(void);//得到交易参数指针
#endif