#include <algorithm>

#include "user.h"

User::User(int id, const std::string &name, const std::string &lastName, const std::string &postpalCode, const std::string &login) :
          mID(id), mName(name), mLastName(lastName), mPostalCode(postpalCode), mLogin(login)
{

}

void User::setId(int id)
{
    mID = id;
}

void User::setName(const std::string &name)
{
    mName = name;
}

void User::setLastName(const std::string &lastName)
{
    mLastName = lastName;
}

void User::setPostalCode(const std::string &postpalCode)
{
    mPostalCode = postpalCode;
}

void User::setLogin(const std::string &login)
{
    mLogin = login;
}

int User::getId() const
{
    return mID;
}

std::string User::getName() const
{
    return mName;
}

std::string User::getLastName() const
{
    return mLastName;
}

std::string User::getPostalCode() const
{
    return mPostalCode;
}

std::string User::getLogin() const
{
    return mLogin;
}

std::string User::dbTableName()
{
    return cDBTableName;
}

std::optional<std::string> User::parameterName(User::Parameters parameter, bool dbTableNamePrefix)
{
    if(cParametersNamesMap.find(parameter) != cParametersNamesMap.end())
    {
        if(dbTableNamePrefix)
            return cDBTableName + "." +cParametersNamesMap.at(parameter);
        return cParametersNamesMap.at(parameter);
    }
    return {};
}

std::string User::parametersNames(const std::vector<User::Parameters> &parameters)
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
