#include "Window.h"

// конструкторы
Window::Window() : title("default"), x(0), y(0), width(0), height(0), visibility(false)//видимость
{}

Window::Window(string title, int x, int y, int width, int height) :
        title(title), x(x), y(y), width(width), height(height), visibility(true)
{};

// Конструктор копирования
Window::Window(const Window &obj)
{
    this->title = obj.title;
    this->x = obj.x;
    this->y = obj.y;
    this->width = obj.width;
    this->height = obj.height;
    this->visibility = obj.visibility;
}

// деструктор, для освобождения памяти
Window::~Window()
{
    cout << "Окно удалено\n";
}

Window Window::operator+(const double &offset) {
    Window result_window(this->title, this->x, this->y, this->width, this->height);

    if (is_point_in_screen(x+offset, y) &&
        is_point_in_screen(x+offset+width, y) &&
        is_point_in_screen(x+offset+width, y+height) &&
        is_point_in_screen(x+offset, y+height)) {
        result_window.set_X(this->x + offset);
        cout << "Успешно передвинуто\n";
    } else {
        cout << "Ошибка перемещения, окно заходит за границы\n";
    }
    return result_window;
}

void Window::operator+=(const double &offset) {
    if (is_point_in_screen(x+offset, y) &&
        is_point_in_screen(x+offset+width, y) &&
        is_point_in_screen(x+offset+width, y+height) &&
        is_point_in_screen(x+offset, y+height)) {
        (*this).set_X(x + offset);
        cout << "Успешно передвинуто\n";
    } else {
        cout << "Ошибка перемещения, окно заходит за границы\n";
    }
}

bool Window::operator==(const Window &window) {
    return this->x == window.x && this->y == window.y;
}

bool Window::operator!() {
    return !visibility;
}

void Window::input_from_keyboard() {
    cout << "*************************\n";
    cout << "Введите заголовок: "; cin >> title;
    cout << "Введите x: "; cin >> x;
    cout << "Введите y: "; cin >> y;
    cout << "Введите ширину: "; cin >> width;
    cout << "Введите высоту: "; cin >> height;
    visibility = true;
    cout << "*************************\n";
}

istream& operator>>(istream& stream, Window& matrix) {
    cout << "*************************\n";
    cout << "Введите заголовок: "; cin >> matrix.title;
    cout << "Введите x: "; cin >> matrix.x;
    cout << "Введите y: "; cin >> matrix.y;
    cout << "Введите ширину: "; cin >> matrix.width;
    cout << "Введите высоту: "; cin >> matrix.height;
    matrix.visibility = true;
    cout << "*************************\n";
}

bool Window::is_point_in_screen(int x, int y) {
    return x >= 0 && y >= 0 && x <= screen_width && y <= screen_height;
}
void Window::move(int dx, int dy) {
    x += dx;
    y += dy;
// проверка на находжение окна внутри экрана
    if (is_point_in_screen(x, y) &&
        is_point_in_screen(x+width, y) &&
        is_point_in_screen(x+width, y+height) &&
        is_point_in_screen(x, y+height)) {
        cout << "Успешно передвинуто\n";
    } else {
        cout << "Ошибка перемещения, окно заходит за границы\n";
        x -= dx;
        y -= dy;
    }
}
void Window::change_size(int dw, int dh) {
    width += dw;
    height += dh;
// проверка на находжение окна внутри экрана
    if (is_point_in_screen(x, y) &&
        is_point_in_screen(x+width, y) &&
        is_point_in_screen(x+width, y+height) &&
        is_point_in_screen(x, y+height)) {
        cout << "Успешно изменен размер\n";
    } else {
        cout << "Ошибка изменения размера, окно заходит за границы\n";
        width -= dw;
        height -= dh;
    };
}

void Window::make_visible() {
    this->visibility = true;
    cout << "Теперь окно " << title << " видимое\n";
}
void Window::make_invisible() {
    this->visibility = false;
    cout << "Теперь окно " << title << " невидимое\n";
}


void Window::print() const {
    cout << "--------------------\n";
    cout << "Заголовок: " << title << "\n";
    cout << "x, y: (" << x << ", " << y << ")\n";
    cout << "Ширина, высота: (" << width << ", " << height << ")\n";
    cout << "Видимость: " << ((visibility) ? "видимое" : "невидимое") << "\n";
    cout << "Размеры экрана: (" << screen_width << ", " << screen_height << ")\n";
    cout << "--------------------\n";
}

ostream& operator<<(ostream& stream, Window& matrix) {
    cout << "--------------------\n";
    cout << "Заголовок: " << matrix.title << "\n";
    cout << "x, y: (" << matrix.x << ", " << matrix.y << ")\n";
    cout << "Ширина, высота: (" << matrix.width << ", " << matrix.height << ")\n";
    cout << "Видимость: " << ((matrix.visibility) ? "видимое" : "невидимое") << "\n";
    cout << "Размеры экрана: (" << matrix.screen_width << ", " << matrix.screen_height << ")\n";
    cout << "--------------------\n";
}

string Window::get_Title() const {return title;}
int Window::get_X() const {return x;} // :: оператор доступа к области видимости
int Window::get_Y() const {return y;}
int Window::get_Width() const {return width;}
int Window::get_Height() const {return height;}
bool Window::get_Visibility() const {return visibility;}

void Window::set_Title(string t) {this->title = t;}
void Window::set_X(int x) {this->x = x;}
void Window::set_Y(int y) {this->y = y;}