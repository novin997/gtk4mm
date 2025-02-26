#include "sigc++/functors/mem_fun.h"
#include <gtkmm.h>
#include <iostream>

class MyWindow : public Gtk::Window
{
public:
  MyWindow();

  Gtk::Button button,button_1,button_2;

  Gtk::Grid grid;

  Gtk::Picture picture;

  void on_button_clicked();
};

MyWindow::MyWindow():
  button("Click on me"),
  button_1("Button_1"),
  button_2("Button_2"),
  picture("./images/steins_gate.jpg")
{
  grid.set_margin(12);
  set_child(grid);
  
  grid.attach(button,0,0);

  grid.attach(button_1,1,0);

  grid.attach(button_2,0,1,2);

  grid.attach(picture,0,2);

  button.set_margin(10);
  button.signal_clicked().connect(sigc::mem_fun(*this,&MyWindow::on_button_clicked));
  set_title("Anime3x3");
  set_default_size(640, 480);
}  

void MyWindow::on_button_clicked() {
  std::cout << "Button Clicked" << std::endl;
}

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.examples.base");

  return app->make_window_and_run<MyWindow>(argc, argv);
}
