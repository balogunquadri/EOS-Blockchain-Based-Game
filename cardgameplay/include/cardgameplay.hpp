#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT cardgameplay : public contract {
public:
     using contract::contract;
     cardgameplay(name receiver,
     name code, datastream<const char*> ds):
     contract(receiver, code, ds),
     _users(receiver, receiver.value)
     {}

    ACTION login(name user);
    

  private:
    TABLE user_info {
      name    username;
      uint64_t win_count = 0;
      uint64_t lost_count = 0;
      //string  text;
      auto primary_key() const { return username.value; }
    };
    typedef multi_index<name("users"), user_info> users_table;


    users_table _users;
};

EOSIO_DISPATCH(cardgameplay, (login))
