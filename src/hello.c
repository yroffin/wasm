#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char ** argv) {
  int h;
  h = open("toto.txt", 0777);

  if(h < 0) {
    perror("Erreur");
  }

  struct stat Stat;
  if (fstat(h, &Stat) < 0) {
  }

  char Memory[32000];
  const ssize_t ChunkSize = 16;
  ssize_t Offset = 0;
  ssize_t ReadBytes = 0;
  do {
    ReadBytes = read(h, Memory + Offset, ChunkSize);
    if (ReadBytes < 0) {
      return 1;
    }
    Offset += ReadBytes;
  } while (ReadBytes != 0);

  printf("Hello World %d '%s'\n", h, Memory);
}