
#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <..\Version.hpp>

int main(int _Argv, char ** _ppArgc)
{
  const ::std::string PathToRunProgram = _ppArgc[0];
  const auto PathToAppFileName = 
    PathToRunProgram.substr(0, PathToRunProgram.rfind(".exe"));

  ::std::ofstream Result(PathToAppFileName + ".Params.txt");
  if (!Result.is_open()) return 1;

  for (int i = 1; i < _Argv; i++)
  {
    Result << _ppArgc[i] << ::std::endl;
  }

  if (PathToRunProgram.find("Version.exe") != ::std::string::npos)
  {
    //set VERSION_SOLUTION=1.2.3

    ::std::wcout << "set VERSION_SOLUTION=" <<
      VERSION << "." << SUBVERSION << "." << SUBSUBVERSION << ::std::endl;
  }

  if (PathToRunProgram.find("Documentation.exe") != ::std::string::npos)
  {
    //set DOXYGEN_NAME=TestDoxygen
    //set DOXYGEN_VERSION=1.2.3.4 (Build 5)
    //set DOXYGEN_BRIEF=Testing generate documentation.
    //set DOXYGEN_INPUT=.\

    ::std::wcout << "set DOXYGEN_NAME=" <<
      __PRODUCT_NAME__ << ::std::endl;
    ::std::wcout << "set DOXYGEN_VERSION=Version: " <<
      VERSION << "." << SUBVERSION << "." << SUBSUBVERSION << " " <<
      "Revision: " << REVISION_SOLUTION << ::std::endl;
    ::std::wcout << "set DOXYGEN_BRIEF=" <<
      __PRODUCT_DESCRIPTION__ << ::std::endl;
    ::std::wcout << "set DOXYGEN_INPUT=" <<
      ".\\" << ::std::endl;
  }

  return 0;
}
