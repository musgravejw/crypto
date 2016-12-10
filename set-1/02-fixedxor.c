#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* decimalToHex(unsigned char c) {
  char* result = malloc(2);
  char* base16Map = "0123456789ABCDEF";
  int i = 0;

  result[0] = base16Map[(c - (c % 16)) / 16];
  result[1] = base16Map[c % 16];
  result[2] = '\0';

  return result;
}

char* fixedXOR(char* a, char* b) {
  if (strlen(a) != strlen(b)) return NULL;

  char* result = malloc(strlen(a));

  for (int i = 0; i < strlen(a); i += 2) {
    unsigned char c = 0;
    unsigned char d = 0;

    char* hexCharA = malloc(2);
    char* hexCharB = malloc(2);

    memcpy(hexCharB, &b[i], 2);
    d = strtol(hexCharB, NULL, 16);

    memcpy(hexCharA, &a[i], 2);
    c = strtol(hexCharA, NULL, 16);

    strcat(result, decimalToHex(c^d));
  }

  return result;
}
