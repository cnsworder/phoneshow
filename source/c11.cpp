#include <initializer_list>
#include <iostream>
#include <thread>
#include <memory>
#include <functional>

namespace test
{
//FIXME: 继承终止
class Base
//class Base final
{ 
public:
    virtual void super(){}
    void print(){}
};

class Child : public Base
{
public:
    //FIXME: 显式重载
    virtual void super() override{}
    using Base::print;
};

//FIXME: 变参模板
template<typename... T>
class tp
{
public:
    void pt(T... args)
    {
    }

    void pt(int arg)
    {
    }
};


//FIXME: 强类型枚举
enum class Color:int{
    kRED,
    kBLUD
};
}




class M
{
public:
   // FIXME: 初始化列表
   M(std::initializer_list<int> ls)
   {
       //FIXME: 循环区域
        for (auto var : ls) {
            std::cout << var << std::endl;
        }
   
   }
   //FIXME: 普遍变量初始化
   int i = 11;

   //TODO: 默认函数
   virtual ~M() = default;

   //TODO: 禁用函数
   M(int &a) = delete;

   //FIXME: 不进行强制类型转换
   explicit operator int()
   {
       return i;
   }

   void print() 
   {
       std::cout << "M..." << std::endl;
   }

   //FIXME: 返回值自动推导
   auto add(int a, int b) -> decltype(a + b) 
   {
        return a + b;
   }

private:
   //FIXME: 空指针
   char *name_ = nullptr;
   //TODO: 智能指针
   std::shared_ptr<int> gotoPtr_;
};

//TODO: c++11
std::function<void()> fun() 
{
    return std::bind([](){return 1;});
}

//TODO: c++14
auto afun() 
{
    return [](){return 1;};
}

int main()
{
    //TODO: 统一的初始化   
    M m{1, 2, 3, 4};
    //TODO: 线程支持, lambda, 右值引用
    std::thread([&](M &&m){ 
              m.print();
            }, m);
    return 0;
}
