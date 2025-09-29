#include "Singleton.h"
#include <memory>

SingleHungry *SingleHungry::single =
    SingleHungry::GetInst(); // 饿汉式需要提前初始化
// auto inst = SingleHungry::GetInst();
SinglePointer *SinglePointer::single = nullptr;

std::mutex SinglePointer::s_mutex;

std::shared_ptr<SingleOnceFlag> SingleOnceFlag::_instance = nullptr;
