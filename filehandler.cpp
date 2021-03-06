#include	<cmath>
#include	<cstdlib>
#include	<vector>
#include	<string>
#include	<sstream>
#include	<fstream>
#include	<iostream>
#include	<iomanip>
#include	<exception>

#include	"filehandler.h"



inline  void    myexit(const int iflag) {
  exit(iflag);
}
inline void     myexception(std::exception& e) {
  std::cerr<<"Exception: "<<e.what()<<std::endl;
  myexit(1);
}




int main(int argc, char **argv)
{
  // Just check that the code works.
  std::vector<int> iarr(16);
  for (int i=0; i<iarr.size(); ++i) iarr[i]=i+1;
  FileHandler::write_int("myfile","iarr",iarr);
  std::vector<float> farr(8);
  for (int i=0; i<farr.size(); ++i) farr[i]=0.5*i;
  FileHandler::write_float("myfile","farr",farr);

  std::vector<float> val=FileHandler::read_float("myfile","farr");
  std::cout<<"Should print 8 half-integers."<<std::endl;
  for (int i=0; i<val.size(); ++i)
    std::cout<<"farr["<<i<<"]="<<val[i]<<std::endl;
  std::cout<<std::endl;

  std::cout<<"Should print 16 integers."<<std::endl;
  std::vector<int> res=FileHandler::read_int("myfile","iarr");
  for (int i=0; i<res.size(); ++i)
    std::cout<<"iarr["<<i<<"]="<<res[i]<<std::endl;

  std::cout<<"This should complain..."<<std::endl;
  std::vector<long> oops=FileHandler::read_long("myfile","iarr");
}
