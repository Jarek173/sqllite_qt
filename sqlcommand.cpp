
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

    cmd += " " + cOrderBy + " " + Order::parameterName(Order::Parameters::ID).value_or("") + " " + cAsc + " ;";

    return cmd;
}

std::string SqlCommand::getUserOrders(const std::string &userLogin, const std::vector<User::Parameters> &userParameters, const std::vector<Order::Parameters> &orderParameters)
{
    std::string cmd = "";

    cmd += cSelect + " "  + User::parametersNames(userParameters) + "," + Order::parametersNames(orderParameters);

    if(orderParameters.empty())
        cmd.pop_back();

    cmd += "\n";

    cmd += " " + cFrom + Order::dbTableName() + " \n";

    cmd += cInnerJoin + " " + User::dbTableName() + " " + cOn + " " + Order::parameterName(Order::Parameters::UserID).value_or("") + "=" + User::parameterName(User::Parameters::ID).value_or("");

    cmd += "\n";

    cmd += cWhere + " " + User::parameterName(User::Parameters::Login).value_or("") + " = '" + userLogin + "';";

}
