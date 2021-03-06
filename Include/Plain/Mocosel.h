/*
 * Author   Neriy Roe <nr@mocosel.com>.
 * Date     02/23/2013.
 * Revision 09/01/2015.
 *
 * Copyright 2015 Nerijus Ramanauskas.
 */

#pragma once

/* C++. */
#ifdef __cplusplus
extern "C" {
#endif

#define MOCOSEL_API 20153 /* API version. */

#include "CL.h"
#include "Shared/Error.h"
#include "Shared/Processing/Type.h"
#include "Shared/Processing/List.h"
#include "Shared/Processing/Value.h"
#include "Shared/Processing/Delegate.h"
#include "Runtime/Subroutine.h"

/* Returns argument at <position>. */
MOCOSEL_INLINE struct MOCOSEL_VALUE* MOCOSEL_ARGUMENT(struct MOCOSEL_LIST* node, MOCOSEL_WORD_DOUBLE position) {
    MOCOSEL_ASSERT(node != NULL);
    if(node == NULL) {
        return NULL;
    }
    MOCOSEL_WORD_DOUBLE length = node->layout.to - node->layout.from;
    MOCOSEL_WORD_DOUBLE offset = sizeof(struct MOCOSEL_VALUE) * position;
    if(offset >= length) {
        return NULL;
    }
    return (struct MOCOSEL_VALUE*)&node->layout.from[offset];
}

/* Returns number of arguments. */
MOCOSEL_INLINE MOCOSEL_WORD_DOUBLE MOCOSEL_ARITY(const struct MOCOSEL_LIST* node) {
    MOCOSEL_ASSERT(node != NULL);
    if(node == NULL) {
        return 0;
    }
    return (node->layout.to - node->layout.from) / sizeof(struct MOCOSEL_VALUE);
}

/* Stores <data> in <value>. Note that <data> will be copied if <length> > 0. */
MOCOSEL_WORD_DOUBLE MOCOSEL_EXPORT(MOCOSEL_BYTE* data, MOCOSEL_WORD_DOUBLE length, MOCOSEL_WORD_DOUBLE type, struct MOCOSEL_VALUE* value);

/* Compiles <segment> to nodes and arguments. Note that only <parent> can be NULL. */
MOCOSEL_WORD_DOUBLE MOCOSEL_TOKENIZE(void* context, struct MOCOSEL_LIST* node, struct MOCOSEL_LIST* parent, const MOCOSEL_BYTE* pattern, struct MOCOSEL_SEGMENT* segment, MOCOSEL_DELEGATE tracker);

/* Frees all memory occupied by <node>. */
void MOCOSEL_UNLINK(struct MOCOSEL_LIST* node);

/* Evaluates the list given by <node>. Note that both <context> and <value> can be NULL. */
MOCOSEL_WORD_DOUBLE MOCOSEL_WALK(void* context, MOCOSEL_SUBROUTINE function, struct MOCOSEL_LIST* node, struct MOCOSEL_VALUE* value);

/* C++. */
#ifdef __cplusplus
}
#endif
