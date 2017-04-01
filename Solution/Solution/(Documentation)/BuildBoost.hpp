
/**
* \page BuildBoost Сборка Boost для Android
*  
*  Сборка при помощи Clang
*  -----------------------
*  
*  - В папке \$(BoostRoot) запустить bootstrap.bat.
*  - В папке \$(BoostRoot) создать файл BuildAndroid.cmd, содержащий
*  (\b ANDROID_NDK задает путь к (сюрприз!) ANDROID NDK, \b RESULT - к 'суммарному'
*  файлу всех собранных библиотек):
* \code
  
set ANDROID_NDK=d:/android/ndk
set RESULT=./stage/lib/libboost.a
  
rmdir bin.v2 /s /q
rmdir stage /s /q
  
set PATH=%PATH%;%ANDROID_NDK%/toolchains/llvm/prebuilt/windows/bin;%ANDROID_NDK%/toolchains/arm-linux-androideabi-4.9/prebuilt/windows/arm-linux-androideabi/bin;
  
b2 toolset=clang-linux target-os=android link=static runtime-link=static -j 4 ^
--without-python ^
cxxflags="-target armv7a-linux-android" ^
cxxflags="--sysroot=%ANDROID_NDK%/platforms/android-15/arch-arm" ^
cxxflags="-I%ANDROID_NDK%/sources/cxx-stl/gnu-libstdc++/4.9/include" ^
cxxflags="-I%ANDROID_NDK%/sources/cxx-stl/gnu-libstdc++/4.9/libs/armeabi-v7a/include" ^
cxxflags="-I%ANDROID_NDK%/sources/cxx-stl/gnu-libstdc++/4.9/include/backward" ^
cxxflags="-std=c++1y -frtti -fexceptions -fshort-wchar -O3 -g0" ^
cxxflags="-DNDEBUG -D__ANDROID__ -D__SOFTFP__ -D__arm__ -DBOOST_FILESYSTEM_VERSION=3"
  
set OUT_TMP_DIR=out_tmp_arm
  
rmdir %OUT_TMP_DIR% /s /q
mkdir %OUT_TMP_DIR%
cd %OUT_TMP_DIR%
  
FOR %%f in (..\stage\lib\*) DO ar xv %%f
  
cd ..
  
ar qv %RESULT% %OUT_TMP_DIR%/*.o
  
* \endcode
*  и запустить его на исполнение.
*  - Результат построения будет в папке \$(BoostRoot)/stage/lib.
*  
* \note
*  Сборка производилась:
*  - 1.09.2016.
*  - Android NDK r12.
*  - Boost 1.61.
*  
*  Сборка при помощи gcc
*  ---------------------
*
*  - В папке \$(BoostRoot)/tools/build/src создать файл с именем 
*  user-config.jam, содержащий (заменить путь к Android NDK при необходимости):
* \code

ANDROID_NDK = d:/android/ndk ;

using gcc : android : $(ANDROID_NDK)/toolchains/arm-linux-androideabi-4.9/prebuilt/windows/bin/arm-linux-androideabi-g++ :
<compileflags>--sysroot=$(ANDROID_NDK)/platforms/android-15/arch-arm
<compileflags>-I$(ANDROID_NDK)/sources/cxx-stl/gnu-libstdc++/4.9/include
<compileflags>-I$(ANDROID_NDK)/sources/cxx-stl/gnu-libstdc++/4.9/libs/armeabi-v7a/include
<compileflags>-I$(ANDROID_NDK)/sources/cxx-stl/gnu-libstdc++/4.9/include/backward
<compileflags>-o
<compileflags>-xc++-header
<compileflags>-xc++
<compileflags>-std=c++1y
<compileflags>-fexceptions
<compileflags>-O3
<compileflags>-DNDEBUG
<compileflags>-D__ANDROID__
<compileflags>-D__SOFTFP__
<compileflags>-D__arm__
<compileflags>-g2
<compileflags>-lstdc++
<compileflags>-D__GLIBC__
<compileflags>-DBOOST_FILESYSTEM_VERSION=3
<linkflags>-r"s"
<archiver>$(ANDROID_NDK)/toolchains/arm-linux-androideabi-4.9/prebuilt/windows/bin/arm-linux-androideabi-ar
<ranlib>$(ANDROID_NDK)/toolchains/arm-linux-androideabi-4.9/prebuilt/windows/bin/arm-linux-androideabi-ranlib
;

* \endcode
*  - В папке \$(BoostRoot) запустить bootstrap.bat.
*  - В папке \$(BoostRoot) создать файл BuildAndroid.cmd, содержащий:
* \code

b2 --without-python --without-thread toolset=gcc-android target-os=linux threading=multi link=static runtime-link=static -j 4

* \endcode
*  и запустить его на исполнение.
*  - Результат построения будет в папке \$(BoostRoot)/stage/lib.
*  
* \note
*  Сборка производилась:
*  - 1.09.2016.
*  - Android NDK r12.
*  - Boost 1.60.
*
* \warning
*  Для Boost 1.61 сборка при помощи gcc не работает, b2.exe при запуске просто
*  висит безо всякого видимого результата.
*/
