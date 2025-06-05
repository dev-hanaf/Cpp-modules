#include "Serializer.hpp"

int main()
{
    Data data;

    data.i = 1337;

    std::cout<<"original add: "<< &data <<std::endl;
    
    uintptr_t r = Serializer::serialize(&data);
    std::cout<<"add serilized : "<< &r <<std::endl;
    std::cout<<"value : "<< r <<std::endl;
    
    Data *desData = Serializer::deserialize(r);
    std::cout<<"add : "<< desData <<std::endl;
    std::cout<<"value: "<< desData->i <<std::endl;
}