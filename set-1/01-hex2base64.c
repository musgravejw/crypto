#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char indexToBase64(int i) {
  char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  return a[i];
}

void hexToBase64(char* hexBuffer) {
  char* result = (char *) malloc(sizeof(hexBuffer));

  for (int i = 0; i < strlen(hexBuffer); i += 6) {
    unsigned char a = 0;
    unsigned char b = 0;
    unsigned char c = 0;
    unsigned char d = 0;
    unsigned char e = 0;
    unsigned char f = 0;

    char hexChar[2];
    memcpy(hexChar, &hexBuffer[i], 2);
    a = strtol(hexChar, NULL, 16);
    b = strtol(hexChar, NULL, 16);

    a = a >> 2;
    b = ((1 << 2) - 1) & b;
    b = b << 4;

    memcpy(hexChar, &hexBuffer[i+2], 2);
    c = strtol(hexChar, NULL, 16);
    d = strtol(hexChar, NULL, 16);

    c = c >> 4;
    d = ((1 << 4) - 1) & d;
    d = d << 2;

    memcpy(hexChar, &hexBuffer[i+4], 2);
    e = strtol(hexChar, NULL, 16);
    f = strtol(hexChar, NULL, 16);

    e = e >> 6;
    f = ((1 << 6) - 1) & f;

    char s[5] = {
      indexToBase64(a),
      indexToBase64(b+c),
      indexToBase64(d+e),
      indexToBase64(f)
    };

    strcat(result, s);
  }

  return result;
}
