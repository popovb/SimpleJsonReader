#include <SimpleJson/Handler.hpp>
#include <gtest/gtest.h>

TEST(handler, test_01)
{
     using namespace simple_json;
     Handler H;
     ASSERT_TRUE(true);
}

TEST(handler, test_02)
{
     using namespace simple_json;
     Handler H;
     H.ObjectStart();
     H.ObjectEnd();
     ASSERT_TRUE(true);
}

TEST(handler, test_03)
{
     using namespace simple_json;
     class MyHandler: public Handler {

     public:
	  void ObjectStart() { return; }
	  void ObjectEnd()   { return; }

     private:
     };
     MyHandler H;
     H.ObjectStart();
     H.ObjectEnd();
     H.ArrayStart();
     H.ArrayEnd();
     H.Value("value");
     H.Key("key");
     ASSERT_TRUE(true);
}
