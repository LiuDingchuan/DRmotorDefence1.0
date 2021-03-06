#include "matrixkey.h"


void Key_Configuration(void)
{
	//矩阵键盘
	GPIO_Set(GPIOB,PIN12|PIN13|PIN14|PIN15,GPIO_MODE_OUT,GPIO_OTYPE_PP,GPIO_SPEED_2M,GPIO_PUPD_PU);//行栈 推挽输出
	GPIO_Set(GPIOC,PIN6|PIN7|PIN8|PIN9,GPIO_MODE_IN,GPIO_OTYPE_PP,GPIO_SPEED_2M,GPIO_PUPD_PU);//列栈 上拉输入
}

u8 Check_Matrixkey(void)
{
	  u8 cord_h=0XFF,cord_l=0XFF;//h为行线 l为列线
		u8 Val = 0xFF;
		
	  Key_Configuration();
		//行线输出全部设置为0
		GPIO_WriteBit(GPIOB,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15, Bit_RESET);
		Delay_us(1);
	
		//读入列线值
		cord_l&=(u8)((GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6)<<0)|(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7)<<1)|(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8)<<2)|(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9)<<3));
		if(cord_l!=0X0F)
		{
			Delay_ms(10);		//去抖
			cord_l&=(u8)((GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6)<<0)|(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7)<<1)|(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8)<<2)|(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9)<<3));
			if(cord_l!=0X0F)
			{
                //列线 推挽输出
                GPIO_Set(GPIOC,PIN6|PIN7|PIN8|PIN9,GPIO_MODE_OUT,GPIO_OTYPE_PP,GPIO_SPEED_2M,GPIO_PUPD_PU);
                //行线 上拉输入
                GPIO_Set(GPIOB,PIN12|PIN13|PIN14|PIN15,GPIO_MODE_IN,GPIO_OTYPE_PP,GPIO_SPEED_2M,GPIO_PUPD_PU);
                //列线输出全部设置为0
                GPIO_WriteBit(GPIOC,GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9, Bit_RESET);
                Delay_ms(2);
                //读入行线值
                cord_h&=(u8)((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)<<3)|(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13)<<2)|(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14)<<1)|(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15)<<0));

                Val=~(cord_h<<4|cord_l);
                return Val;
			}
			//为什么要return两次
		}
		return ~Val;
}

void Key_Ctrl(void)
{
	switch(Check_Matrixkey())
	{
		case S1:Led8DisData(1);
		break;
		
		case S2:Led8DisData(2);
		break;
		
		case S3:Led8DisData(3);
		break;
		
		case S4:Led8DisData(4);
		break;
		
		case S5:Led8DisData(5);
		break;
		
		case S6:Led8DisData(6);
		break;
		
		case S7:Led8DisData(7);
		break;
		
		case S8:Led8DisData(8);
		break;
		
		case S9:Led8DisData(9);
		break;
		
		case S10:Led8DisData(10);
		break;
		
		case S11:Led8DisData(11);
		break;
		
		case S12:Led8DisData(12);
		break;
	}
}





















