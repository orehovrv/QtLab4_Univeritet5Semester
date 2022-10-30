# QtLab4_Univeritet5Semester
В данной работе необходимо написать программу в соответствие с индивидуальным вариантом. 

Все варианты описывают набор объектов для графической сцены (QGraphicsScene). 

Если в варианте не сказано иного, то должны использоваться объекты трёх разных классов, унаследованных от QGraphicsItem. 

У каждого из этих классов должны быть переопределена функция paint. 

В зависимости от варианта либо для каждого из классов должна быть переопределена функция обработки указанного в варианте события, либо должен быть создан класс для фильтрации событий и подключён к объектам. 

Необходимо реализовать возможность выбора типа объекта для добавления на сцену, добавление неограниченного числа объектов любого из указанных в задании классов на сцену, удаление объекта (в зависимости от варианта либо через список, либо через обработку события), выбор и перемещение объекта. 

Если в качестве объекта используется стандартный виджет, то он должен выполнять указанную в варианте функцию.

Некоторые варианты заданий могут противоречить написанному выше, в этом случае приоритет у написанного в варианте.

Написать программу, позволяющую разместить на графической сцене произвольное число объектов, следующих трёх типов:  
1. Текст, предварительно введённый пользователем (для каждого объекта свой);  
2. Квадрат одного из трёх цветов: синий кадетский, тёмный лосось, помидор по выбору пользователя;  
3. Изображение одного из трёх греческих богов: Зевса, Посейдона или Аида.


Должно быть предусмотрено перемещение добавляемых объектов путём перетаскивания их левой кнопкой мыши.

Также должен быть представлен список из всех добавленных элементов, с возможностью выбора и удаления любого из них, а также изменения бога, текста или цвета.

С помощью фильтра событий, должна быть добавлена возможность выбирать объект в списке при нажатии на него правой кнопкой мыши на сцене.
