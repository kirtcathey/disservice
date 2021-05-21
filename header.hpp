//
// Created by Kirt Cathey on 5/21/2021.
//

#ifndef HTTP_HEADER_HPP
#define HTTP_HEADER_HPP

#include <string>

namespace http {
    namespace server {

        struct header
        {
            std::string name;
            std::string value;
        };

    } // namespace server
} // namespace http

#endif // HTTP_HEADER_HPP