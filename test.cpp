
#include <stdio.h>
#include <netinet/in.h>

int main(int arg1, char *arg2[]){

  FILE *file1, *file2;
  uint8_t buffer1[4];
  uint8_t buffer2[4];


  file1 = fopen(arg2[1], "rb");
  file2 = fopen(arg2[2], "rb");
  // 8비트 씩 끝까지
  fread(buffer1,8,1,file1);
  fread(buffer2,8,1,file2);

  fclose(file1);
  fclose(file2);

  uint32_t *p1 = reinterpret_cast < uint32_t * > (buffer1);
  uint32_t *p2 = reinterpret_cast < uint32_t * > (buffer2);


  uint32_t n1 = ntohl(*p1);
  uint32_t n2 = ntohl(*p2);

  uint32_t n3 = n1 + n2;

  printf ("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n3, n3);
  return 0;
}
