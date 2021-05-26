#ifndef USER_H
#define USER_H

#include <string>
#include <optional>
#include <vector>
#include <map>

class User
{
public:

    enum class Parameters
    {
       ID = 1,
       Name = 2,
       LastName = 3,
       PostalCode = 4,
       Login = 5
    };

    User() = default;
    User(int id, const std::string& name, const std::string& lastName,const std::string& postpalCode,const std::string& login);

    void setId(int id);
    void setName(const std::string& name);
    void setLastName(const std::string& lastName);
    void setPostalCode(const std::string& postpalCode);
    void setLogin(const std::string& login);

    int getId() const;
    std::string getName() const;
    std::string getLastName() const;
    std::string getPostalCode() const;
    std::string getLogin() const;

    static std::string dbTableName();

    //Optional because someone can add next value in Parameters but not in cMemberNamesMap
    static std::optional<std::string> parameterName(Parameters parameter);

    /**
     * @brief this method return string of parameters e.g for parameters ID and Name return "Users.ID, Users.Name"
     * @param vector of member parameters names to return
     * @return if vector is not empty return all parameter otherwise only parameter listed in vector
     */
    static std::string parametersNames(const std::vector<Parameters>& parameters = std::vector<Parameters>());
private:
    inline static const std::string cDBTableName = "Users";

    int mID;
    std::string mName;
    std::string mLastName;
    std::string mPostalCode;
    std::string mLogin;

    inline static const std::map<Parameters, std::string> cParametersNamesMap{
        {Parameters::ID, "ID"},
        {Parameters::Name, "Name"},
        {Parameters::LastName, "LastName"},
        {Parameters::PostalCode, "PostalCode"},
        {Parameters::Login, "Login"},
    };

};

#endif // USER_H
