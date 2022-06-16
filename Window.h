#ifndef WINDOW_H //если неопределен
#define WINDOW_H
#pragma once

#include <iostream>
#include <string>
using namespace std;

class Window
{
private:
    string title; // заголовок окна
    int x, y; //левый верхний угол
    int width, height; //ширина высота
    bool visibility; // видимость

    int screen_width = 1920, screen_height = 1080; // ширина и высота экрана для ф-ии движения
    bool is_point_in_screen(int x, int y); // проверяет находится ли точка внутри экрана

public:
    Window();
    Window(string title, int x, int y, int width, int height);
    Window(const Window &obj);
    ~Window(); // деструктор

    void input_from_keyboard();

    void move(int dx, int dy); // перемещение окна
    void change_size(int dw, int dh); // изменение размера окна
    void make_visible(); // сделать видимым
    void make_invisible(); // сделать невидимым

    void print() const;
// геттеры получить данные
    string get_Title() const;
    int get_X() const;
    int get_Y() const;
    int get_Width() const;
    int get_Height() const;
    bool get_Visibility() const;
// сеттеры присвоить данные
    void set_Title(string t);
    void set_X(int x);
    void set_Y(int y);
    void set_Visibility(bool v);

    Window operator+(const double &offset);
    void operator+=(const double &offset);
    bool operator==(const Window &window);
    bool operator!();

    friend ostream& operator<<(ostream& stream, Window& matrix);
    friend istream& operator>>(istream& stream, Window& matrix);
};

#endif