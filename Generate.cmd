@echo off

SET PATH_TO_INI=".\Solution\Solution\Externals\Utilities\Doxygen\universal.doxygen"

SET DOXYGEN_NAME=TestDoxygen
SET DOXYGEN_VERSION=1.2.3.4 (Build 5)
SET DOXYGEN_BRIEF=Testing generate documentation.
SET DOXYGEN_INPUT=.\

doxygen.exe %PATH_TO_INI%

pause
