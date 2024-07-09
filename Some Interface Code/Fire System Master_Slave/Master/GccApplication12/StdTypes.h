/*
 * StdTypes.h
 *
 * Created: 11/2/2022 3:01:03 PM
 *  Author: ahmed
 */ 


#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef   unsigned char         u8;
typedef     signed char         s8;
typedef            char         c8;
                                 
typedef   unsigned int         u16;
typedef     signed int         s16;

typedef   unsigned long         u32;
typedef     signed long         s32;

#define  NULLPTR             ((void*)0)

typedef enum
{
	OK,
	NOK,
	NULL,
	OUT_OF_RANGE
	}Error_Type;
	
typedef enum 
{
	FLASE,
	TURE
	}bool_type;	
	
#define  Max_u16        ((u16)65535)
#define  Max_s16	    ((s16)32767)
#define  Min_s16        ((s16)-32768)
#define  Min_u16          ((u16)0)

#define  Max_u8         ((u8)255)
#define  Max_s8	        ((s8)127)
#define  Min_s8         ((s8)-128)
#define  Min_u8          ((u8)0)



#define  Max_u32        ((u32)4294967295)
#define  Max_s32	    ((s32)2147483647)
#define  Min_s32        ((s32)2147483648)
#define  Min_u32          ((u32)0)
#endif /* STDTYPES_H_ */