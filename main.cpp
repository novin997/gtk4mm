#include "sigc++/functors/mem_fun.h"
#include <gtkmm.h>
#include <iostream>

class MyWindow : public Gtk::Window
{
public:
  MyWindow();

  Gtk::Button button,button_1,button_2;

  Gtk::Grid grid;

  Gtk::Grid boardGrid;

  Gtk::Picture picture;

  Gtk::Image image;

  Gtk::Entry entry;

  void on_button_clicked();

  void on_text_change();
};

MyWindow::MyWindow():
  button("Click on me"),
  button_1("Button_1"),
  button_2("Button_2"),
  picture("./images/steins_gate.jpg"),
  image("./images/steins_gate.jpg")
{
  grid.set_margin(12);
  set_child(grid);
  grid.set_column_homogeneous(true);
  
  grid.attach(button,0,0,1);

  grid.attach(button_1,1,0,1);

  grid.attach(button_2,0,1,2);

  boardGrid.attach(picture,0,0);
  boardGrid.attach(image,1,0);

  boardGrid.set_column_homogeneous(true);

  grid.attach(boardGrid,0,2,2);

  grid.attach(entry,0,3);

  entry.set_text("Text");
  // entry.signal_insert_text().connect(sigc::mem_fun(*this,&MyWindow::on_text_change));
  entry.signal_changed().connect(sigc::mem_fun(*this,&MyWindow::on_text_change));

  button.set_margin(10);
  button.signal_clicked().connect(sigc::mem_fun(*this,&MyWindow::on_button_clicked));

  set_title("Anime3x3");
  set_default_size(640, 480);
}

void MyWindow::on_text_change() {
  std::cout << "Text change" << std::endl;
} 

void MyWindow::on_button_clicked() {
  std::cout << "Button Clicked" << std::endl;
}

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.examples.base");

  return app->make_window_and_run<MyWindow>(argc, argv);
}
