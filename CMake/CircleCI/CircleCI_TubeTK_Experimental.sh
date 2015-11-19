#!/bin/sh

MachineName=CircleCI_GitHub
BuildType=Release
CTestCommand=ctest
DashboardDir=/usr/src/

cd ${DashboardDir}
${CTestCommand} -D Experimental -D SITE_CTEST_MODE:STRING=Experimental -D SITE_BUILD_TYPE:STRING=${BuildType} -S /usr/src/TubeTK/CMake/CircleCI/CircleCI_TubeTK.cmake -V -VV -O CircleCI_TubeTK_Experimental.log
