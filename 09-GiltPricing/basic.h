//********************************************************
//
//	Michael J Phillips
//	Copyright 2013
//	All rights reserved.
//
//********************************************************

#ifndef _BASIC_H_
#define _BASIC_H_

unsigned int DMY_to_serial(unsigned int day, unsigned int month, unsigned int year);
void serial_to_DMY(unsigned int serial, unsigned int& day, unsigned int& month, unsigned int& year);

#endif
