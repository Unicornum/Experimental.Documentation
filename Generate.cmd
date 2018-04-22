@echo off

set PathToExternals=.\Solution\Solution\Externals

call %PathToExternals%\BuildSolution.cmd "Debug:x64" "BuildAll:Rebuild"

.\Solution\Solution\^(Documentation^)\html\index.html

pause
