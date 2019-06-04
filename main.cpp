#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/array.hpp>
#include <string>

std::string send_receive(std::string host, int port, std::string myName){
  boost::system::error_code err;
  boost::asio::io_service service;
  boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(host), port);
  boost::asio::ip::tcp::socket sock(service);
  sock.connect(ep);

  boost::array<char, 1024> buf;
  std::copy(myName.begin(), myName.end(), buf.begin());
  sock.write_some(boost::asio::buffer(buf), err);

  //waits 2 seconds
  boost::asio::deadline_timer t(service, boost::posix_time::seconds(5));

  boost::array<char, 1024> rbuf;
  sock.read_some(boost::asio::buffer(rbuf), err);
  if (err == boost::asio::error::eof){
      return  "Connection closed by server\n";
      sock.close();
      }
      else if (err) {

        sock.close();
        return "error in connection";
      }

  sock.close();
  return rbuf.data();
}


int main()
{
  std::string str = send_receive("127.0.0.1", 33333, "con1");
  std::cout << str << std::endl;
  return 0;
}
