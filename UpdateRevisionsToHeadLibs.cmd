@echo off

set SvnExternals=.\svn.externals

set UrlToLibs="https://svn/svn/Libs/trunk"

set PathToAlicornInclude=./include
set UrlToAlicornInclude=https://svn/svn/Libs/trunk/Solution/Solution/Alicorn/include

set PathToAlicornLib=./lib
set UrlToAlicornLib=https://svn/svn/Libs/trunk/Solution/Solution/Alicorn/lib

set PathToTesting=./Testing
set UrlToTesting=https://svn/svn/Libs/trunk/Solution/Solution/Testing

set PathToProperties=./Properties
set UrlToProperties=https://svn/svn/Libs/trunk/Solution/Solution/Properties

set PathToDoxygen=./Documentation/Doxygen
set UrlToDoxygen=https://svn/svn/Libs/trunk/Solution/Solution/Documentation/Doxygen

set PathToExternals=./Externals
set UrlToExternals=https://svn/svn/Libs/trunk/Solution/Solution/Externals

rem ====== HEAD ревизи€ дл€ Libs ======

for /F "Delims=" %%I In (
	'svn info --show-item=revision %UrlToLibs% --revision HEAD'
) do set LibsHeadRevision=%%~I

echo Update to revision %LibsHeadRevision%

rem ====== ‘ормирование списка папок дл€ обновлени€ ревизии ======

if exist %SvnExternals% del %SvnExternals%

rem ====== ”становка свойств/обновление ревизии ======

echo %PathToAlicornInclude% -r %LibsHeadRevision% %UrlToAlicornInclude% >> %SvnExternals%
echo %PathToAlicornLib% -r %LibsHeadRevision% %UrlToAlicornLib% >> %SvnExternals%

svn propset svn:externals -F%SvnExternals% ./Externals/Alicorn

del %SvnExternals%

rem ====== ”становка свойств/обновление ревизии ======

echo %PathToTesting% -r %LibsHeadRevision% %UrlToTesting% >> %SvnExternals%
echo %PathToDoxygen% -r %LibsHeadRevision% %UrlToDoxygen% >> %SvnExternals%
echo %PathToProperties% -r %LibsHeadRevision% %UrlToProperties% >> %SvnExternals%
echo %PathToExternals% -r %LibsHeadRevision% %UrlToExternals% >> %SvnExternals%

svn propset svn:externals -F%SvnExternals% ./Externals

del %SvnExternals%
