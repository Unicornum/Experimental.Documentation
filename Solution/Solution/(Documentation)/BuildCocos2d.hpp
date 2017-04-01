
/**
* \page BuildCocos2d Сборка Cocos2d для Android
*  
*  Создание проекта
*  ----------------
*
* \pre
*  Для сборки требуются установленные Android SDK, NDK и Apache Ant.
*
* \pre
*  Сборка производилась:
*  - 21.10.2016
*  - Android SDK (Android Studio 2.1).
*  - Crystax-ndk-10.3.2
*  - apache-ant-1.9.7
*  - cocos2d-x-3.13.1
*  - python-2.7.12
*
*  \n
*  - Скачать [Python], установить его и добавить путь к файлу python.exe к
*  переменной окружения PATH (\b ВАЖНО! Cocos2d требует python версий 2.7.x).
*  - Скачать архив с [Cocos2d] и распаковать его.
*  - Из консоли в папке Cocos2d (запуск из консоли нужен из-за того, что
*  потребуется ввести пути к Android SDK, NDK и Apache Ant; либо можно
*  предварительно установить переменные окружения \b ANDROID_SDK_ROOT,
*  \b NDK_ROOT и \b ANT_ROOT) запустить:
* \code

python setup.py

* \endcode
*  Будут добавлены переменные окружения для Cocos.
*  - В консоли (в папке, в которой нужно создать проект; \b ВАЖНО! В пути не
*  должно быть русских букв!) для сборки библиотеки выполнить:
* \code

cocos new Cocos2d -l cpp -d Cocos2dLib

* \endcode
*  - В сгенерированную папку Cocos2dLib\\Cocos2d скопировать содержимое
*  [VSSolution].
*
*  Решение в папке Cocos2dLib\\Cocos2d\\proj.visualstudio можно собрать и
*  использовать для создания приложений.
*
*  Сборка Cocos2d-x как статической библиотеки
*  -------------------------------------------
*
*  - В папке Cocos2dLib\\Cocos2d\\proj.visualstudio открыть решение, у проекта
*  \b Cocos2dcpp удалить папку jni, формат отладочной информации поставить в
*  \b Нет, изменить свойства проекта:
*  
* \image html ".\Solution\Solution\(Documentation)\Cocos2dProps.png"
*  
*  и собрать Release и Debug версии.
*
* \warning
*  Статическая библиотека таким образом собирается, \b НО(!), во-первых
*  cpu-features нужно собирать как отдельную библиотеку (и ставить ее после
*  webp), во-вторых - при построении .so файла с использованием такой
*  библиотеки он не задействует файлы, указанные в дополнительных зависимостях
*  компоновщика (libOpenSLES.so, libEGL.so, libz.a), из-за чего приходится
*  подключать libz явным образом (и подхватывается библиотека, конфликтующая
*  с libpng) и файл результата оказывается гораздо меньшего размера и не
*  работает при запуске на Android-устройстве.
*  
*  Источники:
*  - [Cocos2dVSMicrosoft]
*  - [Cocos2dVsCocos]
*
*  [Cocos2d]: http://cocos2d-x.org/download "Cocos2d download"
*  [Python]: https://www.python.org/downloads/ "Python download"
*  [VSSolution]: https://github.com/Unicornum/Android/tree/master/Cocos2d/v3.13.1/Vs2015 "Visual Studio Cocos Solution"
*  [Cocos2dVSMicrosoft]: https://blogs.msdn.microsoft.com/vcblog/2016/07/12/cocos2d-x-visual-studio-android-project/ "Статья на сайте Microsoft"
*  [Cocos2dVsCocos]: http://cocos2d-x.org/docs/installation/Android-VisualStudio/ "Статья на сайте Cocos2d"
*/
