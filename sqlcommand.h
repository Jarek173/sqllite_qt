#ifndef SQGLCOMMAND_H
#define SQGLCOMMAND_H

#include <string>

#include "user.h"
#include "order.h"

class SqlCommand
{
public:
    SqlCommand() = delete;
    static std::string getLastOrders(int numberOfTheLastOrder, const std::vector<User::Parameters>& userParameters = std::vector<User::Parameters>() ,
                                      const std::vector<Order::Parameters>& orderParameters = std::vector<Order::Parameters>());

    static std::string getUserOrders(const std::string& userLogin , const std::vector<User::Parameters>& userParameters = std::vector<User::Parameters>() ,
                                      const std::vector<Order::Parameters>& orderParameters = std::vector<Order::Parameters>());

    static std::string addUser(const User& user);
    static std::string addOrder(const Order& order);
private:
    inline static const std::string cSelect = "SELECT";
    inline static const std::string cFrom = "FROM";
    inline static const std::string cOrderBy = "ORDER BY";
    inline static const std::string cDesc = "DESC";
    inline static const std::string cAsc = "ASC";
    inline static const std::string cInnerJoin = "INNER JOIN";
    inline static const std::string cOn = "ON";
    inline static const std::string cTop = "TOP";
    inline static const std::string cLimit = "LIMIT";
    inline static const std::string cWhere = "WHERE";
    inline static const std::string cInsertInto = "INSERT INTO";
    inline static const std::string cValues = "VALUES";
};

#endif // SQGLCOMMAND_H
