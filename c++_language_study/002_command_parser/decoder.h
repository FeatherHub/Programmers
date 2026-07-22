#pragma once

int getInput(char** buffer);
int tokenizer(char* string, char*** tokens);
void distributer(char** tokens);
void func1Decoder(char** params);
void func2Decoder(char** params);
void func1(int a, int b);
void func2(const char* s1, const char* s2, const char* s3);