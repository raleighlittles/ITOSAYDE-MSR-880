	


CString ShowHexData(unsigned char * Data,int num)		//在text显示16进制数据     就是one_two
{ 
		CString strValue="";
		CString str="";

		for(int i=0;i<num;i++)
		{	
			str.Format("%02x ",Data[i]);
			strValue=strValue+str;
		}

//		for ( int nIndex = 0; nIndex < strValue.GetLength(); nIndex++ )
//		{
		//	if( (strValue[nIndex]>='a') && (strValue[nIndex]<='z') )
			//	strValue[nIndex] = strValue[nIndex] - 32;
		
//		}
		strValue.MakeUpper();

		return strValue;
}

void GetHexData(CString strValue, unsigned char * buff)			//在text里获取16进制数据
{
	CString str;
	unsigned char data[225];
	//int buff[255];

	memset(data,0,sizeof(data));


	strcpy((char*)data,strValue);
		//GetLength
	int j,i;
	for(j=0,i=0;i<strValue.GetLength();i++)	//strValue.GetLength()
	{
		int a,b;
		if('0'<=data[i] && data[i]<='9')
			data[i]=data[i]-48;
		else if('A'<=data[i] && data[i]<='F')
			data[i]=data[i]-55;
		else if('a'<=data[i] && data[i]<='f')
			data[i]=data[i]-87;
	}
	
	for( i=0;i<(strlen((const char*)data)+1)/2;i++)		//strlen((const char*)data)
	{
		j=2*i;
		buff[i]=data[j]*16+data[j+1];	
	//	buff[i]=(unsigned char *)(data[j]*16+data[j+1]);
	}
	if(strlen((const char*)data)%2==1)
		buff[i-1]=data[j];


//	return buff;
}