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
