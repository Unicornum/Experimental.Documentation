
/**
* \page ExternalsWindowsPage Построение для Windows
*  
*  Boost
*  -----
*  Домашняя страница: [Boost](http://www.boost.org/).
*
*  Построение всех возможных вариантов:
* \code

bootstrap.bat
b2.exe

* \endcode
*  Построение только нужных библиотек:
* \code

bootstrap.bat
b2.exe --build-type=minimal msvc stage --with-filesystem

* \endcode
*  Построение для конкретной версии Visual Studio:
* \code

// Для VS2008
bootstrap.bat vc9
b2.exe toolset=msvc-9.0

* \endcode
*  [Построение для x64](http://devsql.blogspot.ru/2007/05/building-boost-134-for-x86-x64-and-ia64.html).
*
* ### Конфликт в DLL, построенной на базе MFC
*  Проявляется как assert'ы в файлах dllinit.cpp и dllmodul.cpp при загрузке DLL.
*
*  Для решения проблемы, закомментировать в файле
*  ./libs/thread/src/win32/tss_pe.cpp строку
* \code

// extern BOOL (WINAPI * const _pRawDllMain)(HANDLE, DWORD, LPVOID)=&dll_callback;

* \endcode
*  и пересобрать lib'ы. Также нужно будет при выгрузке библиотеки вызвать
* \code

#include <boost/thread/detail/tss_hooks.hpp>
on_process_exit();

* \endcode
*
*  Poco
*  ----
*  Домашняя страница [Poco](http://pocoproject.org/).
*
*  ### Построение
*  Использование buildwin.cmd:
* \include "Solution\Externals\Externals\Poco\Build.txt"
*  Для построения без отладочной информации открыть нужное решение в папке
*  Foundation, в свойствах проекта в разделе "C\C++" параметр "Формат
*  отладочных данных" установить в "Нет".
*
*  wxWidgets
*  ---------
*  Домашняя страница: [wxWidgets](https://www.wxwidgets.org/).
*
*  ### Построение для Windows
*  - Скачать [инсталлятор](http://www.wxwidgets.org/downloads/).
*  - Установить библиотеку.
*  - Открыть решение для нужной версии Visual Studio в папке build\\msw.
*  - Отключить UniCA (чтобы она не подключала Version.rc) и собрать все решение
*  (результат построения будет в папке lib).
*  - Не используемые библиотеки добавить в Lib.props (параметр "Игнорировать
*  библиотеки в разделе Компоновщик -> Ввод).
*
*  ### Полезные ссылки
*  -# [Перевод книги](http://wx.cdelta.org/).
*  -# [Визуальный редактор форм](http://sourceforge.net/projects/wxformbuilder/).
*
*  Crypto++
*  --------
*  Домашняя страница [Crypto++](https://www.cryptopp.com/)
*
*  ### Построение для Windows
*  - Скачать архив, распаковать его и открыть решение cryptest.sln.
*  - В свойствах проекта cryptlib C\\C++ -> Общее -> Формат отладочной информации
*  поставит в \b Нет, а C\\C++ -> Создание кода -> Библиотека времени выполнения
*  - в 'Многопоточная (отладка) DLL'.
*  - Собрать нужные конфигурации.
*/
