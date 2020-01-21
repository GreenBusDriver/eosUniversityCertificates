#include <first.hpp>

ACTION first::issuecertcat(name issuer, uint64_t certificate_id, string owner_gov_id, float gpa, int year, string area_of_study) {
  require_auth(issuer);

  // Init the _message table
  certificates_table _certificates(get_self(), get_self().value);

  // Find the record from _certificates table
  auto msg_itr = _certificates.find(certificate_id);
  if (msg_itr == _certificates.end()) {
    // eosio::check(msg_itr == _certificates.end(), "Error: certificate_id already exists");
    // Create a message record if it does not exist
    _certificates.emplace(issuer, [&](auto& certificate) {
      certificate.issuer = issuer;
      certificate.certificate_id = certificate_id;
      certificate.owner_gov_id = owner_gov_id;
      certificate.gpa = gpa;
      certificate.year = year;
      certificate.area_of_study = area_of_study;
    });
  } else {
    // Modify a message record if it exists
    printf("Error: certificate_id already exists");
  }
}

EOSIO_DISPATCH(first, (issuecertcat))
