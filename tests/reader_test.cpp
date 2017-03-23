#include <SimpleJson/Reader.hpp>
#include <SimpleJson/Handler.hpp>
#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include <iostream>

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
