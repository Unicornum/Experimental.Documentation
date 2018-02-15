
#include "stdafx.h"

/**
* \file
*  Описание файла.
*/

/**
* \defgroup Part1Group Группа классов первого раздела
*  Описание группы классов.
*/

/**
* \defgroup Part1Project1Group Группа классов первого проекта
* \ingroup Part1Group
*  Описание группы классов.
*/

/**
* \ingroup Part1Project1Group
* \brief
*  Класс входит в проект \ref Part1Project1Page \n
*  < Краткое описание класса >
* \details
*  - Подробное описание класса.
*  
* \version
*  1.0.0.0        \n
* \date
*  14 Февраль 2018    \n
* \author
*  CTAPOBEP (unicornum.verum@gmail.com)
* \copyright
*  © CTAPOBEP 2018
*  
*  Пример использования:
*  ---------------------
*  
* ### Первый пример
*  
* \code
// Здесь должен быть пример использования...
// ...
* \endcode
*/
class Base
{
public:
  virtual int DoIt(int _Index) = 0;
};

/**
* \ingroup Part1Project1Group
* \brief
*  Класс входит в проект \ref Part1Project1Page \n
*  < Краткое описание класса >
* \details
*  - Подробное описание класса.
*  
* \version
*  1.0.0.0        \n
* \date
*  14 Февраль 2018    \n
* \author
*  CTAPOBEP (unicornum.verum@gmail.com)
* \copyright
*  © CTAPOBEP 2018
*  
*  Пример использования:
*  ---------------------
*  
* ### Первый пример
*  
* \code
// Здесь должен быть пример использования...
// ...
* \endcode
*/
class ClassName final : 
  public Base
{
public:
  virtual int DoIt(int _Index);
};

/**
* \brief
*  Функция для <... краткое описание>.
* \details
*  - Функция предназначена для <... подробное описание>.
*  
* \param [in] _Index
*  Исходное значение.
*  
* \return \b Value
*  В случае (таком-то...).
*  
* \exception std::exception
*  - Действие невозможно (подробнее см. описание исключения).
*/
/*virtual*/ int ClassName::DoIt(int _Index)
{
  return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
  TODO("Сделай это немедленно!");

	return 0;
}
