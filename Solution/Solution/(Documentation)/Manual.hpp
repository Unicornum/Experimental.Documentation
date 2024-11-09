
/**
* \page ManualPage Manual
*
*  Примеры форматирования
*  ======================
*
*  Примеры используемых тегов Doxygen
*  ----------------------------------
*
*  Текст для проверки отступа.
*
* \note
*  Это неочевидные подробности работы функции.
*
* \pre
*  Предусловие, которое следует выполнить, чтобы можно было этим
*  воспользоваться.
*
* \warning
*  ВАЖНО! На это следует обратить внимание.
*
* \bug
*  Страшный баг, требует немедленного излечения.
*
* \todo
*  Сделай это, ну пожааааааааааааааааалуйста!.
*
* \test
*  Тестовый объект.
*
* \deprecated
*  Устаревшая функция/класс, не использовать в новом коде.
*
*  Предварительный просмотр изображений
*  ------------------------------------
*  
* ### Открытие в новом окне
*  
* \htmlonly

<!-- Отображение на той же странице -->
<a href="ScreenShot.png"><img class="preview" src="ScreenShot.png"></a>

<!-- Отображение на новой странице -->
<a target="_blank" href="ScreenShot.png"><img class="preview" src="ScreenShot.png"></a>

* \endhtmlonly
* \copydoc Preview1Page
*  
* ### Открытие во всплывающем окне
*
* \htmlonly

<img class="PreviewImage" src="ScreenShot.png">
<img class="PreviewImage" src="ScreenShot.png">

* \endhtmlonly
* \copydoc Preview2Page
*  
*  Примеры описания классов/функций
*  --------------------------------
*
*  ClassName
*
*  Пример формирования таблицы
*  ---------------------------
*
* The following text **table** produces a full HTML table with its
* first column centered, and the last column left aligned.
*
* | Return Code | Meaning                |
* | :---------: | :--------------------- |
* | 0           | Success 1              |
* | ^           | Success 2              |
* | 10          | Unexpected end-of-file |
* | 20          | Communication error    |
* | 30          | Invalid input          |
*
*  Ссылки
*  ------
*
*  [Boost](http://www.boost.org/) \n
*  <http://www.boost.org/> \n
*  [Boost можно скачать здесь].
*
*  [Boost можно скачать здесь]: http://www.boost.org/ "Boost"
*
*  Блоки кода
*  ----------

~~~~~~~~~~~~~~~~~{.cpp}
#pragma once
~~~~~~~~~~~~~~~~~

*  Checkbox'ы
*  ----------
*
* - \checked Выполненное требование.
* - \checked Выполненное требование.
* - \checked Выполненное требование.
* - \unchecked Не выполненное требование.
*
*  --------------
*/

/**
* \page ScreenShotsPage ScreenShots
*
* \image html "./Solution/(Documentation)/ScreenShot.png" "ScreenShot"
*
*/

/**
* \page Preview1Page
* \htmlonly

<style>

img.preview {
  border: 1px solid #ddd;
  border-radius: 10px;
  width: 250px;
}

img.preview:hover{
  box-shadow: 0 0 2px 1px rgba(0, 140, 186, 0.5);
  opacity: 0.7;
}

</style>

* \endhtmlonly
*/

/**
* \page Preview2Page
* \htmlonly

<style>

.PreviewImage {
  width:100%;
  max-width:250px;
  border-radius: 10px;
  cursor: pointer;
  transition: 0.3s;
}

.PreviewImage:hover {
  opacity: 0.7;
}

.modal{
  display: none;
  position: fixed;
  z-index: 9999;
  padding-top: 100px;
  left : 0;
  top : 0;
  width: 100%;
  height: 100%;
  overflow: auto;
  background-color: rgb(0,0,0);
  background-color: rgba(0,0,0,0.9);
}

.modal-content{
  margin: auto;
  display: block;
  width: 80%;
  max-width: 700px;
}

#caption{
  margin: auto;
  display: block;
  width: 80%;
  max-width: 700px;
  text-align: center;
  color: #ccc;
  padding: 10px 0;
  height: 150px;
}

.modal-content, #caption{
  animation-name: zoom;
  animation-duration: 0.6s;
}

@keyframes zoom{
  from {transform:scale(0)}
  to {transform:scale(1)}
}

.close{
  position: absolute;
  top: 15px;
  right: 35px;
  color: #f1f1f1;
  font-size: 40px;
  font-weight: bold;
  transition: 0.3s;
}

.close:hover,
.close : focus{
  color: #bbb;
  text-decoration: none;
  cursor: pointer;
}

@media only screen and (max-width: 700px) {
  .modal-content{
    width: 100 % ;
  }
}
</style>

<!-- Окно предварительного просмотра -->
<div id="PreviewWindow" class="modal">
  <span class="close">&times;</span>
  <img class="modal-content" id="FullSizeImage">
</div>

<script>

// Для всех изображений...
var Images = document.getElementsByClassName('PreviewImage');

for (i = 0; i < Images.length; i++)
{
  Images[i].onclick = function()
  {
    document.getElementById('PreviewWindow').style.display = "block";
    document.getElementById("FullSizeImage").src = this.src;
  };
}

// Для элемента, закрывающего окно предпросмотра...
var Close = document.getElementsByClassName("close")[0];

Close.onclick = function()
{
  document.getElementById('PreviewWindow').style.display = "none";
}

</script>

* \endhtmlonly
*/