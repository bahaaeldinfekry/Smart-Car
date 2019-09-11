/*
 * BitsHandle.h
 *
 * Created: 09-Sep-19 2:03:56 PM
 *  Author: al ghazaly
 */ 


#ifndef BITSHANDLE_H_
#define BITSHANDLE_H_

#define setBit(REG,BN)			REG |=  (1<<BN)
#define clearBit(REG,BN)		REG &= ~(1<<BN)
#define toggleBit(REG,BN)		REG ^=  (1<<BN)

#define setByte(REG)			REG =  (0xFF)
#define clearByte(REG)		    REG =  (0x00)
#define toggleByte(REG)		    REG ^= (0xFF)

#define setBits(REG,BM)			REG |=  (BM)
#define clearBits(REG,BM)		REG &= ~(BM)
#define toggleBits(REG,BM)		REG ^=  (BM)



#define readBit(REG,BN)			(REG&(1<<BN))



#endif /* BITSHANDLE_H_ */