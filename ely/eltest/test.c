#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "test_h.h"

int main() {
    char input[1024];
    size_t length;

    printf("Enter a line of text: ");
    length = _getline(input, sizeof(input));

    printf("Line read (%zu bytes): %s\n", length, input);

    return 0;
}
