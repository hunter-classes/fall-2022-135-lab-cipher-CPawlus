/*
Author: Christopher Pawlus
Course: CSCI-136
Instructor: Professor Zamansky
Assignment: Ciphers, main.cpp, Lab Cipher Lab Continued.

This is a program finds a different 
to use cipher decryption.
*/

#include <iostream>
#include "funcs.h"

int main()
{
  std::cout << solve(encryptCaesar("Decrypt this piece of text.", 12)) << "\n";
  return 0;
}
