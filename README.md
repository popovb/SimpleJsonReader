# SimpleJsonReader - простой событийный парсер JSON
	
## Особенности
* работает только с UTF-8 и однобайтными кодировками
* все числовые типы представлены через std::string
* тип bool представлен через std::string
* тип null представлен через std::string
* под капотом [RapidJSON](https://github.com/miloyip/rapidjson)

## Как это работает
### Создать класс обработчика наследованием
Желательно, но не обязательно, переопределить методы.

```cpp
#include <SimpleJson/Reader.hpp>
#include <SimpleJson/Handler.hpp>

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
```
### Создать входящий поток JSON
#### из файла:
```cpp
#include <fstream>

std::ifstream in("first_test_05.json");
```
#### или из std::string:
```cpp
#include <string>
#include <sstream>

std::string s = R"raw(
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
std::stringstream in(s);
```

### Создаём ридер, экземпляр обработчика. Парсим.
```cpp
simple_json::Reader R;
MH MHH;
if (R.Parse(in, MHH)) {
	std::cout << "good!\n";
}
```

## Ссылки
[RapidJSON https://github.com/miloyip/rapidjson](https://github.com/miloyip/rapidjson)

## Лицензия
Mozilla Public License Version 2.0
