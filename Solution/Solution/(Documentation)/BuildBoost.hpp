
/**
* \page BuildBoost Сборка Boost для Android
*  
*  Сборка при помощи gcc
*  ---------------------
*  
* \note
*  Сборка производилась:
*  - 3.05.2017.
*  - crystax-ndk-10.3.2.
*  - Boost 1.64.
*  
*  Сборка:
*  - В папке \$(BoostRoot) запустить bootstrap.bat (будет построен файл b2.exe).
*  - В папке \$(BoostRoot)/tools/build/src создать файл с именем
*  user-config.jam, содержащий (при необходимости изменить путь к ANDROID_NDK и
*  нужный ANDROID_API):
* \include ".\Solution\(Documentation)\user-config.jam"
*  
*  - В папке \$(BoostRoot) создать и запустить на исполнение файл 
*  BuildAndroid.cmd (при необходимости изменить путь к ANDROID_NDK и библиотеке
*  icu):
* \include ".\Solution\(Documentation)\BuildAndroid.cmd"
*  
*  - Результат построения будет в папке \$(BoostRoot)/android/lib.
*  
* \warning
*  После первого запуска не будет построена библиотека Boost.Locale, т.к. 
*  сборщик Boost не сможет собрать файл 
*  \$(BoostRoot)/libs/locale/build/has_icu_test.cpp (в чем проблема, неясно,
*  ясно только, что для сборки этого файла не используются настройки из
*  user-config.jam, а используются настройки по умолчанию); для того, чтобы
*  собрать Boost.Locale, нужно в файле \$(BoostRoot)/bin.v2/project-cache.jam
*  заменить \b false на \b true в строке
* \code

set "icu-<address-model>32-<architecture>arm-<target-os>linux-<toolset-clang:version>android-<toolset>clang" : "false" ;

* \endcode
*  после чего запустить скрипт BuildAndroid.cmd еще раз.
*  
* \note
*  Во всех файлах выше используется слово \b clang, хотя сборка производится 
*  при помощи \b gcc. Это из-за того, что, начиная с версии 1.61, запуск
*  построения при созданном файле user-config.jam, содержащем 
*  "using gcc : android :", сборка просто зависает.
*
*  Сборка при помощи Clang
*  -----------------------
*  
* \note
*  Сборка производилась:
*  - 1.09.2016.
*  - Android NDK r12.
*  - Boost 1.61.
*  
*  Сборка:
*  - В папке \$(BoostRoot) запустить bootstrap.bat.
*  - В папке \$(BoostRoot) создать и запустить на исполнение файл 
*  BuildAndroid.cmd, содержащий (\b ANDROID_NDK задает путь к (сюрприз!) 
*  ANDROID NDK, \b RESULT - к 'суммарному' файлу всех собранных библиотек):
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
*  - Результат построения будет в папке \$(BoostRoot)/stage/lib.
*/
