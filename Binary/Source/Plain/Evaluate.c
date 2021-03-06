/*
 * Author   Neriy Roe <nr@mocosel.com>.
 * Date     11/01/2014.
 * Revision 08/30/2015.
 *
 * Copyright 2015 Nerijus Ramanauskas.
 */

#include <stdio.h>
#include <Plain/VM.h>

/* Report syntax errors to the stream, passed by <context>. */
void report(void* context, const MOCOSEL_BYTE* data, MOCOSEL_WORD_DOUBLE length, MOCOSEL_WORD_DOUBLE type);

/* Resolve <data>, using <value> for optional substitution. */
MOCOSEL_WORD_DOUBLE resolve(void* context, void* data, MOCOSEL_WORD_DOUBLE type, struct MOCOSEL_VALUE* value);

/* Evaluate <source>, passing <context> to <report> and <resolve>. */
int evaluate(void* context, const char* source) {
    MOCOSEL_WORD_DOUBLE error = MOCOSEL_EVALUATE((MOCOSEL_ENVIRONMENT*)context, &resolve, (const MOCOSEL_BYTE*)source, &report, NULL);
    if(error == MOCOSEL_ERROR_SYNTAX) {
        printf("The evaluation failed due to a syntax error.\n");
    } else if(error != 0) {
        printf("The evaluation failed due to an unidentified error (0x%X).\n", error);
    }
    return 0;
}
