/*
 * header.h
 *
 *  Created on: 2024. 10. 25.
 *      Author: FM23
 */

#ifndef TESTFILE_HEADER_H_
#define TESTFILE_HEADER_H_

#include "Header_275.h"

// 1. 전역 변수 선언
#ifdef USE_GLOBAL_H
#define Global
#else
#define Global extern
#endif

Global float a;

#endif /* TESTFILE_HEADER_H_ */
