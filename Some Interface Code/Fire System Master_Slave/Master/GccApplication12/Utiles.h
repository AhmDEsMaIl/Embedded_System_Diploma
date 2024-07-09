/*
 * Utiles.h
 *
 * Created: 11/2/2022 2:55:40 PM
 *  Author: ahmed
 */ 


#ifndef UTILES_H_
#define UTILES_H_

#define  check_BIT(num,Bit)           (1&(num>>Bit))

#define  READ_BIT(REG,Bit)          ((REG>>Bit)&1)
#define  SET_BIT(REG,Bit)           (REG=(REG|(1<<Bit)))
#define  CLR_BIT(REG,Bit)           (REG=(REG&(~(1<<Bit))))
#define  Toggle_BIT(REG,Bit)        (REG=(REG^(1<<Bit)))
#define  Toggle_REG(REG)            (REG=(REG^(0xff)))
#define  Toggle_PIN(PIN)             (PIN=!(PIN))
#endif /* UTILES_H_ */