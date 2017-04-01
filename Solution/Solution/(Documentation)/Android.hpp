
/**
* \page ExternalsAndroidPage Построение для Android
*
*  \subpage PrebuiltLibrariesPage
*
*  \subpage BuildBoost
*
*  \subpage BuildCocos2d
*
* ### Сборка libRocket
*  [Сборка libRocket]
*
*  [Сборка libRocket]: https://github.com/Unicornum/Android/tree/master/libRocket "libRocket build"
*
* ### Сборка Crypto++
*
*  - Распаковать архив и открыть решение cryptest.sln.
*  - Добавить проект статической библиотеки для Android.
*  - Добавить в этот проект все .cpp файлы из папки cryptopp.
*  - Включить RTTI и исключения, отключить отладочную информацию.
*  - Собрать нужные конфигурации проекта.
*
* ### Сборка OpenFrameworks
*
*  - Собрать не удалось (ссылки на несуществующие функции, двойные определения
*  функций, не найденные функции стандартной библиотеки).
*  - В целом - ощущение, что работа нативного кода завязана на совместную
*  работу с кодом java.
*/
