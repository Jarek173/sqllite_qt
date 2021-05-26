#include "order.h"


Order::Order(int id, const std::string &product, int orderNumber) : mID(id), mProduct(product), mOrderNumber(orderNumber)
{

}

void Order::setID(int id)
{
    mID = id;
}

void Order::setProduct(const std::string &product)
{
    mProduct = product;
}

void Order::setOrderNumber(int orderNumber)
{
    mOrderNumber = orderNumber;
}

int Order::getID() const
{
    return mID;
}

std::string Order::getProduct() const
{
    return mProduct;
}

int Order::getOrderNumber() const
{
    return mOrderNumber;
}

std::string Order::dbTableName()
{
    return cDBTableName;
}

std::optional<std::string> Order::parameterName(Order::Parameters parameter)
{
    if(cParametersNamesMap.find(parameter) != cParametersNamesMap.end())
        return cDBTableName + "." + cParametersNamesMap.at(parameter);
    return {};
}

std::string Order::parametersNames(const std::vector<Order::Parameters> &parameters)
{
    std::string str = "";
    if(parameters.empty())
    {
        return str;
    }

    for(auto p : parameters)
    {
        str += parameterName(p).value_or("") + ",";
    }

    str.pop_back();

    return str;
}
