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

std::string solve(std::string encrypted_string) 
{
   std::ifstream con;
   std::string s = "";
   std::string t = "";
   std::vector<double> engsfrqv = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   std::vector<double> encfrqv = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   int count = 0, count2 = 0;
   double result = 0;
   con.open("english.txt");
   if(con.fail()) 
   {
      return "File does not exist.";
   }
   getline(con, s);
   // For English Sentence
   for(int i = 0; i < s.length(); i++) 
   {
      if(isalpha(s[i])) 
      {
         char a = tolower(s[i]);
         engsfrqv[((int)a)-97] += 1; //97-122
         count++;
      }
      else if(isspace(s[i]) || !isalpha(s[i])) 
      {
         count++;
      }
   }
   // For Encrypted String
   for(int i = 0; i < 25; i++)  
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
   }
   // Making them percents
   for(int i = 0; i < 26; i++) 
   {
      engsfrqv[i] = engsfrqv[i]/count;
      encfrqv[i] = encfrqv[i]/count2;
   }
   // Using distance forumla to find the smallest distance
   double comp = INT16_MAX;
   for(int i = 0; i < 25; i++) 
   {
      double temp = sqrt(pow((engsfrqv[i+1]-encfrqv[i+1]), 2));
      if((sqrt(pow((engsfrqv[i]-encfrqv[i]), 2))) < comp) 
      {
         result = sqrt(pow((engsfrqv[i]-encfrqv[i]), 2));
         comp = result;
      }
   }

   //std::cout << result << "\n"; *This has more precision*
   std::string fin = std::to_string(result);
   return fin;
}
