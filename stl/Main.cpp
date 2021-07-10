#include "Container.h"
#include "Algorithms.h"
#include <iostream>

struct Goods {
    uint32_t m_id;
    std::string m_name;
    std::string m_manufacturer;
    std::string m_warehouse_address;
    double m_weight;

    Goods(uint32_t p_id = 0,
          const std::string& p_name = " ",
          const std::string& p_manufacturer = " ",
          const std::string& p_warehouse_address = " ",
          double p_weight = 0.) : m_id(p_id),
                                  m_name(p_name),
                                  m_manufacturer(p_manufacturer),
                                  m_warehouse_address(p_warehouse_address),
                                  m_weight(p_weight)
    {}
};

class Functor {
public:
    auto operator() (const Goods& goods) {
        return goods.m_manufacturer == "person5";
    };
};

int main() {
    try {
        auto print = [](const auto& goods) {
            if (goods.m_id != 0) {
                std::cout << goods.m_id << std::endl;
                std::cout << goods.m_name << std::endl;
                std::cout << goods.m_manufacturer << std::endl;
                std::cout << goods.m_warehouse_address << std::endl;
                std::cout << goods.m_weight << std::endl;
            }
        };

        std::cout << "========Test1========" << std::endl;
        List<Goods> obj1{{1, "name1", "person1", "address1", 100},
                         {2, "name2", "person2", "address2", 200},
                         {3, "name3", "person3", "address3", 300} };
        forEach(obj1.begin(), obj1.end(), print);

        std::cout << "========Test2========" << std::endl;
        Goods goods1{ 4,"name4","person4","address4", 400 };
        Goods goods2{ 5,"name5","person5","address5", 500 };
        Goods goods3{ 6,"name6","person6","address6", 600 };

        List<Goods> obj2;
        obj2.pushBack(goods1);
        obj2.pushBack(goods2);
        obj2.insert(obj2.end(), goods3);
        forEach(obj2.begin(), obj2.end(), print);

        std::cout << "========Test3========" << std::endl;
        obj1.insert(obj1.end(), obj2.begin(), obj2.end());
        forEach(obj1.begin(), obj1.end(), print);

        std::cout << "========Test4========" << std::endl;
        Sort(obj1.begin(), obj1.end(),
             [](const auto& goods1, const auto& goods2) {return goods1.m_name > goods2.m_name;});
        
        forEach(obj1.begin(), obj1.end(), print);

        std::cout << "========Test5========" << std::endl;
        List<Goods>::iterator res = findIf(obj1.begin(), obj1.end(), [](const auto& goods) {
            return goods.m_weight == 300;
        });
        print(*res);

        std::cout << "========Test6========" << std::endl;
        res->m_warehouse_address = "new_address";
        forEach(obj1.begin(), obj1.end(), print);

        std::cout << "========Test7========" << std::endl;
        List<Goods> obj3(1, Goods());
        copyIf(obj1.begin(), obj1.end(), obj3.begin(), Functor());
        forEach(obj3.begin(), obj3.end(), print);
    }
    catch (const std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }
    return 0;
}
