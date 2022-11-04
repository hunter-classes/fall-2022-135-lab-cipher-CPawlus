#pragma once

char shiftChar(char c, int rshift);
char shiftCharReverse(char c, int rshift);
std::string encryptCaesar(std::string plaintext, int rshift);
std::string decryptCaesar(std::string ciphertext, int rshift);
std::string solve(std::string encrypted_string);


