#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <optional>
#include <vector>
#include <map>

class Order
{
public:
    enum class Parameters
    {
        ID = 1,
        Product = 2,
        UserID = 3,
    };

    Order() = default;
    Order(int id, const std::string& product, int orderNumber);

    void setID(int id);
    void setProduct(const std::string& product);
    void setOrderNumber(int orderNumber);

    int getID() const;
    std::string getProduct() const;
    int getOrderNumber() const;

    static std::string dbTableName();

    //Optional because someone can add next value in Parameters but not in cMemberNamesMap
    static std::optional<std::string> parameterName(Parameters parameter);

    /**
     * @brief this method return string of parameters e.g for parameters ID and Name return "Orders.ID, Orders.Product"
     * @param vector of member parameters names to return
     * @return if vector is not empty return all parameter otherwise only parameter listed in vector
     */
    static std::string parametersNames(const std::vector<Parameters>& parameters = std::vector<Parameters>());

private:
    inline static const std::string cDBTableName = "Orders";

    int mID;
    std::string mProduct;
    int mOrderNumber;

    inline static const std::map<Parameters, std::string> cParametersNamesMap{
        {Parameters::ID, "ID"},
        {Parameters::Product, "Product"},
        {Parameters::UserID, "UserID"},
    };
};

#endif // ORDER_H
