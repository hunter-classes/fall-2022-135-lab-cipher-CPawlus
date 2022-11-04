#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Solve Function Cases For Decryption") 
{
   CHECK(solve("") == "");
   CHECK(solve(" ") == " ");
   CHECK(solve("(#644@#534&234$^2154/.';") == "(#644@#534&234$^2154/.';");
   CHECK(solve(encryptCaesar("Example text", 0)) == "Ibeqtpi xibx");
   CHECK(solve(encryptCaesar("1", 100)) == "1");
   CHECK(solve("123456") == "123456");
   CHECK(solve("''") == "''");
   CHECK(solve(" a4") == " e4");
}
