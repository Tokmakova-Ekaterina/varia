#pragma once
char* crypt(const char* str, int key);
char* decrypt(const char* str, int key);
char* crypt1(char*& str, int key);
char* decrypt1(char*& str, int key);