/*
 * Author   Nerijus Ramanauskas <nerijus.ramanauskas@mocosel.org>,
 * Date     11/01/2014,
 * Revision 11/05/2014,
 *
 * Copyright 2014 Nerijus Ramanauskas.
 */

#include <stdlib.h>
#include <stdio.h>
#include <Plain/VM.h>

// Prompt will return a proper value.
int prompt(void* context, const char* identifier, int (*listener) (void*, const char*));

// Run will return a proper value, the application will be terminated.
int run(void* context, const char* source);

int main() {
    MOCOSEL_ENVIRONMENT environment;
    if(MOCOSEL_VERSION(&environment) == 0) {
        printf("Warning! Your platform is not supported, some functionality might be unavailable.");
    }
    return prompt(&environment, "do: ", &run);
}