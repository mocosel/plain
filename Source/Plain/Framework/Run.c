/*
 * Author   Nerijus Ramanauskas <nerijus.ramanauskas@mocosel.org>,
 * Date     11/09/2013,
 * Revision 11/09/2013,
 *
 * Copyright 2013 Nerijus Ramanauskas.
 */

#include <Plain/VM.h>

MOCOSEL_WORD_DOUBLE MOCOSEL_RUN(struct MOCOSEL_MANIFEST * __restrict manifest,
                                struct MOCOSEL_OBJECT   * __restrict object,
                                struct MOCOSEL_SEGMENT  * __restrict segment) {
    MOCOSEL_ASSERT(manifest != NULL);
    MOCOSEL_ASSERT(object != NULL);
    MOCOSEL_ASSERT(segment != NULL);
    /* MOCOSEL_ERROR_SYSTEM_WRONG_DATA. */
    if(manifest == NULL || object == NULL || segment == NULL) {
        return MOCOSEL_ERROR_SYSTEM_WRONG_DATA;
    }
    MOCOSEL_WORD_DOUBLE error = MOCOSEL_CONCAT(&object->segment.data, segment);
    if(error != 0) {
        return error;
    }
    error = MOCOSEL_TOKENIZE(&object->segment.structure, NULL, &manifest->pattern, segment);
    if(error != 0) {
        return error;
    }
    error = MOCOSEL_WALK(&object->segment.structure, &object->registry.data, NULL);
    if(error != 0) {
        return error;
    }
    return 0;
}