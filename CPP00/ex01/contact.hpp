#ifndef CONTACT_HPP

# define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _darkest_secret;
        int         _phonenumber;
        int         _id;
    public:
        std::string getFirstName();
        std::string getNickName();
        std::string getLastName();
        std::string getDarkestSecret();
        void        setFirstName( void );
        void        setLastName(std::string first_name);
        void        setNickName(std::string first_name);
        void        setDarkestSecret(std::string darkest_secret);

};

#endif