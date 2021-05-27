#include "order.h"


Order::Order(const std::string& userID, const std::string &product, int orderNumber) : mUserId(userID) , mProduct(product), mOrderNumber(orderNumber)
{

}

void Order::setUserID(const std::string &id)
{
    mUserId = id;
}

void Order::setProduct(const std::string &product)
{
    mProduct = product;
}

void Order::setOrderNumber(int orderNumber)
{
    mOrderNumber = orderNumber;
}

std::string Order::getUserID() const
{
    return mUserId;
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

std::optional<std::string> Order::parameterName(Order::Parameters parameter, bool dbTableNamePrefix)
{
    if(cParametersNamesMap.find(parameter) != cParametersNamesMap.end())
    {
        if(dbTableNamePrefix)
            return cDBTableName + "." + cParametersNamesMap.at(parameter);
        return cParametersNamesMap.at(parameter);
    }
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
