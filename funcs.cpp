#include <iostream>
#include <vector>
#include <cctype>
#include <fstream>
#include <cmath>
#include <string>
#include "funcs.h"

// Functions
char shiftChar(char c, int rshift) 
{
   char s = ' ';
   s = (int)c;
   s = c + rshift;
   return s;
}

char shiftCharReverse(char c, int rshift) 
{
   char s = ' ';
   s = (int)c;
   s = c - rshift;
   return s;
}

std::string encryptCaesar(std::string plaintext, int rshift) 
{
   std::string newtext = "";
   char c = ' ';
   for(int i = 0; i < plaintext.length(); i++) 
   {
      if(isalpha(plaintext[i])) 
      {
         c = plaintext[i];
         c = shiftChar(c, rshift);
         if(isalpha(c))
         {
            newtext += c;
         }
         else 
         {
            c = (int)c - 26;
            newtext += c;
         }
      }
      else
      {
         c = plaintext[i];
         newtext += c;
      }
   }
   return newtext;
}

std::string decryptCaesar(std::string ciphertext, int rshift) 
{
   std::string newtext = "";
   char c = ' ';
   for(int i = 0; i < ciphertext.length(); i++) 
   {
      if(isalpha(ciphertext[i])) 
      {
         c = ciphertext[i];
         c = shiftCharReverse(c, rshift);
         if(isalpha(c))
         {
            newtext += c;
         }
         else 
         {
            c = (int)c + 26;
            newtext += c;
         }
      }
      else
      {
         c = ciphertext[i];
         newtext += c;
      }
   }
   return newtext;
}

std::string solve(std::string encrypted_string) 
{
   std::ifstream con;
   std::string s = "";
   std::string t = "";
   std::vector<double> engsfrqv = {0.084966, 0.020720, 0.045388, 0.033844, 0.111607, 0.018121, 0.024705, 0.030034, 0.075448, 0.001964, 0.011016, 0.054893, 0.030129, 0.066544, 0.071635, 0.031671, 0.001962, 0.075809, .057351, 0.069509, 0.036308, 0.010074, 0.012899, 0.002902, 0.017779, 0.002722};
   std::vector<double> encfrqv = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   int count = 0, count2 = 0, shift = 0;
   double result = 0;
   con.open("english.txt");
   if(con.fail()) 
   {
      return "File does not exist.";
   }
   getline(con, s);
   // For Encrypted String
   for(int i = 0; i < 26; i++)  
   {
      t = encryptCaesar(encrypted_string, i);
      for(int o = 0; o < encrypted_string.length(); o++) 
      {
         if(isalpha(t[o])) 
         {
            char a = tolower(t[o]);
            encfrqv[((int)a)-97] += 1; //97-122
            count2++;
         }
         else if(isspace(t[o]) || !isalpha(t[o])) 
         {
            count2++;
         }
      }
      double temp = sqrt(pow((engsfrqv[0]-encfrqv[0]), 2));
      for(int a = 1; a < 26; a++) 
      {
         if(sqrt(pow((engsfrqv[a]-encfrqv[a]), 2)) < temp) 
         {
            result = sqrt(pow((engsfrqv[a]-encfrqv[a]), 2));
            shift = a;
            temp = result;
         }
      }
   }
   //std::cout << result << "\n"; *This has more precision* 
   std::cout << shift << std::endl;
   std::string fin = encryptCaesar(encrypted_string, shift);
   return fin;
}
