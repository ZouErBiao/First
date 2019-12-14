@echo off
set MATLAB=F:\MATLAB~1
set MATLAB_ARCH=win64
set MATLAB_BIN="F:\MatlabInstall\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=AgriMapZoomInterface_mex
set MEX_NAME=AgriMapZoomInterface_mex
set MEX_EXT=.mexw64
call "F:\MATLAB~1\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for AgriMapZoomInterface > AgriMapZoomInterface_mex.mki
echo COMPILER=%COMPILER%>> AgriMapZoomInterface_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> AgriMapZoomInterface_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> AgriMapZoomInterface_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> AgriMapZoomInterface_mex.mki
echo LINKER=%LINKER%>> AgriMapZoomInterface_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> AgriMapZoomInterface_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> AgriMapZoomInterface_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> AgriMapZoomInterface_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> AgriMapZoomInterface_mex.mki
echo BORLAND=%BORLAND%>> AgriMapZoomInterface_mex.mki
echo OMPFLAGS= >> AgriMapZoomInterface_mex.mki
echo OMPLINKFLAGS= >> AgriMapZoomInterface_mex.mki
echo EMC_COMPILER=lcc64>> AgriMapZoomInterface_mex.mki
echo EMC_CONFIG=optim>> AgriMapZoomInterface_mex.mki
"F:\MatlabInstall\bin\win64\gmake" -B -f AgriMapZoomInterface_mex.mk
