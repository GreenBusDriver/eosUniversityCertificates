#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

// class[[ contract("first") ]] first  : public contract {
CONTRACT first : public contract {
  public:
    using contract::contract;

    ACTION issuecertcat(name issuer, uint64_t certificate_id, string owner_gov_id, float gpa, int year, string area_of_study);

  private:
    TABLE certificates {
      name issuer;
      uint64_t certificate_id;
      string owner_gov_id;
      float gpa;
      int year;
      string area_of_study;

      auto primary_key() const { return certificate_id; }
    };
    typedef multi_index<name("certificates"), certificates> certificates_table;
};
