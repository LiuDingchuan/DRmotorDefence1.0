//=====================================================================================================
//                       DataScope 下位机协议帧生成库 v1.0
//Files : DataScope_CP.H & DataScope_CP.Lib
//Author: L.S.H. @ ACE-Tech   
//Date  : 2014.02.03
//=====================================================================================================

/******************************************************************************************************
////////////////////////////// 一、前言 /////////////////////////////////////

注意：
      使用此库文件前，请先确保您系统的串口通讯正常工作。
			
			若您是第一次尝试和 DataScope 建立通讯，不妨仔细浏览余下内容。

###################################################################################

1、库文件将帮助您快速、简易的搭建起与 DataScope 的数据通讯。
2、使用库，您无需了解通讯协议，只需调用相应的函数，并通过串口发送帧数据即可。
3、库文件将占用您系统的部分资源。
4、如需获取更多资源，请访问我们的官网：http://www.ACE--Tech.com
5、DataScope 讨论群：127044172
    
//=====================================================================================================
////////////////////////////// 二、库版本里程碑 /////////////////////////////////////

1、 2014.01.03  --  DataScope 下位机协议库 v1.0 创建。

 
//=====================================================================================================
////////////////////////////// 三、资源占用 /////////////////////////////////////

//库文件(v1.0)，ROM及RAM占用情况参考：

  226 bytes of CODE memory  ( At Cortex-M3 ) 
  44  bytes of DATA memory  ( At Cortex-M3 )

使用我们提供的库文件将占用您系统 226 字节的存储空间及 44 字节的随机存储空间。

若需要编写适用于您自己系统下的发送协议，
请在我们官网中 DataScope 板块中查找参考内容
 
//=====================================================================================================
////////////////////////////// 四、库文件说明及使用例子 /////////////////////////////////////
 
         v1.0 版本库文件拥有一个 42 字节宽度的数组及 2 个功能函数。

数组：DataScope_OutPut_Buffer[42] ，待发送帧数据缓存区，里面存放经过功能函数格式化后的待发送帧数据。 

功能函数：
         1、DataScope_Get_Channel_Data(float Data,unsigned char Channel) ：
				    此函数无返回。
						函数功能说明：将指定通道的待发送单精度浮点数据转换为字节数据存放至 DataScope_OutPut_Buffer (待发送帧数据缓存区)。
						              
						参数说明:
						          1、Channel，单字节无符号整型，识别范围：1 - 10
											   含义：指定本次数据对应哪个通道。
												 
						          2、Data ，  单精度浮点型。
											   含义：传递待转换的通道数据。
												 
         2、DataScope_Data_Generate(unsigned char Channel_Number) ：
				    返回一个单字节无符号整型。
						
						返回说明：返回串口需要发送的字节个数，返回 0 表示发生本次帧数据生成错误。
						
						函数功能说明：产生指定通道个数的待发送帧数据。存放至 DataScope_OutPut_Buffer (待发送帧数据缓存区)，
						
						参数说明;
						          1、Channel_Number，单字节无符号整型，识别范围：1 - 10
											   含义：设定需要发送的通道个数，最少1个通道，最多10个通道。
						
						补充说明：与 DataScope 通讯的帧数据长度不固定，故调用 DataScope_Data_Generate 时
						          传递不同的Channel_Number，将在DataScope_OutPut_Buffer中生成不同长度的 格式化帧数据。
						
--------------------------------------------------------------------------------------------------------
//MDK下库文件使用例子（stm32 发送10个通道数据）：
   
   int main(void)
   {
	   unsigned char i;          //计数变量
		 unsigned char Send_Count; //串口需要发送的数据个数
		 
		 uart_init(72,115200);     //串口1初始化， 波特率115200，数据位8，停止位1，无校验位，无流控制
		 
     while(1)            
	   { 		    		    				 
			DataScope_Get_Channel_Data( 1.0 , 1 ); //将数据 1.0  写入通道 1
      DataScope_Get_Channel_Data( 2.0 , 2 ); //将数据 2.0  写入通道 2
      DataScope_Get_Channel_Data( 3.0 , 3 ); //将数据 3.0  写入通道 3
      DataScope_Get_Channel_Data( 4.0 , 4 ); //将数据 4.0  写入通道 4
		  DataScope_Get_Channel_Data( 5.0 , 5 ); //将数据 5.0  写入通道 5
      DataScope_Get_Channel_Data( 6.0 , 6 ); //将数据 6.0  写入通道 6
			DataScope_Get_Channel_Data( 7.0 , 7 ); //将数据 7.0  写入通道 7
      DataScope_Get_Channel_Data( 8.0 , 8 ); //将数据 8.0  写入通道 8
			DataScope_Get_Channel_Data( 9.0 , 9 ); //将数据 9.0  写入通道 9
      DataScope_Get_Channel_Data( 10.0 , 10); //将数据 10.0 写入通道 10
 
	  	Send_Count = DataScope_Data_Generate(10); //生成10个通道的 格式化帧数据，返回帧数据长度
		
		  for( i = 0 ; i < Send_Count; i++)  //循环发送,直到发送完毕   
	 	  {
		    while((USART1->SR&0X40)==0);  
  	    USART1->DR = DataScope_OutPut_Buffer[i]; //从串口丢一个字节数据出去      
		  }
  
     delay_ms(50); //20fps, 帧间隔时间。 不同电脑配置及 USB-TTL 设备的优劣均会影响此时间的长短，建议实测为准。  
    }
	}

******************************************************************************************************/
//头文件内容：

#ifndef _VISUALSCOPE_H
#define _VISUALSCOPE_H

extern unsigned char DataScope_OutPut_Buffer[42];	   //待发送帧数据缓存区


void DataScope_Get_Channel_Data(float Data,unsigned char Channel);    // 写通道数据至 待发送帧数据缓存区

unsigned char DataScope_Data_Generate(unsigned char Channel_Number);  // 发送帧数据生成函数 
 
 
#endif 
