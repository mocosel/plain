/*
 * Author   Neriy Roe <nr@mocosel.com>.
 * Date     05/25/2014.
 * Revision 09/01/2015.
 *
 * Copyright 2015 Nerijus Ramanauskas.
 */

#pragma once

/* C++. */
#ifdef __cplusplus
extern "C" {
#endif

#include "System/Platform.h"
#include "Shared/Segment.h"

/* Appends <source> to <destination>. Note that <destination> will be reallocated. */
MOCOSEL_WORD_DOUBLE MOCOSEL_CONCAT(struct MOCOSEL_SEGMENT* destination, MOCOSEL_WORD_DOUBLE length, const MOCOSEL_BYTE* source);

/* Returns 32-bit hash of <data>. */
MOCOSEL_WORD_DOUBLE MOCOSEL_HASH(const MOCOSEL_BYTE* data, MOCOSEL_WORD_DOUBLE length);

/* Reserves <number> bytes of memory in <segment>. */
MOCOSEL_WORD_DOUBLE MOCOSEL_RESERVE(MOCOSEL_WORD_DOUBLE number, struct MOCOSEL_SEGMENT* segment);

/* Allocates <destination> bytes of memory. Note that <data> will be reallocated if <source> > 0, released if <destination> = 0. */
void* MOCOSEL_RESIZE(void* data, MOCOSEL_WORD_DOUBLE destination, MOCOSEL_WORD_DOUBLE source);

/* C++. */
#ifdef __cplusplus
}
#endif
