#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Solve Function Cases For Decryption") 
{
   CHECK(solve("") == "0.000000");
   CHECK(solve(" ") == "0.000562");
   CHECK(solve("(#644@#534&234$^2154/.';") == "0.000562");
   CHECK(solve(encryptCaesar("Example text", 2)) == "0.000281");
   CHECK(solve(encryptCaesar("1", 100)) == "0.000562");
   CHECK(solve("123456") == "0.000562");
   CHECK(solve(encryptCaesar("(#644@#534&234$^2154/.';", 100)) == "0.000562");
   CHECK(solve(encryptCaesar(" ", 100)) == "0.000562");
   CHECK(solve("This a string of text.") == "0.003620");
   CHECK(solve(encryptCaesar("Text", 16)) == "0.000991");
}
