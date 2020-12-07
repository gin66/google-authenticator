#include "sha1.h"
#include <stdio.h>

int main(int argc, char **argv) {
	uint8_t key[] = { 0, 68, 50, 20, 199, 66, 84, 182, 53, 207};
	uint8_t msg[] = { 0, 0, 0, 0, 3, 49, 140, 53};
      Sha1.initHmac(key, 10);
	  for (uint8_t i = 0;i < 8;i++) {
	  Sha1.write(msg[i]);
	  }
      uint8_t *hash = Sha1.resultHmac();
	  uint8_t o = hash[19] & 0x0f;
	  uint8_t out[4];
	  out[3] = hash[o];
	  out[2] = hash[o+1];
	  out[1] = hash[o+2];
	  out[0] = hash[o+3];
	  uint32_t *o32 = (uint32_t *)out;
	  char tmp[8];
	  sprintf(tmp,"%d\n", (*o32 & (0x7fffffff)) %1000000 + 1000000);
	  printf("%s\n",tmp+1);
	  puts("ORIG:");
	  puts("[0, 68, 50, 20, 199, 66, 84, 182, 53, 207]");
puts("[0, 0, 0, 0, 3, 49, 140, 53]");
	puts("[212, 61, 13, 217, 91, 221, 210, 93, 20, 35, 241, 133, 135, 181, 42, 46, 229, 194, 118, 238]");
		puts("716546");
}
