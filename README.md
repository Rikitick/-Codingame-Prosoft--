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

## Medium задачи
  [К оглавлению](#оглавление)


## Hard задачи
  [К оглавлению](#оглавление)
