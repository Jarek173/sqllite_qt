
#include "sqlcommand.h"


std::string SqlCommand::getLastOrders(int numberOfTheLastOrder, const std::vector<User::Parameters> &userParameters, const std::vector<Order::Parameters> &orderParameters)
{
    std::string cmd = "";

    cmd += cSelect + " "  + cTop + " " + std::to_string(numberOfTheLastOrder) + " " + User::parametersNames(userParameters) + "," + Order::parametersNames(orderParameters);

    if(orderParameters.empty())
        cmd.pop_back();

    cmd += cFrom + " " + User::dbTableName() + " ";

    cmd += cInnerJoin + " " + Order::dbTableName() + " " + cOn + " " + Order::parameterName(Order::Parameters::ID).value_or("") + "=" + User::parameterName(User::Parameters::ID).value_or("") + ";";

    return cmd;
}
