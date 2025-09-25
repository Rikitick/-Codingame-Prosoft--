# Puzzles c сайта Codingame
Здесь находятся алгоритмические задачи с сайта Codingame для поступления в школу разработчиков Prosoft-системы

## Оглавление
- [Easy задачи](#easy-задачи)
  - [1D Spreadsheet](#1d-spreadsheet)
  - [Ascii art](#ascii-art)
  - [Defibrillators](#defibrillators)
  - [Encryption/decryption of Enigma machine](#encryption/decryption-of-enigma-machine)
  - [Ghost legs](#ghost-legs)
  - [Horse-racing duals](#horse-racing-duals)
  - [Island escape](#island-escape)
  - [Logic gates](#logic-gates)
  - [MIME type](#mime-type)
  - [Power of Thor - Episode 1](#power-of-thor-episode-1)
  - [Retro typewriter art](#retro-typewriter-art)
  - [Temperatures](#temperatures)
  - [The descent](#the-descent)
  - [The River I](#the-river-I)
  - [Unary](#unary)
- [Medium задачи](#medium-задачи)
- [Hard задачи](#hard-задачи)

## Easy задачи 
  ### 1D Spreadsheet
  [Код](/Puzzles/Easy/1d_spreadsheet.cpp)  
  [Задача](https://www.codingame.com/ide/puzzle/1d-spreadsheet)  
  __Идея__: Рекурсивно вычисляем каждую ячейку. Если встречаем ссылку на другую ячейку (например, $3) - сначала вычисляем ту ячейку, потом используем её значение.  
  __Трудности__: Додуматься, как хранить значение и как использовать предыдущие (решил воспользоваться `struct`). Потом были проблемы с повторными вычислениями из-за чего вышибало дно рекурсии (решил это флагом `calculated`)  
  [К оглавлению](#оглавление)
  
  ### Ascii art
  [Код](/Puzzles/Easy/ascii_art.cpp)  
  [Задача](https://www.codingame.com/ide/puzzle/ascii-art)  
  __Идея__: Построчно сохранять символы алфавита, а потом построчно из алфавита брать те символы, которые относяться к буквам слова и сразу же выводить составленную строку  
  __Трудности__: В слове мог быть символ, которого нет в алфавите, а значит формула `c - 'A'` могла привести к ошибке `index was out of range`  
  [К оглавлению](#оглавление)

  ### Defibrillators
  [Код](/Puzzles/Easy/defibrillators.cpp)  
  [Задача](https://www.codingame.com/ide/puzzle/defibrillators)  
  __Идея__: Считать данные из `input`, сохранить только `Name`, `Longitude` и `Latitude` предварительно переведя в `double`, в цикле посчитать для каждого дифибрилятора расстояние до пользователя, выбрать минимальное и вывести название дифибрилятора с минимальным расстоянием  
  __Трудности__: В `input`-е `Longitude` и `Latitude` даются с `,`, из-за этого `stod` выдаёт ошибку  
  [К оглавлению](#оглавление)

  ### Encryption/decryption of Enigma machine
  [Код](/Puzzles/Easy/encryption_decryption_of_enigma_machine.cpp)  
  [Задача](https://www.codingame.com/ide/puzzle/encryptiondecryption-of-enigma-machine)  
  __Идея__: Описана в самой задаче. При декодировании просто сделать описанные действия в обратном порядке роторов  
  __Трудности__: Продумать формулу вычисления следующей буквы для кодирования и декодирования.  
  [К оглавлению](#оглавление)

  ### Ghost legs
  [Код](/Puzzles/Easy/ghost_legs.cpp)  
  [Задача](https://www.codingame.com/ide/puzzle/ghost-legs)  
  __Идея__: Спускаемся сверху вниз по каждой вертикальной линии. На каждой высоте проверяем, есть ли горизонтальные перемычки слева или справа. Если есть, переходим на соседнюю линию. Когда дошли до конца выводим начальную верхнюю метку и конечную нижнюю  
  __Трудности__: Пролетела со свистом)  
  [К оглавлению](#оглавление)

  ### Horse-racing duals
  [Код](/Puzzles/Easy/horse-racing_duals.cpp)  
  [Задача](https://www.codingame.com/ide/puzzle/horse-racing-duals)  
  __Идея__: Жадный алгоритм. Сортируем силы лошадей по возрастанию и попарно перебираем, начиная с 1-ой, сохраняя минимальную разницу в переменную  
  __Трудности__: Пролетела со свистом :)  
  [К оглавлению](#оглавление)

  ### Island escape
  [Код](/Puzzles/Easy/island_escape.cpp)  
  [Задача](https://www.codingame.com/ide/puzzle/island-escape)  
  __Идея__: DFS (Обход графа в глубину). Начинаем с точки `{n/2, n/2}` и добавляем в массив вершин точки, у которых разница с текущей <= 1. Обязательно помечаем обработанные точки, чтобы не уйти в бесконечный цикл   
  __Трудности__: Вспомнить DFS XD  
  [К оглавлению](#оглавление)
  
## Medium задачи
  [К оглавлению](#оглавление)


## Hard задачи
  [К оглавлению](#оглавление)
