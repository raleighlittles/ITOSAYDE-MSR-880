#ifndef _MSRAPI_
#define _MSRAPI_


// ***ע����ͷ�ļ������ڶ�汾�豸�����������豸������֧�����нӿ�
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

// ��д�ſ��ӿ� 
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



//IC Memory�� �ӿ�
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

//������� �ӿ�
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


// IC CPU  �ӿ�
extern unsigned char  __stdcall  IccInit(uchar slot,uchar *ATR);
extern void __stdcall   IccClose(uchar slot);
extern unsigned char __stdcall   IccIsoCommand(uchar slot, APDU_SEND *ApduSend,APDU_RESP *ApduRecv);
extern unsigned char __stdcall   IccDetect(uchar slot);
extern void  __stdcall  IccAutoResp(unsigned char slot, unsigned char autoresp);
extern unsigned char __stdcall   IccIsoCommand2(unsigned char slot, unsigned char *Send ,int sendLen, unsigned char *Recv,int &rcvLen);

//�ſ�
extern void __stdcall   MagOpen(void);
extern void __stdcall   MagClose(void);
extern void __stdcall   MagReset(void);
extern unsigned char __stdcall  MagSwiped(void);
extern unsigned char __stdcall  MagRead(unsigned char *Track1, unsigned char *Track2,unsigned char *Track3);
extern unsigned char __stdcall  MagRead_DES(unsigned char *Track1,unsigned char *Track2,unsigned char *Track3);


// M1�� �ӿ�
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
#define KEYTYPE_PINEK           (0x20)	/*PIN������Կ/������Կ��ֻ����PIN����*/
#define KEYTYPE_DATAEK          (0x21)	/*���ݼ�����Կ/������Կ��ֻ�������ݼ��ܡ�MAC�����*/
#define KEYTYPE_DATADK          (0x22)	/*���ݽ�����Կ/������Կ��ֻ�������ݽ���*/

extern int _stdcall PinPadSetCom(unsigned char ComId);
extern int _stdcall PinPadGetCom(unsigned char *ComId);
extern int _stdcall PinPadInit(void);
extern int _stdcall PinPadGetInfo(unsigned char *OutVer,unsigned char *OutSN);
extern int _stdcall PinPadGetPin(unsigned char *Title, unsigned char Mode, unsigned char *PAN, unsigned char *PinData, unsigned char MinPINLen, unsigned char MaxPINLen, unsigned short TimeOut, unsigned short KeyIndex);
extern int _stdcall PinpadLoadMasterKey(unsigned int mkeyID, unsigned char keyType, unsigned char *keybuf, unsigned char keylen);
extern int _stdcall PinpadLoadWorkKey(unsigned int wkeyID, unsigned int mkeyID, unsigned char keyType, unsigned char *keybuf, unsigned char keylen,unsigned char *kcv,unsigned char kcvlen);
extern int _stdcall PinPadCalcDES(unsigned char CalcMode, unsigned char *OutData, unsigned char *InData,unsigned int InDataLen, unsigned int KeyIndex, unsigned char CbcMode,unsigned char *InvData);
extern int _stdcall PinPadGetMac(unsigned char CalMode, unsigned char *pMac, unsigned char *Data,unsigned int DataLen, unsigned int KeyIndex);

//���֤ģ��ӿ�
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
extern void _stdcall Print_RESET();//��ʼ��  ��������� �ָ�Ĭ��ֵ �����־λ
extern void _stdcall Print_LF();//��ӡ���һ���
extern void _stdcall Print_SP_R(unsigned char n);//�����ַ��ұ߼��Ϊn���ַ�	Ĭ����0
extern void _stdcall Print_SP_LINE(unsigned char n);//�����о� Ϊn, Ĭ��ֵΪ4 ��(28 x 0.125mm)���������ַ��߶�
extern void _stdcall Print_ALIGN(unsigned char n);//���ö��뷽ʽ n=0����� 1���� 2 �Ҷ���
extern void _stdcall Print_FONT(unsigned char n);//n=0 normal font   n=1 big font
extern void _stdcall Print_BMP(unsigned char* data,long len);//�Ҳ����õĽӿ� �ͻ�����Ҫʹ��
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


//����2 3 4
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



//�����籣��
extern unsigned char _stdcall GetSocialCard(unsigned char slot,unsigned char *name,unsigned char *cardnum);
extern int _stdcall MSR_ICCardID(unsigned char slot,char *data);
extern int _stdcall PBOC_ICPAN(unsigned char slot,char *data);

//�ж�IC���� �忨��ο� ˲�� �ӿڡ�   �忨����1  �ο�����2
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

//�ն˲���_������֮ǰ(�����main()����)����һ��(���洢)
typedef struct
{
	u8 ucIFD[8+1];                  //9F1E �豸���к�,ASC��0x00����
	u8 ucTerminalCountry[2];        //9F1A ���Ҵ���
	u8 ucTermType;				    //9F35 �ն�����
	u8 ucTermCapa[3];               //9F33 �ն�����
	u8 ucAddTermCapa[5];            //9F40 �ն˸�������

	u8 ucMerchantNameLocation[40+1];//9F4E �̻�����ASC����0x00����
	u8 ucMerchantCode[2];           //9F15 �̻������BCD
	u8 ucMerchantID[15+1];          //9F16 �̻���,Ӧ����0x00����
	u8 ucAcquirerID[6];        		//9F01 �յ���BCD
	u8 ucTermID[8+1];               //9F1C �ն˱�ʶ(�ն˺�),ASC��0x00����

	u8 ucTranRefCurrExp;		    //9F3D �ο�����ָ��
	u8 ucTranRefCurr[2];			//9F3C �ο����Ҵ���
	u8 ucTranCurrExp;			    //5F36 ���׻���ָ��
	u8 ucTranCurrCode[2];			//5F2A ���׻��Ҵ���

    u8 ucCapture;                   //     ���ݲɼ� = 0�������ݲɼ� =1�����ݲɼ�
	u8 ucTermSMSupportIndicator;	//     �ն��Ƿ�֧��SM�㷨 =0��֧�� =1֧��
    u8 ucPaypassImplementationOptions;      //PayPassִ��ѡ�� =0 EMV��=1 Data Exchange

	u8 ucTermFLmtFlg;    			//	   �ǽӶ������Ƿ�֧���ն�����޶���9F1B (qPBOCһ��Ϊ1) =0����飬=1���
	u8 ucRFTxnLmtFlg;				//	   �ǽӶ������Ƿ�֧�ֽ����޶���DF20(qPBOCһ��Ϊ1) =0����飬=1���
	u8 ucRFFLmtFlg;					//	   �ǽӶ������Ƿ�֧���ѻ�����޶���DF19(qPBOCһ��Ϊ1) =0����飬=1���
	u8 ucRFCVMLmtFlg;   			//	   �ǽӶ������Ƿ�֧��CVMִ���޶���DF21(qPBOCһ��Ϊ1) =0����飬=1���

	u8 ucRFStatusCheckFlg;    		// 	   �ǽӶ������Ƿ�֧��״̬���(qPBOCһ��Ϊ0) =1����Ȩ���Ϊ1,��9F66Ҫ����������
	u8 ucRFZeroAmtNoAllowed;       	//	   �ǽӽ���0�����(qPBOCһ��Ϊ0) =0����飬=1�������Ȩ���Ϊ0,��9F66Ҫ����������

	u8 ucUseFangba;                 //     �ǽ������������� =0������ =1����

	u8 ucPrintfDebugInfo;           //     ��ӡ���ڵ�����Ϣ =0����ӡ =1��ӡ
	u8 ucHostType;				    //	   =0��׼,=1BCTC���Ժ�̨
    u8 ucEmvTest;                   //     =0unionPay, =1EMV, =2PBOC, =3qPBOC, =4qUICS,=5PayWare,=6PayPass
    u8 ucUseCallBackApdu;           //     ʹ�ûص��������ͷ��ͽ���APDU =0������ =1����
}T_EMV_TERM_PARAM;

//���ײ���_������ǰ(����Ӧ��ѡ����)����(���洢)
typedef struct
{
	u8 ucTransKernalType; 			// 	   �ں�����, =0�Ӵ�ʽ��ǽӴ�ʽEMV/PBOC, =1�ǽ�ͳһ���
	u8 ucIsForceOnline;             //     �Ƿ�ǿ������,����EMV/PBOC�� =1 ǿ������(������ѯ��Ҫ)
	u8 ucIsSimpleFlow;              //     ����EMV/PBOC�� =0�������� =1 ��������(ֻ�ߵ�read record)
    u8 ucOption;                    //     ���׿�ѡ��(�����׿�ѡ��궨��,��λʹ��)
	u8 ucEcTerminalSupportIndicator;//9F7A �����ֽ��ն�֧��ָʾ��,����EMV/PBOC�� =0EMV =1�����ֽ�
    u8 ucReaderTTQ[4];      		//9F66 �ն˽������ܣ�����qPBOC��

    u8 ucTransNo[4];      			//9F41 ������ˮ�� BCD���������ѽ��ף�����ѯ��������
	u8 ucTransDate[3];  		    //9A   �������� BCD YYMMDD
	u8 ucTransTime[3];  			//9F21 ����ʱ�� BCD HHMMS
    u8 ucAmountAuth[6];     		//9F02 ��Ȩ���(���׽��) BCD ,ucAmountAuth[0]=0x01��ʾ���Ϊ��
    u8 ucAmountOther[6];    		//9F03 �������(���ֽ��) BCD ,ucAmountOther[0]=0x01��ʾ���Ϊ��
	u8 ucTransType;                 //9C   �������� һ��Ϊ0x00 ,����������0x09

}T_EMV_TRANS_PARAM;
typedef struct
{
	u8 ucAID[16];		        	//9F06 Ӧ��ID
	u8 ucAIDLen;                  	//     Ӧ��aid����
	u8 ucSelectIndicator;     		//DF01 Ӧ��ѡ��ָʾ����ASI��(=0����ƥ��,=1��ȫƥ��)
	u8 ucTargetPercentage;     		//DF17 ����ٷֱ�
	u8 ucMaxTargetPercentage;  		//DF16 ������ٷֱ�
	u8 ucTermFloor[4];        		//9F1B �ն�����޶�HEX

    u32 uiThresholdValue;			//DF15 ���ѡ��ֵ
    u8 ucOnLinePINFlag;            	//DF18 �ն�����PIN֧������(=0��֧��,=1֧��)
	
	u8 ucTACDefault[5];        		//DF11 ȱʡ
	u8 ucTACDenial[5];         		//DF13 �ܾ�
	u8 ucTACOnline[5];         		//DF12 ����
	u8 ucDdolLen;       			//     DDOL����
	u8 ucDdol[252];            		//DF14 ȱʡDDOL
	u8 ucTdolLen;       			//     TDOL����
	u8 ucTdol[252];            		//97   ȱʡTDOL
	u8 ucTermAVM[2];           		//9F09 Ӧ�ð汾��
	u8 ucRFTxnLmt[6];   			//DF20 �ǽӴ���д�������޶�bcd,>=��ֵ������ֹ
	u8 ucRFFLmt[6];     			//DF19 �ǽӴ���д���ѻ�����޶�bcd,>��ֵ���� DF8123
	u8 ucRFCVMLmt[6];       		//DF21 �ǽӶ�д���ֿ�����֤����CVM��������bcd,>=��ִֵ��CVM
	u8 ucECTranLmt[6];        		//9F7B �����ֽ��ն˽����޶�bcd,<�ߵ����ֽ�

    //����EMV���Ժ�̨����---------------------------------
	u8 ucMerchantNameLocation[40+1];//9F4E �̻�����ASC����0x00����
	u8 ucMerchantCode[2];           //9F15 �̻������BCD
	u8 ucMerchantID[15+1];          //9F16 �̻���,Ӧ����0x00����
	u8 ucAcquirerID[6];        		//9F01 �յ���BCD
	u8 ucTermID[8+1];               //9F1C �ն˱�ʶ(�ն˺�),ASC��0x00����
	u8 ucTranRefCurrExp;		    //9F3D ���ײο�����ָ��
	u8 ucTranRefCurr[2];			//9F3C �ο����Ҵ���
	u8 ucTranCurrExp;			    //5F36 ���׻���ָ��
	u8 ucTranCurrCode[2];			//5F2A ���׻��Ҵ���
    //----------------------------------------------------

	//PAYPASS---------------------------------
	u8 ucUdolLen;       			//UDOL����
	u8 ucUdol[240];            		//9F69     ȱʡUDOL
	u8 MagStripeInd;       			//     Mag Stripeָʾ��
	u8 MagStripeVer[2];             //9F6D    Mag Stripe�汾
    u8 TermCapNoCVMReq[3];          //NoCVM �ն�����
	u8 TermCapCVMReq[3];            //CVM �ն�����
	u8 ucPayPassAddTermCapa[5];     //9F40 �ն˸�������
	u8 ucPayPassTermType;		   //9F35 �ն�����
	u8 PaypassRFU[32];             //Ԥ��
	 //----------------------------------------------------
	u16 unCrc;						//	   crc
}T_EMV_APP_LIST;
typedef struct
{
	u8 ucRID[5];               		//9F06 ����֤���Ĺ�Կ����һ���ʶ��֤���ĵĹ�Կ
	u8 ucIndex;                		//9F22 ��֤���Ĺ�Կ����
	u8 ucHashIndicator;        		//DF06 ��֤���Ĺ�Կ��ʲ�㷨��ʶ
	u8 ucCAPKIndicator;        		//DF07 ��֤���Ĺ�Կ�㷨��ʶ
	u8 ucModulusLen;
	u8 ucModulus[248];         		//DF02 ��֤���Ĺ�Կģ   �䳤�����Ϊ248
	u8 ucExponentLen;
	u8 ucExponent[3];         		//DF04 ��֤���Ĺ�Կָ��  0x10001��0x03
	u8 ucExpDate[3];           		//DF05 ��֤���Ĺ�Կ��Ч��(bcd yyyymmdd)
	u8 ucCheckSum[20];         		//DF03 ��֤���Ĺ�ԿУ��ֵsha1
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
	
    //EMVר�ûص�����
    s32 (*EmvCbSelAppFun)(u8 ucIsFirstSelect,s8 *pcAppLabelList[], s32 iAppNum);//��ʾӦ�ñ�ǩ�б�Ҫ��ֿ���ѡ�� >= 1ѡ��Ӧ���б�����(��1��ʼ) <0(EMV_USER_CANCEL,EMV_TIME_OUT��)
    s32 (*EmvCbShowHintFun)(s8 *pcStr,s32 iClearFlag,s32 iDisplayTime);//��ʾ�ַ���ucStr;��ʾiDisplayTime�루�ɰ������������,iDisplayTime=0���ȴ�ֱ�ӷ��أ�iDisplayTime=-1�а����ŷ���
    s32 (*EmvCbInputPINFun)(u8 ucPINType,u8 *pucOutPINBlock);//����PIN, ucPINType(�μ��궨��);pucICChallenge ��IC���õ��������,�����ѻ�����PIN;tPublicKey IC������PIN��Կ�������ѻ�����PIN;pucOutPINBlock:�õ���PINBLOCK
    s32 (*EmvCbCertVerifyFun)(void);//�ֿ���֤����֤ =0�ɹ� <0(EMV_USER_CANCEL,EMV_TIME_OUT��)
    s32 (*EmvCbGetSumLogByPANFun)(u8 *pucPAN,u32 uiPANLen,u32 *puiOutAmount);//�õ�һ�ſ�Ƭ�Ľ����ۼƽ������ж��ն�����޶�9f1b
    s32 (*EmvCbOnlineProcFun)(void);//�������ͽ��գ�������Ӧ��55������,RspCodeΪ39��Ӧ����,>0ΪӦ�ò������
    s32 (*EmvCbReferProcFun)(void); //�����з�����Ȩ��Ӧ��(39��Ϊ01��02)��ʾ�ο�(��׼��ܾ�)
    s32 (*EmvCbAdviceProcFun)(void);//GAC֮��, ����֪ͨ

	s32 (*EmvCbReSwipeCardFun)(void);// ��������,���»ӿ�
	s32 (*EmvCbLoadRevocListFun)(u8 *pucRID,u8 ucCAPKIndex,u8 *pucCertSerial);//����RID�͹�Կ�����õ���Կ�����б�=0�ҵ�
	s32 (*EmvCbSearchExceptionListFun)(u8 *pucPAN,u32 uiPANLen,u8 ucPANSeq);//���Һ������������쳣�ļ���� =0�ҵ�
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
extern T_EMV_TERM_PARAM *EmvCoreGetTermParam(void);//�õ��ն˲���ָ��
extern T_EMV_TRANS_PARAM *EmvCoreGetTransParam(void);//�õ����ײ���ָ��
#endif