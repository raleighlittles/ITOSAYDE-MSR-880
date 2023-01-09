#ifndef _EMV_CORE_H
#define _EMV_CORE_H

#ifdef __cplusplus
    extern "C" {
#endif

#pragma pack(1)

#ifdef DLL_API
#define DLLAPI  _declspec(dllexport)
#else
#define DLLAPI
#endif

#ifndef u8
#define u8 unsigned char
#endif
#ifndef u16
#define u16 unsigned short
#endif
#ifndef u32
#define u32 unsigned int
#endif
#ifndef s8
#define s8  char
#endif
#ifndef s16
#define s16  short
#endif
#ifndef s32
#define s32  int
#endif

//交易的内核类型
#define KERNAL_EMV_PBOC                     0       //EMV&PBOC
#define KERNAL_CONTACTLESS_ENTRY_POINT      1       //非接统一入口

//EMV L2测试特殊部分
#define EMV_TEST_CONFIG_UNIONPAY            0
#define EMV_TEST_CONFIG_EMV                 1
#define EMV_TEST_CONFIG_PBOC                2
#define EMV_TEST_CONFIG_QPBOC               3
#define EMV_TEST_CONFIG_QUICS               4
#define EMV_TEST_CONFIG_PAYWARE             5
#define EMV_TEST_CONFIG_PAYPASS             6

//qPBOC持卡人认证方式
#define RD_CVM_NO 					0x00        //无
#define RD_CVM_ONLINE_PIN 		    0x80        //联机PIN
#define RD_CVM_SIG 					0x40        //签名
//#define RD_CVM_ONLINE_PIN_AND_SIG   0xC0        //联机+签名

//交易结果
#define APPROVE_M                   0x40        //批准
#define DECLINE_M                   0x00        //拒绝
#define ONLINE_M                    0x80        //联机

//PIN
#define ONLINE_ENCIPHERED_PIN       0x00        //联机密文PIN
#define OFFLINE_PLAINTEXT_PIN       0x01        //脱机明文PIN
#define OFFLINE_ENCIPHERED_PIN      0x02        //脱机密文PIN

//交易可选项,按位使用
#define OPTION_CARDHOLDER_NOT_PERFORM       0x01 //现金充值，圈存类设置此位不执行持卡人验证
#define OPTION_OFFLINE_DATA_AUTH_PREFORM    0x02 //脱机数据认证不执行

//PayPass 交易类型
#define TYPE_GOODS           0x00    //交易类型(购物)
#define TYPE_REFUND          0x20    //交易类型(退货)

//IC卡参数_下载时存储
typedef struct
{
	u8 ucAID[16];		        	//9F06 应用ID
	u8 ucAIDLen;                  	//     应用aid长度
	u8 ucSelectIndicator;     		//DF01 应用选择指示符（ASI）(=0部分匹配,=1完全匹配)
	u8 ucTargetPercentage;     		//DF17 随机百分比
	u8 ucMaxTargetPercentage;  		//DF16 随机最大百分比
	u8 ucTermFloor[4];        		//9F1B 终端最低限额HEX
    u8 ucOnLinePINFlag;            	//DF18 终端联机PIN支持能力(=0不支持,=1支持)
	u32 uiThresholdValue;			//DF15 随机选择阀值
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

//认证中心公钥参数_下载时存储
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

//证书回收列表_存储_EMV/PBOC L2测试使用
typedef struct
{
	u8 ucRID[5];               		//9F06 与认证中心公钥索引一起标识认证中心的公钥
	u8 ucIndex;                		//9F22 认证中心公钥索引
	u8 ucCertSerial[3];       		//     证书序列号
	u8 ucDeleteFlag;                //     =1已删除 =0未删除
	u16 unCrc;						//	   crc
}T_EMV_REVOCATIONLIST;

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

//交易日志
typedef struct
{
	u8 ucTransDate[3];  		    //9A   交易日期 BCD YYMMDD
	u8 ucTransTime[3];  			//9F21 交易时间 BCD HHMMS
    u8 ucAmountAuth[6];     		//9F02 授权金额(交易金额) BCD
    u8 ucAmountOther[6];    		//9F03 其他金额(返现金额) BCD
	u8 ucTerminalCountry[2];        //9F1A 终终端国家代码
	u8 ucTranCurrCode[2];			//5F2A 交易货币代码
	u8 ucMerchantNameLocation[40+1];//9F4E 商户名称，ASC码以0x00结束
	u8 ucTransType;                 //9C   交易类型 一般为0x00 ,返现请设置0x09
	u8 ucATC[2];                    //9F36 ATC
}T_EMV_TRANS_LOG;

#ifndef MAX_RSA_MODULUS_LEN
#define MAX_RSA_MODULUS_LEN 248
typedef struct
{
    u16 unBits;                        //length in bits of modulus
    u8 ucModulus[MAX_RSA_MODULUS_LEN]; //modulus
    u8 ucExponent[3];                  //public exponent
}T_RSA_PUBLIC_KEY;

#endif

//手机芯片专用
typedef struct
{
    u8 ucCardName[20];              //卡名称
    u8 ucCardNo[10];                //卡号 BCD,不足为后为F
    u8 ucCardTrack2[20];            //二磁道信息
    u8 ucCardTrack3[54];            //三磁道信息
    u8 ucValidDate[2];              //有效期
    u8 ucRfu[2];
    u8 ucKey[8];                    //DF33 过程密钥
    u8 ucDateTime[7];               //DF34 终端读取间 BCD YYYYMMDDHHMMSS
    u8 ucChipSeq[10];               //DF32 芯片序列号
}T_UPCARD;

//函数返回错误码定义
#define EMV_OK                      0          //成功
#define ICC_CMD_ERR                 -1         //APDU命令失败
#define EMV_PARAM_ERR               -2         //EMV参数错误
#define ICC_BLOCK                   -3         //IC卡锁卡
#define ICC_RSP_ERR                 -4         //APDU响应错误
#define EMV_APP_BLOCK               -5         //应用已锁
#define EMV_NO_APP                  -6         //卡片没有终端支持的应用
#define EMV_USER_CANCEL             -7         //交易取消
#define EMV_TIME_OUT                -8         //用户操作超时
#define EMV_DATA_ERR                -9         //卡片数据错误
#define EMV_NOT_ACCEPT              -10        //交易不接受
#define EMV_KEY_EXP                 -12        //认证中心公钥过有效期
#define EMV_DATETIME_ERR            -13        //日期时间错误
#define EMV_FILE_ERR                -14        //读写EMV文件错误
#define EMV_SUM_ERR                 -15        //认证中心公钥校验失败
#define EMV_NOT_FOUND               -16        //读EMV文件没有找到相应的记录
#define EMV_DATA_AUTH_FAIL          -17        //脱机数据认证失败
#define EMV_NOT_MATCH               -18        //两数据不匹配(如2磁的卡号与Tag:5A卡号等)
#define EMV_NO_TRANS_LOG            -19        //无交易日志
#define EMV_ONLINE_FAILED           -20        //联机不成功,连接主机失败
#define EMV_NOT_ORG_ICC             -21        //不是产生闪卡的原始卡
#define ICC_RSP_6985                -22        //GAC中卡片回送6985, 由应用决定是否fallback
#define EMV_EXCP_FILE               -23        //卡片出现在终端异常文件中
#define EMV_USE_CONTACT  		    -24        //如支持其他界面,提示"请使用其他界面进行交易"；不支持其他界面,提示"交易终止"
#define EMV_CARD_EXPIRED            -25        //卡片过有效期
#define EMV_TERMINATE    		    -26        //交易终止
#define EMV_BALANCE_ERR    		    -27        //获取余额失败，提示"交易终止"
#define EMV_NOT_PAY    		        -28        //发生闪卡扣款未成功
#define EMV_ALREADY_PAY    		    -29        //发生闪卡扣款成功
#define EMV_BALANCE_NOT_ENOUGH    	-30        //余额不足
#define EMV_DECLINE                 -31        //交易拒绝(交易结果为拒绝)
#define EMV_NO_PASSWORD             -32        //没有密码或未输入密码
#define EMV_FANGBA                  -33        //发生闪卡
#define EMV_NO_PINPAD_OR_ERR        -34        //密码键盘不存在或工作不正常
#define EMV_NOT_QPBOC               -35        //不支持QuickPass
#define EMV_NOT_SUPPORT             -36        //不支持该交易
#define ICC_RSP_6986                -37        //GPO返回6986, 提示持卡人查验手机，立即下电，在1-1.5s提示重新挥卡
#define EMV_ONLINE_NORESP_MAC_OR_RECV_ERR  -38 //联机不成功,联机无响应或返回MAC错误或接收数据错误,冲正
#define EMV_NO_ONLINE               -39        //未联机
#define EMV_ONLINE_RESP_AAC         -40        //联机成功,联机授权响应码返回拒绝

//PayPass L1
#define ICC_TIME_OUT_ERROR          -60
#define ICC_TRANSMISSION_ERROR      -61
#define ICC_PROTOCOL_ERROR          -62

//PayPass L2
#define EMV_CARD_DATA_MISSING       -70
#define EMV_CAM_FAILED              -71
#define EMV_STATUS_BYTES            ICC_RSP_ERR
#define EMV_PARSING_ERROR           -73
#define EMV_MAX_LIMIT_EXCEEDED      -74
#define EMV_CARD_DATA_ERROR         EMV_DATA_ERR
#define EMV_MAGSTRIPE_NOT_SUPPORTED -76
#define EMV_NO_PPSE                 -77
#define EMV_PPSE_FAULT              -78
#define EMV_EMPTY_CANDIDATE_LIST    EMV_NO_APP
#define EMV_IDS_READ_ERROR          -80
#define EMV_IDS_WRITE_ERROR         -81
#define EMV_IDS_DATA_ERROR          -82
#define EMV_IDS_NO_MATCHING_AC      -83
#define EMV_TERMINAL_DATA_ERROR     -84

//PayPass L3
//#define EMV_TIME_OUT                -90 //已定义
#define EMV_STOP                    -91
#define EMV_AMOUNT_NOT_PRESENT      -92


/********************************************************************
函数功能: 交易回调函数_做EMV交易前设置(也可开机初始化时设置一次)
输入参数:
输出参数:
返 回 值: =0 成功
          <0 错误，错误的返回值请使用本头文件错误码定义，如有特殊请参考回调函数说明
修改信息: 2014-09-26  罗成  创建
********************************************************************/
typedef struct
{
    //EMV与qPBOC共用回调函数
    s32 (*EmvCbGetAppListNum)(void);//得到IC卡其他参数(应用列表)总数
    s32 (*EmvCbLoadAppListByIndex)(u32 uiIndex,T_EMV_APP_LIST *ptAppList);//根据索引号得到IC卡其他参数(应用列表)

    s32 (*EmvCbGetCapkNum)(void);//得到认证中心公钥参数总数
    s32 (*EmvCbLoadCapkByRIDCAPKIndex)(u8 *pucRID,u8 ucCAPKIndex,T_EMV_TERM_CAPK *ptTermCapk);//根据RID和公钥索引得到认证中心公钥参数

    s32 (*EmvCbLoadRevocList)(u8 *pucRID,u8 ucCAPKIndex,u8 *pucCertSerial);//根据RID和公钥索引得到公钥回收列表，=0找到

    s32 (*EmvCbExchangeApdu)(const u8 *pucSend,u32 uiSendLen,u8 *pucResp,u32 *puiRespLen);//发送apdu,响应apdu处理
    s32 (*EmvCbGetRand)(u8 *pucRand,u8 ucLen); //从密码键盘得到指定字节的随机数
    s32 (*EmvCbSearchExceptionList)(u8 *pucPAN,u32 uiPANLen,u8 ucPANSeq);//查找黑名单，用于异常文件检查 =0找到

    //qPBOC专用回调函数
    s32 (*EmvCbReSwipeCard)(void);// 出现闪卡,重新挥卡
    s32 (*EmvCbControlLedAndBeep)(const u8 ucState);//控制LED和BEEP = 0读完最后一条记录之后,=1脱机数据认证之后

    //EMV专用回调函数
    s32 (*EmvCbSelApp)(u8 ucIsFirstSelect,s8 *pcAppLabelList[], s32 iAppNum);//显示应用标签列表，要求持卡人选择 >= 1选择应用列表的序号(从1开始) <0(EMV_USER_CANCEL,EMV_TIME_OUT等)
    s32 (*EmvCbShowHint)(s8 *pcStr,s32 iClearFlag,s32 iDisplayTime);//显示字符串ucStr;显示iDisplayTime秒（可按任意键）返回,iDisplayTime=0不等待直接返回，iDisplayTime=-1有按键才返回
    s32 (*EmvCbInputPIN)(u8 ucPINType,u8 *pucICChallenge,T_RSA_PUBLIC_KEY *tPublicKey,u8 *pucOutPINBlock);//输入PIN, ucPINType(参见宏定义);pucICChallenge 从IC卡得到的随机数,用于脱机密文PIN;tPublicKey IC卡加密PIN公钥，用于脱机密文PIN;pucOutPINBlock:得到的PINBLOCK
    s32 (*EmvCbCertVerify)(void);//持卡人证件验证 =0成功 <0(EMV_USER_CANCEL,EMV_TIME_OUT等)
    s32 (*EmvCbGetSumLogByPAN)(u8 *pucPAN,u32 uiPANLen,u32 *puiOutAmount);//得到一张卡片的交易累计金额，用于判断终端最低限额9f1b
    //s32 (*EmvCbOnlineProc)(u8 *pucRspCode,u8 *pucIAuthData,u32 *puiIAuthDataLen, u8 *pucscript71,u32 *puiScriptLen71,u8 *pucScript72,u32 *puiScriptLen72);//联机发送接收，解析响应的55域数据,RspCode为39域应答码,>0为应用层错误码
    s32 (*EmvCbReferProc)(void); //发卡行返回授权响应码(39域为01或02)显示参考(批准或拒绝)
    s32 (*EmvCbAdviceProc)(void);//GAC之后, 请求通知

    //s32 (*EmvCbCardholderConfirm)(s8 *pcAppLabel);//持卡人确认提示(已修改为EmvCbMenuAppSel)，cAppLabel为显示的应用标签，不需要显示为空
    //s32 (*EmvCbGetPreferenceLanguage)(u8 *pucLanguagePrefer,u8 ucLen);//根据 5F2d首选语言pucLanguagePrefer 得到终端设置的语言数组下标（0--中文，1--english）
}T_EMV_CALLBACK;

DLLAPI void sdkEmvSetCallBackFunc(T_EMV_CALLBACK *ptEmvCallback);//上层应用设置回调函数到Emv内核(启动时或emv交易开始前设置一次),使内核可以调用

/********************************************************************
函数功能:
输入参数:
输出参数:
返 回 值: =0 成功
          <0 错误，错误的返回值参见本头文件错误码定义，如有特殊请参考具体函数说明
修改信息: 2014-09-26  罗成  创建
********************************************************************/

DLLAPI void sdkEmvKernelVersion(s8 *pcStrVer);//得到EMV内核版本号
DLLAPI s32 sdkEmvVerifyCAPK(T_EMV_TERM_CAPK *ptTermCapk);//认证中心公钥校验

//EMV流程
DLLAPI s32 sdkEmvAppSelect(void);//应用选择
DLLAPI s32 sdkEmvAppInit(void);//应用初始化(GPO)
DLLAPI s32 sdkEmvReadAppData(void);//读应用数据
DLLAPI s32 sdkEmvOfflineDataAuth(void);//脱机数据认证
DLLAPI s32 sdkEmvProcessRestrictions(void);//处理限制
DLLAPI s32 sdkEmvCardholderVerification(void);//持卡人验证
DLLAPI s32 sdkEmvTerminalRiskManagement(void);//终端风险管理
DLLAPI s32 sdkEmvTerminalAndCardActionAnalysis(u8 *pucTransResult);//终端行为分析
DLLAPI s32 sdkEmvSeparateOnlineResp(u8 *pucAuthRespCode,u8 *pucIssuerResp,u32 uiIssuerRespLen);//解析联机响应数据,如果pucAuthRespCode(8A,39域) == NULL或=="",则授权响应码要存在于pucIssuerResp(发卡行响应数据,55域)中
DLLAPI s32 sdkEmvOnlineProcessing(s32 iOnlineRet,u8 *pucTransResult);//联机响应后处理,交易结束

//qPBOC专用
DLLAPI s32 sdkEmvQTransPreProc(u8 *pucAmountAuth);//交易预处理，在非接寻卡之前执行,ucAmountAuth :授权金额(6Byte BCD)
DLLAPI s32 skdEmvQTrans(u8 *pucBalance,u8 *pucTransResult,u8 *pucCVMType);//QPBOC完整交易流程,如交易结果(pucTransResult)为联机，请根据pucCVMType执行CVM,pucBalance为交易后的余额(pucBalance[0]=0x01表示9F5D无余额返回)
DLLAPI s32 sdkEmvQIssuerUpdateIsNeed(u8 *pucAuthRespCode,u8 *pucIssuerResp,u32 uiIssuerRespLen);
DLLAPI s32 sdkEmvQIssuerUpdateProcessing(void);
DLLAPI s32 sdkEmvQGetCVMType(void);//qPBOC交易结束后，得到持卡人认证方式
//DLLAPI s32 skdEmvQBalanceQuery(u8 *pucTransDate,u8 *pucBalance);//QPBOC余额查询BCD(6byte)完整流程,入口:pucTransDate交易日期(BCD YYMMDD)，出口:pucBalance余额(BCD 6byte)

//EMV交易流程
//DLLAPI s32 sdkEmvECBalanceQuery(u8 ucDoubleFlag,u8 *pucBalance1,u8 *pucBalance1code,u8 *pucBalance2,u8 *pucBalance2code);//完整流程，双币电子现金余额BCD(6byte)查询;ucDoubleFlag=2(双币),=1(单币);当为ucDoubleFlag=2时,卡片只有一种币时，会返回错误，但pucBalance1,pucBalance1Code会返回，pucBalance2Code返回"\x00\x00"
DLLAPI s32 sdkEmvBalanceQuery(u8 ucTransKernalType,u8 *pucBalance);//余额查询完整流程
DLLAPI s32 sdkEmvReadPANProc(u8 ucTransKernalType,u8 *pucTransDate,u8 *pucStrTrack2,u8 *pucStrPAN);//完整流程,非接读二磁和卡号,入口交易日期(9A   交易日期 BCD YYMMDD)
DLLAPI s32 sdkEmvReadTransLog(u8 ucTransKernalType,u8 *pucRecordNum,T_EMV_TRANS_LOG *ptEmvTransLog); //读取所有交易日志记录(完整流程) ,*pucRecordNum 读出的日志总记录数,*tEmvTransLog :读出的日志结构体数据组

//得到常用EMV函数
DLLAPI s32 sdkEmvGetData(u8 ucP1,u8 ucP2,u8 *pucLen,u8 *pucResp,u8 *pucStatus);//发送get data apdu
DLLAPI void sdkEmvSetTransResult(u8 ucTransResult);//设置交易结果
DLLAPI u8 sdkEmvGetTransResult(void);//得到交易结果
DLLAPI s32 sdkEmvGetTVR(u8 *pucTVR);//得到TVR
DLLAPI s32 sdkEmvGetTSI(u8 *pucTSI);//得到TSI
DLLAPI s32 sdkEmvGetTLVData(u32 uiTag,u8 *pucDataOut,u32 *puiDataOutLen);//得到一个tag的数据
DLLAPI s32 sdkEmvSetTLVData(u32 uiTag,u8 *pucDataIn,u32 uiDataInLen);//设置一个tag数据到到emv内核
DLLAPI s32 sdkEmvGetScriptResult(u8 *pucResult, u32 *puiResultLen);//得到脚本处理结果
DLLAPI s32 sdkEmvGetTrack2AndPAN(u8 *pucStrTrack2,u8 *pucStrPAN);//获取二磁道等效数据(ASC),主账号(ASC)
DLLAPI s32 sdkEmvGetPAN(u8 *pucPAN,u32 *puiPANLen);//得到主账号(BCD,奇数后补'F'),如得Tag5A得不到，从Tag57中得到
DLLAPI s32 sdkEmvGetBalance(u8 *pucBalance);//得到GAC返回的电子现金余额或qPBOC交易后的余额,ucBalance[0] == 0x00为成功返回
DLLAPI s32 sdkEmvGetCardFromTrack(u8 *pucCardNo,u8 *pucTrack2,u8 *pucTrack3); //从磁道中取卡号 track2 2磁道数据 track3 3磁道数据

DLLAPI void sdkRemoveTailChars(u8 *pucStr, u8 ucRemove);//去除字符串pStr未尾指定的字符(ucRemove),如去除卡号未尾的'F'
DLLAPI u8 *sdkEmvSeparateTLV(u8 *pucTLVData,u32 *puiTag,u32 *puiDataOutLen);//解析tlv数据，得到解析后tlv数据指针，tag，长度
DLLAPI u32 sdkEmvPackageTLV(u32 uiTag,u8 *pucData,u32 uiDataLen,u8 *pucOutTLVData);//根据Tag,Data,DataLen，打包为TLV结构的数据,返回TLV数据总长(暂只处理两(一)字节Tag,忽略(长度=0,>0xFF)的TAG)
DLLAPI s32 sdkEmvFindTLV(u8 *pucTLVData,u32 uiTLVDataLen,u32 uiTag,u8 *pucDataOut,u32 *puiDataOutLen);//根据TLV数据，查找指定的TAG，并把TAG值和长度输出
DLLAPI s32 sdkFindTagFromTLVList(u32 uiTLVLen,u8 *ucTLV,u32 uiTag);  //根据TLV列表,查找Tag,找到=0,未找到=1
DLLAPI s32 sdkFindTagFromTLList(u32 uiTLListLen,u8 *ucTLList,u32 uiTag); //根据TL列表,例如CDOL,PDOL,查找Tag,找到=0,未找到=1

DLLAPI s32 sdkEmvRSAPublicKeyDecrypt(u8 *ucOutput, u32 *uiOutputLen, u8 *ucInput, u32 uiInputLen, T_RSA_PUBLIC_KEY *tPublicKey);


//让上层应用得到emv内核参数指针,使其可以设置
DLLAPI T_EMV_TERM_PARAM *sdkEmvGetTermParam(void);//得到终端参数指针
DLLAPI T_EMV_TRANS_PARAM *sdkEmvGetTransParam(void);//得到交易参数指针

//手机芯片专用
DLLAPI s32 sdkReadUpCard(u8 *pucDataTime,T_UPCARD *ptUpCard);//读手机芯片卡数据,ucDataTime为当前时间(bcd YYYYMMDDHHMMSS)

//paypass
DLLAPI s32 sdkPaypassSelODAMethod(void);
DLLAPI s32 sdkPaypassTerminalRiskManagement(void);

#ifdef __cplusplus
	}
#endif

#endif

