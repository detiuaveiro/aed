//
// Algoritmos e Estruturas de Dados --- 2023/2024
//
// João Manuel Rodrigues, Joaquim Madeira, May 2020, Nov 2023
//
// A FileReader is an object that keeps a buffer of the last read data
// from a file, together with the file pointer and file name.
//
#ifndef _FILEREADER_
#define _FILEREADER_

#include <errno.h>
#include <stdio.h>

typedef struct {
  FILE* file;    // the open file
  char* name;    // the file name
  char* buffer;  // the buffer with last line read from the file
  size_t bsize;  // the current size of the buffer
  int error;     // the error code of the last operation 0=OK, otherwise errno
} FileReader;

FileReader* FileReaderOpen(char* fname);

void FileReaderClose(FileReader* fr);

int FileReaderNextLine(FileReader* fr);

int FileReaderError(FileReader* fr);

char* FileReaderBuffer(FileReader* fr);

#endif
