#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *applyCeaserCipher (const char *TARGET, const int SHIFTING_NUMBER) {
  const size_t targetLen = strlen(TARGET);
  char *result = malloc(targetLen * sizeof(char));
  int shifted_char;


  for (int i = 0; i < targetLen; i++) {
    if (TARGET[i] >= 'a' && TARGET[i] <= 'z') {
      shifted_char = TARGET[i] + SHIFTING_NUMBER;
      if (shifted_char > 'z') {
        shifted_char = (shifted_char - 'z') + ('a' - 1);
      }
    } else if (TARGET[i] >= 'A' && TARGET[i] <= 'Z') {
      shifted_char = TARGET[i] + SHIFTING_NUMBER;
      if (shifted_char > 'Z') {
        shifted_char = (shifted_char - 'Z') + ('A' - 1);
      }
    } else {
      result[i] = TARGET[i];
      continue;
    }
    result[i] = shifted_char;
  }
  return result;
}

int main(int argc, const char *argv[]) {
  const char *target = "picoCTF{dspttjohuifsvcjdpoabrkttds}";
  printf("Encrypted message: %s\n\n", target);

  const int LEN = 25;
  for (int i = 1; i <= LEN; i++) {
    char *result = applyCeaserCipher(target, i);
    printf("Decryptions: %s\n", applyCeaserCipher(target, i));
    free(result);
  }

  return 0;
}
