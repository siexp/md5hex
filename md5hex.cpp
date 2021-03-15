#include <array>
#include <iostream>
#include <iterator>
#include <string>

#include <boost/algorithm/hex.hpp>

#include <openssl/md5.h>

std::string openssl_md5(const std::string& data)
{
    std::array<unsigned char, MD5_DIGEST_LENGTH> md;
    const auto hash = MD5(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), md.data());

    std::string hex;
    boost::algorithm::hex(hash, hash + MD5_DIGEST_LENGTH, std::back_inserter(hex));

    return hex;
}

int main()
{
    std::cout << "openssl_md5: " << openssl_md5( "Hello, World!") << std::endl
              << "expected md5: " << "65A8E27D8879283831B664BD8B7F0AD4" << std::endl;

    return 0;
}