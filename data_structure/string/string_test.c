#include <stdio.h>
#include "string.h"

void character_classification_test(void);

int main(void)
{
  printf("string testing\n");

  int select;
  while (1) {
    printf("0:character classification\n");
    scanf("%d", &select);
    switch (select) {
      case 0:
        character_classification_test();
        break;
      default:
        break;

    }
  }
  

  return 0;
}

void character_classification_test(void)
{
  printf("character classification testing\n");

  int i = 0;

  // isalnum
  printf("isalnum:\n");
  for (i = 32; i <= 126; i++) {
     if (isalnum((char)i))
       printf("%c:true\n", (char)i);
     else
       printf("%c:false\n", (char)i);
  }
  printf("\n");

  // isalpha
  printf("isalpha:\n");
  for (i = 32; i <= 126; i++) {
     if (isalpha((char)i))
       printf("%c:true\n", (char)i);
     else
       printf("%c:false\n", (char)i);
  }
  printf("\n");
  
  // islower
  printf("islower:\n");
  for (i = 32; i <= 126; i++) {
     if (islower((char)i))
       printf("%c:true\n", (char)i);
     else
       printf("%c:false\n", (char)i);
  }
  printf("\n");

  // isupper
  printf("isupper:\n");
  for (i = 32; i <= 126; i++) {
     if (isupper((char)i))
       printf("%c:true\n", (char)i);
     else
       printf("%c:false\n", (char)i);
  }
  printf("\n");


}
