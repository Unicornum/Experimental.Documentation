  
@echo off
  
set ANDROID_NDK=E:/Android/crystax-ndk-10.3.2
set PATH=%PATH%;%ANDROID_NDK%/toolchains/arm-linux-androideabi-4.9/prebuilt/windows/arm-linux-androideabi/bin;
set ICU_PATH=%ANDROID_NDK%/sources/icu/56.1
  
b2 toolset=clang-android target-os=linux threading=multi threadapi=pthread link=static runtime-link=static --stagedir=android ^
	--with-date_time --with-filesystem --with-locale -sHAVE_ICU=1 -sICU_PATH="%ICU_PATH%"
  
pause
  