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
private:
    inline static const std::string cSelect = "SELECT";
    inline static const std::string cFrom = "FROM";
    inline static const std::string cOrderBy = "ORDER BY";
    inline static const std::string cDesc = "DESC";
    inline static const std::string cAsc = "ASC";
    inline static const std::string cInnerJoin = "INNER JOIN";
    inline static const std::string cOn = "ON";
    inline static const std::string cTop = "TOP";
};

#endif // SQGLCOMMAND_H
