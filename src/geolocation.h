#ifndef GEOLOCATION_H
#define GEOLOCATION_H

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

using tcp = boost::asio::ip::tcp; 
namespace http = boost::beast::http; 
 
template<typename Function>
inline void fetch_sync(const std::string host, const std::string target, Function callback ) {
    try
    {
        auto const port = "80";
        int version = 11;
        boost::asio::io_context ioc;
        tcp::resolver resolver{ioc};
        tcp::socket socket{ioc};
        auto const results = resolver.resolve(host, port);
        boost::asio::connect(socket, results.begin(), results.end());
        http::request<http::string_body> req{http::verb::get, target, version};
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        http::write(socket, req);
        boost::beast::flat_buffer buffer;
        http::response<http::string_body> res;
        http::read(socket, buffer, res);
        callback(res);
        boost::system::error_code ec;
        socket.shutdown(tcp::socket::shutdown_both, ec);
        if(ec && ec != boost::system::errc::not_connected){
            throw boost::system::system_error{ec};
        }
    } catch(std::exception const &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

#endif // GEOLOCATION_H
