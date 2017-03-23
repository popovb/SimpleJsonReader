#include <SimpleJson/rapidjson/reader.h>
#include <gtest/gtest.h>
#include <string>

TEST(first, test_01)
{
     ASSERT_TRUE(true);
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

/*
! Combination of parseFlags
! \see Reader::Parse, Document::Parse, Document::ParseInsitu, Document::ParseStream

enum ParseFlag {
    kParseNoFlags = 0,              //!< No flags are set.
    kParseInsituFlag = 1,           //!< In-situ(destructive) parsing.
    kParseValidateEncodingFlag = 2, //!< Validate encoding of JSON strings.
    kParseIterativeFlag = 4,        //!< Iterative(constant complexity in terms of function call stack size) parsing.
    kParseStopWhenDoneFlag = 8,     //!< After parsing a complete JSON root from stream, stop further processing the rest of stream. When this flag is used, parser will not generate kParseErrorDocumentRootNotSingular error.
    kParseFullPrecisionFlag = 16,   //!< Parse number in full precision (but slower).
    kParseCommentsFlag = 32,        //!< Allow one-line (//) and multi-line comments.
    kParseNumbersAsStringsFlag = 64,    //!< Parse all numbers (ints/doubles) as strings.
    kParseTrailingCommasFlag = 128, //!< Allow trailing commas at the end of objects and arrays.
    kParseNanAndInfFlag = 256,      //!< Allow parsing NaN, Inf, Infinity, -Inf and -Infinity as doubles.
    kParseDefaultFlags = RAPIDJSON_PARSE_DEFAULT_FLAGS  //!< Default parse flags. Can be customized by defining RAPIDJSON_PARSE_DEFAULT_FLAGS
};
*/

TEST(first, test_03)
{
     std::string in = R"raw(
{
    "hello2" : "world2",
    "t" : true ,
    "f" : false,
    "n" : null,
    "i" : 123,
    "pi" : 3.1416
}

)raw";

     MyHandler handler;
     Reader reader;
     StringStream ss(in.c_str());

     //<unsigned parseFlags, typename InputStream, typename Handler>
     reader.Parse<kParseNumbersAsStringsFlag>(ss, handler);
}

TEST(first, test_04)
{
     std::string in = R"raw(
{
    "hello3" : "world3",
    "t"      : true ,
    "f"      : false,
    "n"      : null,
    "i"      : 123,
    "pi"     : { "x" : 6 },
    "pi2"    : [ "x", 6 ]
}

)raw";

     MyHandler handler;
     Reader reader;
     StringStream ss(in.c_str());

     //constexpr int PF = kParseInsituFlag | kParseStopWhenDoneFlag | kParseCommentsFlag | kParseNumbersAsStringsFlag | kParseTrailingCommasFlag;
     constexpr int PF = kParseValidateEncodingFlag | kParseStopWhenDoneFlag | kParseCommentsFlag | kParseNumbersAsStringsFlag | kParseTrailingCommasFlag;

     //<unsigned parseFlags, typename InputStream, typename Handler>
     auto res = reader.Parse<PF>(ss, handler);
     ASSERT_TRUE(res);
}
