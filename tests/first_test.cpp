//#include <file/NameGenerator.hpp>
#include <rapidjson/reader.h>
#include <gtest/gtest.h>
#include <string>

TEST(first, test_01)
{
     ASSERT_TRUE(true);
     //using namespace file;
     //NameGenerator ng(2, 1);
     //ASSERT_EQ("download_0.xml", ng.name());
}

using namespace rapidjson;
using namespace std;

struct MyHandler : public BaseReaderHandler<UTF8<>, MyHandler> {
    bool Null() { cout << "Null()" << endl; return true; }
    bool Bool(bool b) { cout << "Bool(" << boolalpha << b << ")" << endl; return true; }
    bool Int(int i) { cout << "Int(" << i << ")" << endl; return true; }
    bool Uint(unsigned u) { cout << "Uint(" << u << ")" << endl; return true; }
    bool Int64(int64_t i) { cout << "Int64(" << i << ")" << endl; return true; }
    bool Uint64(uint64_t u) { cout << "Uint64(" << u << ")" << endl; return true; }
    bool Double(double d) { cout << "Double(" << d << ")" << endl; return true; }
    bool String(const char* str, SizeType length, bool copy) { 
        cout << "String(" << str << ", " << length << ", " << boolalpha << copy << ")" << endl;
        return true;
    }
    bool StartObject() { cout << "StartObject()" << endl; return true; }
    bool Key(const char* str, SizeType length, bool copy) { 
        cout << "Key(" << str << ", " << length << ", " << boolalpha << copy << ")" << endl;
        return true;
    }
    bool EndObject(SizeType memberCount) { cout << "EndObject(" << memberCount << ")" << endl; return true; }
    bool StartArray() { cout << "StartArray()" << endl; return true; }
    bool EndArray(SizeType elementCount) { cout << "EndArray(" << elementCount << ")" << endl; return true; }
};

TEST(first, test_02)
{
     std::string in = R"raw(
{
    "hello" : "world",
    "t" : true ,
    "f" : false,
    "n" : null,
    "i" : 123,
    "pi" : 3.1416,
    "a" : [1, 2, 3, 4]
}

)raw";

     MyHandler handler;
     Reader reader;
     StringStream ss(in.c_str());
     reader.Parse(ss, handler);
}
