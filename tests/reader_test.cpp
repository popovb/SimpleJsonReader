#include <SimpleJson/Reader.hpp>
#include <SimpleJson/Handler.hpp>
#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

TEST(handler, test_01)
{
     using namespace simple_json;
     Reader R;
     ASSERT_TRUE(true);
}

TEST(handler, test_02)
{
     using namespace simple_json;
     std::ifstream in("first_test_05.json");
     Reader R;
     Handler H;
     ASSERT_TRUE(R.Parse(in, H));
}

TEST(handler, test_03)
{
     using namespace simple_json;
     std::ifstream in("first_test_05.json");
     Reader R;

     class MH: public Handler {

     public:
	  virtual void ObjectStart() { std::cout << "START!\n"; }
	  virtual void ObjectEnd()   { std::cout << "END!\n";   }
     };
     MH MHH;
     ASSERT_TRUE(R.Parse(in, MHH));
}

class MH: public simple_json::Handler {

public:
     virtual void ObjectStart() { std::cout << "object start\n"; }
     virtual void ObjectEnd()   { std::cout << "object end\n";   }

     virtual void ArrayStart()  { std::cout << "array start\n"; }
     virtual void ArrayEnd()    { std::cout << "array end\n";   };

     virtual void Key(const simple_json::key_t k) {
	  std::cout << "key=";
	  std::cout << k << std::endl;
     };
     virtual void Value(const simple_json::value_t v) {
	  std::cout << "value=";
	  std::cout << v << std::endl;
     }
};

TEST(handler, test_04)
{
     using namespace simple_json;
     std::ifstream in("first_test_05.json");
     Reader R;
     MH MHH;
     ASSERT_TRUE(R.Parse(in, MHH));
}

class MH2: public simple_json::Handler {

public:
     MH2(): counter(0) { };
     virtual void ObjectStart() {
	  counter++;
	  std::cout << "object start\n";
     }

     virtual void ObjectEnd() {
	  counter++;
	  std::cout << "object end\n";
     }

     virtual void ArrayStart() {
	  counter++;
	  std::cout << "array start\n";
     }

     virtual void ArrayEnd() {
	  counter++;
	  std::cout << "array end\n";
     };

     virtual void Key(const simple_json::key_t) {
	  counter++;
	  switch (counter) {
	  case 2:
	  case 4:
	  case 6:
	  case 8:
	  case 10:
	  case 12:
	  case 14:
	  case 17:
	       return;
	  default:
	       throw std::runtime_error("key");
	  }
     };

     virtual void Value(const simple_json::value_t) {
	  counter++;
	  switch (counter) {
	  case 3:
	  case 5:
	  case 7:
	  case 9:
	  case 11:
	  case 15:
	  case 19:
	  case 20:
	  case 21:
	  case 22:
	  case 23:
	       return;
	  default:
	       throw std::runtime_error("value");
	  }
     }

private:
     int counter;
};

TEST(handler, test_05)
{
     using namespace simple_json;
     std::string in = R"raw(
{
    "hello7" : "world7",
    "t"      : true ,
    "f"      : false,
    "n"      : null,
    "i"      : 123,
    "pi"     : { "x" : 6 },
    "pi2"    : [ "x", 6, 777.77, true, "true" ]
}

)raw";
     std::stringstream in2(in);
     Reader R;
     MH2 MHH;
     ASSERT_TRUE(R.Parse(in2, MHH));
}
