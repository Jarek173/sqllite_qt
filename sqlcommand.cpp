
#include "sqlcommand.h"


std::string SqlCommand::getLastOrders(int numberOfTheLastOrder, const std::vector<User::Parameters> &userParameters, const std::vector<Order::Parameters> &orderParameters)
{
    std::string cmd = "";

    cmd += cSelect + " "  + User::parametersNames(userParameters) + "," + Order::parametersNames(orderParameters);

    if(orderParameters.empty())
        cmd.pop_back();

    cmd += "\n";

    cmd += " " + cFrom + " (" + cSelect + " * " + cFrom + " " + Order::dbTableName() + " " + cLimit + " " + std::to_string(numberOfTheLastOrder) + ")";

    cmd += " " + Order::dbTableName() + " ";

    cmd += "\n";

    cmd += cInnerJoin + " " + User::dbTableName() + " " + cOn + " " + Order::parameterName(Order::Parameters::UserID).value_or("") + "=" + User::parameterName(User::Parameters::ID).value_or("");

    cmd += "\n";

    cmd += " " + cOrderBy + " " + Order::parameterName(Order::Parameters::ID).value_or("") + " " + cAsc + ";";

    return cmd;
}

std::string SqlCommand::getUserOrders(const std::string &userLogin, const std::vector<User::Parameters> &userParameters, const std::vector<Order::Parameters> &orderParameters)
{
    std::string cmd = "";

    cmd += cSelect + " "  + User::parametersNames(userParameters) + "," + Order::parametersNames(orderParameters);

    if(orderParameters.empty())
        cmd.pop_back();

    cmd += "\n";

    cmd += " " + cFrom + " " + Order::dbTableName() + " \n";

    cmd += cInnerJoin + " " + User::dbTableName() + " " + cOn + " " + Order::parameterName(Order::Parameters::UserID).value_or("") + "=" + User::parameterName(User::Parameters::ID).value_or("");

    cmd += "\n";

    cmd += cWhere + " " + User::parameterName(User::Parameters::Login).value_or("") + " = '" + userLogin + "';";

    return cmd;
}

std::string SqlCommand::addUser(const User &user)
{
    std::string cmd = "";

    cmd += cInsertInto + " " + User::dbTableName() + " (" + User::parameterName(User::Parameters::Name, false).value_or("") + ", ";
    cmd += User::parameterName(User::Parameters::LastName, false).value_or("") + ", ";
    cmd += User::parameterName(User::Parameters::PostalCode, false).value_or("") + ", ";
    cmd += User::parameterName(User::Parameters::Login, false).value_or("") + ")\n";

    cmd += cValues + " ('" + user.getName() + "', '" + user.getLastName() + "', '" + user.getPostalCode() + "', '" + user.getLogin() + "');";

    return cmd;
}

std::string SqlCommand::addOrder(const Order &order)
{
    std::string cmd = "";

     cmd += cInsertInto + " " + Order::dbTableName() + " (" + Order::parameterName(Order::Parameters::UserID, false).value_or("") + ", ";
     cmd += Order::parameterName(Order::Parameters::Product, false).value_or("") + ")\n";

     cmd += cValues + " ('" + order.getUserID() + "', '" + order.getProduct() + "');";

    return cmd;
}
