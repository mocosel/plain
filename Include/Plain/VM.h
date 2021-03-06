/*
 * Author   Neriy Roe <nr@mocosel.com>.
 * Date     10/05/2013.
 * Revision 09/01/2015.
 *
 * Copyright 2015 Nerijus Ramanauskas.
 */

#pragma once

/* C++. */
#ifdef __cplusplus
extern "C" {
#endif

#include "Mocosel.h"
#include "Framework/Host/Environment.h"
#include "Framework/Object.h"

typedef struct MOCOSEL_ENVIRONMENT  MOCOSEL_ENVIRONMENT;
typedef struct MOCOSEL_LIST         MOCOSEL_LIST;
typedef struct MOCOSEL_OBJECT       MOCOSEL_OBJECT;
typedef struct MOCOSEL_SEGMENT      MOCOSEL_SEGMENT;
typedef struct MOCOSEL_VALUE        MOCOSEL_VALUE;

/* Compiles and evaluates <source>. */
MOCOSEL_WORD_DOUBLE MOCOSEL_EVALUATE(MOCOSEL_ENVIRONMENT* environment, MOCOSEL_SUBROUTINE function, const MOCOSEL_BYTE* source, MOCOSEL_DELEGATE tracker, MOCOSEL_VALUE* value);

/* Returns library version. Other version-specific information will be stored in <environment>. */
MOCOSEL_WORD_DOUBLE MOCOSEL_VERSION(MOCOSEL_ENVIRONMENT* environment);

/* C++. */
#ifdef __cplusplus
}
#endif
