#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scoring(char* str) {
  int result = 0;
  int map[] = { 8, 1, 3, 4, 13, 2, 2, 6, 7, 0, 1, 4, 2, 7, 8, 2, 0, 6, 6, 9, 3, 1, 2, 0, 2, 0 };

  for (int i = 0; i < strlen(str); i++) {
    char c = str[i];
    if (c >= 91 && c <= 96) {
      result -= 2;
    } else if (c == 32) {
      result += 1;
    } else if (c >= 65 && c <= 122) {
      if (c >= 97) c -= 32;

      c -= 65;

      if (c >= 26) c = 26;

      result += map[c];
    } else {
      result -= 2;
    }
  }

  return result;
}

char* singleByteXOR(char* cipher, char key) {
  char* result = malloc(strlen(cipher));

  for (int i = 0; i < strlen(cipher); i += 2) {
    unsigned char c = 0;

    char* hexChar = malloc(2);

    memcpy(hexChar, &cipher[i], 2);
    c = strtol(hexChar, NULL, 16);

    char r[2] = { c^key };

    strcat(result, r);
  }

  return result;
}

char* decrypt(char* cipher) {
  int max = 0;
  int key = 0;

  for (int i = 0; i < 128; i++) {
    char* str = singleByteXOR(cipher, i);
    int score = scoring(str);
    if (score > max) {
      max = score;
      key = i;
    }
  }

  return singleByteXOR(cipher, key);
}

int main() {
  char* s = decrypt("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");
  printf("%s\n", s);
}
